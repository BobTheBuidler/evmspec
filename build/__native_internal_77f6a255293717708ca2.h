#ifndef MYPYC_NATIVE_INTERNAL_77f6a255293717708ca2_H
#define MYPYC_NATIVE_INTERNAL_77f6a255293717708ca2_H
#include <Python.h>
#include <CPy.h>
#include "__native_77f6a255293717708ca2.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[60];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_evmspec____new_internal;
extern CPyModule *CPyModule_evmspec____new;
extern PyObject *CPyStatic__new___globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_cchecksum;
extern CPyModule *CPyModule_eth_typing;
extern CPyModule *CPyModule_evmspec____utils_internal;
extern CPyModule *CPyModule_evmspec____utils;
extern PyObject *CPyStatic__utils___globals;
extern CPyModule *CPyModule_binascii;
extern CPyModule *CPyModule_hexbytes____utils;
extern CPyModule *CPyModule_hexbytes___main;
extern PyObject *CPyStatic__new___ONE_EMPTY_BYTE;
extern PyObject *CPyStatic__new___MISSING_BYTES;
extern PyObject *CPyStatic__new___to_checksum_address;
extern PyObject *CPyDef__new___Address(PyObject *cpy_r_cls, PyObject *cpy_r_address);
extern PyObject *CPyPy__new___Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef__new___HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v);
extern PyObject *CPyPy__new___HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef__new_____top_level__(void);
extern PyObject *CPyStatic__utils___unhexlify;
extern PyObject *CPyDef__utils___to_bytes(PyObject *cpy_r_val);
extern PyObject *CPyPy__utils___to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef__utils___hexstr_to_bytes(PyObject *cpy_r_hexstr);
extern PyObject *CPyPy__utils___hexstr_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef__utils___monkey_patch_hexbytes_utils(void);
extern PyObject *CPyPy__utils___monkey_patch_hexbytes_utils(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef__utils_____top_level__(void);
#endif
