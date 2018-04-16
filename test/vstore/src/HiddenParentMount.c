/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_HiddenParentMount_construct(
    test_HiddenParentMount this)
{
    /* Let corto filter results for the mount */
    corto_mount(this)->policy.filterResults = true;

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "foo",
        NULL,
        ".",
        "void",
        0,
        CORTO_RESULT_HIDDEN
    );

    corto_result__assign(
        corto_resultList__append_alloc(this->items),
        "bar",
        NULL,
        "foo",
        "void",
        0,
        CORTO_RESULT_LEAF
    );

    return corto_super_construct(this);
}

corto_resultIter test_HiddenParentMount_on_query(
    test_HiddenParentMount this,
    corto_query *query)
{
    this->on_query_count ++;
    return corto_ll_iterAlloc(this->items);
}
