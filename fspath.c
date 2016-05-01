/*
    Return the file system path of the object.

    If the object is str or bytes, then allow it to pass through with
    an incremented refcount. All other types raise a TypeError.
*/
PyObject *
PyOS_RawFSPath(PyObject *path)
{
    if (PyObject_HasAttrString(path, "__fspath__")) {
        path = PyObject_CallMethodObjArgs(path, "__fspath__", NULL);
        if (path == NULL) {
            return NULL;
        }
    }
    else {
        Py_INCREF(path);
    }

    if (!PyUnicode_Check(path) && !PyBytes_Check(path)) {
        Py_DECREF(path);
        return PyErr_Format(PyExc_TypeError,
                            "expected a string, bytes, or path object, not %S",
                            path->ob_type);
    }

    return path;
}
