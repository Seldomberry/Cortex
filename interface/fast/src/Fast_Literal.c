/* Fast_Literal.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
/* $end */

/* ::cortex::Fast::Literal::getValue() */
cx_word Fast_Literal_getValue_v(Fast_Literal _this) {
/* $begin(::cortex::Fast::Literal::getValue) */
    cx_word result = 0;

    switch(_this->kind) {
    case Fast_Bool: result = (cx_word)&Fast_Boolean(_this)->value; break;
    case Fast_Char: result = (cx_word)&Fast_Character(_this)->value; break;
    case Fast_Int: result = (cx_word)&Fast_Integer(_this)->value; break;
    case Fast_SignedInt: result = (cx_word)&Fast_SignedInteger(_this)->value; break;
    case Fast_Float: result = (cx_word)&Fast_FloatingPoint(_this)->value; break;
    default: break; /* Enumerated, Reference & Null have no value. String handles it's own value. */
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Literal::init() */
cx_int16 Fast_Literal_init(Fast_Literal _this) {
/* $begin(::cortex::Fast::Literal::init) */
    if (!Fast_Expression(_this)->type) {
        switch(_this->kind) {
        case Fast_Bool:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_bool_o);
            break;
        case Fast_Char:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_char_o);
            break;
        case Fast_Int:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_uint64_o);
            break;
        case Fast_SignedInt:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_int64_o);
            break;
        case Fast_Float:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_float64_o);
            break;
        case Fast_Text:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_string_o);
            break;
        case Fast_Enum:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_uint32_o);
            break;
        case Fast_Ref:
            Fast_Expression(_this)->type = (Fast_Variable)Fast_Object__create(cx_object_o);
            break;
        case Fast_Nothing:
            /* No type. */
            break;
        }
    }

    Fast_Node(_this)->kind = Fast_LiteralExpr;

    return Fast_Node_init(Fast_Node(_this));
/* $end */
}
