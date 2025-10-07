#ifndef DIFFCHECK_PLACEHOLDER
#define DIFFCHECK_PLACEHOLDER 0
#endif
#include <Python.h>

PyMODINIT_FUNC
PyInit__new(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("evmspec._new__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_evmspec____new");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "evmspec._new__mypyc.init_evmspec____new");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__new(); }
