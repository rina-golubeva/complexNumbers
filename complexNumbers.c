#include <Python.h>
#include <math.h>

static PyObject *plus(PyObject *self, PyObject *args){ /* обработка */
    PyObject* list;
    int i, n;
    double res;
    double newElement;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - обработка аргументов функции и трасформация типы данных Python в типы данных C.
    Первый агрумент PyObject, кортеж переданных функции аргументов,  второй - тип переменных в которые мы хотим преобразовать наши аргументы
    ("O" - произвольный агрумент, то есть будет сохраняться объект Python (без какого-либо преобразования) в указателе объекта C). Далее идут сами
    переменныке в которые мы сохраняем преобразованные значения. Также осуществляется проверка, корректно ли отработала функция. */
        return NULL;
    }
    /*Преобразование данных из PyObject в наш массив в С */
	n = PyList_GET_SIZE(list); /*Длина объекта списка в list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* Возвращает ссылку на i-й элемент list */
	    res = PyFloat_AsDouble(item); /* Возвращает double представление элемента item */
	    a[i] = res;
    }

    for (i = 0; i < 2; i++){
            b[i]=a[i]+a[i+2];
        }

    PyObject *my_list = PyList_New(n/2); /* Создаем массив объектов типа PyObject длины n, точнее указатель на первый элемент массива длины n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* Устанавливает элемент в список my_list на индекс i, перед этим  создаем объект PyFloatObject из a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *minus(PyObject *self, PyObject *args){ /*вычитание*/
    PyObject* list;
    int n;
    int i;
    double res;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - обработка аргументов функции и трасформация типы данных Python в типы данных C.
    Первый агрумент PyObject, кортеж переданных функции аргументов,  второй - тип переменных в которые мы хотим преобразовать наши аргументы
    ("O" - произвольный агрумент, то есть будет сохраняться объект Python (без какого-либо преобразования) в указателе объекта C). Далее идут сами
    переменныке в которые мы сохраняем преобразованные значения. Также осуществляется проверка, корректно ли отработала функция. */
        return NULL;
    }
    /*Преобразование данных из PyObject в наш массив в С */
	n = PyList_GET_SIZE(list); /*Длина объекта списка в list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* Возвращает ссылку на i-й элемент list */
	    res = PyFloat_AsDouble(item); /* Возвращает double представление элемента item */
	    a[i] = res;
    }

    for (i = 0; i < 2; i++){
            b[i]=a[i]-a[i+2];
        }

    PyObject *my_list = PyList_New(n/2); /* Создаем массив объектов типа PyObject длины n, точнее указатель на первый элемент массива длины n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* Устанавливает элемент в список my_list на индекс i, перед этим  создаем объект PyFloatObject из a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *times(PyObject *self, PyObject *args){ /*умножение*/
    PyObject* list;
    int n;
    int i;
    double res;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - обработка аргументов функции и трасформация типы данных Python в типы данных C.
    Первый агрумент PyObject, кортеж переданных функции аргументов,  второй - тип переменных в которые мы хотим преобразовать наши аргументы
    ("O" - произвольный агрумент, то есть будет сохраняться объект Python (без какого-либо преобразования) в указателе объекта C). Далее идут сами
    переменныке в которые мы сохраняем преобразованные значения. Также осуществляется проверка, корректно ли отработала функция. */
        return NULL;
    }
    /*Преобразование данных из PyObject в наш массив в С */
	n = PyList_GET_SIZE(list); /*Длина объекта списка в list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* Возвращает ссылку на i-й элемент list */
	    res = PyFloat_AsDouble(item); /* Возвращает double представление элемента item */
	    a[i] = res;
    }
    b[0]=a[0]*a[2]-a[1]*a[3];
    b[1]=a[0]*a[3]+a[1]*a[2];

    PyObject *my_list = PyList_New(n/2); /* Создаем массив объектов типа PyObject длины n, точнее указатель на первый элемент массива длины n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* Устанавливает элемент в список my_list на индекс i, перед этим  создаем объект PyFloatObject из a[i]*/
    return my_list;
    free(a);
    free(b);
}

static PyObject *divide(PyObject *self, PyObject *args){ /*деление*/
    PyObject* list;
    int n;
    int i;
    double res, len;
    if (!PyArg_ParseTuple(args, "O", &list)){ /* PyArg_ParseTuple - обработка аргументов функции и трасформация типы данных Python в типы данных C.
    Первый агрумент PyObject, кортеж переданных функции аргументов,  второй - тип переменных в которые мы хотим преобразовать наши аргументы
    ("O" - произвольный агрумент, то есть будет сохраняться объект Python (без какого-либо преобразования) в указателе объекта C). Далее идут сами
    переменныке в которые мы сохраняем преобразованные значения. Также осуществляется проверка, корректно ли отработала функция. */
        return NULL;
    }
    /*Преобразование данных из PyObject в наш массив в С */
	n = PyList_GET_SIZE(list); /*Длина объекта списка в list */
    double *a = (double**)malloc(n * sizeof(double*));
    double *b = (double**)malloc(2 * sizeof(double*));
    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i); /* Возвращает ссылку на i-й элемент list */
	    res = PyFloat_AsDouble(item); /* Возвращает double представление элемента item */
	    a[i] = res;
    }
    len = pow(a[2],2) + pow(a[3],2);
    b[0]=(a[0]*a[2]+a[1]*a[3])/len;
    b[1]=(a[1]*a[2]-a[0]*a[3])/len;

    PyObject *my_list = PyList_New(n/2); /* Создаем массив объектов типа PyObject длины n, точнее указатель на первый элемент массива длины n*/
    for (i=0; i<2; i++)
    PyList_SetItem(my_list, i,  PyFloat_FromDouble(b[i])); /* Устанавливает элемент в список my_list на индекс i, перед этим  создаем объект PyFloatObject из a[i]*/
    return my_list;
    free(a);
    free(b);
}

/* Массив структур, описывающий методы модуля */
static PyMethodDef ownmod_methods[] = {
    {
	"plus", /* название функции внутри python */
	plus, /* функция C */
	 METH_VARARGS, /* макрос, поясняющий, что функция у нас с аргументами */
	"plus" /* документация для функции внутри python */
    },
    {
	"minus", /* название функции внутри python */
	minus, /* функция C */
	 METH_VARARGS, /* макрос, поясняющий, что функция у нас с аргументами */
	"minus" /* документация для функции внутри python */
    },
    {
	"times", /* название функции внутри python */
	times, /* функция C */
	 METH_VARARGS, /* макрос, поясняющий, что функция у нас с аргументами */
	"times" /* документация для функции внутри python */
    },
    {
	"divide", /* название функции внутри python */
	divide, /* функция C */
	 METH_VARARGS, /* макрос, поясняющий, что функция у нас с аргументами */
	"divide" /* документация для функции внутри python */
    },
    { NULL, NULL, 0, NULL }
};


/* Cтруктура, которая описывает непосредственно сам модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT, /* обязательный макрос */
    "complexNumbers", /* complexnumbers.__name__ */
    "services with Complex numbers: plus, minus, times, divide", /* complexNumbers.__doc__ */
    -1,
    ownmod_methods, /* передаем массив с методами модуля */
    NULL,NULL,NULL
};


/* Создание самого модуля */
PyMODINIT_FUNC PyInit_complexNumbers(void)
{
    PyObject* m;
    /* создаем модуль */
    m = PyModule_Create(&simple_module);
    /* если все корректно, то эта проверка не проходит */
    if (m == NULL)
        return NULL;
    return m;
}
