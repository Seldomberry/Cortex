/* ast_If.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::If::construct() */
cx_int16 _ast_If_construct(ast_If this) {
/* $begin(::corto::ast::If::construct) */
    cx_type conditionType;

    ast_Node(this)->kind = Ast_IfExpr;

    if (this->condition) {
        conditionType = ast_Expression_getType(this->condition);
        if (conditionType) {
            /* Check if condition can evaluate to a boolean value */
            if ((!this->condition->deref == Ast_ByReference) && !conditionType->reference && (conditionType->kind != CX_PRIMITIVE)) {
                ast_Parser_error(yparser(), "expression does not evaluate to condition");
                goto error;
            }
        }
    }
    
    this->warnUnreachable = TRUE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::If::noWarnUnreachable() */
cx_void _ast_If_noWarnUnreachable(ast_If this) {
/* $begin(::corto::ast::If::noWarnUnreachable) */
    this->warnUnreachable = FALSE;
/* $end */
}

/* ::corto::ast::If::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_If_toIc_v(ast_If this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::If::toIc) */
    ic_storage accumulator;
    ic_label labelEval = NULL, labelEnd = NULL;
    ic_node expr = NULL;
    cx_bool inverse = FALSE, condResult = FALSE;
    ast_Expression condition = NULL;
    cx_bool hasReturnedResource = ast_Expression_hasReturnedResource(this->condition);
    ic_node preEval = (ic_node)ic_program_pushAccumulator(
                    program, cx_type(cx_bool_o), FALSE,  FALSE); /* See below for explanation */

    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    if (this->condition && !(condition = ast_Node_optimizeCondition(this->condition, &condResult, &inverse))) {
        if (condResult) {
            ast_Block_toIc(this->trueBranch, program, NULL, FALSE);
            if (this->falseBranch && this->warnUnreachable) {
                ast_Parser_warning(yparser(), "false-branch has no effect");
            }
        } else if (this->falseBranch) {
            ast_If_toIc(this->falseBranch, program, NULL, FALSE);
            if (this->trueBranch && this->warnUnreachable) {
                ast_Parser_warning(yparser(), "true-branch has no effect");
            }
        }
    } else {

        /* The if-statement will insert the false-branch before the true branch. The reason for this is that
         * the first branch that comes directly after the condition evaluation, needs a second jump to
         * jump over the other branch. Assuming that the true-branch is most commonly occurring, it makes
         * sense to optimize for this case.
         * If there is no false-branch, obviously the true-branch is first to insert.
         */

        /* Parse condition (if no condition, assume true) */
        if (this->condition) {
            ic_derefKind deref1 = IC_DEREF_VALUE;

            if (condition->deref == Ast_ByReference) {
                deref1 = IC_DEREF_ADDRESS;
            }

            /* Obtain accumulator for evaluating the condition */
            accumulator = (ic_storage)ic_program_pushAccumulator(
                program,
                ast_Expression_getType(this->condition),
                condition->isReference,
                hasReturnedResource);

            /* Parse condition */
            expr = ast_Node_toIc(ast_Node(condition), program, accumulator, TRUE);

            /* Check whether condition is a resource returned by function.
             * Because of how resources are managed, his case needs to be handled
             * separately. Resources are references, strings or certain collections.
             * 
             * A function returnvalue used in an condition
             * is stored in a temporary register. Temporary registers don't do
             * resource management, except when they contain a resource returned
             * by a function. This is because a resource returned by a function
             * implies a change of ownership of the resource (and thus transfer
             * a resource claim).
             *
             * The assembler will automatically insert the code to free the
             * register, however since this code will insert jumps, there is a
             * possibility that the generated bytecode will jump over the
             * instruction that frees the resoure.
             *
             * For that purpose, this code stores the result of the evaluation
             * of the condition in a temporary boolean storage. The assembler
             * will therefore see that the storage containing the resource goes
             * out of use before the jump, and will insert the free instruction
             * before the jump occurs.
             */
             if (hasReturnedResource) {
                ic_node boolType = ic_node(ic_objectCreate(cx_bool_o));

                IC_3(program, ast_Node(this)->line, ic_cast, preEval, expr, boolType,
                    IC_DEREF_VALUE, deref1, IC_DEREF_ADDRESS);

                ic_program_popAccumulator(program);

                expr = preEval;
                deref1 = IC_DEREF_VALUE;
             }


            /* Create label to jump to when condition evaluates true */
            labelEval = ic_labelCreate();

            /* Evaluate condition, insert jump */
            if (this->falseBranch) {
                IC_3(program, ast_Node(this)->line, inverse ? ic_jneq : ic_jeq, expr, 
                    labelEval, NULL, deref1, IC_DEREF_VALUE, IC_DEREF_VALUE);

                /* Label to jump over true-branch */
                labelEnd = ic_labelCreate();
            } else {
                IC_3(program, ast_Node(this)->line, inverse ? ic_jeq : ic_jneq, expr,
                    labelEval, NULL, deref1, IC_DEREF_VALUE, IC_DEREF_VALUE);
            }

            ic_program_popAccumulator(program);
        }

        /* Parse false-branch if provided */
        if (this->falseBranch) {
            ast_If_toIc(this->falseBranch, program, NULL, TRUE);

            /* Insert jump to end (would otherwise continue at true-branch) */
            IC_1(program, ast_Node(this)->line, ic_jump, labelEnd, IC_DEREF_VALUE);

            /* If condition evaluates true, jump to this label */
            ic_program_add(program, ic_node(labelEval));
        }

        /* Insert true-branch */
        ast_Block_toIc(this->trueBranch, program, NULL, FALSE);
        if (this->condition && !this->falseBranch) {
            ic_program_add(program, (ic_node)labelEval);
        }

        if (this->falseBranch) {
            ic_program_add(program, (ic_node)labelEnd);
        }

        if (expr && (expr != preEval)) {
            ic_program_popAccumulator(program);
        }
    }

    return NULL;
/* $end */
}