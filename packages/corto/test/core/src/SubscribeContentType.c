/* $CORTO_GENERATED
 *
 * SubscribeContentType.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_SubscribeContentType_setup(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/setup) */

    /* Create 'json' scope for JSON mount */
    corto_object json_o = corto_voidCreateChild(root_o, "json");

    /* Create 'string' scope for Corto string mount */
    corto_object str_o = corto_voidCreateChild(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_voidCreateChild(root_o, "obj");

    /* Attach json mount to json scope */
    test_JsonReplicatorCreate(json_o);

    /* Attach str mount to str scope */
    test_StringReplicatorCreate(str_o);

    /* Create three objects in 'obj' scope */
    test_PointCreateChild(obj_o, "a", 10, 20);
    test_PointCreateChild(obj_o, "b", 30, 40);
    test_PointCreateChild(obj_o, "c", 50, 60);

/* $end */
}

/* $header(test/SubscribeContentType/tc_subscribeBinaryFromJson) */
void binary(corto_subscriberEvent *e) {
    test_SubscribeContentType this = e->instance;
    test_Point *p;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 10);
        test_assertint(p->y, 20);
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 30);
        test_assertint(p->y, 40);
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 50);
        test_assertint(p->y, 60);
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 70);
        test_assertint(p->y, 80);
        break;        
    }
}
/* $end */
void _test_SubscribeContentType_tc_subscribeBinaryFromJson(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromJson) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);

    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeBinaryFromJsonDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromJsonDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);

    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeBinaryFromObjects(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromObjects) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeBinaryFromObjectsDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromObjectsDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeBinaryFromString(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromString) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeBinaryFromStringDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeBinaryFromStringDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/SubscribeContentType/tc_subscribeJsonFromJson) */
void json(corto_subscriberEvent *e) {
    test_SubscribeContentType this = e->instance;
    char *json;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":10,\"y\":20}");
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":30,\"y\":40}");
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":50,\"y\":60}");
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":70,\"y\":80}");
        break;        
    }
}
/* $end */
void _test_SubscribeContentType_tc_subscribeJsonFromJson(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromJson) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeJsonFromJsonDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromJsonDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeJsonFromObjects(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromObjects) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeJsonFromObjectsDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromObjectsDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeJsonFromString(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromString) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeJsonFromStringDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeJsonFromStringDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/SubscribeContentType/tc_subscribeStringFromJson) */
void string(corto_subscriberEvent *e) {
    test_SubscribeContentType this = e->instance;
    char *json;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{10,20}");
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{30,40}");
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{50,60}");
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{70,80}");
        break;        
    }
}
/* $end */
void _test_SubscribeContentType_tc_subscribeStringFromJson(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromJson) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeStringFromJsonDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromJsonDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "json/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeStringFromObjects(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromObjects) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeStringFromObjectsDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromObjectsDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "obj/*")
        .instance(this)
        .contentType("text/corto")
        .dispatcher(dispatcher)
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = corto_lookupAssert(NULL, "obj/c", test_Point_o);
    test_assert(test_PointUpdate(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeStringFromString(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromString) */
    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_SubscribeContentType_tc_subscribeStringFromStringDispatch(
    test_SubscribeContentType this)
{
/* $begin(test/SubscribeContentType/tc_subscribeStringFromStringDispatch) */
    test_FooDispatcher dispatcher = test_FooDispatcherCreate();

    corto_subscriber s = corto_subscribe(CORTO_ON_DEFINE|CORTO_ON_UPDATE, "str/*")
        .instance(this)
        .contentType("text/corto")
        .dispatcher(dispatcher)
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_ON_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

/* $end */
}
