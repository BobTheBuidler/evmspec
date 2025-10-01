#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native__new.h"
#include "__native_internal__new.h"
static PyMethodDef module_methods[] = {
    {"Address", (PyCFunction)CPyPy_Address, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("Address(cls, address)\n--\n\n") /* docstring */},
    {"HexBytes32", (PyCFunction)CPyPy_HexBytes32, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("HexBytes32(cls, v)\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_evmspec____new(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_evmspec____new__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_evmspec____new__internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_evmspec____new__internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_ONE_EMPTY_BYTE);
    CPyStatic_ONE_EMPTY_BYTE = NULL;
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f0);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f1);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f2);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f3);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f4);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f5);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f6);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f7);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f8);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f9);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f10);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f11);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f12);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f13);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f14);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f15);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f16);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f17);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f18);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f19);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f20);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f21);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f22);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f23);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f24);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f25);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f26);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f27);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f28);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f29);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f30);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f31);
    CPy_XDECREF(CPyStatic_MISSING_BYTES.f32);
    CPyStatic_MISSING_BYTES = (tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO) { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    CPy_XDECREF(CPyStatic_to_bytes);
    CPyStatic_to_bytes = NULL;
    CPy_XDECREF(CPyStatic_to_checksum_address);
    CPyStatic_to_checksum_address = NULL;
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "evmspec._new",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_evmspec____new(void)
{
    if (CPyModule_evmspec____new__internal) {
        Py_INCREF(CPyModule_evmspec____new__internal);
        return CPyModule_evmspec____new__internal;
    }
    CPyModule_evmspec____new__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_evmspec____new__internal == NULL))
        goto fail;
    if (CPyExec_evmspec____new(CPyModule_evmspec____new__internal) != 0)
        goto fail;
    return CPyModule_evmspec____new__internal;
    fail:
    return NULL;
}

PyObject *CPyDef_Address(PyObject *cpy_r_cls, PyObject *cpy_r_address) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    cpy_r_r0 = (PyObject *)&PyUnicode_Type;
    cpy_r_r1 = CPyStatic_to_checksum_address;
    if (likely(cpy_r_r1 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_checksum_address\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 62, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_Unreachable();
CPyL3: ;
    PyObject *cpy_r_r3[1] = {cpy_r_address};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r1, cpy_r_r4, 1, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 62, CPyStatic_globals);
        goto CPyL7;
    }
    if (likely(PyUnicode_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "Address", 62, CPyStatic_globals, "str", cpy_r_r5);
        goto CPyL7;
    }
    cpy_r_r7 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r8[3] = {cpy_r_r0, cpy_r_cls, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 62, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r6);
    return cpy_r_r10;
CPyL7: ;
    cpy_r_r11 = NULL;
    return cpy_r_r11;
CPyL8: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL7;
}

PyObject *CPyPy_Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"cls", "address", 0};
    static CPyArg_Parser parser = {"OO:Address", kwlist, 0};
    PyObject *obj_cls;
    PyObject *obj_address;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_cls, &obj_address)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_address = obj_address;
    PyObject *retval = CPyDef_Address(arg_cls, arg_address);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "Address", 61, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    int32_t cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO cpy_r_r16;
    char cpy_r_r17;
    CPyPtr cpy_r_r18;
    int64_t cpy_r_r19;
    CPyTagged cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    tuple_T3OOO cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyPtr cpy_r_r32;
    int64_t cpy_r_r33;
    CPyTagged cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    cpy_r_r0 = PyUnicode_Check(cpy_r_v);
    if (!cpy_r_r0) goto CPyL6;
    CPy_INCREF(cpy_r_v);
    if (likely(PyUnicode_Check(cpy_r_v)))
        cpy_r_r1 = cpy_r_v;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 68, CPyStatic_globals, "str", cpy_r_v);
        goto CPyL34;
    }
    cpy_r_r2 = CPyStatics[4]; /* '0x' */
    cpy_r_r3 = CPyStr_Startswith(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r4 = cpy_r_r3;
    if (!cpy_r_r4) goto CPyL6;
    CPy_INCREF(cpy_r_v);
    if (likely(PyUnicode_Check(cpy_r_v)))
        cpy_r_r5 = cpy_r_v;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 69, CPyStatic_globals, "str", cpy_r_v);
        goto CPyL34;
    }
    cpy_r_r6 = CPyStatics[5]; /* '_check_hexstr' */
    PyObject *cpy_r_r7[2] = {cpy_r_cls, cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r6, cpy_r_r8, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 69, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL36;
CPyL5: ;
    CPy_DECREF(cpy_r_r5);
CPyL6: ;
    cpy_r_r10 = CPyStatic_to_bytes;
    if (likely(cpy_r_r10 != NULL)) goto CPyL9;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_bytes\" was not set");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 71, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_Unreachable();
CPyL9: ;
    PyObject *cpy_r_r12[1] = {cpy_r_v};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r10, cpy_r_r13, 1, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 71, CPyStatic_globals);
        goto CPyL34;
    }
    if (likely(PyBytes_Check(cpy_r_r14) || PyByteArray_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 71, CPyStatic_globals, "bytes", cpy_r_r14);
        goto CPyL34;
    }
    cpy_r_r16 = CPyStatic_MISSING_BYTES;
    if (likely(cpy_r_r16.f0 != NULL)) goto CPyL15;
    PyErr_SetString(PyExc_NameError, "value for final name \"MISSING_BYTES\" was not set");
    cpy_r_r17 = 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 73, CPyStatic_globals);
        goto CPyL18;
    } else
        goto CPyL37;
CPyL14: ;
    CPy_Unreachable();
CPyL15: ;
    cpy_r_r18 = (CPyPtr)&((PyVarObject *)cpy_r_r15)->ob_size;
    cpy_r_r19 = *(int64_t *)cpy_r_r18;
    cpy_r_r20 = cpy_r_r19 << 1;
    CPy_INCREF(cpy_r_r16.f0);
    CPy_INCREF(cpy_r_r16.f1);
    CPy_INCREF(cpy_r_r16.f2);
    CPy_INCREF(cpy_r_r16.f3);
    CPy_INCREF(cpy_r_r16.f4);
    CPy_INCREF(cpy_r_r16.f5);
    CPy_INCREF(cpy_r_r16.f6);
    CPy_INCREF(cpy_r_r16.f7);
    CPy_INCREF(cpy_r_r16.f8);
    CPy_INCREF(cpy_r_r16.f9);
    CPy_INCREF(cpy_r_r16.f10);
    CPy_INCREF(cpy_r_r16.f11);
    CPy_INCREF(cpy_r_r16.f12);
    CPy_INCREF(cpy_r_r16.f13);
    CPy_INCREF(cpy_r_r16.f14);
    CPy_INCREF(cpy_r_r16.f15);
    CPy_INCREF(cpy_r_r16.f16);
    CPy_INCREF(cpy_r_r16.f17);
    CPy_INCREF(cpy_r_r16.f18);
    CPy_INCREF(cpy_r_r16.f19);
    CPy_INCREF(cpy_r_r16.f20);
    CPy_INCREF(cpy_r_r16.f21);
    CPy_INCREF(cpy_r_r16.f22);
    CPy_INCREF(cpy_r_r16.f23);
    CPy_INCREF(cpy_r_r16.f24);
    CPy_INCREF(cpy_r_r16.f25);
    CPy_INCREF(cpy_r_r16.f26);
    CPy_INCREF(cpy_r_r16.f27);
    CPy_INCREF(cpy_r_r16.f28);
    CPy_INCREF(cpy_r_r16.f29);
    CPy_INCREF(cpy_r_r16.f30);
    CPy_INCREF(cpy_r_r16.f31);
    CPy_INCREF(cpy_r_r16.f32);
    cpy_r_r21 = PyTuple_New(33);
    if (unlikely(cpy_r_r21 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r16.f0;
    PyTuple_SET_ITEM(cpy_r_r21, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r16.f1;
    PyTuple_SET_ITEM(cpy_r_r21, 1, __tmp2);
    PyObject *__tmp3 = cpy_r_r16.f2;
    PyTuple_SET_ITEM(cpy_r_r21, 2, __tmp3);
    PyObject *__tmp4 = cpy_r_r16.f3;
    PyTuple_SET_ITEM(cpy_r_r21, 3, __tmp4);
    PyObject *__tmp5 = cpy_r_r16.f4;
    PyTuple_SET_ITEM(cpy_r_r21, 4, __tmp5);
    PyObject *__tmp6 = cpy_r_r16.f5;
    PyTuple_SET_ITEM(cpy_r_r21, 5, __tmp6);
    PyObject *__tmp7 = cpy_r_r16.f6;
    PyTuple_SET_ITEM(cpy_r_r21, 6, __tmp7);
    PyObject *__tmp8 = cpy_r_r16.f7;
    PyTuple_SET_ITEM(cpy_r_r21, 7, __tmp8);
    PyObject *__tmp9 = cpy_r_r16.f8;
    PyTuple_SET_ITEM(cpy_r_r21, 8, __tmp9);
    PyObject *__tmp10 = cpy_r_r16.f9;
    PyTuple_SET_ITEM(cpy_r_r21, 9, __tmp10);
    PyObject *__tmp11 = cpy_r_r16.f10;
    PyTuple_SET_ITEM(cpy_r_r21, 10, __tmp11);
    PyObject *__tmp12 = cpy_r_r16.f11;
    PyTuple_SET_ITEM(cpy_r_r21, 11, __tmp12);
    PyObject *__tmp13 = cpy_r_r16.f12;
    PyTuple_SET_ITEM(cpy_r_r21, 12, __tmp13);
    PyObject *__tmp14 = cpy_r_r16.f13;
    PyTuple_SET_ITEM(cpy_r_r21, 13, __tmp14);
    PyObject *__tmp15 = cpy_r_r16.f14;
    PyTuple_SET_ITEM(cpy_r_r21, 14, __tmp15);
    PyObject *__tmp16 = cpy_r_r16.f15;
    PyTuple_SET_ITEM(cpy_r_r21, 15, __tmp16);
    PyObject *__tmp17 = cpy_r_r16.f16;
    PyTuple_SET_ITEM(cpy_r_r21, 16, __tmp17);
    PyObject *__tmp18 = cpy_r_r16.f17;
    PyTuple_SET_ITEM(cpy_r_r21, 17, __tmp18);
    PyObject *__tmp19 = cpy_r_r16.f18;
    PyTuple_SET_ITEM(cpy_r_r21, 18, __tmp19);
    PyObject *__tmp20 = cpy_r_r16.f19;
    PyTuple_SET_ITEM(cpy_r_r21, 19, __tmp20);
    PyObject *__tmp21 = cpy_r_r16.f20;
    PyTuple_SET_ITEM(cpy_r_r21, 20, __tmp21);
    PyObject *__tmp22 = cpy_r_r16.f21;
    PyTuple_SET_ITEM(cpy_r_r21, 21, __tmp22);
    PyObject *__tmp23 = cpy_r_r16.f22;
    PyTuple_SET_ITEM(cpy_r_r21, 22, __tmp23);
    PyObject *__tmp24 = cpy_r_r16.f23;
    PyTuple_SET_ITEM(cpy_r_r21, 23, __tmp24);
    PyObject *__tmp25 = cpy_r_r16.f24;
    PyTuple_SET_ITEM(cpy_r_r21, 24, __tmp25);
    PyObject *__tmp26 = cpy_r_r16.f25;
    PyTuple_SET_ITEM(cpy_r_r21, 25, __tmp26);
    PyObject *__tmp27 = cpy_r_r16.f26;
    PyTuple_SET_ITEM(cpy_r_r21, 26, __tmp27);
    PyObject *__tmp28 = cpy_r_r16.f27;
    PyTuple_SET_ITEM(cpy_r_r21, 27, __tmp28);
    PyObject *__tmp29 = cpy_r_r16.f28;
    PyTuple_SET_ITEM(cpy_r_r21, 28, __tmp29);
    PyObject *__tmp30 = cpy_r_r16.f29;
    PyTuple_SET_ITEM(cpy_r_r21, 29, __tmp30);
    PyObject *__tmp31 = cpy_r_r16.f30;
    PyTuple_SET_ITEM(cpy_r_r21, 30, __tmp31);
    PyObject *__tmp32 = cpy_r_r16.f31;
    PyTuple_SET_ITEM(cpy_r_r21, 31, __tmp32);
    PyObject *__tmp33 = cpy_r_r16.f32;
    PyTuple_SET_ITEM(cpy_r_r21, 32, __tmp33);
    cpy_r_r22 = CPySequenceTuple_GetItem(cpy_r_r21, cpy_r_r20);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 73, CPyStatic_globals);
        goto CPyL18;
    }
    if (likely(PyBytes_Check(cpy_r_r22) || PyByteArray_Check(cpy_r_r22)))
        cpy_r_r23 = cpy_r_r22;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 73, CPyStatic_globals, "bytes", cpy_r_r22);
        goto CPyL18;
    }
    goto CPyL31;
CPyL18: ;
    cpy_r_r24 = CPy_CatchError();
    cpy_r_r25 = CPyModule_builtins;
    cpy_r_r26 = CPyStatics[6]; /* 'KeyError' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r28 = CPy_ExceptionMatches(cpy_r_r27);
    CPy_DecRef(cpy_r_r27);
    if (!cpy_r_r28) goto CPyL39;
    cpy_r_r29 = CPy_GetExcValue();
    CPy_DecRef(cpy_r_r29);
    cpy_r_r30 = PyObject_Repr(cpy_r_v);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r31 = CPyStatics[7]; /* ' is too long: ' */
    cpy_r_r32 = (CPyPtr)&((PyVarObject *)cpy_r_r15)->ob_size;
    cpy_r_r33 = *(int64_t *)cpy_r_r32;
    CPy_DecRef(cpy_r_r15);
    cpy_r_r34 = cpy_r_r33 << 1;
    cpy_r_r35 = CPyTagged_Str(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r36 = CPyStr_Build(3, cpy_r_r30, cpy_r_r31, cpy_r_r35);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL41;
    }
    PyObject *cpy_r_r40[1] = {cpy_r_r36};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 1, 0);
    CPy_DecRef(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DecRef(cpy_r_r36);
    CPy_Raise(cpy_r_r42);
    CPy_DecRef(cpy_r_r42);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL42;
CPyL26: ;
    CPy_Unreachable();
CPyL27: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL29;
    } else
        goto CPyL43;
CPyL28: ;
    CPy_Unreachable();
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r24);
    CPy_DecRef(cpy_r_r24.f0);
    CPy_DecRef(cpy_r_r24.f1);
    CPy_DecRef(cpy_r_r24.f2);
    cpy_r_r43 = CPy_KeepPropagating();
    if (!cpy_r_r43) goto CPyL34;
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r44 = (PyObject *)&PyBytes_Type;
    cpy_r_r45 = CPyBytes_Concat(cpy_r_r23, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 76, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r46 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r47[3] = {cpy_r_r44, cpy_r_cls, cpy_r_r45};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = PyObject_VectorcallMethod(cpy_r_r46, cpy_r_r48, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 76, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_r45);
    return cpy_r_r49;
CPyL34: ;
    cpy_r_r50 = NULL;
    return cpy_r_r50;
CPyL35: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL34;
CPyL36: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL5;
CPyL37: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL14;
CPyL38: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL29;
CPyL39: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL27;
CPyL40: ;
    CPy_DecRef(cpy_r_r30);
    goto CPyL29;
CPyL41: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL29;
CPyL42: ;
    CPy_DecRef(cpy_r_r24.f0);
    CPy_DecRef(cpy_r_r24.f1);
    CPy_DecRef(cpy_r_r24.f2);
    goto CPyL26;
CPyL43: ;
    CPy_DecRef(cpy_r_r24.f0);
    CPy_DecRef(cpy_r_r24.f1);
    CPy_DecRef(cpy_r_r24.f2);
    goto CPyL28;
CPyL44: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL34;
}

PyObject *CPyPy_HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"cls", "v", 0};
    static CPyArg_Parser parser = {"OO:HexBytes32", kwlist, 0};
    PyObject *obj_cls;
    PyObject *obj_v;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_cls, &obj_v)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_v;
    if (PyBytes_Check(obj_v) || PyByteArray_Check(obj_v))
        arg_v = obj_v;
    else {
        arg_v = NULL;
    }
    if (arg_v != NULL) goto __LL34;
    if (PyUnicode_Check(obj_v))
        arg_v = obj_v;
    else {
        arg_v = NULL;
    }
    if (arg_v != NULL) goto __LL34;
    CPy_TypeError("union[bytes, str]", obj_v); 
    goto fail;
__LL34: ;
    PyObject *retval = CPyDef_HexBytes32(arg_cls, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 65, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r9;
    PyObject **cpy_r_r10;
    PyObject **cpy_r_r11;
    void *cpy_r_r13;
    void *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    int32_t cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    int32_t cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    int32_t cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    int32_t cpy_r_r92;
    char cpy_r_r93;
    char cpy_r_r94;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[9]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", -1, CPyStatic_globals);
        goto CPyL16;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[61]; /* ('Final', 'Type', 'TypeVar', 'Union') */
    cpy_r_r6 = CPyStatics[14]; /* 'typing' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 1, CPyStatic_globals);
        goto CPyL16;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_cchecksum;
    cpy_r_r10 = (PyObject **)&CPyModule_faster_eth_utils;
    cpy_r_r11 = (PyObject **)&CPyModule_faster_hexbytes____utils;
    PyObject **cpy_r_r12[3] = {cpy_r_r9, cpy_r_r10, cpy_r_r11};
    cpy_r_r13 = (void *)&cpy_r_r12;
    int64_t cpy_r_r14[3] = {3, 4, 5};
    cpy_r_r15 = (void *)&cpy_r_r14;
    cpy_r_r16 = CPyStatics[65]; /* (('cchecksum', 'cchecksum', 'cchecksum'),
                                   ('faster_eth_utils', 'faster_eth_utils',
                                    'faster_eth_utils'),
                                   ('faster_hexbytes._utils', 'faster_hexbytes',
                                    'faster_hexbytes')) */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyStatics[19]; /* 'evmspec/_new.py' */
    cpy_r_r19 = CPyStatics[20]; /* '<module>' */
    cpy_r_r20 = CPyImport_ImportMany(cpy_r_r16, cpy_r_r13, cpy_r_r17, cpy_r_r18, cpy_r_r19, cpy_r_r15);
    if (!cpy_r_r20) goto CPyL16;
    cpy_r_r21 = CPyStatics[66]; /* ('AnyAddress',) */
    cpy_r_r22 = CPyStatics[22]; /* 'eth_typing' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 6, CPyStatic_globals);
        goto CPyL16;
    }
    CPyModule_eth_typing = cpy_r_r24;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[23]; /* '__T' */
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[12]; /* 'TypeVar' */
    cpy_r_r28 = CPyDict_GetItem(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r29[1] = {cpy_r_r25};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_Vectorcall(cpy_r_r28, cpy_r_r30, 1, 0);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r32 = CPyStatic_globals;
    cpy_r_r33 = CPyStatics[23]; /* '__T' */
    cpy_r_r34 = CPyDict_SetItem(cpy_r_r32, cpy_r_r33, cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r35 = cpy_r_r34 >= 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r36 = CPyStatics[28]; /* b'\x00' */
    CPyStatic_ONE_EMPTY_BYTE = cpy_r_r36;
    CPy_INCREF(CPyStatic_ONE_EMPTY_BYTE);
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[24]; /* 'ONE_EMPTY_BYTE' */
    cpy_r_r39 = CPyDict_SetItem(cpy_r_r37, cpy_r_r38, cpy_r_r36);
    cpy_r_r40 = cpy_r_r39 >= 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 12, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r41 = CPyStatics[29]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r42 = CPyStatics[30]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r43 = CPyStatics[31]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00') */
    cpy_r_r44 = CPyStatics[32]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00') */
    cpy_r_r45 = CPyStatics[33]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00') */
    cpy_r_r46 = CPyStatics[34]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00') */
    cpy_r_r47 = CPyStatics[35]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00') */
    cpy_r_r48 = CPyStatics[36]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r49 = CPyStatics[37]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r50 = CPyStatics[38]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r51 = CPyStatics[39]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r52 = CPyStatics[40]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r53 = CPyStatics[41]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r54 = CPyStatics[42]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r55 = CPyStatics[43]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00') */
    cpy_r_r56 = CPyStatics[44]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00') */
    cpy_r_r57 = CPyStatics[45]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00') */
    cpy_r_r58 = CPyStatics[46]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00') */
    cpy_r_r59 = CPyStatics[47]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r60 = CPyStatics[48]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r61 = CPyStatics[49]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r62 = CPyStatics[50]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r63 = CPyStatics[51]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r64 = CPyStatics[52]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r65 = CPyStatics[53]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r66 = CPyStatics[54]; /* b'\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r67 = CPyStatics[55]; /* b'\x00\x00\x00\x00\x00\x00' */
    cpy_r_r68 = CPyStatics[56]; /* b'\x00\x00\x00\x00\x00' */
    cpy_r_r69 = CPyStatics[57]; /* b'\x00\x00\x00\x00' */
    cpy_r_r70 = CPyStatics[58]; /* b'\x00\x00\x00' */
    cpy_r_r71 = CPyStatics[59]; /* b'\x00\x00' */
    cpy_r_r72 = CPyStatics[28]; /* b'\x00' */
    cpy_r_r73 = CPyStatics[60]; /* b'' */
    CPy_INCREF(cpy_r_r41);
    CPy_INCREF(cpy_r_r42);
    CPy_INCREF(cpy_r_r43);
    CPy_INCREF(cpy_r_r44);
    CPy_INCREF(cpy_r_r45);
    CPy_INCREF(cpy_r_r46);
    CPy_INCREF(cpy_r_r47);
    CPy_INCREF(cpy_r_r48);
    CPy_INCREF(cpy_r_r49);
    CPy_INCREF(cpy_r_r50);
    CPy_INCREF(cpy_r_r51);
    CPy_INCREF(cpy_r_r52);
    CPy_INCREF(cpy_r_r53);
    CPy_INCREF(cpy_r_r54);
    CPy_INCREF(cpy_r_r55);
    CPy_INCREF(cpy_r_r56);
    CPy_INCREF(cpy_r_r57);
    CPy_INCREF(cpy_r_r58);
    CPy_INCREF(cpy_r_r59);
    CPy_INCREF(cpy_r_r60);
    CPy_INCREF(cpy_r_r61);
    CPy_INCREF(cpy_r_r62);
    CPy_INCREF(cpy_r_r63);
    CPy_INCREF(cpy_r_r64);
    CPy_INCREF(cpy_r_r65);
    CPy_INCREF(cpy_r_r66);
    CPy_INCREF(cpy_r_r67);
    CPy_INCREF(cpy_r_r68);
    CPy_INCREF(cpy_r_r69);
    CPy_INCREF(cpy_r_r70);
    CPy_INCREF(cpy_r_r71);
    CPy_INCREF(cpy_r_r72);
    CPy_INCREF(cpy_r_r73);
    cpy_r_r74.f0 = cpy_r_r41;
    cpy_r_r74.f1 = cpy_r_r42;
    cpy_r_r74.f2 = cpy_r_r43;
    cpy_r_r74.f3 = cpy_r_r44;
    cpy_r_r74.f4 = cpy_r_r45;
    cpy_r_r74.f5 = cpy_r_r46;
    cpy_r_r74.f6 = cpy_r_r47;
    cpy_r_r74.f7 = cpy_r_r48;
    cpy_r_r74.f8 = cpy_r_r49;
    cpy_r_r74.f9 = cpy_r_r50;
    cpy_r_r74.f10 = cpy_r_r51;
    cpy_r_r74.f11 = cpy_r_r52;
    cpy_r_r74.f12 = cpy_r_r53;
    cpy_r_r74.f13 = cpy_r_r54;
    cpy_r_r74.f14 = cpy_r_r55;
    cpy_r_r74.f15 = cpy_r_r56;
    cpy_r_r74.f16 = cpy_r_r57;
    cpy_r_r74.f17 = cpy_r_r58;
    cpy_r_r74.f18 = cpy_r_r59;
    cpy_r_r74.f19 = cpy_r_r60;
    cpy_r_r74.f20 = cpy_r_r61;
    cpy_r_r74.f21 = cpy_r_r62;
    cpy_r_r74.f22 = cpy_r_r63;
    cpy_r_r74.f23 = cpy_r_r64;
    cpy_r_r74.f24 = cpy_r_r65;
    cpy_r_r74.f25 = cpy_r_r66;
    cpy_r_r74.f26 = cpy_r_r67;
    cpy_r_r74.f27 = cpy_r_r68;
    cpy_r_r74.f28 = cpy_r_r69;
    cpy_r_r74.f29 = cpy_r_r70;
    cpy_r_r74.f30 = cpy_r_r71;
    cpy_r_r74.f31 = cpy_r_r72;
    cpy_r_r74.f32 = cpy_r_r73;
    CPyStatic_MISSING_BYTES = cpy_r_r74;
    CPy_INCREF(CPyStatic_MISSING_BYTES.f0);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f1);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f2);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f3);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f4);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f5);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f6);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f7);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f8);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f9);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f10);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f11);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f12);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f13);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f14);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f15);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f16);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f17);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f18);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f19);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f20);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f21);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f22);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f23);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f24);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f25);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f26);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f27);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f28);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f29);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f30);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f31);
    CPy_INCREF(CPyStatic_MISSING_BYTES.f32);
    cpy_r_r75 = CPyStatic_globals;
    cpy_r_r76 = CPyStatics[25]; /* 'MISSING_BYTES' */
    cpy_r_r77 = PyTuple_New(33);
    if (unlikely(cpy_r_r77 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r74.f0;
    PyTuple_SET_ITEM(cpy_r_r77, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r74.f1;
    PyTuple_SET_ITEM(cpy_r_r77, 1, __tmp36);
    PyObject *__tmp37 = cpy_r_r74.f2;
    PyTuple_SET_ITEM(cpy_r_r77, 2, __tmp37);
    PyObject *__tmp38 = cpy_r_r74.f3;
    PyTuple_SET_ITEM(cpy_r_r77, 3, __tmp38);
    PyObject *__tmp39 = cpy_r_r74.f4;
    PyTuple_SET_ITEM(cpy_r_r77, 4, __tmp39);
    PyObject *__tmp40 = cpy_r_r74.f5;
    PyTuple_SET_ITEM(cpy_r_r77, 5, __tmp40);
    PyObject *__tmp41 = cpy_r_r74.f6;
    PyTuple_SET_ITEM(cpy_r_r77, 6, __tmp41);
    PyObject *__tmp42 = cpy_r_r74.f7;
    PyTuple_SET_ITEM(cpy_r_r77, 7, __tmp42);
    PyObject *__tmp43 = cpy_r_r74.f8;
    PyTuple_SET_ITEM(cpy_r_r77, 8, __tmp43);
    PyObject *__tmp44 = cpy_r_r74.f9;
    PyTuple_SET_ITEM(cpy_r_r77, 9, __tmp44);
    PyObject *__tmp45 = cpy_r_r74.f10;
    PyTuple_SET_ITEM(cpy_r_r77, 10, __tmp45);
    PyObject *__tmp46 = cpy_r_r74.f11;
    PyTuple_SET_ITEM(cpy_r_r77, 11, __tmp46);
    PyObject *__tmp47 = cpy_r_r74.f12;
    PyTuple_SET_ITEM(cpy_r_r77, 12, __tmp47);
    PyObject *__tmp48 = cpy_r_r74.f13;
    PyTuple_SET_ITEM(cpy_r_r77, 13, __tmp48);
    PyObject *__tmp49 = cpy_r_r74.f14;
    PyTuple_SET_ITEM(cpy_r_r77, 14, __tmp49);
    PyObject *__tmp50 = cpy_r_r74.f15;
    PyTuple_SET_ITEM(cpy_r_r77, 15, __tmp50);
    PyObject *__tmp51 = cpy_r_r74.f16;
    PyTuple_SET_ITEM(cpy_r_r77, 16, __tmp51);
    PyObject *__tmp52 = cpy_r_r74.f17;
    PyTuple_SET_ITEM(cpy_r_r77, 17, __tmp52);
    PyObject *__tmp53 = cpy_r_r74.f18;
    PyTuple_SET_ITEM(cpy_r_r77, 18, __tmp53);
    PyObject *__tmp54 = cpy_r_r74.f19;
    PyTuple_SET_ITEM(cpy_r_r77, 19, __tmp54);
    PyObject *__tmp55 = cpy_r_r74.f20;
    PyTuple_SET_ITEM(cpy_r_r77, 20, __tmp55);
    PyObject *__tmp56 = cpy_r_r74.f21;
    PyTuple_SET_ITEM(cpy_r_r77, 21, __tmp56);
    PyObject *__tmp57 = cpy_r_r74.f22;
    PyTuple_SET_ITEM(cpy_r_r77, 22, __tmp57);
    PyObject *__tmp58 = cpy_r_r74.f23;
    PyTuple_SET_ITEM(cpy_r_r77, 23, __tmp58);
    PyObject *__tmp59 = cpy_r_r74.f24;
    PyTuple_SET_ITEM(cpy_r_r77, 24, __tmp59);
    PyObject *__tmp60 = cpy_r_r74.f25;
    PyTuple_SET_ITEM(cpy_r_r77, 25, __tmp60);
    PyObject *__tmp61 = cpy_r_r74.f26;
    PyTuple_SET_ITEM(cpy_r_r77, 26, __tmp61);
    PyObject *__tmp62 = cpy_r_r74.f27;
    PyTuple_SET_ITEM(cpy_r_r77, 27, __tmp62);
    PyObject *__tmp63 = cpy_r_r74.f28;
    PyTuple_SET_ITEM(cpy_r_r77, 28, __tmp63);
    PyObject *__tmp64 = cpy_r_r74.f29;
    PyTuple_SET_ITEM(cpy_r_r77, 29, __tmp64);
    PyObject *__tmp65 = cpy_r_r74.f30;
    PyTuple_SET_ITEM(cpy_r_r77, 30, __tmp65);
    PyObject *__tmp66 = cpy_r_r74.f31;
    PyTuple_SET_ITEM(cpy_r_r77, 31, __tmp66);
    PyObject *__tmp67 = cpy_r_r74.f32;
    PyTuple_SET_ITEM(cpy_r_r77, 32, __tmp67);
    cpy_r_r78 = CPyDict_SetItem(cpy_r_r75, cpy_r_r76, cpy_r_r77);
    CPy_DECREF(cpy_r_r77);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 15, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r80 = CPyModule_faster_hexbytes____utils;
    cpy_r_r81 = CPyStatics[26]; /* 'to_bytes' */
    cpy_r_r82 = CPyObject_GetAttr(cpy_r_r80, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 57, CPyStatic_globals);
        goto CPyL16;
    }
    CPyStatic_to_bytes = cpy_r_r82;
    CPy_INCREF(CPyStatic_to_bytes);
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyStatics[26]; /* 'to_bytes' */
    cpy_r_r85 = CPyDict_SetItem(cpy_r_r83, cpy_r_r84, cpy_r_r82);
    CPy_DECREF(cpy_r_r82);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 57, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r87 = CPyModule_cchecksum;
    cpy_r_r88 = CPyStatics[27]; /* 'to_checksum_address' */
    cpy_r_r89 = CPyObject_GetAttr(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 58, CPyStatic_globals);
        goto CPyL16;
    }
    CPyStatic_to_checksum_address = cpy_r_r89;
    CPy_INCREF(CPyStatic_to_checksum_address);
    cpy_r_r90 = CPyStatic_globals;
    cpy_r_r91 = CPyStatics[27]; /* 'to_checksum_address' */
    cpy_r_r92 = CPyDict_SetItem(cpy_r_r90, cpy_r_r91, cpy_r_r89);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r93 = cpy_r_r92 >= 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 58, CPyStatic_globals);
        goto CPyL16;
    }
    return 1;
CPyL16: ;
    cpy_r_r94 = 2;
    return cpy_r_r94;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_evmspec____new = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_cchecksum = Py_None;
    CPyModule_faster_eth_utils = Py_None;
    CPyModule_faster_hexbytes____utils = Py_None;
    CPyModule_eth_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[67];
const char * const CPyLit_Str[] = {
    "\a\a__new__\0020x\r_check_hexstr\bKeyError\016 is too long: \nValueError\bbuiltins",
    "\a\005Final\004Type\aTypeVar\005Union\006typing\tcchecksum\020faster_eth_utils",
    "\004\026faster_hexbytes._utils\017faster_hexbytes\017evmspec/_new.py\b<module>",
    "\006\nAnyAddress\neth_typing\003__T\016ONE_EMPTY_BYTE\rMISSING_BYTES\bto_bytes",
    "\001\023to_checksum_address",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\003\001\000 \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\037\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\002\036\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\035\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\002\034\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\002\032\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\031\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\002\030\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\027\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\003\026\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\025\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\024\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\003\023\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\022\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\021\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\004\020\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\017\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\016\000\000\000\000\000\000\000\000\000\000\000\000\000\000\r\000\000\000\000\000\000\000\000\000\000\000\000\000",
    "\a\f\000\000\000\000\000\000\000\000\000\000\000\000\v\000\000\000\000\000\000\000\000\000\000\000\n\000\000\000\000\000\000\000\000\000\000\t\000\000\000\000\000\000\000\000\000\b\000\000\000\000\000\000\000\000\a\000\000\000\000\000\000\000\006\000\000\000\000\000\000",
    "\005\005\000\000\000\000\000\004\000\000\000\000\003\000\000\000\002\000\000\000",
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    6, 4, 10, 11, 12, 13, 3, 15, 15, 15, 3, 16, 16, 16, 3, 17, 18, 18,
    3, 62, 63, 64, 1, 21
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_evmspec____new__internal = NULL;
CPyModule *CPyModule_evmspec____new;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_cchecksum;
CPyModule *CPyModule_faster_eth_utils;
CPyModule *CPyModule_faster_hexbytes____utils;
CPyModule *CPyModule_eth_typing;
PyObject *CPyStatic_ONE_EMPTY_BYTE = NULL;
tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO CPyStatic_MISSING_BYTES = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
PyObject *CPyStatic_to_bytes = NULL;
PyObject *CPyStatic_to_checksum_address = NULL;
PyObject *CPyDef_Address(PyObject *cpy_r_cls, PyObject *cpy_r_address);
PyObject *CPyPy_Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v);
PyObject *CPyPy_HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec__new__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_evmspec____new(void);
    capsule = PyCapsule_New((void *)CPyInit_evmspec____new, "evmspec._new__mypyc.init_evmspec____new", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_evmspec____new", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def__new__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "evmspec._new__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit__new__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def__new__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec__new__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
