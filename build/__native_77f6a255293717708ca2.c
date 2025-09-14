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
#include "__native_77f6a255293717708ca2.h"
#include "__native_internal_77f6a255293717708ca2.h"
static PyMethodDef _newmodule_methods[] = {
    {"Address", (PyCFunction)CPyPy__new___Address, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("Address(cls, address)\n--\n\n") /* docstring */},
    {"HexBytes32", (PyCFunction)CPyPy__new___HexBytes32, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("HexBytes32(cls, v)\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_evmspec____new(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_evmspec____new__internal, "__name__");
    CPyStatic__new___globals = PyModule_GetDict(CPyModule_evmspec____new__internal);
    if (unlikely(CPyStatic__new___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__new_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_evmspec____new__internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__new___ONE_EMPTY_BYTE);
    CPyStatic__new___ONE_EMPTY_BYTE = NULL;
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f0);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f1);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f2);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f3);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f4);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f5);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f6);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f7);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f8);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f9);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f10);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f11);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f12);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f13);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f14);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f15);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f16);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f17);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f18);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f19);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f20);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f21);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f22);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f23);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f24);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f25);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f26);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f27);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f28);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f29);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f30);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f31);
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES.f32);
    CPyStatic__new___MISSING_BYTES = (tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO) { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    CPy_XDECREF(CPyStatic__new___to_checksum_address);
    CPyStatic__new___to_checksum_address = NULL;
    return -1;
}
static struct PyModuleDef _newmodule = {
    PyModuleDef_HEAD_INIT,
    "evmspec._new",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _newmodule_methods,
    NULL,
};

PyObject *CPyInit_evmspec____new(void)
{
    if (CPyModule_evmspec____new__internal) {
        Py_INCREF(CPyModule_evmspec____new__internal);
        return CPyModule_evmspec____new__internal;
    }
    CPyModule_evmspec____new__internal = PyModule_Create(&_newmodule);
    if (unlikely(CPyModule_evmspec____new__internal == NULL))
        goto fail;
    if (CPyExec_evmspec____new(CPyModule_evmspec____new__internal) != 0)
        goto fail;
    return CPyModule_evmspec____new__internal;
    fail:
    return NULL;
}

PyObject *CPyDef__new___Address(PyObject *cpy_r_cls, PyObject *cpy_r_address) {
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
    cpy_r_r1 = CPyStatic__new___to_checksum_address;
    if (likely(cpy_r_r1 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_checksum_address\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 61, CPyStatic__new___globals);
        goto CPyL7;
    }
    CPy_Unreachable();
CPyL3: ;
    PyObject *cpy_r_r3[1] = {cpy_r_address};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r1, cpy_r_r4, 1, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 61, CPyStatic__new___globals);
        goto CPyL7;
    }
    if (likely(PyUnicode_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "Address", 61, CPyStatic__new___globals, "str", cpy_r_r5);
        goto CPyL7;
    }
    cpy_r_r7 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r8[3] = {cpy_r_r0, cpy_r_cls, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 61, CPyStatic__new___globals);
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

PyObject *CPyPy__new___Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"cls", "address", 0};
    static CPyArg_Parser parser = {"OO:Address", kwlist, 0};
    PyObject *obj_cls;
    PyObject *obj_address;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_cls, &obj_address)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_address = obj_address;
    PyObject *retval = CPyDef__new___Address(arg_cls, arg_address);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "Address", 60, CPyStatic__new___globals);
    return NULL;
}

PyObject *CPyDef__new___HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v) {
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
    tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO cpy_r_r11;
    char cpy_r_r12;
    CPyPtr cpy_r_r13;
    int64_t cpy_r_r14;
    CPyTagged cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    tuple_T3OOO cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    CPyPtr cpy_r_r27;
    int64_t cpy_r_r28;
    CPyTagged cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    cpy_r_r0 = PyUnicode_Check(cpy_r_v);
    if (!cpy_r_r0) goto CPyL6;
    CPy_INCREF(cpy_r_v);
    if (likely(PyUnicode_Check(cpy_r_v)))
        cpy_r_r1 = cpy_r_v;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 67, CPyStatic__new___globals, "str", cpy_r_v);
        goto CPyL30;
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
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 68, CPyStatic__new___globals, "str", cpy_r_v);
        goto CPyL30;
    }
    cpy_r_r6 = CPyStatics[5]; /* '_check_hexstr' */
    PyObject *cpy_r_r7[2] = {cpy_r_cls, cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r6, cpy_r_r8, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 68, CPyStatic__new___globals);
        goto CPyL31;
    } else
        goto CPyL32;
CPyL5: ;
    CPy_DECREF(cpy_r_r5);
CPyL6: ;
    cpy_r_r10 = CPyDef__utils___to_bytes(cpy_r_v);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 70, CPyStatic__new___globals);
        goto CPyL30;
    }
    cpy_r_r11 = CPyStatic__new___MISSING_BYTES;
    if (likely(cpy_r_r11.f0 != NULL)) goto CPyL11;
    PyErr_SetString(PyExc_NameError, "value for final name \"MISSING_BYTES\" was not set");
    cpy_r_r12 = 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 72, CPyStatic__new___globals);
        goto CPyL14;
    } else
        goto CPyL33;
CPyL10: ;
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r13 = (CPyPtr)&((PyVarObject *)cpy_r_r10)->ob_size;
    cpy_r_r14 = *(int64_t *)cpy_r_r13;
    cpy_r_r15 = cpy_r_r14 << 1;
    CPy_INCREF(cpy_r_r11.f0);
    CPy_INCREF(cpy_r_r11.f1);
    CPy_INCREF(cpy_r_r11.f2);
    CPy_INCREF(cpy_r_r11.f3);
    CPy_INCREF(cpy_r_r11.f4);
    CPy_INCREF(cpy_r_r11.f5);
    CPy_INCREF(cpy_r_r11.f6);
    CPy_INCREF(cpy_r_r11.f7);
    CPy_INCREF(cpy_r_r11.f8);
    CPy_INCREF(cpy_r_r11.f9);
    CPy_INCREF(cpy_r_r11.f10);
    CPy_INCREF(cpy_r_r11.f11);
    CPy_INCREF(cpy_r_r11.f12);
    CPy_INCREF(cpy_r_r11.f13);
    CPy_INCREF(cpy_r_r11.f14);
    CPy_INCREF(cpy_r_r11.f15);
    CPy_INCREF(cpy_r_r11.f16);
    CPy_INCREF(cpy_r_r11.f17);
    CPy_INCREF(cpy_r_r11.f18);
    CPy_INCREF(cpy_r_r11.f19);
    CPy_INCREF(cpy_r_r11.f20);
    CPy_INCREF(cpy_r_r11.f21);
    CPy_INCREF(cpy_r_r11.f22);
    CPy_INCREF(cpy_r_r11.f23);
    CPy_INCREF(cpy_r_r11.f24);
    CPy_INCREF(cpy_r_r11.f25);
    CPy_INCREF(cpy_r_r11.f26);
    CPy_INCREF(cpy_r_r11.f27);
    CPy_INCREF(cpy_r_r11.f28);
    CPy_INCREF(cpy_r_r11.f29);
    CPy_INCREF(cpy_r_r11.f30);
    CPy_INCREF(cpy_r_r11.f31);
    CPy_INCREF(cpy_r_r11.f32);
    cpy_r_r16 = PyTuple_New(33);
    if (unlikely(cpy_r_r16 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r11.f0;
    PyTuple_SET_ITEM(cpy_r_r16, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r11.f1;
    PyTuple_SET_ITEM(cpy_r_r16, 1, __tmp2);
    PyObject *__tmp3 = cpy_r_r11.f2;
    PyTuple_SET_ITEM(cpy_r_r16, 2, __tmp3);
    PyObject *__tmp4 = cpy_r_r11.f3;
    PyTuple_SET_ITEM(cpy_r_r16, 3, __tmp4);
    PyObject *__tmp5 = cpy_r_r11.f4;
    PyTuple_SET_ITEM(cpy_r_r16, 4, __tmp5);
    PyObject *__tmp6 = cpy_r_r11.f5;
    PyTuple_SET_ITEM(cpy_r_r16, 5, __tmp6);
    PyObject *__tmp7 = cpy_r_r11.f6;
    PyTuple_SET_ITEM(cpy_r_r16, 6, __tmp7);
    PyObject *__tmp8 = cpy_r_r11.f7;
    PyTuple_SET_ITEM(cpy_r_r16, 7, __tmp8);
    PyObject *__tmp9 = cpy_r_r11.f8;
    PyTuple_SET_ITEM(cpy_r_r16, 8, __tmp9);
    PyObject *__tmp10 = cpy_r_r11.f9;
    PyTuple_SET_ITEM(cpy_r_r16, 9, __tmp10);
    PyObject *__tmp11 = cpy_r_r11.f10;
    PyTuple_SET_ITEM(cpy_r_r16, 10, __tmp11);
    PyObject *__tmp12 = cpy_r_r11.f11;
    PyTuple_SET_ITEM(cpy_r_r16, 11, __tmp12);
    PyObject *__tmp13 = cpy_r_r11.f12;
    PyTuple_SET_ITEM(cpy_r_r16, 12, __tmp13);
    PyObject *__tmp14 = cpy_r_r11.f13;
    PyTuple_SET_ITEM(cpy_r_r16, 13, __tmp14);
    PyObject *__tmp15 = cpy_r_r11.f14;
    PyTuple_SET_ITEM(cpy_r_r16, 14, __tmp15);
    PyObject *__tmp16 = cpy_r_r11.f15;
    PyTuple_SET_ITEM(cpy_r_r16, 15, __tmp16);
    PyObject *__tmp17 = cpy_r_r11.f16;
    PyTuple_SET_ITEM(cpy_r_r16, 16, __tmp17);
    PyObject *__tmp18 = cpy_r_r11.f17;
    PyTuple_SET_ITEM(cpy_r_r16, 17, __tmp18);
    PyObject *__tmp19 = cpy_r_r11.f18;
    PyTuple_SET_ITEM(cpy_r_r16, 18, __tmp19);
    PyObject *__tmp20 = cpy_r_r11.f19;
    PyTuple_SET_ITEM(cpy_r_r16, 19, __tmp20);
    PyObject *__tmp21 = cpy_r_r11.f20;
    PyTuple_SET_ITEM(cpy_r_r16, 20, __tmp21);
    PyObject *__tmp22 = cpy_r_r11.f21;
    PyTuple_SET_ITEM(cpy_r_r16, 21, __tmp22);
    PyObject *__tmp23 = cpy_r_r11.f22;
    PyTuple_SET_ITEM(cpy_r_r16, 22, __tmp23);
    PyObject *__tmp24 = cpy_r_r11.f23;
    PyTuple_SET_ITEM(cpy_r_r16, 23, __tmp24);
    PyObject *__tmp25 = cpy_r_r11.f24;
    PyTuple_SET_ITEM(cpy_r_r16, 24, __tmp25);
    PyObject *__tmp26 = cpy_r_r11.f25;
    PyTuple_SET_ITEM(cpy_r_r16, 25, __tmp26);
    PyObject *__tmp27 = cpy_r_r11.f26;
    PyTuple_SET_ITEM(cpy_r_r16, 26, __tmp27);
    PyObject *__tmp28 = cpy_r_r11.f27;
    PyTuple_SET_ITEM(cpy_r_r16, 27, __tmp28);
    PyObject *__tmp29 = cpy_r_r11.f28;
    PyTuple_SET_ITEM(cpy_r_r16, 28, __tmp29);
    PyObject *__tmp30 = cpy_r_r11.f29;
    PyTuple_SET_ITEM(cpy_r_r16, 29, __tmp30);
    PyObject *__tmp31 = cpy_r_r11.f30;
    PyTuple_SET_ITEM(cpy_r_r16, 30, __tmp31);
    PyObject *__tmp32 = cpy_r_r11.f31;
    PyTuple_SET_ITEM(cpy_r_r16, 31, __tmp32);
    PyObject *__tmp33 = cpy_r_r11.f32;
    PyTuple_SET_ITEM(cpy_r_r16, 32, __tmp33);
    cpy_r_r17 = CPySequenceTuple_GetItem(cpy_r_r16, cpy_r_r15);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 72, CPyStatic__new___globals);
        goto CPyL14;
    }
    if (likely(PyBytes_Check(cpy_r_r17) || PyByteArray_Check(cpy_r_r17)))
        cpy_r_r18 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 72, CPyStatic__new___globals, "bytes", cpy_r_r17);
        goto CPyL14;
    }
    goto CPyL27;
CPyL14: ;
    cpy_r_r19 = CPy_CatchError();
    cpy_r_r20 = CPyModule_builtins;
    cpy_r_r21 = CPyStatics[6]; /* 'KeyError' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 73, CPyStatic__new___globals);
        goto CPyL34;
    }
    cpy_r_r23 = CPy_ExceptionMatches(cpy_r_r22);
    CPy_DecRef(cpy_r_r22);
    if (!cpy_r_r23) goto CPyL35;
    cpy_r_r24 = CPy_GetExcValue();
    CPy_DecRef(cpy_r_r24);
    cpy_r_r25 = PyObject_Repr(cpy_r_v);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL34;
    }
    cpy_r_r26 = CPyStatics[7]; /* ' is too long: ' */
    cpy_r_r27 = (CPyPtr)&((PyVarObject *)cpy_r_r10)->ob_size;
    cpy_r_r28 = *(int64_t *)cpy_r_r27;
    CPy_DecRef(cpy_r_r10);
    cpy_r_r29 = cpy_r_r28 << 1;
    cpy_r_r30 = CPyTagged_Str(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL36;
    }
    cpy_r_r31 = CPyStr_Build(3, cpy_r_r25, cpy_r_r26, cpy_r_r30);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL25;
    }
    cpy_r_r32 = CPyModule_builtins;
    cpy_r_r33 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL37;
    }
    PyObject *cpy_r_r35[1] = {cpy_r_r31};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, 0);
    CPy_DecRef(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL37;
    }
    CPy_DecRef(cpy_r_r31);
    CPy_Raise(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 74, CPyStatic__new___globals);
        goto CPyL25;
    } else
        goto CPyL38;
CPyL22: ;
    CPy_Unreachable();
CPyL23: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL25;
    } else
        goto CPyL39;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_RestoreExcInfo(cpy_r_r19);
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    cpy_r_r38 = CPy_KeepPropagating();
    if (!cpy_r_r38) goto CPyL30;
    CPy_Unreachable();
CPyL27: ;
    cpy_r_r39 = (PyObject *)&PyBytes_Type;
    cpy_r_r40 = CPyBytes_Concat(cpy_r_r18, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic__new___globals);
        goto CPyL30;
    }
    cpy_r_r41 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r42[3] = {cpy_r_r39, cpy_r_cls, cpy_r_r40};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r43, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 75, CPyStatic__new___globals);
        goto CPyL40;
    }
    CPy_DECREF(cpy_r_r40);
    return cpy_r_r44;
CPyL30: ;
    cpy_r_r45 = NULL;
    return cpy_r_r45;
CPyL31: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL30;
CPyL32: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL5;
CPyL33: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL10;
CPyL34: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL23;
CPyL36: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL25;
CPyL37: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL25;
CPyL38: ;
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    goto CPyL22;
CPyL39: ;
    CPy_DecRef(cpy_r_r19.f0);
    CPy_DecRef(cpy_r_r19.f1);
    CPy_DecRef(cpy_r_r19.f2);
    goto CPyL24;
CPyL40: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL30;
}

PyObject *CPyPy__new___HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef__new___HexBytes32(arg_cls, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 64, CPyStatic__new___globals);
    return NULL;
}

char CPyDef__new_____top_level__(void) {
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
    void *cpy_r_r11;
    void *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject **cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
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
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    int32_t cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    int32_t cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[9]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", -1, CPyStatic__new___globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[83]; /* ('Final', 'Type', 'TypeVar', 'Union') */
    cpy_r_r6 = CPyStatics[14]; /* 'typing' */
    cpy_r_r7 = CPyStatic__new___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 1, CPyStatic__new___globals);
        goto CPyL15;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_cchecksum;
    PyObject **cpy_r_r10[1] = {cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[1] = {3};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[85]; /* (('cchecksum', 'cchecksum', 'cchecksum'),) */
    cpy_r_r15 = CPyStatic__new___globals;
    cpy_r_r16 = CPyStatics[16]; /* 'evmspec/_new.py' */
    cpy_r_r17 = CPyStatics[17]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL15;
    cpy_r_r19 = CPyStatics[86]; /* ('AnyAddress',) */
    cpy_r_r20 = CPyStatics[19]; /* 'eth_typing' */
    cpy_r_r21 = CPyStatic__new___globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 4, CPyStatic__new___globals);
        goto CPyL15;
    }
    CPyModule_eth_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[87]; /* ('to_bytes',) */
    cpy_r_r24 = CPyStatics[21]; /* 'evmspec._utils' */
    cpy_r_r25 = CPyStatic__new___globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 6, CPyStatic__new___globals);
        goto CPyL15;
    }
    CPyModule_evmspec____utils = cpy_r_r26;
    CPy_INCREF(CPyModule_evmspec____utils);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[22]; /* '__T' */
    cpy_r_r28 = CPyStatic__new___globals;
    cpy_r_r29 = CPyStatics[12]; /* 'TypeVar' */
    cpy_r_r30 = CPyDict_GetItem(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic__new___globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r31[1] = {cpy_r_r27};
    cpy_r_r32 = (PyObject **)&cpy_r_r31;
    cpy_r_r33 = PyObject_Vectorcall(cpy_r_r30, cpy_r_r32, 1, 0);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic__new___globals);
        goto CPyL15;
    }
    cpy_r_r34 = CPyStatic__new___globals;
    cpy_r_r35 = CPyStatics[22]; /* '__T' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic__new___globals);
        goto CPyL15;
    }
    cpy_r_r38 = CPyStatics[49]; /* b'\x00' */
    CPyStatic__new___ONE_EMPTY_BYTE = cpy_r_r38;
    CPy_INCREF(CPyStatic__new___ONE_EMPTY_BYTE);
    cpy_r_r39 = CPyStatic__new___globals;
    cpy_r_r40 = CPyStatics[23]; /* 'ONE_EMPTY_BYTE' */
    cpy_r_r41 = CPyDict_SetItem(cpy_r_r39, cpy_r_r40, cpy_r_r38);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 12, CPyStatic__new___globals);
        goto CPyL15;
    }
    cpy_r_r43 = CPyStatics[50]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r44 = CPyStatics[51]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r45 = CPyStatics[52]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00') */
    cpy_r_r46 = CPyStatics[53]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00') */
    cpy_r_r47 = CPyStatics[54]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00') */
    cpy_r_r48 = CPyStatics[55]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00') */
    cpy_r_r49 = CPyStatics[56]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00') */
    cpy_r_r50 = CPyStatics[57]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r51 = CPyStatics[58]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r52 = CPyStatics[59]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r53 = CPyStatics[60]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r54 = CPyStatics[61]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r55 = CPyStatics[62]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r56 = CPyStatics[63]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00\x00') */
    cpy_r_r57 = CPyStatics[64]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00\x00') */
    cpy_r_r58 = CPyStatics[65]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00\x00') */
    cpy_r_r59 = CPyStatics[66]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00\x00') */
    cpy_r_r60 = CPyStatics[67]; /* (b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
                                   b'\x00\x00\x00') */
    cpy_r_r61 = CPyStatics[68]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r62 = CPyStatics[69]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r63 = CPyStatics[70]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r64 = CPyStatics[71]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r65 = CPyStatics[72]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r66 = CPyStatics[73]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r67 = CPyStatics[74]; /* b'\x00\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r68 = CPyStatics[75]; /* b'\x00\x00\x00\x00\x00\x00\x00' */
    cpy_r_r69 = CPyStatics[76]; /* b'\x00\x00\x00\x00\x00\x00' */
    cpy_r_r70 = CPyStatics[77]; /* b'\x00\x00\x00\x00\x00' */
    cpy_r_r71 = CPyStatics[78]; /* b'\x00\x00\x00\x00' */
    cpy_r_r72 = CPyStatics[79]; /* b'\x00\x00\x00' */
    cpy_r_r73 = CPyStatics[80]; /* b'\x00\x00' */
    cpy_r_r74 = CPyStatics[49]; /* b'\x00' */
    cpy_r_r75 = CPyStatics[81]; /* b'' */
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
    CPy_INCREF(cpy_r_r74);
    CPy_INCREF(cpy_r_r75);
    cpy_r_r76.f0 = cpy_r_r43;
    cpy_r_r76.f1 = cpy_r_r44;
    cpy_r_r76.f2 = cpy_r_r45;
    cpy_r_r76.f3 = cpy_r_r46;
    cpy_r_r76.f4 = cpy_r_r47;
    cpy_r_r76.f5 = cpy_r_r48;
    cpy_r_r76.f6 = cpy_r_r49;
    cpy_r_r76.f7 = cpy_r_r50;
    cpy_r_r76.f8 = cpy_r_r51;
    cpy_r_r76.f9 = cpy_r_r52;
    cpy_r_r76.f10 = cpy_r_r53;
    cpy_r_r76.f11 = cpy_r_r54;
    cpy_r_r76.f12 = cpy_r_r55;
    cpy_r_r76.f13 = cpy_r_r56;
    cpy_r_r76.f14 = cpy_r_r57;
    cpy_r_r76.f15 = cpy_r_r58;
    cpy_r_r76.f16 = cpy_r_r59;
    cpy_r_r76.f17 = cpy_r_r60;
    cpy_r_r76.f18 = cpy_r_r61;
    cpy_r_r76.f19 = cpy_r_r62;
    cpy_r_r76.f20 = cpy_r_r63;
    cpy_r_r76.f21 = cpy_r_r64;
    cpy_r_r76.f22 = cpy_r_r65;
    cpy_r_r76.f23 = cpy_r_r66;
    cpy_r_r76.f24 = cpy_r_r67;
    cpy_r_r76.f25 = cpy_r_r68;
    cpy_r_r76.f26 = cpy_r_r69;
    cpy_r_r76.f27 = cpy_r_r70;
    cpy_r_r76.f28 = cpy_r_r71;
    cpy_r_r76.f29 = cpy_r_r72;
    cpy_r_r76.f30 = cpy_r_r73;
    cpy_r_r76.f31 = cpy_r_r74;
    cpy_r_r76.f32 = cpy_r_r75;
    CPyStatic__new___MISSING_BYTES = cpy_r_r76;
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f0);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f1);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f2);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f3);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f4);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f5);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f6);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f7);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f8);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f9);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f10);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f11);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f12);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f13);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f14);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f15);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f16);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f17);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f18);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f19);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f20);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f21);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f22);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f23);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f24);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f25);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f26);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f27);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f28);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f29);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f30);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f31);
    CPy_INCREF(CPyStatic__new___MISSING_BYTES.f32);
    cpy_r_r77 = CPyStatic__new___globals;
    cpy_r_r78 = CPyStatics[24]; /* 'MISSING_BYTES' */
    cpy_r_r79 = PyTuple_New(33);
    if (unlikely(cpy_r_r79 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r76.f0;
    PyTuple_SET_ITEM(cpy_r_r79, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r76.f1;
    PyTuple_SET_ITEM(cpy_r_r79, 1, __tmp36);
    PyObject *__tmp37 = cpy_r_r76.f2;
    PyTuple_SET_ITEM(cpy_r_r79, 2, __tmp37);
    PyObject *__tmp38 = cpy_r_r76.f3;
    PyTuple_SET_ITEM(cpy_r_r79, 3, __tmp38);
    PyObject *__tmp39 = cpy_r_r76.f4;
    PyTuple_SET_ITEM(cpy_r_r79, 4, __tmp39);
    PyObject *__tmp40 = cpy_r_r76.f5;
    PyTuple_SET_ITEM(cpy_r_r79, 5, __tmp40);
    PyObject *__tmp41 = cpy_r_r76.f6;
    PyTuple_SET_ITEM(cpy_r_r79, 6, __tmp41);
    PyObject *__tmp42 = cpy_r_r76.f7;
    PyTuple_SET_ITEM(cpy_r_r79, 7, __tmp42);
    PyObject *__tmp43 = cpy_r_r76.f8;
    PyTuple_SET_ITEM(cpy_r_r79, 8, __tmp43);
    PyObject *__tmp44 = cpy_r_r76.f9;
    PyTuple_SET_ITEM(cpy_r_r79, 9, __tmp44);
    PyObject *__tmp45 = cpy_r_r76.f10;
    PyTuple_SET_ITEM(cpy_r_r79, 10, __tmp45);
    PyObject *__tmp46 = cpy_r_r76.f11;
    PyTuple_SET_ITEM(cpy_r_r79, 11, __tmp46);
    PyObject *__tmp47 = cpy_r_r76.f12;
    PyTuple_SET_ITEM(cpy_r_r79, 12, __tmp47);
    PyObject *__tmp48 = cpy_r_r76.f13;
    PyTuple_SET_ITEM(cpy_r_r79, 13, __tmp48);
    PyObject *__tmp49 = cpy_r_r76.f14;
    PyTuple_SET_ITEM(cpy_r_r79, 14, __tmp49);
    PyObject *__tmp50 = cpy_r_r76.f15;
    PyTuple_SET_ITEM(cpy_r_r79, 15, __tmp50);
    PyObject *__tmp51 = cpy_r_r76.f16;
    PyTuple_SET_ITEM(cpy_r_r79, 16, __tmp51);
    PyObject *__tmp52 = cpy_r_r76.f17;
    PyTuple_SET_ITEM(cpy_r_r79, 17, __tmp52);
    PyObject *__tmp53 = cpy_r_r76.f18;
    PyTuple_SET_ITEM(cpy_r_r79, 18, __tmp53);
    PyObject *__tmp54 = cpy_r_r76.f19;
    PyTuple_SET_ITEM(cpy_r_r79, 19, __tmp54);
    PyObject *__tmp55 = cpy_r_r76.f20;
    PyTuple_SET_ITEM(cpy_r_r79, 20, __tmp55);
    PyObject *__tmp56 = cpy_r_r76.f21;
    PyTuple_SET_ITEM(cpy_r_r79, 21, __tmp56);
    PyObject *__tmp57 = cpy_r_r76.f22;
    PyTuple_SET_ITEM(cpy_r_r79, 22, __tmp57);
    PyObject *__tmp58 = cpy_r_r76.f23;
    PyTuple_SET_ITEM(cpy_r_r79, 23, __tmp58);
    PyObject *__tmp59 = cpy_r_r76.f24;
    PyTuple_SET_ITEM(cpy_r_r79, 24, __tmp59);
    PyObject *__tmp60 = cpy_r_r76.f25;
    PyTuple_SET_ITEM(cpy_r_r79, 25, __tmp60);
    PyObject *__tmp61 = cpy_r_r76.f26;
    PyTuple_SET_ITEM(cpy_r_r79, 26, __tmp61);
    PyObject *__tmp62 = cpy_r_r76.f27;
    PyTuple_SET_ITEM(cpy_r_r79, 27, __tmp62);
    PyObject *__tmp63 = cpy_r_r76.f28;
    PyTuple_SET_ITEM(cpy_r_r79, 28, __tmp63);
    PyObject *__tmp64 = cpy_r_r76.f29;
    PyTuple_SET_ITEM(cpy_r_r79, 29, __tmp64);
    PyObject *__tmp65 = cpy_r_r76.f30;
    PyTuple_SET_ITEM(cpy_r_r79, 30, __tmp65);
    PyObject *__tmp66 = cpy_r_r76.f31;
    PyTuple_SET_ITEM(cpy_r_r79, 31, __tmp66);
    PyObject *__tmp67 = cpy_r_r76.f32;
    PyTuple_SET_ITEM(cpy_r_r79, 32, __tmp67);
    cpy_r_r80 = CPyDict_SetItem(cpy_r_r77, cpy_r_r78, cpy_r_r79);
    CPy_DECREF(cpy_r_r79);
    cpy_r_r81 = cpy_r_r80 >= 0;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 15, CPyStatic__new___globals);
        goto CPyL15;
    }
    cpy_r_r82 = CPyModule_cchecksum;
    cpy_r_r83 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 57, CPyStatic__new___globals);
        goto CPyL15;
    }
    CPyStatic__new___to_checksum_address = cpy_r_r84;
    CPy_INCREF(CPyStatic__new___to_checksum_address);
    cpy_r_r85 = CPyStatic__new___globals;
    cpy_r_r86 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r87 = CPyDict_SetItem(cpy_r_r85, cpy_r_r86, cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r88 = cpy_r_r87 >= 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 57, CPyStatic__new___globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r89 = 2;
    return cpy_r_r89;
}
static PyMethodDef _utilsmodule_methods[] = {
    {"to_bytes", (PyCFunction)CPyPy__utils___to_bytes, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("to_bytes(val)\n--\n\n") /* docstring */},
    {"hexstr_to_bytes", (PyCFunction)CPyPy__utils___hexstr_to_bytes, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("hexstr_to_bytes(hexstr)\n--\n\n") /* docstring */},
    {"monkey_patch_hexbytes_utils", (PyCFunction)CPyPy__utils___monkey_patch_hexbytes_utils, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("monkey_patch_hexbytes_utils()\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_evmspec____utils(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_evmspec____utils__internal, "__name__");
    CPyStatic__utils___globals = PyModule_GetDict(CPyModule_evmspec____utils__internal);
    if (unlikely(CPyStatic__utils___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__utils_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_evmspec____utils__internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__utils___unhexlify);
    CPyStatic__utils___unhexlify = NULL;
    return -1;
}
static struct PyModuleDef _utilsmodule = {
    PyModuleDef_HEAD_INIT,
    "evmspec._utils",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _utilsmodule_methods,
    NULL,
};

PyObject *CPyInit_evmspec____utils(void)
{
    if (CPyModule_evmspec____utils__internal) {
        Py_INCREF(CPyModule_evmspec____utils__internal);
        return CPyModule_evmspec____utils__internal;
    }
    CPyModule_evmspec____utils__internal = PyModule_Create(&_utilsmodule);
    if (unlikely(CPyModule_evmspec____utils__internal == NULL))
        goto fail;
    if (CPyExec_evmspec____utils(CPyModule_evmspec____utils__internal) != 0)
        goto fail;
    return CPyModule_evmspec____utils__internal;
    fail:
    return NULL;
}

PyObject *CPyDef__utils___to_bytes(PyObject *cpy_r_val) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    CPyTagged cpy_r_r17;
    int64_t cpy_r_r18;
    char cpy_r_r19;
    int64_t cpy_r_r20;
    char cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject **cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    CPyPtr cpy_r_r75;
    CPyPtr cpy_r_r76;
    CPyPtr cpy_r_r77;
    CPyPtr cpy_r_r78;
    CPyPtr cpy_r_r79;
    CPyPtr cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject **cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    cpy_r_r0 = PyBytes_Check(cpy_r_val);
    if (!cpy_r_r0) goto CPyL3;
    CPy_INCREF(cpy_r_val);
    if (likely(PyBytes_Check(cpy_r_val) || PyByteArray_Check(cpy_r_val)))
        cpy_r_r1 = cpy_r_val;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 18, CPyStatic__utils___globals, "bytes", cpy_r_val);
        goto CPyL51;
    }
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = PyUnicode_Check(cpy_r_val);
    if (!cpy_r_r2) goto CPyL7;
    CPy_INCREF(cpy_r_val);
    if (likely(PyUnicode_Check(cpy_r_val)))
        cpy_r_r3 = cpy_r_val;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 20, CPyStatic__utils___globals, "str", cpy_r_val);
        goto CPyL51;
    }
    cpy_r_r4 = CPyDef__utils___hexstr_to_bytes(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 20, CPyStatic__utils___globals);
        goto CPyL51;
    }
    return cpy_r_r4;
CPyL7: ;
    cpy_r_r5 = PyByteArray_Check(cpy_r_val);
    if (!cpy_r_r5) goto CPyL11;
    cpy_r_r6 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r7[1] = {cpy_r_val};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 22, CPyStatic__utils___globals);
        goto CPyL51;
    }
    if (likely(PyBytes_Check(cpy_r_r9) || PyByteArray_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 22, CPyStatic__utils___globals, "bytes", cpy_r_r9);
        goto CPyL51;
    }
    return cpy_r_r10;
CPyL11: ;
    cpy_r_r11 = PyBool_Check(cpy_r_val);
    if (!cpy_r_r11) goto CPyL17;
    if (unlikely(!PyBool_Check(cpy_r_val))) {
        CPy_TypeError("bool", cpy_r_val); cpy_r_r12 = 2;
    } else
        cpy_r_r12 = cpy_r_val == Py_True;
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 24, CPyStatic__utils___globals);
        goto CPyL51;
    }
    if (!cpy_r_r12) goto CPyL15;
    cpy_r_r13 = CPyStatics[82]; /* b'\x01' */
    CPy_INCREF(cpy_r_r13);
    cpy_r_r14 = cpy_r_r13;
    goto CPyL16;
CPyL15: ;
    cpy_r_r15 = CPyStatics[49]; /* b'\x00' */
    CPy_INCREF(cpy_r_r15);
    cpy_r_r14 = cpy_r_r15;
CPyL16: ;
    return cpy_r_r14;
CPyL17: ;
    cpy_r_r16 = PyLong_Check(cpy_r_val);
    if (!cpy_r_r16) goto CPyL37;
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r17 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r17 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 28, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r18 = cpy_r_r17 & 1;
    cpy_r_r19 = cpy_r_r18 != 0;
    if (cpy_r_r19) goto CPyL21;
    cpy_r_r20 = 0 & 1;
    cpy_r_r21 = cpy_r_r20 != 0;
    if (!cpy_r_r21) goto CPyL22;
CPyL21: ;
    cpy_r_r22 = CPyTagged_IsLt_(cpy_r_r17, 0);
    cpy_r_r23 = cpy_r_r22;
    goto CPyL23;
CPyL22: ;
    cpy_r_r24 = (Py_ssize_t)cpy_r_r17 < (Py_ssize_t)0;
    cpy_r_r23 = cpy_r_r24;
CPyL23: ;
    CPyTagged_DECREF(cpy_r_r17);
    if (!cpy_r_r23) goto CPyL31;
    cpy_r_r25 = CPyStatics[26]; /* 'Cannot convert negative integer ' */
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r26 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r26 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r26 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r27 = CPyTagged_Str(cpy_r_r26);
    CPyTagged_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r28 = CPyStatics[27]; /* ' to bytes' */
    cpy_r_r29 = CPyStr_Build(3, cpy_r_r25, cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r30 = CPyModule_builtins;
    cpy_r_r31 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r33[1] = {cpy_r_r29};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_Vectorcall(cpy_r_r32, cpy_r_r34, 1, 0);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r29);
    CPy_Raise(cpy_r_r35);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL51;
    }
    CPy_Unreachable();
CPyL31: ;
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r36 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r36 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r36 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[28]; /* 'hex' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL53;
    }
    cpy_r_r40 = CPyTagged_StealAsObject(cpy_r_r36);
    PyObject *cpy_r_r41[1] = {cpy_r_r40};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r42, 1, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL54;
    }
    CPy_DECREF(cpy_r_r40);
    if (likely(PyUnicode_Check(cpy_r_r43)))
        cpy_r_r44 = cpy_r_r43;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals, "str", cpy_r_r43);
        goto CPyL51;
    }
    cpy_r_r45 = CPyDef__utils___to_bytes(cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL51;
    }
    return cpy_r_r45;
CPyL37: ;
    cpy_r_r46 = CPyModule_builtins;
    cpy_r_r47 = CPyStatics[29]; /* 'memoryview' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 32, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r49 = PyObject_IsInstance(cpy_r_val, cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 32, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r51 = cpy_r_r49;
    if (!cpy_r_r51) goto CPyL43;
    cpy_r_r52 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r53[1] = {cpy_r_val};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, 0);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 33, CPyStatic__utils___globals);
        goto CPyL51;
    }
    if (likely(PyBytes_Check(cpy_r_r55) || PyByteArray_Check(cpy_r_r55)))
        cpy_r_r56 = cpy_r_r55;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 33, CPyStatic__utils___globals, "bytes", cpy_r_r55);
        goto CPyL51;
    }
    return cpy_r_r56;
CPyL43: ;
    cpy_r_r57 = CPyStatics[30]; /* '' */
    cpy_r_r58 = CPyStatics[31]; /* 'Cannot convert ' */
    cpy_r_r59 = CPyStatics[32]; /* '{!r:{}}' */
    cpy_r_r60 = CPyStatics[30]; /* '' */
    cpy_r_r61 = CPyStatics[33]; /* 'format' */
    PyObject *cpy_r_r62[3] = {cpy_r_r59, cpy_r_val, cpy_r_r60};
    cpy_r_r63 = (PyObject **)&cpy_r_r62;
    cpy_r_r64 = PyObject_VectorcallMethod(cpy_r_r61, cpy_r_r63, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r65 = CPyStatics[34]; /* ' of type ' */
    cpy_r_r66 = CPyStatics[35]; /* '{:{}}' */
    cpy_r_r67 = CPy_TYPE(cpy_r_val);
    cpy_r_r68 = CPyStatics[30]; /* '' */
    cpy_r_r69 = CPyStatics[33]; /* 'format' */
    PyObject *cpy_r_r70[3] = {cpy_r_r66, cpy_r_r67, cpy_r_r68};
    cpy_r_r71 = (PyObject **)&cpy_r_r70;
    cpy_r_r72 = PyObject_VectorcallMethod(cpy_r_r69, cpy_r_r71, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r67);
    cpy_r_r73 = CPyStatics[27]; /* ' to bytes' */
    cpy_r_r74 = PyList_New(5);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL56;
    }
    cpy_r_r75 = (CPyPtr)&((PyListObject *)cpy_r_r74)->ob_item;
    cpy_r_r76 = *(CPyPtr *)cpy_r_r75;
    CPy_INCREF(cpy_r_r58);
    *(PyObject * *)cpy_r_r76 = cpy_r_r58;
    cpy_r_r77 = cpy_r_r76 + 8;
    *(PyObject * *)cpy_r_r77 = cpy_r_r64;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r78 = cpy_r_r76 + 16;
    *(PyObject * *)cpy_r_r78 = cpy_r_r65;
    cpy_r_r79 = cpy_r_r76 + 24;
    *(PyObject * *)cpy_r_r79 = cpy_r_r72;
    CPy_INCREF(cpy_r_r73);
    cpy_r_r80 = cpy_r_r76 + 32;
    *(PyObject * *)cpy_r_r80 = cpy_r_r73;
    cpy_r_r81 = PyUnicode_Join(cpy_r_r57, cpy_r_r74);
    CPy_DECREF_NO_IMM(cpy_r_r74);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL51;
    }
    cpy_r_r82 = CPyModule_builtins;
    cpy_r_r83 = CPyStatics[36]; /* 'TypeError' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL57;
    }
    PyObject *cpy_r_r85[1] = {cpy_r_r81};
    cpy_r_r86 = (PyObject **)&cpy_r_r85;
    cpy_r_r87 = PyObject_Vectorcall(cpy_r_r84, cpy_r_r86, 1, 0);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL57;
    }
    CPy_DECREF(cpy_r_r81);
    CPy_Raise(cpy_r_r87);
    CPy_DECREF(cpy_r_r87);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL51;
    }
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r88 = NULL;
    return cpy_r_r88;
CPyL52: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL51;
CPyL53: ;
    CPyTagged_DecRef(cpy_r_r36);
    goto CPyL51;
CPyL54: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL51;
CPyL55: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r67);
    goto CPyL51;
CPyL56: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r72);
    goto CPyL51;
CPyL57: ;
    CPy_DecRef(cpy_r_r81);
    goto CPyL51;
}

PyObject *CPyPy__utils___to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"val", 0};
    static CPyArg_Parser parser = {"O:to_bytes", kwlist, 0};
    PyObject *obj_val;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_val)) {
        return NULL;
    }
    PyObject *arg_val;
    if (PyBool_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL68;
    arg_val = obj_val;
    if (arg_val != NULL) goto __LL68;
    if (PyBytes_Check(obj_val) || PyByteArray_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL68;
    if (PyLong_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL68;
    if (PyUnicode_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL68;
    CPy_TypeError("union[bool, object, bytes, int, str]", obj_val); 
    goto fail;
__LL68: ;
    PyObject *retval = CPyDef__utils___to_bytes(arg_val);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 10, CPyStatic__utils___globals);
    return NULL;
}

PyObject *CPyDef__utils___hexstr_to_bytes(PyObject *cpy_r_hexstr) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    tuple_T2OO cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_non_prefixed_hex;
    int64_t cpy_r_r7;
    char cpy_r_r8;
    CPyTagged cpy_r_r9;
    CPyTagged cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_padded_hex;
    PyObject *cpy_r_r14;
    tuple_T3OOO cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    cpy_r_r0 = CPyStatics[4]; /* '0x' */
    cpy_r_r1 = CPyStatics[37]; /* '0X' */
    CPy_INCREF(cpy_r_r0);
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = PyTuple_New(2);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp69 = cpy_r_r2.f0;
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp69);
    PyObject *__tmp70 = cpy_r_r2.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp70);
    cpy_r_r4 = CPyStr_Startswith(cpy_r_hexstr, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == 2)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 39, CPyStatic__utils___globals);
        goto CPyL31;
    }
    if (!cpy_r_r4) goto CPyL5;
    cpy_r_r5 = CPyStr_GetSlice(cpy_r_hexstr, 4, 9223372036854775806LL);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 40, CPyStatic__utils___globals);
        goto CPyL31;
    }
    if (likely(PyUnicode_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "hexstr_to_bytes", 40, CPyStatic__utils___globals, "str", cpy_r_r5);
        goto CPyL31;
    }
    cpy_r_non_prefixed_hex = cpy_r_r6;
    goto CPyL6;
CPyL5: ;
    CPy_INCREF(cpy_r_hexstr);
    cpy_r_non_prefixed_hex = cpy_r_hexstr;
CPyL6: ;
    cpy_r_r7 = CPyStr_Size_size_t(cpy_r_hexstr);
    cpy_r_r8 = cpy_r_r7 >= 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 45, CPyStatic__utils___globals);
        goto CPyL32;
    }
    cpy_r_r9 = cpy_r_r7 << 1;
    cpy_r_r10 = CPyTagged_Remainder(cpy_r_r9, 4);
    if (unlikely(cpy_r_r10 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 45, CPyStatic__utils___globals);
        goto CPyL32;
    }
    cpy_r_r11 = cpy_r_r10 != 0;
    CPyTagged_DECREF(cpy_r_r10);
    if (!cpy_r_r11) goto CPyL11;
    cpy_r_r12 = CPyStatics[38]; /* '0' */
    cpy_r_r13 = PyUnicode_Concat(cpy_r_r12, cpy_r_non_prefixed_hex);
    CPy_DECREF(cpy_r_non_prefixed_hex);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 46, CPyStatic__utils___globals);
        goto CPyL31;
    }
    cpy_r_padded_hex = cpy_r_r13;
    goto CPyL12;
CPyL11: ;
    cpy_r_padded_hex = cpy_r_non_prefixed_hex;
CPyL12: ;
    cpy_r_r14 = PyUnicode_AsASCIIString(cpy_r_padded_hex);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 51, CPyStatic__utils___globals);
        goto CPyL14;
    } else
        goto CPyL33;
CPyL13: ;
    goto CPyL25;
CPyL14: ;
    cpy_r_r15 = CPy_CatchError();
    cpy_r_r16 = CPyModule_builtins;
    cpy_r_r17 = CPyStatics[39]; /* 'UnicodeDecodeError' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 52, CPyStatic__utils___globals);
        goto CPyL34;
    }
    cpy_r_r19 = CPy_ExceptionMatches(cpy_r_r18);
    CPy_DecRef(cpy_r_r18);
    if (!cpy_r_r19) goto CPyL35;
    cpy_r_r20 = CPyStatics[40]; /* 'hex string ' */
    cpy_r_r21 = CPyStatics[41]; /* ' may only contain [0-9a-fA-F] characters' */
    cpy_r_r22 = CPyStr_Build(3, cpy_r_r20, cpy_r_padded_hex, cpy_r_r21);
    CPy_DecRef(cpy_r_padded_hex);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 54, CPyStatic__utils___globals);
        goto CPyL23;
    }
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 53, CPyStatic__utils___globals);
        goto CPyL36;
    }
    PyObject *cpy_r_r26[1] = {cpy_r_r22};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_Vectorcall(cpy_r_r25, cpy_r_r27, 1, 0);
    CPy_DecRef(cpy_r_r25);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 53, CPyStatic__utils___globals);
        goto CPyL36;
    }
    CPy_DecRef(cpy_r_r22);
    CPy_Raise(cpy_r_r28);
    CPy_DecRef(cpy_r_r28);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 53, CPyStatic__utils___globals);
        goto CPyL23;
    } else
        goto CPyL37;
CPyL20: ;
    CPy_Unreachable();
CPyL21: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL23;
    } else
        goto CPyL38;
CPyL22: ;
    CPy_Unreachable();
CPyL23: ;
    CPy_RestoreExcInfo(cpy_r_r15);
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    cpy_r_r29 = CPy_KeepPropagating();
    if (!cpy_r_r29) goto CPyL31;
    CPy_Unreachable();
CPyL25: ;
    cpy_r_r30 = CPyStatic__utils___unhexlify;
    if (unlikely(cpy_r_r30 == NULL)) {
        goto CPyL39;
    } else
        goto CPyL28;
CPyL26: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"unhexlify\" was not set");
    cpy_r_r31 = 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 57, CPyStatic__utils___globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL28: ;
    PyObject *cpy_r_r32[1] = {cpy_r_r14};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_Vectorcall(cpy_r_r30, cpy_r_r33, 1, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 57, CPyStatic__utils___globals);
        goto CPyL40;
    }
    CPy_DECREF(cpy_r_r14);
    if (likely(PyBytes_Check(cpy_r_r34) || PyByteArray_Check(cpy_r_r34)))
        cpy_r_r35 = cpy_r_r34;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "hexstr_to_bytes", 57, CPyStatic__utils___globals, "bytes", cpy_r_r34);
        goto CPyL31;
    }
    return cpy_r_r35;
CPyL31: ;
    cpy_r_r36 = NULL;
    return cpy_r_r36;
CPyL32: ;
    CPy_DecRef(cpy_r_non_prefixed_hex);
    goto CPyL31;
CPyL33: ;
    CPy_DECREF(cpy_r_padded_hex);
    goto CPyL13;
CPyL34: ;
    CPy_DecRef(cpy_r_padded_hex);
    goto CPyL23;
CPyL35: ;
    CPy_DecRef(cpy_r_padded_hex);
    goto CPyL21;
CPyL36: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL23;
CPyL37: ;
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    goto CPyL20;
CPyL38: ;
    CPy_DecRef(cpy_r_r15.f0);
    CPy_DecRef(cpy_r_r15.f1);
    CPy_DecRef(cpy_r_r15.f2);
    goto CPyL22;
CPyL39: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL26;
CPyL40: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL31;
}

PyObject *CPyPy__utils___hexstr_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"hexstr", 0};
    static CPyArg_Parser parser = {"O:hexstr_to_bytes", kwlist, 0};
    PyObject *obj_hexstr;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_hexstr)) {
        return NULL;
    }
    PyObject *arg_hexstr;
    if (likely(PyUnicode_Check(obj_hexstr)))
        arg_hexstr = obj_hexstr;
    else {
        CPy_TypeError("str", obj_hexstr); 
        goto fail;
    }
    PyObject *retval = CPyDef__utils___hexstr_to_bytes(arg_hexstr);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 38, CPyStatic__utils___globals);
    return NULL;
}

char CPyDef__utils___monkey_patch_hexbytes_utils(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    int32_t cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    int32_t cpy_r_r43;
    char cpy_r_r44;
    char cpy_r_r45;
    cpy_r_r0 = CPyStatic__utils___globals;
    cpy_r_r1 = CPyModule_hexbytes____utils;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_r1 != cpy_r_r2;
    if (cpy_r_r3) goto CPyL3;
    cpy_r_r4 = CPyStatics[42]; /* 'hexbytes._utils' */
    cpy_r_r5 = PyImport_Import(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 62, CPyStatic__utils___globals);
        goto CPyL17;
    }
    CPyModule_hexbytes____utils = cpy_r_r5;
    CPy_INCREF(CPyModule_hexbytes____utils);
    CPy_DECREF(cpy_r_r5);
CPyL3: ;
    cpy_r_r6 = CPyStatics[43]; /* 'hexbytes' */
    cpy_r_r7 = PyImport_GetModuleDict();
    cpy_r_r8 = CPyStatics[43]; /* 'hexbytes' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 62, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r10 = CPyDict_SetItem(cpy_r_r0, cpy_r_r6, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 62, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r12 = CPyStatic__utils___globals;
    cpy_r_r13 = CPyModule_hexbytes___main;
    cpy_r_r14 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r15 = cpy_r_r13 != cpy_r_r14;
    if (cpy_r_r15) goto CPyL8;
    cpy_r_r16 = CPyStatics[44]; /* 'hexbytes.main' */
    cpy_r_r17 = PyImport_Import(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 63, CPyStatic__utils___globals);
        goto CPyL17;
    }
    CPyModule_hexbytes___main = cpy_r_r17;
    CPy_INCREF(CPyModule_hexbytes___main);
    CPy_DECREF(cpy_r_r17);
CPyL8: ;
    cpy_r_r18 = CPyStatics[43]; /* 'hexbytes' */
    cpy_r_r19 = PyImport_GetModuleDict();
    cpy_r_r20 = CPyStatics[43]; /* 'hexbytes' */
    cpy_r_r21 = CPyDict_GetItem(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 63, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r22 = CPyDict_SetItem(cpy_r_r12, cpy_r_r18, cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 63, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r24 = CPyStatic__utils___globals;
    cpy_r_r25 = CPyStatics[20]; /* 'to_bytes' */
    cpy_r_r26 = CPyDict_GetItem(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 65, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r27 = CPyModule_hexbytes___main;
    cpy_r_r28 = CPyStatics[20]; /* 'to_bytes' */
    cpy_r_r29 = PyObject_SetAttr(cpy_r_r27, cpy_r_r28, cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r30 = cpy_r_r29 >= 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 65, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r31 = CPyStatic__utils___globals;
    cpy_r_r32 = CPyStatics[20]; /* 'to_bytes' */
    cpy_r_r33 = CPyDict_GetItem(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 67, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r34 = CPyModule_hexbytes____utils;
    cpy_r_r35 = CPyStatics[20]; /* 'to_bytes' */
    cpy_r_r36 = PyObject_SetAttr(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 67, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r38 = CPyStatic__utils___globals;
    cpy_r_r39 = CPyStatics[45]; /* 'hexstr_to_bytes' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 68, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r41 = CPyModule_hexbytes____utils;
    cpy_r_r42 = CPyStatics[45]; /* 'hexstr_to_bytes' */
    cpy_r_r43 = PyObject_SetAttr(cpy_r_r41, cpy_r_r42, cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r44 = cpy_r_r43 >= 0;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 68, CPyStatic__utils___globals);
        goto CPyL17;
    }
    return 1;
CPyL17: ;
    cpy_r_r45 = 2;
    return cpy_r_r45;
}

PyObject *CPyPy__utils___monkey_patch_hexbytes_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":monkey_patch_hexbytes_utils", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    char retval = CPyDef__utils___monkey_patch_hexbytes_utils();
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 60, CPyStatic__utils___globals);
    return NULL;
}

char CPyDef__utils_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    int32_t cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[9]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "<module>", -1, CPyStatic__utils___globals);
        goto CPyL8;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_binascii;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {3};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[89]; /* (('binascii', 'binascii', 'binascii'),) */
    cpy_r_r11 = CPyStatic__utils___globals;
    cpy_r_r12 = CPyStatics[47]; /* 'evmspec/_utils.py' */
    cpy_r_r13 = CPyStatics[17]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL8;
    cpy_r_r15 = CPyStatics[90]; /* ('Final', 'Union') */
    cpy_r_r16 = CPyStatics[14]; /* 'typing' */
    cpy_r_r17 = CPyStatic__utils___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "<module>", 4, CPyStatic__utils___globals);
        goto CPyL8;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyModule_binascii;
    cpy_r_r20 = CPyStatics[48]; /* 'unhexlify' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "<module>", 7, CPyStatic__utils___globals);
        goto CPyL8;
    }
    CPyStatic__utils___unhexlify = cpy_r_r21;
    CPy_INCREF(CPyStatic__utils___unhexlify);
    cpy_r_r22 = CPyStatic__utils___globals;
    cpy_r_r23 = CPyStatics[48]; /* 'unhexlify' */
    cpy_r_r24 = CPyDict_SetItem(cpy_r_r22, cpy_r_r23, cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r25 = cpy_r_r24 >= 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("evmspec/_utils.py", "<module>", 7, CPyStatic__utils___globals);
        goto CPyL8;
    }
    return 1;
CPyL8: ;
    cpy_r_r26 = 2;
    return cpy_r_r26;
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
    CPyModule_eth_typing = Py_None;
    CPyModule_evmspec____utils = Py_None;
    CPyModule_evmspec____utils = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_binascii = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_hexbytes____utils = Py_None;
    CPyModule_hexbytes___main = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[91];
const char * const CPyLit_Str[] = {
    "\a\a__new__\0020x\r_check_hexstr\bKeyError\016 is too long: \nValueError\bbuiltins",
    "\b\005Final\004Type\aTypeVar\005Union\006typing\tcchecksum\017evmspec/_new.py\b<module>",
    "\006\nAnyAddress\neth_typing\bto_bytes\016evmspec._utils\003__T\016ONE_EMPTY_BYTE",
    "\003\rMISSING_BYTES\023to_checksum_address Cannot convert negative integer ",
    "\b\t to bytes\003hex\nmemoryview\000\017Cannot convert \a{!r:{}}\006format\t of type ",
    "\006\005{:{}}\tTypeError\0020X\0010\022UnicodeDecodeError\vhex string ",
    "\003( may only contain [0-9a-fA-F] characters\017hexbytes._utils\bhexbytes",
    "\005\rhexbytes.main\017hexstr_to_bytes\bbinascii\021evmspec/_utils.py\tunhexlify",
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
    "\006\005\000\000\000\000\000\004\000\000\000\000\003\000\000\000\002\000\000\000\001\001",
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    8, 4, 10, 11, 12, 13, 3, 15, 15, 15, 1, 84, 1, 18, 1, 20, 3, 46, 46,
    46, 1, 88, 2, 10, 13
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_evmspec____new__internal = NULL;
CPyModule *CPyModule_evmspec____new;
PyObject *CPyStatic__new___globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_cchecksum;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_evmspec____utils__internal = NULL;
CPyModule *CPyModule_evmspec____utils;
PyObject *CPyStatic__utils___globals;
CPyModule *CPyModule_binascii;
CPyModule *CPyModule_hexbytes____utils;
CPyModule *CPyModule_hexbytes___main;
PyObject *CPyStatic__new___ONE_EMPTY_BYTE = NULL;
tuple_T33OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO CPyStatic__new___MISSING_BYTES = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
PyObject *CPyStatic__new___to_checksum_address = NULL;
PyObject *CPyDef__new___Address(PyObject *cpy_r_cls, PyObject *cpy_r_address);
PyObject *CPyPy__new___Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__new___HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v);
PyObject *CPyPy__new___HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__new_____top_level__(void);
PyObject *CPyStatic__utils___unhexlify = NULL;
PyObject *CPyDef__utils___to_bytes(PyObject *cpy_r_val);
PyObject *CPyPy__utils___to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__utils___hexstr_to_bytes(PyObject *cpy_r_hexstr);
PyObject *CPyPy__utils___hexstr_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__utils___monkey_patch_hexbytes_utils(void);
PyObject *CPyPy__utils___monkey_patch_hexbytes_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__utils_____top_level__(void);

static int exec_77f6a255293717708ca2__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_evmspec____new(void);
    capsule = PyCapsule_New((void *)CPyInit_evmspec____new, "77f6a255293717708ca2__mypyc.init_evmspec____new", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_evmspec____new", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_evmspec____utils(void);
    capsule = PyCapsule_New((void *)CPyInit_evmspec____utils, "77f6a255293717708ca2__mypyc.init_evmspec____utils", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_evmspec____utils", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_77f6a255293717708ca2__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "77f6a255293717708ca2__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_77f6a255293717708ca2__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_77f6a255293717708ca2__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_77f6a255293717708ca2__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
