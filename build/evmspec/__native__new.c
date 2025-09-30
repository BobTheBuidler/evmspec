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
    CPy_XDECREF(CPyStatic_MISSING_BYTES);
    CPyStatic_MISSING_BYTES = NULL;
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
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_Unreachable();
CPyL3: ;
    PyObject *cpy_r_r3[1] = {cpy_r_address};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r1, cpy_r_r4, 1, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic_globals);
        goto CPyL7;
    }
    if (likely(PyUnicode_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "Address", 31, CPyStatic_globals, "str", cpy_r_r5);
        goto CPyL7;
    }
    cpy_r_r7 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r8[3] = {cpy_r_r0, cpy_r_cls, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "Address", 31, CPyStatic_globals);
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
    CPy_AddTraceback("evmspec/_new.py", "Address", 30, CPyStatic_globals);
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
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
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
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 37, CPyStatic_globals, "str", cpy_r_v);
        goto CPyL33;
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
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 38, CPyStatic_globals, "str", cpy_r_v);
        goto CPyL33;
    }
    cpy_r_r6 = CPyStatics[5]; /* '_check_hexstr' */
    PyObject *cpy_r_r7[2] = {cpy_r_cls, cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r6, cpy_r_r8, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 38, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL35;
CPyL5: ;
    CPy_DECREF(cpy_r_r5);
CPyL6: ;
    cpy_r_r10 = CPyStatic_globals;
    cpy_r_r11 = CPyStatics[6]; /* 'to_bytes' */
    cpy_r_r12 = CPyDict_GetItem(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 40, CPyStatic_globals);
        goto CPyL33;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_v};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 40, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r16 = CPyStatic_MISSING_BYTES;
    if (likely(cpy_r_r16 != NULL)) goto CPyL12;
    PyErr_SetString(PyExc_NameError, "value for final name \"MISSING_BYTES\" was not set");
    cpy_r_r17 = 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic_globals);
        goto CPyL16;
    } else
        goto CPyL36;
CPyL11: ;
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r18 = CPyObject_Size(cpy_r_r15);
    if (unlikely(cpy_r_r18 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r19 = CPySequenceTuple_GetItem(cpy_r_r16, cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic_globals);
        goto CPyL16;
    }
    if (likely(PyBytes_Check(cpy_r_r19) || PyByteArray_Check(cpy_r_r19)))
        cpy_r_r20 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "HexBytes32", 42, CPyStatic_globals, "bytes", cpy_r_r19);
        goto CPyL16;
    }
    goto CPyL30;
CPyL16: ;
    cpy_r_r21 = CPy_CatchError();
    cpy_r_r22 = CPyModule_builtins;
    cpy_r_r23 = CPyStatics[7]; /* 'KeyError' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 43, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r25 = CPy_ExceptionMatches(cpy_r_r24);
    CPy_DecRef(cpy_r_r24);
    if (!cpy_r_r25) goto CPyL38;
    cpy_r_r26 = CPy_GetExcValue();
    CPy_DecRef(cpy_r_r26);
    cpy_r_r27 = PyObject_Repr(cpy_r_v);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r28 = CPyStatics[8]; /* ' is too long: ' */
    cpy_r_r29 = CPyObject_Size(cpy_r_r15);
    CPy_DecRef(cpy_r_r15);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r30 = CPyTagged_Str(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r31 = CPyStr_Build(3, cpy_r_r27, cpy_r_r28, cpy_r_r30);
    CPy_DecRef(cpy_r_r27);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r32 = CPyModule_builtins;
    cpy_r_r33 = CPyStatics[9]; /* 'ValueError' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL40;
    }
    PyObject *cpy_r_r35[1] = {cpy_r_r31};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, 0);
    CPy_DecRef(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_DecRef(cpy_r_r31);
    CPy_Raise(cpy_r_r37);
    CPy_DecRef(cpy_r_r37);
    if (unlikely(!0)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 44, CPyStatic_globals);
        goto CPyL28;
    } else
        goto CPyL41;
CPyL25: ;
    CPy_Unreachable();
CPyL26: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL28;
    } else
        goto CPyL42;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    cpy_r_r38 = CPy_KeepPropagating();
    if (!cpy_r_r38) goto CPyL33;
    CPy_Unreachable();
CPyL30: ;
    cpy_r_r39 = (PyObject *)&PyBytes_Type;
    cpy_r_r40 = PyNumber_Add(cpy_r_r20, cpy_r_r15);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 45, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r41 = CPyStatics[3]; /* '__new__' */
    PyObject *cpy_r_r42[3] = {cpy_r_r39, cpy_r_cls, cpy_r_r40};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r43, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 45, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_DECREF(cpy_r_r40);
    return cpy_r_r44;
CPyL33: ;
    cpy_r_r45 = NULL;
    return cpy_r_r45;
CPyL34: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL33;
CPyL35: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL5;
CPyL36: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL11;
CPyL37: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL28;
CPyL38: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL26;
CPyL39: ;
    CPy_DecRef(cpy_r_r27);
    goto CPyL28;
CPyL40: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL28;
CPyL41: ;
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL25;
CPyL42: ;
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL27;
CPyL43: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL33;
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
    PyObject *retval = CPyDef_HexBytes32(arg_cls, arg_v);
    return retval;
fail: ;
    CPy_AddTraceback("evmspec/_new.py", "HexBytes32", 34, CPyStatic_globals);
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
    cpy_r_r3 = CPyStatics[10]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", -1, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[27]; /* ('Final', 'Type', 'TypeVar', 'Union') */
    cpy_r_r6 = CPyStatics[15]; /* 'typing' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 1, CPyStatic_globals);
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
    cpy_r_r14 = CPyStatics[29]; /* (('cchecksum', 'cchecksum', 'cchecksum'),) */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[17]; /* 'evmspec/_new.py' */
    cpy_r_r17 = CPyStatics[18]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL26;
    cpy_r_r19 = CPyStatics[30]; /* ('AnyAddress',) */
    cpy_r_r20 = CPyStatics[20]; /* 'eth_typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 4, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_eth_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[31]; /* ('to_bytes',) */
    cpy_r_r24 = CPyStatics[21]; /* 'evmspec._utils' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 6, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_evmspec____utils = cpy_r_r26;
    CPy_INCREF(CPyModule_evmspec____utils);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[22]; /* '__T' */
    cpy_r_r28 = CPyStatic_globals;
    cpy_r_r29 = CPyStatics[13]; /* 'TypeVar' */
    cpy_r_r30 = CPyDict_GetItem(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL26;
    }
    PyObject *cpy_r_r31[1] = {cpy_r_r27};
    cpy_r_r32 = (PyObject **)&cpy_r_r31;
    cpy_r_r33 = PyObject_Vectorcall(cpy_r_r30, cpy_r_r32, 1, 0);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[22]; /* '__T' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 9, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r38 = CPyStatics[26]; /* b'\x00' */
    CPyStatic_ONE_EMPTY_BYTE = cpy_r_r38;
    CPy_INCREF(CPyStatic_ONE_EMPTY_BYTE);
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyStatics[23]; /* 'ONE_EMPTY_BYTE' */
    cpy_r_r41 = CPyDict_SetItem(cpy_r_r39, cpy_r_r40, cpy_r_r38);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 12, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r43 = PyList_New(0);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r44 = 0;
    cpy_r_i = cpy_r_r44;
CPyL13: ;
    cpy_r_r45 = (Py_ssize_t)cpy_r_r44 < (Py_ssize_t)66;
    if (!cpy_r_r45) goto CPyL27;
    cpy_r_r46 = CPyTagged_Subtract(64, cpy_r_i);
    CPyTagged_DECREF(cpy_r_i);
    cpy_r_r47 = CPyStatic_ONE_EMPTY_BYTE;
    if (unlikely(cpy_r_r47 == NULL)) {
        goto CPyL28;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ONE_EMPTY_BYTE\" was not set");
    cpy_r_r48 = 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r49 = CPyTagged_StealAsObject(cpy_r_r46);
    cpy_r_r50 = PyNumber_Multiply(cpy_r_r49, cpy_r_r47);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
        goto CPyL29;
    }
    if (likely(PyBytes_Check(cpy_r_r50) || PyByteArray_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals, "bytes", cpy_r_r50);
        goto CPyL29;
    }
    cpy_r_r52 = PyList_Append(cpy_r_r43, cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
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
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
        goto CPyL26;
    }
    CPyStatic_MISSING_BYTES = cpy_r_r55;
    CPy_INCREF(CPyStatic_MISSING_BYTES);
    cpy_r_r56 = CPyStatic_globals;
    cpy_r_r57 = CPyStatics[24]; /* 'MISSING_BYTES' */
    cpy_r_r58 = CPyDict_SetItem(cpy_r_r56, cpy_r_r57, cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 14, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r60 = CPyModule_cchecksum;
    cpy_r_r61 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 27, CPyStatic_globals);
        goto CPyL26;
    }
    CPyStatic_to_checksum_address = cpy_r_r62;
    CPy_INCREF(CPyStatic_to_checksum_address);
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyStatics[25]; /* 'to_checksum_address' */
    cpy_r_r65 = CPyDict_SetItem(cpy_r_r63, cpy_r_r64, cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("evmspec/_new.py", "<module>", 27, CPyStatic_globals);
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
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[32];
const char * const CPyLit_Str[] = {
    "\a\a__new__\0020x\r_check_hexstr\bto_bytes\bKeyError\016 is too long: \nValueError",
    "\b\bbuiltins\005Final\004Type\aTypeVar\005Union\006typing\tcchecksum\017evmspec/_new.py",
    "\006\b<module>\nAnyAddress\neth_typing\016evmspec._utils\003__T\016ONE_EMPTY_BYTE",
    "\002\rMISSING_BYTES\023to_checksum_address",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\001\001\000",
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {5, 4, 11, 12, 13, 14, 3, 16, 16, 16, 1, 28, 1, 19, 1, 6};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_evmspec____new__internal = NULL;
CPyModule *CPyModule_evmspec____new;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_cchecksum;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_evmspec____utils;
PyObject *CPyStatic_ONE_EMPTY_BYTE = NULL;
PyObject *CPyStatic_MISSING_BYTES = NULL;
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
