#include <Python.h>
#include <math.h>

static PyObject *plus(PyObject *self, PyObject *args){ /* ��������� */
    PyObject* list;
    int i, n;
    double res;
    double newElement;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - ��������� ���������� ������� � ������������ ���� ������ Python � ���� ������ C.
    ������ �������� PyObject, ������ ���������� ������� ����������,  ������ - ��� ���������� � ������� �� ����� ������������� ���� ���������
    ("O" - ������������ ��������, �� ���� ����� ����������� ������ Python (��� ������-���� ��������������) � ��������� ������� C). ����� ���� ����
    ����������� � ������� �� ��������� ��������������� ��������. ����� �������������� ��������, ��������� �� ���������� �������. */
        return NULL;
    }
    /*�������������� ������ �� PyObject � ��� ������ � � */
	n = PyList_GET_SIZE(list); /*����� ������� ������ � list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* ���������� ������ �� i-� ������� list */
	    res = PyFloat_AsDouble(item); /* ���������� double ������������� �������� item */
	    a[i] = res;
    }

    for (i = 0; i < 2; i++){
            b[i]=a[i]+a[i+2];
        }

    PyObject *my_list = PyList_New(n/2); /* ������� ������ �������� ���� PyObject ����� n, ������ ��������� �� ������ ������� ������� ����� n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* ������������� ������� � ������ my_list �� ������ i, ����� ����  ������� ������ PyFloatObject �� a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *minus(PyObject *self, PyObject *args){ /*���������*/
    PyObject* list;
    int n;
    int i;
    double res;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - ��������� ���������� ������� � ������������ ���� ������ Python � ���� ������ C.
    ������ �������� PyObject, ������ ���������� ������� ����������,  ������ - ��� ���������� � ������� �� ����� ������������� ���� ���������
    ("O" - ������������ ��������, �� ���� ����� ����������� ������ Python (��� ������-���� ��������������) � ��������� ������� C). ����� ���� ����
    ����������� � ������� �� ��������� ��������������� ��������. ����� �������������� ��������, ��������� �� ���������� �������. */
        return NULL;
    }
    /*�������������� ������ �� PyObject � ��� ������ � � */
	n = PyList_GET_SIZE(list); /*����� ������� ������ � list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* ���������� ������ �� i-� ������� list */
	    res = PyFloat_AsDouble(item); /* ���������� double ������������� �������� item */
	    a[i] = res;
    }

    for (i = 0; i < 2; i++){
            b[i]=a[i]-a[i+2];
        }

    PyObject *my_list = PyList_New(n/2); /* ������� ������ �������� ���� PyObject ����� n, ������ ��������� �� ������ ������� ������� ����� n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* ������������� ������� � ������ my_list �� ������ i, ����� ����  ������� ������ PyFloatObject �� a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *times(PyObject *self, PyObject *args){ /*���������*/
    PyObject* list;
    int n;
    int i;
    double res;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - ��������� ���������� ������� � ������������ ���� ������ Python � ���� ������ C.
    ������ �������� PyObject, ������ ���������� ������� ����������,  ������ - ��� ���������� � ������� �� ����� ������������� ���� ���������
    ("O" - ������������ ��������, �� ���� ����� ����������� ������ Python (��� ������-���� ��������������) � ��������� ������� C). ����� ���� ����
    ����������� � ������� �� ��������� ��������������� ��������. ����� �������������� ��������, ��������� �� ���������� �������. */
        return NULL;
    }
    /*�������������� ������ �� PyObject � ��� ������ � � */
	n = PyList_GET_SIZE(list); /*����� ������� ������ � list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* ���������� ������ �� i-� ������� list */
	    res = PyFloat_AsDouble(item); /* ���������� double ������������� �������� item */
	    a[i] = res;
    }
    b[0]=a[0]*a[2]-a[1]*a[3];
    b[1]=a[0]*a[3]+a[1]*a[2];

    PyObject *my_list = PyList_New(n/2); /* ������� ������ �������� ���� PyObject ����� n, ������ ��������� �� ������ ������� ������� ����� n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* ������������� ������� � ������ my_list �� ������ i, ����� ����  ������� ������ PyFloatObject �� a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *divide(PyObject *self, PyObject *args){ /*�������*/
    PyObject* list;
    int n;
    int i;
    double res, len;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - ��������� ���������� ������� � ������������ ���� ������ Python � ���� ������ C.
    ������ �������� PyObject, ������ ���������� ������� ����������,  ������ - ��� ���������� � ������� �� ����� ������������� ���� ���������
    ("O" - ������������ ��������, �� ���� ����� ����������� ������ Python (��� ������-���� ��������������) � ��������� ������� C). ����� ���� ����
    ����������� � ������� �� ��������� ��������������� ��������. ����� �������������� ��������, ��������� �� ���������� �������. */
        return NULL;
    }
    /*�������������� ������ �� PyObject � ��� ������ � � */
	n = PyList_GET_SIZE(list); /*����� ������� ������ � list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* ���������� ������ �� i-� ������� list */
	    res = PyFloat_AsDouble(item); /* ���������� double ������������� �������� item */
	    a[i] = res;
    }
    len = pow(a[2],2) + pow(a[3],2);
    b[0]=(a[0]*a[2]+a[1]*a[3])/len;
    b[1]=(a[1]*a[2]-a[0]*a[3])/len;

    PyObject *my_list = PyList_New(n/2); /* ������� ������ �������� ���� PyObject ����� n, ������ ��������� �� ������ ������� ������� ����� n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* ������������� ������� � ������ my_list �� ������ i, ����� ����  ������� ������ PyFloatObject �� a[i]*/
    return my_list;
    free(a);
    free(b);
}

/* ������ ��������, ����������� ������ ������ */
static PyMethodDef ownmod_methods[] = {
    {
	"plus", /* �������� ������� ������ python */
	plus, /* ������� C */
	 METH_VARARGS, /* ������, ����������, ��� ������� � ��� � ����������� */
	"plus" /* ������������ ��� ������� ������ python */
    },
    {
	"minus", /* �������� ������� ������ python */
	minus, /* ������� C */
	 METH_VARARGS, /* ������, ����������, ��� ������� � ��� � ����������� */
	"minus" /* ������������ ��� ������� ������ python */
    },
    {
	"times", /* �������� ������� ������ python */
	times, /* ������� C */
	 METH_VARARGS, /* ������, ����������, ��� ������� � ��� � ����������� */
	"times" /* ������������ ��� ������� ������ python */
    },
    {
	"divide", /* �������� ������� ������ python */
	divide, /* ������� C */
	 METH_VARARGS, /* ������, ����������, ��� ������� � ��� � ����������� */
	"divide" /* ������������ ��� ������� ������ python */
    },
    { NULL, NULL, 0, NULL }
};


/* C��������, ������� ��������� ��������������� ��� ������ */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT, /* ������������ ������ */
    "complexNumbers", /* complexnumbers.__name__ */
    "services with Complex numbers: plus, minus, times, divide", /* complexNumbers.__doc__ */
    -1,
    ownmod_methods, /* �������� ������ � �������� ������ */
    NULL,NULL,NULL
};


/* �������� ������ ������ */
PyMODINIT_FUNC PyInit_complexNumbers(void)
{
    PyObject* m;
    /* ������� ������ */
    m = PyModule_Create(&simple_module);
    /* ���� ��� ���������, �� ��� �������� �� �������� */
    if (m == NULL)
        return NULL;
    return m;
}
