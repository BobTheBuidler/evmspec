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
    {"Address", (PyCFunction)CPyPy__new___Address, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"HexBytes32", (PyCFunction)CPyPy__new___HexBytes32, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _newmodule = {
    PyModuleDef_HEAD_INIT,
    "evmspec._new",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _newmodule_methods
};

PyObject *CPyInit_evmspec____new(void)
{
    PyObject* modname = NULL;
    if (CPyModule_evmspec____new_internal) {
        Py_INCREF(CPyModule_evmspec____new_internal);
        return CPyModule_evmspec____new_internal;
    }
    CPyModule_evmspec____new_internal = PyModule_Create(&_newmodule);
    if (unlikely(CPyModule_evmspec____new_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_evmspec____new_internal, "__name__");
    CPyStatic__new___globals = PyModule_GetDict(CPyModule_evmspec____new_internal);
    if (unlikely(CPyStatic__new___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__new_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_evmspec____new_internal;
    fail:
    Py_CLEAR(CPyModule_evmspec____new_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__new___ONE_EMPTY_BYTE);
    CPyStatic__new___ONE_EMPTY_BYTE = NULL;
    CPy_XDECREF(CPyStatic__new___MISSING_BYTES);
    CPyStatic__new___MISSING_BYTES = NULL;
    CPy_XDECREF(CPyStatic__new___to_checksum_address);
    CPyStatic__new___to_checksum_address = NULL;
    return NULL;
}

PyObject *CPyDef__new___Address(PyObject *cpy_r_cls, PyObject *cpy_r_address) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    cpy_r_r0 = (PyObject *)&PyUnicode_Type;
    cpy_r_r1 = CPyStatic__new___to_checksum_address;
    if (likely(cpy_r_r1 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"to_checksum_address\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic__new___globals);
        goto CPyL6;
    }
    CPy_Unreachable();
CPyL3: ;
    PyObject *cpy_r_r3[1] = {cpy_r_address};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r1, cpy_r_r4, 1, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic__new___globals);
        goto CPyL6;
    }
    cpy_r_r6 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r7[3] = {cpy_r_r0, cpy_r_cls, cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r6, cpy_r_r8, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic__new___globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r5);
    return cpy_r_r9;
CPyL6: ;
    cpy_r_r10 = NULL;
    return cpy_r_r10;
CPyL7: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL6;
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
    CPy_AddTraceback("evmspec/_new.py", "Address", 30, CPyStatic__new___globals);
    return NULL;
}

PyObject *CPyDef__new___HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    int32_t cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    CPyPtr cpy_r_r16;
    int64_t cpy_r_r17;
    CPyTagged cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    tuple_T3OOO cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyPtr cpy_r_r29;
    int64_t cpy_r_r30;
    CPyTagged cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    cpy_r_r0 = (PyObject *)&PyUnicode_Type;
    cpy_r_r1 = PyObject_IsInstance(cpy_r_v, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 37, CPyStatic__new___globals);
        goto CPyL31;
    }
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL7;
    CPy_INCREF(cpy_r_v);
    if (likely(PyUnicode_Check(cpy_r_v)))
        cpy_r_r4 = cpy_r_v;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 37, CPyStatic__new___globals, "str", cpy_r_v);
        goto CPyL31;
    }
    cpy_r_r5 = CPyStatics[4]; /* '0x' */
    cpy_r_r6 = CPyStr_Startswith(cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r4);
    cpy_r_r7 = cpy_r_r6;
    if (!cpy_r_r7) goto CPyL7;
    CPy_INCREF(cpy_r_v);
    if (likely(PyUnicode_Check(cpy_r_v)))
        cpy_r_r8 = cpy_r_v;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 38, CPyStatic__new___globals, "str", cpy_r_v);
        goto CPyL31;
    }
    cpy_r_r9 = CPyStatics[5]; /* '_check_hexstr' */
    PyObject *cpy_r_r10[2] = {cpy_r_cls, cpy_r_r8};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r11, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 38, CPyStatic__new___globals);
        goto CPyL32;
    } else
        goto CPyL33;
CPyL6: ;
    CPy_DECREF(cpy_r_r8);
CPyL7: ;
    cpy_r_r13 = CPyDef__utils___to_bytes(cpy_r_v);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 40, CPyStatic__new___globals);
        goto CPyL31;
    }
    cpy_r_r14 = CPyStatic__new___MISSING_BYTES;
    if (likely(cpy_r_r14 != NULL)) goto CPyL12;
    PyErr_SetString(PyExc_NameError, "value for final name \"MISSING_BYTES\" was not set");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic__new___globals);
        goto CPyL15;
    } else
        goto CPyL34;
CPyL11: ;
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r16 = (CPyPtr)&((PyVarObject *)cpy_r_r13)->ob_size;
    cpy_r_r17 = *(int64_t *)cpy_r_r16;
    cpy_r_r18 = cpy_r_r17 << 1;
    cpy_r_r19 = CPySequenceTuple_GetItem(cpy_r_r14, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic__new___globals);
        goto CPyL15;
    }
    if (likely(PyBytes_Check(cpy_r_r19) || PyByteArray_Check(cpy_r_r19)))
        cpy_r_r20 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic__new___globals, "bytes", cpy_r_r19);
        goto CPyL15;
    }
    goto CPyL28;
CPyL15: ;
    cpy_r_r21 = CPy_CatchError();
    cpy_r_r22 = CPyModule_builtins;
    cpy_r_r23 = CPyStatics[6]; /* 'KeyError' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 43, CPyStatic__new___globals);
        goto CPyL35;
    }
    cpy_r_r25 = CPy_ExceptionMatches(cpy_r_r24);
    CPy_DecRef(cpy_r_r24);
    if (!cpy_r_r25) goto CPyL36;
    cpy_r_r26 = CPy_GetExcValue();
    CPy_DecRef(cpy_r_r26);
    cpy_r_r27 = PyObject_Repr(cpy_r_v);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL35;
    }
    cpy_r_r28 = CPyStatics[7]; /* ' is too long: ' */
    cpy_r_r29 = (CPyPtr)&((PyVarObject *)cpy_r_r13)->ob_size;
    cpy_r_r30 = *(int64_t *)cpy_r_r29;
    CPy_DecRef(cpy_r_r13);
    cpy_r_r31 = cpy_r_r30 << 1;
    cpy_r_r32 = CPyTagged_Str(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL37;
    }
    cpy_r_r33 = CPyStr_Build(3, cpy_r_r27, cpy_r_r28, cpy_r_r32);
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r34 = CPyModule_builtins;
    cpy_r_r35 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL38;
    }
    PyObject *cpy_r_r37[1] = {cpy_r_r33};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r36, cpy_r_r38, 1, 0);
    CPy_DecRef(cpy_r_r36);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL38;
    }
    CPy_DecRef(cpy_r_r33);
    CPy_Raise(cpy_r_r39);
    CPy_DecRef(cpy_r_r39);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic__new___globals);
        goto CPyL26;
    } else
        goto CPyL39;
CPyL23: ;
    CPy_Unreachable();
CPyL24: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL26;
    } else
        goto CPyL40;
CPyL25: ;
    CPy_Unreachable();
CPyL26: ;
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    cpy_r_r40 = CPy_KeepPropagating();
    if (!cpy_r_r40) goto CPyL31;
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r41 = (PyObject *)&PyBytes_Type;
    cpy_r_r42 = CPyBytes_Concat(cpy_r_r20, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 45, CPyStatic__new___globals);
        goto CPyL31;
    }
    cpy_r_r43 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r44[3] = {cpy_r_r41, cpy_r_cls, cpy_r_r42};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r43, cpy_r_r45, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 45, CPyStatic__new___globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r42);
    return cpy_r_r46;
CPyL31: ;
    cpy_r_r47 = NULL;
    return cpy_r_r47;
CPyL32: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL31;
CPyL33: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL6;
CPyL34: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL11;
CPyL35: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL26;
CPyL36: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL24;
CPyL37: ;
    CPy_DecRef(cpy_r_r27);
    goto CPyL26;
CPyL38: ;
    CPy_DecRef(cpy_r_r33);
    goto CPyL26;
CPyL39: ;
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL23;
CPyL40: ;
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL25;
CPyL41: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL31;
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
    if (arg_v != NULL) goto __LL1;
    if (PyUnicode_Check(obj_v))
        arg_v = obj_v;
    else {
        arg_v = NULL;
    }
    if (arg_v != NULL) goto __LL1;
    CPy_TypeError("union[bytes, str]", obj_v); 
    goto fail;
__LL1: ;
    PyObject *retval = CPyDef__new___HexBytes32(arg_cls, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 34, CPyStatic__new___globals);
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
    CPyTagged cpy_r_r44;
    CPyTagged cpy_r_i;
    char cpy_r_r45;
    CPyTagged cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    CPyTagged cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[9]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", -1, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[52]; /* ('Final', 'Type', 'TypeVar', 'Union') */
    cpy_r_r6 = CPyStatics[14]; /* 'typing' */
    cpy_r_r7 = CPyStatic__new___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 1, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_cchecksum;
    PyObject **cpy_r_r10[1] = {cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[1] = {3};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[54]; /* (('cchecksum', 'cchecksum', 'cchecksum'),) */
    cpy_r_r15 = CPyStatic__new___globals;
    cpy_r_r16 = CPyStatics[16]; /* 'evmspec/_new.py' */
    cpy_r_r17 = CPyStatics[17]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL26;
    cpy_r_r19 = CPyStatics[55]; /* ('AnyAddress',) */
    cpy_r_r20 = CPyStatics[19]; /* 'eth_typing' */
    cpy_r_r21 = CPyStatic__new___globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 4, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPyModule_eth_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[56]; /* ('to_bytes',) */
    cpy_r_r24 = CPyStatics[21]; /* 'evmspec._utils' */
    cpy_r_r25 = CPyStatic__new___globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 6, CPyStatic__new___globals);
        goto CPyL26;
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
        goto CPyL26;
    }
    PyObject *cpy_r_r31[1] = {cpy_r_r27};
    cpy_r_r32 = (PyObject **)&cpy_r_r31;
    cpy_r_r33 = PyObject_Vectorcall(cpy_r_r30, cpy_r_r32, 1, 0);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r34 = CPyStatic__new___globals;
    cpy_r_r35 = CPyStatics[22]; /* '__T' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r38 = CPyStatics[50]; /* b'\x00' */
    CPyStatic__new___ONE_EMPTY_BYTE = cpy_r_r38;
    CPy_INCREF(CPyStatic__new___ONE_EMPTY_BYTE);
    cpy_r_r39 = CPyStatic__new___globals;
    cpy_r_r40 = CPyStatics[23]; /* 'ONE_EMPTY_BYTE' */
    cpy_r_r41 = CPyDict_SetItem(cpy_r_r39, cpy_r_r40, cpy_r_r38);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 12, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r43 = PyList_New(0);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r44 = 0;
    cpy_r_i = cpy_r_r44;
CPyL13: ;
    cpy_r_r45 = (Py_ssize_t)cpy_r_r44 < (Py_ssize_t)66;
    if (!cpy_r_r45) goto CPyL27;
    cpy_r_r46 = CPyTagged_Subtract(64, cpy_r_i);
    CPyTagged_DECREF(cpy_r_i);
    cpy_r_r47 = CPyStatic__new___ONE_EMPTY_BYTE;
    if (unlikely(cpy_r_r47 == NULL)) {
        goto CPyL28;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ONE_EMPTY_BYTE\" was not set");
    cpy_r_r48 = 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r49 = CPyTagged_StealAsObject(cpy_r_r46);
    cpy_r_r50 = PyNumber_Multiply(cpy_r_r49, cpy_r_r47);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL29;
    }
    if (likely(PyBytes_Check(cpy_r_r50) || PyByteArray_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals, "bytes", cpy_r_r50);
        goto CPyL29;
    }
    cpy_r_r52 = PyList_Append(cpy_r_r43, cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL29;
    }
    cpy_r_r54 = cpy_r_r44 + 2;
    cpy_r_r44 = cpy_r_r54;
    cpy_r_i = cpy_r_r54;
    goto CPyL13;
CPyL21: ;
    cpy_r_r55 = PyList_AsTuple(cpy_r_r43);
    CPy_DECREF_NO_IMM(cpy_r_r43);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPyStatic__new___MISSING_BYTES = cpy_r_r55;
    CPy_INCREF(CPyStatic__new___MISSING_BYTES);
    cpy_r_r56 = CPyStatic__new___globals;
    cpy_r_r57 = CPyStatics[24]; /* 'MISSING_BYTES' */
    cpy_r_r58 = CPyDict_SetItem(cpy_r_r56, cpy_r_r57, cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic__new___globals);
        goto CPyL26;
    }
    cpy_r_r60 = CPyModule_cchecksum;
    cpy_r_r61 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 27, CPyStatic__new___globals);
        goto CPyL26;
    }
    CPyStatic__new___to_checksum_address = cpy_r_r62;
    CPy_INCREF(CPyStatic__new___to_checksum_address);
    cpy_r_r63 = CPyStatic__new___globals;
    cpy_r_r64 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r65 = CPyDict_SetItem(cpy_r_r63, cpy_r_r64, cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 27, CPyStatic__new___globals);
        goto CPyL26;
    }
    return 1;
CPyL26: ;
    cpy_r_r67 = 2;
    return cpy_r_r67;
CPyL27: ;
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL21;
CPyL28: ;
    CPy_DecRef(cpy_r_r43);
    CPyTagged_DecRef(cpy_r_r46);
    goto CPyL15;
CPyL29: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL26;
}
static PyMethodDef _utilsmodule_methods[] = {
    {"to_bytes", (PyCFunction)CPyPy__utils___to_bytes, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"hexstr_to_bytes", (PyCFunction)CPyPy__utils___hexstr_to_bytes, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"monkey_patch_hexbytes_utils", (PyCFunction)CPyPy__utils___monkey_patch_hexbytes_utils, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _utilsmodule = {
    PyModuleDef_HEAD_INIT,
    "evmspec._utils",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _utilsmodule_methods
};

PyObject *CPyInit_evmspec____utils(void)
{
    PyObject* modname = NULL;
    if (CPyModule_evmspec____utils_internal) {
        Py_INCREF(CPyModule_evmspec____utils_internal);
        return CPyModule_evmspec____utils_internal;
    }
    CPyModule_evmspec____utils_internal = PyModule_Create(&_utilsmodule);
    if (unlikely(CPyModule_evmspec____utils_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_evmspec____utils_internal, "__name__");
    CPyStatic__utils___globals = PyModule_GetDict(CPyModule_evmspec____utils_internal);
    if (unlikely(CPyStatic__utils___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__utils_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_evmspec____utils_internal;
    fail:
    Py_CLEAR(CPyModule_evmspec____utils_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__utils___unhexlify);
    CPyStatic__utils___unhexlify = NULL;
    return NULL;
}

PyObject *CPyDef__utils___to_bytes(PyObject *cpy_r_val) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    int32_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    int32_t cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    int32_t cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    CPyTagged cpy_r_r34;
    int64_t cpy_r_r35;
    char cpy_r_r36;
    int64_t cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    CPyTagged cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    CPyTagged cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    int32_t cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject **cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    CPyPtr cpy_r_r92;
    CPyPtr cpy_r_r93;
    CPyPtr cpy_r_r94;
    CPyPtr cpy_r_r95;
    CPyPtr cpy_r_r96;
    CPyPtr cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject **cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    cpy_r_r0 = (PyObject *)&PyBytes_Type;
    cpy_r_r1 = PyObject_IsInstance(cpy_r_val, cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 17, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL4;
    CPy_INCREF(cpy_r_val);
    if (likely(PyBytes_Check(cpy_r_val) || PyByteArray_Check(cpy_r_val)))
        cpy_r_r4 = cpy_r_val;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 18, CPyStatic__utils___globals, "bytes", cpy_r_val);
        goto CPyL57;
    }
    return cpy_r_r4;
CPyL4: ;
    cpy_r_r5 = (PyObject *)&PyUnicode_Type;
    cpy_r_r6 = PyObject_IsInstance(cpy_r_val, cpy_r_r5);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 19, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r8 = cpy_r_r6;
    if (!cpy_r_r8) goto CPyL9;
    CPy_INCREF(cpy_r_val);
    if (likely(PyUnicode_Check(cpy_r_val)))
        cpy_r_r9 = cpy_r_val;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 20, CPyStatic__utils___globals, "str", cpy_r_val);
        goto CPyL57;
    }
    cpy_r_r10 = CPyDef__utils___hexstr_to_bytes(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 20, CPyStatic__utils___globals);
        goto CPyL57;
    }
    return cpy_r_r10;
CPyL9: ;
    cpy_r_r11 = CPyModule_builtins;
    cpy_r_r12 = CPyStatics[26]; /* 'bytearray' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 21, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r14 = PyObject_IsInstance(cpy_r_val, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    cpy_r_r15 = cpy_r_r14 >= 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 21, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r16 = cpy_r_r14;
    if (!cpy_r_r16) goto CPyL15;
    cpy_r_r17 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r18[1] = {cpy_r_val};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 22, CPyStatic__utils___globals);
        goto CPyL57;
    }
    if (likely(PyBytes_Check(cpy_r_r20) || PyByteArray_Check(cpy_r_r20)))
        cpy_r_r21 = cpy_r_r20;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 22, CPyStatic__utils___globals, "bytes", cpy_r_r20);
        goto CPyL57;
    }
    return cpy_r_r21;
CPyL15: ;
    cpy_r_r22 = (PyObject *)&PyBool_Type;
    cpy_r_r23 = PyObject_IsInstance(cpy_r_val, cpy_r_r22);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 23, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r25 = cpy_r_r23;
    if (!cpy_r_r25) goto CPyL22;
    if (unlikely(!PyBool_Check(cpy_r_val))) {
        CPy_TypeError("bool", cpy_r_val); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_val == Py_True;
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 24, CPyStatic__utils___globals);
        goto CPyL57;
    }
    if (!cpy_r_r26) goto CPyL20;
    cpy_r_r27 = CPyStatics[51]; /* b'\x01' */
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28 = cpy_r_r27;
    goto CPyL21;
CPyL20: ;
    cpy_r_r29 = CPyStatics[50]; /* b'\x00' */
    CPy_INCREF(cpy_r_r29);
    cpy_r_r28 = cpy_r_r29;
CPyL21: ;
    return cpy_r_r28;
CPyL22: ;
    cpy_r_r30 = (PyObject *)&PyLong_Type;
    cpy_r_r31 = PyObject_IsInstance(cpy_r_val, cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 >= 0;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 25, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r33 = cpy_r_r31;
    if (!cpy_r_r33) goto CPyL43;
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r34 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r34 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r34 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 28, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r35 = cpy_r_r34 & 1;
    cpy_r_r36 = cpy_r_r35 != 0;
    if (cpy_r_r36) goto CPyL27;
    cpy_r_r37 = 0 & 1;
    cpy_r_r38 = cpy_r_r37 != 0;
    if (!cpy_r_r38) goto CPyL28;
CPyL27: ;
    cpy_r_r39 = CPyTagged_IsLt_(cpy_r_r34, 0);
    cpy_r_r40 = cpy_r_r39;
    goto CPyL29;
CPyL28: ;
    cpy_r_r41 = (Py_ssize_t)cpy_r_r34 < (Py_ssize_t)0;
    cpy_r_r40 = cpy_r_r41;
CPyL29: ;
    CPyTagged_DECREF(cpy_r_r34);
    if (!cpy_r_r40) goto CPyL37;
    cpy_r_r42 = CPyStatics[27]; /* 'Cannot convert negative integer ' */
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r43 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r43 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r43 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r44 = CPyTagged_Str(cpy_r_r43);
    CPyTagged_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r45 = CPyStatics[28]; /* ' to bytes' */
    cpy_r_r46 = CPyStr_Build(3, cpy_r_r42, cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r47 = CPyModule_builtins;
    cpy_r_r48 = CPyStatics[8]; /* 'ValueError' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r50[1] = {cpy_r_r46};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_Vectorcall(cpy_r_r49, cpy_r_r51, 1, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r46);
    CPy_Raise(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 29, CPyStatic__utils___globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL37: ;
    if (likely(PyLong_Check(cpy_r_val)))
        cpy_r_r53 = CPyTagged_FromObject(cpy_r_val);
    else {
        CPy_TypeError("int", cpy_r_val); cpy_r_r53 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r53 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r54 = CPyModule_builtins;
    cpy_r_r55 = CPyStatics[29]; /* 'hex' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL59;
    }
    cpy_r_r57 = CPyTagged_StealAsObject(cpy_r_r53);
    PyObject *cpy_r_r58[1] = {cpy_r_r57};
    cpy_r_r59 = (PyObject **)&cpy_r_r58;
    cpy_r_r60 = PyObject_Vectorcall(cpy_r_r56, cpy_r_r59, 1, 0);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL60;
    }
    CPy_DECREF(cpy_r_r57);
    if (likely(PyUnicode_Check(cpy_r_r60)))
        cpy_r_r61 = cpy_r_r60;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals, "str", cpy_r_r60);
        goto CPyL57;
    }
    cpy_r_r62 = CPyDef__utils___to_bytes(cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 31, CPyStatic__utils___globals);
        goto CPyL57;
    }
    return cpy_r_r62;
CPyL43: ;
    cpy_r_r63 = CPyModule_builtins;
    cpy_r_r64 = CPyStatics[30]; /* 'memoryview' */
    cpy_r_r65 = CPyObject_GetAttr(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 32, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r66 = PyObject_IsInstance(cpy_r_val, cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    cpy_r_r67 = cpy_r_r66 >= 0;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 32, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r68 = cpy_r_r66;
    if (!cpy_r_r68) goto CPyL49;
    cpy_r_r69 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r70[1] = {cpy_r_val};
    cpy_r_r71 = (PyObject **)&cpy_r_r70;
    cpy_r_r72 = PyObject_Vectorcall(cpy_r_r69, cpy_r_r71, 1, 0);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 33, CPyStatic__utils___globals);
        goto CPyL57;
    }
    if (likely(PyBytes_Check(cpy_r_r72) || PyByteArray_Check(cpy_r_r72)))
        cpy_r_r73 = cpy_r_r72;
    else {
        CPy_TypeErrorTraceback("evmspec/_utils.py", "to_bytes", 33, CPyStatic__utils___globals, "bytes", cpy_r_r72);
        goto CPyL57;
    }
    return cpy_r_r73;
CPyL49: ;
    cpy_r_r74 = CPyStatics[31]; /* '' */
    cpy_r_r75 = CPyStatics[32]; /* 'Cannot convert ' */
    cpy_r_r76 = CPyStatics[33]; /* '{!r:{}}' */
    cpy_r_r77 = CPyStatics[31]; /* '' */
    cpy_r_r78 = CPyStatics[34]; /* 'format' */
    PyObject *cpy_r_r79[3] = {cpy_r_r76, cpy_r_val, cpy_r_r77};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = PyObject_VectorcallMethod(cpy_r_r78, cpy_r_r80, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r82 = CPyStatics[35]; /* ' of type ' */
    cpy_r_r83 = CPyStatics[36]; /* '{:{}}' */
    cpy_r_r84 = PyObject_Type(cpy_r_val);
    cpy_r_r85 = CPyStatics[31]; /* '' */
    cpy_r_r86 = CPyStatics[34]; /* 'format' */
    PyObject *cpy_r_r87[3] = {cpy_r_r83, cpy_r_r84, cpy_r_r85};
    cpy_r_r88 = (PyObject **)&cpy_r_r87;
    cpy_r_r89 = PyObject_VectorcallMethod(cpy_r_r86, cpy_r_r88, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL61;
    }
    CPy_DECREF(cpy_r_r84);
    cpy_r_r90 = CPyStatics[28]; /* ' to bytes' */
    cpy_r_r91 = PyList_New(5);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL62;
    }
    cpy_r_r92 = (CPyPtr)&((PyListObject *)cpy_r_r91)->ob_item;
    cpy_r_r93 = *(CPyPtr *)cpy_r_r92;
    CPy_INCREF(cpy_r_r75);
    *(PyObject * *)cpy_r_r93 = cpy_r_r75;
    cpy_r_r94 = cpy_r_r93 + 8;
    *(PyObject * *)cpy_r_r94 = cpy_r_r81;
    CPy_INCREF(cpy_r_r82);
    cpy_r_r95 = cpy_r_r93 + 16;
    *(PyObject * *)cpy_r_r95 = cpy_r_r82;
    cpy_r_r96 = cpy_r_r93 + 24;
    *(PyObject * *)cpy_r_r96 = cpy_r_r89;
    CPy_INCREF(cpy_r_r90);
    cpy_r_r97 = cpy_r_r93 + 32;
    *(PyObject * *)cpy_r_r97 = cpy_r_r90;
    cpy_r_r98 = PyUnicode_Join(cpy_r_r74, cpy_r_r91);
    CPy_DECREF_NO_IMM(cpy_r_r91);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL57;
    }
    cpy_r_r99 = CPyModule_builtins;
    cpy_r_r100 = CPyStatics[37]; /* 'TypeError' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL63;
    }
    PyObject *cpy_r_r102[1] = {cpy_r_r98};
    cpy_r_r103 = (PyObject **)&cpy_r_r102;
    cpy_r_r104 = PyObject_Vectorcall(cpy_r_r101, cpy_r_r103, 1, 0);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL63;
    }
    CPy_DECREF(cpy_r_r98);
    CPy_Raise(cpy_r_r104);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_utils.py", "to_bytes", 35, CPyStatic__utils___globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL57: ;
    cpy_r_r105 = NULL;
    return cpy_r_r105;
CPyL58: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL57;
CPyL59: ;
    CPyTagged_DecRef(cpy_r_r53);
    goto CPyL57;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL57;
CPyL61: ;
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r84);
    goto CPyL57;
CPyL62: ;
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r89);
    goto CPyL57;
CPyL63: ;
    CPy_DecRef(cpy_r_r98);
    goto CPyL57;
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
    if (arg_val != NULL) goto __LL2;
    arg_val = obj_val;
    if (arg_val != NULL) goto __LL2;
    if (PyBytes_Check(obj_val) || PyByteArray_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL2;
    if (PyLong_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL2;
    if (PyUnicode_Check(obj_val))
        arg_val = obj_val;
    else {
        arg_val = NULL;
    }
    if (arg_val != NULL) goto __LL2;
    CPy_TypeError("union[bool, object, bytes, int, str]", obj_val); 
    goto fail;
__LL2: ;
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
    cpy_r_r1 = CPyStatics[38]; /* '0X' */
    CPy_INCREF(cpy_r_r0);
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = PyTuple_New(2);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = cpy_r_r2.f0;
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp3);
    PyObject *__tmp4 = cpy_r_r2.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp4);
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
    cpy_r_r12 = CPyStatics[39]; /* '0' */
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
    cpy_r_r17 = CPyStatics[40]; /* 'UnicodeDecodeError' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "hexstr_to_bytes", 52, CPyStatic__utils___globals);
        goto CPyL34;
    }
    cpy_r_r19 = CPy_ExceptionMatches(cpy_r_r18);
    CPy_DecRef(cpy_r_r18);
    if (!cpy_r_r19) goto CPyL35;
    cpy_r_r20 = CPyStatics[41]; /* 'hex string ' */
    cpy_r_r21 = CPyStatics[42]; /* ' may only contain [0-9a-fA-F] characters' */
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
    cpy_r_r4 = CPyStatics[43]; /* 'hexbytes._utils' */
    cpy_r_r5 = PyImport_Import(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 62, CPyStatic__utils___globals);
        goto CPyL17;
    }
    CPyModule_hexbytes____utils = cpy_r_r5;
    CPy_INCREF(CPyModule_hexbytes____utils);
    CPy_DECREF(cpy_r_r5);
CPyL3: ;
    cpy_r_r6 = CPyStatics[44]; /* 'hexbytes' */
    cpy_r_r7 = PyImport_GetModuleDict();
    cpy_r_r8 = CPyStatics[44]; /* 'hexbytes' */
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
    cpy_r_r16 = CPyStatics[45]; /* 'hexbytes.main' */
    cpy_r_r17 = PyImport_Import(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 63, CPyStatic__utils___globals);
        goto CPyL17;
    }
    CPyModule_hexbytes___main = cpy_r_r17;
    CPy_INCREF(CPyModule_hexbytes___main);
    CPy_DECREF(cpy_r_r17);
CPyL8: ;
    cpy_r_r18 = CPyStatics[44]; /* 'hexbytes' */
    cpy_r_r19 = PyImport_GetModuleDict();
    cpy_r_r20 = CPyStatics[44]; /* 'hexbytes' */
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
    cpy_r_r39 = CPyStatics[46]; /* 'hexstr_to_bytes' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "monkey_patch_hexbytes_utils", 68, CPyStatic__utils___globals);
        goto CPyL17;
    }
    cpy_r_r41 = CPyModule_hexbytes____utils;
    cpy_r_r42 = CPyStatics[46]; /* 'hexstr_to_bytes' */
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
    cpy_r_r10 = CPyStatics[58]; /* (('binascii', 'binascii', 'binascii'),) */
    cpy_r_r11 = CPyStatic__utils___globals;
    cpy_r_r12 = CPyStatics[48]; /* 'evmspec/_utils.py' */
    cpy_r_r13 = CPyStatics[17]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL8;
    cpy_r_r15 = CPyStatics[59]; /* ('Final', 'Union') */
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
    cpy_r_r20 = CPyStatics[49]; /* 'unhexlify' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("evmspec/_utils.py", "<module>", 7, CPyStatic__utils___globals);
        goto CPyL8;
    }
    CPyStatic__utils___unhexlify = cpy_r_r21;
    CPy_INCREF(CPyStatic__utils___unhexlify);
    cpy_r_r22 = CPyStatic__utils___globals;
    cpy_r_r23 = CPyStatics[49]; /* 'unhexlify' */
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

PyObject *CPyStatics[60];
const char * const CPyLit_Str[] = {
    "\a\a__new__\0020x\r_check_hexstr\bKeyError\016 is too long: \nValueError\bbuiltins",
    "\b\005Final\004Type\aTypeVar\005Union\006typing\tcchecksum\017evmspec/_new.py\b<module>",
    "\006\nAnyAddress\neth_typing\bto_bytes\016evmspec._utils\003__T\016ONE_EMPTY_BYTE",
    "\003\rMISSING_BYTES\023to_checksum_address\tbytearray",
    "\005 Cannot convert negative integer \t to bytes\003hex\nmemoryview\000",
    "\b\017Cannot convert \a{!r:{}}\006format\t of type \005{:{}}\tTypeError\0020X\0010",
    "\002\022UnicodeDecodeError\vhex string ",
    "\003( may only contain [0-9a-fA-F] characters\017hexbytes._utils\bhexbytes",
    "\005\rhexbytes.main\017hexstr_to_bytes\bbinascii\021evmspec/_utils.py\tunhexlify",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\002\001\000\001\001",
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    8, 4, 10, 11, 12, 13, 3, 15, 15, 15, 1, 53, 1, 18, 1, 20, 3, 47, 47,
    47, 1, 57, 2, 10, 13
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_evmspec____new_internal = NULL;
CPyModule *CPyModule_evmspec____new;
PyObject *CPyStatic__new___globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_cchecksum;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_evmspec____utils_internal = NULL;
CPyModule *CPyModule_evmspec____utils;
PyObject *CPyStatic__utils___globals;
CPyModule *CPyModule_binascii;
CPyModule *CPyModule_hexbytes____utils;
CPyModule *CPyModule_hexbytes___main;
PyObject *CPyStatic__new___ONE_EMPTY_BYTE = NULL;
PyObject *CPyStatic__new___MISSING_BYTES = NULL;
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

static struct export_table_77f6a255293717708ca2 exports = {
    &CPyStatic__new___ONE_EMPTY_BYTE,
    &CPyStatic__new___MISSING_BYTES,
    &CPyStatic__new___to_checksum_address,
    &CPyDef__new___Address,
    &CPyDef__new___HexBytes32,
    &CPyDef__new_____top_level__,
    &CPyStatic__utils___unhexlify,
    &CPyDef__utils___to_bytes,
    &CPyDef__utils___hexstr_to_bytes,
    &CPyDef__utils___monkey_patch_hexbytes_utils,
    &CPyDef__utils_____top_level__,
};

PyMODINIT_FUNC PyInit_77f6a255293717708ca2__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "77f6a255293717708ca2__mypyc", NULL, -1, NULL, NULL };
    int res;
    PyObject *capsule;
    PyObject *tmp;
    static PyObject *module;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&def);
    if (!module) {
        goto fail;
    }
    
    capsule = PyCapsule_New(&exports, "77f6a255293717708ca2__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
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
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
