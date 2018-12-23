/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_Matcher_tc_filterA(
    test_Matcher this)
{
    corto_bool result = ut_expr("*", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterAnd(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*&*x", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterAndFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*&*y", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterAQ(
    test_Matcher this)
{
    corto_bool result = ut_expr("*?", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("b*", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterIdA(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterIdAFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*", "bx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterIdQ(
    test_Matcher this)
{
    corto_bool result = ut_expr("a?", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterIdQFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a?", "bx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterNot(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b*", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterNotAnd(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a*&*y", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterNotAndFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a*&*x", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterNotFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b*", "bx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterNotFilter(
    test_Matcher this)
{
    corto_bool result = ut_expr("*x^b*", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("*x^b*", "cx");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterNotFilterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("*x^a*", "ax");
    test_assertint(result, FALSE);

    result = ut_expr("*x^a*", "by");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterNotOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b*|c*", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterNotOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a*|b*", "ax");
    test_assertint(result, FALSE);

    result = ut_expr("^a*|b*", "by");
    test_assertint(result, FALSE);

    result = ut_expr("^a*|b*", "bx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*|b*", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("a*|b*", "ay");
    test_assertint(result, TRUE);

    result = ut_expr("a*|b*", "bx");
    test_assertint(result, TRUE);

    result = ut_expr("a*|*x", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("a*|*x", "abcx");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a*|b*", "cx");
    test_assertint(result, FALSE);

    result = ut_expr("a*|*y", "cx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterQA(
    test_Matcher this)
{
    corto_bool result = ut_expr("?*", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("?*", "abc");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterQFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("?", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_filterQQ(
    test_Matcher this)
{
    corto_bool result = ut_expr("??", "ax");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_filterQQFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("??", "a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_id(
    test_Matcher this)
{
    corto_bool result = ut_expr("a", "a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idAnd(
    test_Matcher this)
{
    corto_bool result = ut_expr("a&a", "a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idAndFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a&b", "a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("b", "a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idNot(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b", "a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idNotAnd(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a&b", "a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idNotAndFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a&a", "a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idNotFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b", "b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idNotOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b|c", "a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idNotOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a|b", "a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("a|b", "a");
    test_assertint(result, TRUE);

    result = ut_expr("a|b", "b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a|b", "c");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_idOrMulti(
    test_Matcher this)
{
    corto_bool result = ut_expr("a|b|c|d|e|f", "a");
    test_assertint(result, TRUE);

    result = ut_expr("a|b|c|d|e|f", "b");
    test_assertint(result, TRUE);

    result = ut_expr("a|b|c|d|e|f", "c");
    test_assertint(result, TRUE);

    result = ut_expr("a|b|c|d|e|f", "d");
    test_assertint(result, TRUE);

    result = ut_expr("a|b|c|d|e|f", "e");
    test_assertint(result, TRUE);

    result = ut_expr("a|b|c|d|e|f", "f");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_idOrMultiFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a|b|c|d|e|f", "g");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeFilter(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a*", "/ax");
    test_assertint(result, TRUE);

    result = ut_expr("/a*", "/ay");
    test_assertint(result, TRUE);

    result = ut_expr("/a*", "/abc");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeFilterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a*", "/bx");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeFilterMulti(
    test_Matcher this)
{
    corto_bool result = ut_expr("/*x/b", "/ax/b");
    test_assertint(result, TRUE);
    result = ut_expr("/*x/b", "/bx/b");
    test_assertint(result, TRUE);
    result = ut_expr("/*x/c", "bx/c");
    test_assertint(result, TRUE);
}

void test_Matcher_tc_scopeFilterMultiFail1(
    test_Matcher this)
{
    corto_bool result = ut_expr("/*y/b", "/ax/b");
    test_assertint(result, FALSE);
    result = ut_expr("/*y/b", "/ayx/b");
    test_assertint(result, FALSE);
    result = ut_expr("/*y/b", "/a/y/b");
    test_assertint(result, FALSE);
}

void test_Matcher_tc_scopeFilterMultiFail2(
    test_Matcher this)
{
    corto_bool result = ut_expr("/*x/c", "/ax/b");
    test_assertint(result, FALSE);
    result = ut_expr("/*x/c", "/axy/c");
    test_assertint(result, FALSE);
}

void test_Matcher_tc_scopeFilterMultiSingleFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a", "/a/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeFilterSingleMultiFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b", "/a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeId(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a", "/a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeIdFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/b", "/a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeIdMulti(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b", "/a/b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeIdMultiFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/c", "/a/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeIdMultiSingleFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a", "/a/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeIdSingleMultiFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b", "/a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeImplicit(
    test_Matcher this)
{
    corto_bool result = ut_expr("/", "/a");
    test_assertint(result, TRUE);

    result = ut_expr("/", "a");
    test_assertint(result, TRUE);

    result = ut_expr("/", "/b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeImplicitFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/", "/a/b");
    test_assertint(result, FALSE);

    result = ut_expr("/", "a/b");
    test_assertint(result, FALSE);

    result = ut_expr("/", ".");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a|b", "/a");
    test_assertint(result, TRUE);

    result = ut_expr("/a|b", "/b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a|b", "/c");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_scopeOrMulti(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b|c", "/a/b");
    test_assertint(result, TRUE);

    result = ut_expr("/a/b|c", "/a/c");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_scopeOrMultiFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b|c", "/a/d");
    test_assertint(result, FALSE);

    result = ut_expr("/a/b|c", "/b/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_separatorFilter(
    test_Matcher this)
{
    corto_bool result = ut_expr("b*,*x", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("b*,*x", "bx");
    test_assertint(result, TRUE);

    result = ut_expr("b*,*x", "by");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_separatorFilterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("b*,*y", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_separatorId(
    test_Matcher this)
{
    corto_bool result = ut_expr("a,b", "a");
    test_assertint(result, TRUE);

    result = ut_expr("a,b", "b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_separatorIdFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("a,b", "c");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_separatorNotFilter(
    test_Matcher this)
{
    corto_bool result = ut_expr("^b*,*y", "ax");
    test_assertint(result, TRUE);

    result = ut_expr("^b*,*y", "by");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_separatorNotFilterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("^a*,*y", "ax");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeFilter(
    test_Matcher this)
{
    corto_bool result = ut_expr("//a*", "/ab");
    test_assertint(result, TRUE);

    result = ut_expr("//a*", "/a/ab");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeFilterFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("//a*", "/bb");
    test_assertint(result, FALSE);

    result = ut_expr("//a*", "/a/bb");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeId(
    test_Matcher this)
{
    corto_bool result = ut_expr("//a", "/a");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeIdFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("//b", "/a");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeImplicit(
    test_Matcher this)
{
    corto_bool result = ut_expr("//", "/a");
    test_assertint(result, TRUE);

    result = ut_expr("//", "/b");
    test_assertint(result, TRUE);

    result = ut_expr("//", "/a/b");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeImplicitFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("//", ".");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeNested(
    test_Matcher this)
{
    corto_bool result = ut_expr("//b", "/a/b");
    test_assertint(result, TRUE);

    result = ut_expr("//c", "/a/b/c");
    test_assertint(result, TRUE);

    result = ut_expr("//c", "/a/b/c/c");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeNestedFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("//a", "/a/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeNestedScope(
    test_Matcher this)
{
    corto_bool result = ut_expr("//b/c", "/a/b/c");
    test_assertint(result, TRUE);

    result = ut_expr("//b/c", "/a/x/b/c");
    test_assertint(result, TRUE);

    result = ut_expr("//b/c", "/b/c");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeNestedScopeFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("//b/c", "/a/b");
    test_assertint(result, FALSE);

    result = ut_expr("//b/c", "/a/b/c/c");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeOffset(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a//c", "/a/b/c");
    test_assertint(result, TRUE);

    result = ut_expr("a//c", "/a/b/c/c");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeOffsetAny(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a//", "/a/b/c");
    test_assertint(result, TRUE);

    result = ut_expr("a//", "/a/b/c/c");
    test_assertint(result, TRUE);

    result = ut_expr("a//", "/a/b/c/d");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeOffsetAnyFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a//", "/a");
    test_assertint(result, FALSE);

    result = ut_expr("a//", "/b/a/");
    test_assertint(result, FALSE);

    result = ut_expr("a//", "/b/a/c");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeOffsetFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a//c", "/a");
    test_assertint(result, FALSE);

    result = ut_expr("/a//c", "/a/c/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeOffsetNested(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b//d", "/a/b/c/d");
    test_assertint(result, TRUE);

    result = ut_expr("a/b//d", "/a/b/d");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeOffsetNestedFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a/b//d", "/b/c/d");
    test_assertint(result, FALSE);

    result = ut_expr("a/b//d", "/a/b//c");
    test_assertint(result, FALSE);

    result = ut_expr("a/b//d", "/a/b//c/d/e");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_treeOffsetOr(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a|b//d", "/a/c/d");
    test_assertint(result, TRUE);

    result = ut_expr("/a|b//d", "/a/d");
    test_assertint(result, TRUE);

    result = ut_expr("/a|b//d", "/b/c/d");
    test_assertint(result, TRUE);

    result = ut_expr("/a|b//d", "/b/d");
    test_assertint(result, TRUE);

}

void test_Matcher_tc_treeOffsetOrFail(
    test_Matcher this)
{
    corto_bool result = ut_expr("/a|b//d", "/c/c/d");
    test_assertint(result, FALSE);

    result = ut_expr("/a|b//d", "/c/d");
    test_assertint(result, FALSE);

    result = ut_expr("/a|b//d", "/b/d/b");
    test_assertint(result, FALSE);

}

void test_Matcher_tc_emptyString(
    test_Matcher this)
{
    corto_bool result = ut_expr("*", "");
    test_assertint(result, TRUE);
}

void test_Matcher_tc_null(
    test_Matcher this)
{
    corto_bool result = ut_expr("*", NULL);
    test_assertint(result, TRUE);
}

void test_Matcher_tc_scopeEmptyString(
    test_Matcher this)
{
    corto_bool result = ut_expr("/", "");
    test_assertint(result, TRUE);
}

void test_Matcher_tc_scopeNull(
    test_Matcher this)
{
    corto_bool result = ut_expr("/", NULL);
    test_assertint(result, TRUE);
}

void test_Matcher_tc_treeEmptyString(
    test_Matcher this)
{
    corto_bool result = ut_expr("//", "");
    test_assertint(result, TRUE);
}

void test_Matcher_tc_treeNull(
    test_Matcher this)
{
    corto_bool result = ut_expr("//", NULL);
    test_assertint(result, TRUE);
}
