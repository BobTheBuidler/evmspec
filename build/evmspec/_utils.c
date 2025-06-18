#include <Python.h>

PyMODINIT_FUNC
PyInit__utils(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("77f6a255293717708ca2__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_evmspec____utils");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "77f6a255293717708ca2__mypyc.init_evmspec____utils");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__utils(); }
