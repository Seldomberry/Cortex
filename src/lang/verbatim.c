/* This is a managed file. Do not delete this comment. */

#include <corto>

int16_t corto_verbatim_init(
    corto_verbatim this)
{
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_primitive(this)->kind = CORTO_TEXT;
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return corto_primitive_init((corto_primitive)this);
}

