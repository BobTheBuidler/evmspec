#ifndef MYPYC_LIBRT_INTERNAL_evmspec____new_H
#define MYPYC_LIBRT_INTERNAL_evmspec____new_H
#include <Python.h>
#include <CPy.h>
#include "__native__new.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[33];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_evmspec____new__internal;
extern CPyModule *CPyModule_evmspec____new;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_cchecksum;
extern CPyModule *CPyModule_faster_hexbytes____utils;
extern CPyModule *CPyModule_eth_typing;
extern PyObject *CPyStatic_ONE_EMPTY_BYTE;
extern PyObject *CPyStatic_MISSING_BYTES;
extern PyObject *CPyStatic_to_bytes;
extern PyObject *CPyStatic_to_checksum_address;
extern PyObject *CPyDef_Address(PyObject *cpy_r_cls, PyObject *cpy_r_address);
extern PyObject *CPyPy_Address(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HexBytes32(PyObject *cpy_r_cls, PyObject *cpy_r_v);
extern PyObject *CPyPy_HexBytes32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
