/* Fast_StaticCall.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::StaticCall::construct() */
cx_int16 _Fast_StaticCall_construct(Fast_StaticCall _this) {
/* $begin(::corto::Fast::StaticCall::construct) */
    Fast_Object fExpr;

    fExpr = Fast_ObjectCreate(_this->function);
    Fast_Parser_collect(yparser(), fExpr);
    cx_setref(&Fast_Call(_this)->functionExpr, fExpr);

    /* Set parameters */
    Fast_Call_setParameters(Fast_Call(_this), _this->function);

    /* If function is a metaprocedure, signal Call class to push this as any */
    Fast_Call(_this)->instanceIsAny = 
        (cx_procedure(cx_typeof(_this->function))->kind == CX_METAPROCEDURE);

    return Fast_Call_construct(Fast_Call(_this));
/* $end */
}