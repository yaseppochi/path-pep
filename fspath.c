/*
    Return the file system path of the object.

    If a value other than a string is found, raise TypeError.
    Returns a new reference.
*/
PyObject *
PyOS_FSPath(PyObject *path)
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

    if (!PyUnicode_Check(path)) {
        Py_DECREF(path);
        return PyErr_Format(PyExc_TypeError,
                            "expected a string or path object, not %S",
                            path->ob_type);
    }
    else {
        return path;
    }
}