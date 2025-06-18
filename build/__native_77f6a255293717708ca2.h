#ifndef MYPYC_NATIVE_77f6a255293717708ca2_H
#define MYPYC_NATIVE_77f6a255293717708ca2_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif


struct export_table_77f6a255293717708ca2 {
    PyObject **CPyStatic__new___ONE_EMPTY_BYTE;
    PyObject **CPyStatic__new___MISSING_BYTES;
    PyObject **CPyStatic__new___to_checksum_address;
    PyObject *(*CPyDef__new___Address)(PyObject *cpy_r_cls, PyObject *cpy_r_address);
    PyObject *(*CPyDef__new___HexBytes32)(PyObject *cpy_r_cls, PyObject *cpy_r_v);
    char (*CPyDef__new_____top_level__)(void);
    PyObject **CPyStatic__utils___unhexlify;
    PyObject *(*CPyDef__utils___to_bytes)(PyObject *cpy_r_val);
    PyObject *(*CPyDef__utils___hexstr_to_bytes)(PyObject *cpy_r_hexstr);
    char (*CPyDef__utils___monkey_patch_hexbytes_utils)(void);
    char (*CPyDef__utils_____top_level__)(void);
};
#endif
