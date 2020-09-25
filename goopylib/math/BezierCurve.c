#define PY_SSIZE_T_CLEAN 16

#include <Python.h>
#include <math.h>


struct DoubleTuple2 {
    double x, y;
};

unsigned long long factorial(unsigned long long number){
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);
}

unsigned long long combination(unsigned long long n, unsigned long long k){
    return factorial(n) / (factorial(k) * factorial(n - k));}

double bernstein_polynomial(unsigned long long i, unsigned long long n, double t){
    return combination(n, i) * pow(t, i) * pow(1 - t, n - i);}


struct DoubleTuple2 bezier_curve(long double t, unsigned long long size, long long control_points[]){

    if (size > 5)
        double sum_x = 0, sum_y = 0;
        int i = 0;

        unsigned long long degree = size, index = 0;
        size *= 2;

        while (i < size) {
            double coeff = bernstein_polynomial(index, degree - 1, t);
            sum_x += coeff * control_points[i];
            sum_y += coeff * control_points[i + 1];

            i += 2;
            index++;
        }

        struct DoubleTuple2 point;
        point.x = sum_x;
        point.y = sum_y;

        return point;

    struct DoubleTuple2 point;

    double t2 = 0, t3 = 0, t4 = 0;

    switch (size) {
        case 2:
            point.x = ((1 - t) * control_points[0]) + (t * control_points[2]);
            point.y = ((1 - t) * control_points[1]) + (t * control_points[3]);
            break;

        case 3:
            t2 = t * t;

            t *= 2;

            point.x = ((t2 - t + 1) * control_points[0]) +
            (((-2 * t2) + t) * control_points[2]) +
            (t2 * control_points[4]);

            point.y = ((t2 - t + 1) * control_points[1]) +
            (((-2 * t2) + t) * control_points[3]) +
            (t2 * control_points[5]);

            break;

        case 4:
            t2 = t * t;
            t3 = t2 * t;

            t *= 3;

            point.x = ((-t3 + (3 * t2) - t + 1) * control_points[0]) +
            (((3 * t3) - (6 * t2) + t) * control_points[2]) +
            (((-3 * t3) + (3 * t2)) * control_points[4]) +
            (t3 * control_points[6]);

            point.y = ((-t3 + (3 * t2) - t + 1) * control_points[1]) +
            (((3 * t3) - (6 * t2) + t) * control_points[3]) +
             (((-3 * t3) + (3 * t2)) * control_points[5]) +
            (t3 * control_points[7]);

            break;

        case 5:
            t2 = t * t;
            t3 = t2 * t;
            t4 = t3 * t;

            t *= 4;

            point.x = ((t4 - (4 * t3) + (6 * t2) - t + 1) * control_points[0]) +
            (((-4 * t4) + (12 * t3) - (12 * t2) + t) * control_points[2]) +
            (((6 * t4) - (12 * t3) + (6 * t2)) * control_points[4]) +
            (((-4 * t4) + (4 * t3)) * control_points[6]) +
            (t4 * control_points[8]);

            point.y = ((t4 - (4 * t3) + (6 * t2) - t + 1) * control_points[1]) +
            (((-4 * t4) + (12 * t3) - (12 * t2) + t) * control_points[3]) +
            (((6 * t4) - (12 * t3) + (6 * t2)) * control_points[5]) +
            (((-4 * t4) + (4 * t3)) * control_points[7]) +
            (t4 * control_points[9]);

            break;}

    return point;
}


static PyObject* BezierCurve_factorial(PyObject *self, PyObject *args){
    unsigned long long n;

    if (!PyArg_ParseTuple(args, "K", &n))
        return NULL;

    return Py_BuildValue("K", factorial(n));
}

static PyObject* BezierCurve_combination(PyObject *self, PyObject *args){
    unsigned long long n, k;

    if (!PyArg_ParseTuple(args, "KK", &n, &k))
        return NULL;

    return Py_BuildValue("K", combination(n, k));
}

static PyObject* BezierCurve_bernstein_polynomial(PyObject* self, PyObject* args){
    unsigned long long i, n;
    long double t;

    if (!PyArg_ParseTuple(args, "KKd", &i, &n, &t))
        return NULL;

    return Py_BuildValue("d", bernstein_polynomial(i, n, t));
}

static PyObject* BezierCurve_raw_bezier_curve(PyObject* self, PyObject* args){
    unsigned long long size;
    double t;
    PyObject *py_control_points, *temp1, *x, *y;

    if (!PyArg_ParseTuple(args, "dO", &t, &py_control_points))
        return NULL;

    size = PyLong_AsUnsignedLongLong(PyLong_FromSsize_t(PyList_GET_SIZE(py_control_points)));

    long long *control_points = (long long*)malloc(size * sizeof(long long) * 2);
    unsigned long long index = 0;

    for (unsigned long long i = 0; i < size; i++){

        temp1 = PyList_GetItem(py_control_points, i);

        if (temp1 == NULL)
            return NULL;

        x = PyList_GetItem(temp1, 0);
        y = PyList_GetItem(temp1, 1);

        if (PyNumber_Check(x) != 1 || PyNumber_Check(y) != 1){
            PyErr_SetString(PyExc_TypeError, "Control Points Argument is Non-Numeric");
            return NULL;}

        control_points[index] = PyLong_AsLongLong(x);
        control_points[index + 1] = PyLong_AsLongLong(y);
        index += 2;

        if (PyErr_Occurred())
            return NULL;
    }

    struct DoubleTuple2 point = raw_bezier_curve(t, size, control_points);
    return Py_BuildValue("[d, d]", point.x, point.y);
}

static PyObject* BezierCurve_bezier_curve(PyObject* self, PyObject* args) {
    unsigned long long size;
    double t;
    PyObject *py_control_points, *temp1, *x, *y;

    if (!PyArg_ParseTuple(args, "dO", &t, &py_control_points))
        return NULL;

    size = PyLong_AsUnsignedLongLong(PyLong_FromSsize_t(PyList_GET_SIZE(py_control_points)));

    long long *control_points = (long long*)malloc(size * sizeof(long long) * 2);
    unsigned long long index = 0;

    for (unsigned long long i = 0; i < size; i++){

        temp1 = PyList_GetItem(py_control_points, i);

        if (temp1 == NULL)
            return NULL;

        x = PyList_GetItem(temp1, 0);
        y = PyList_GetItem(temp1, 1);

        if (PyNumber_Check(x) != 1 || PyNumber_Check(y) != 1){
            PyErr_SetString(PyExc_TypeError, "Control Points Argument is Non-Numeric");
            return NULL;}

        control_points[index] = PyLong_AsLongLong(x);
        control_points[index + 1] = PyLong_AsLongLong(y);
        index += 2;

        if (PyErr_Occurred())
            return NULL;
    }

    struct DoubleTuple2 point = bezier_curve(t, size, control_points);
    return Py_BuildValue("[d, d]", point.x, point.y);
}



static PyMethodDef BezierCurve_funcs[] = {
    {"factorial", (PyCFunction)BezierCurve_factorial, METH_VARARGS, "factorial(x): calculates factorial of x"},
    {"combination", (PyCFunction)BezierCurve_combination, METH_VARARGS, "combination(n, k): calculates nCk"},
    {"bernstein_polynomial", (PyCFunction)BezierCurve_bernstein_polynomial, METH_VARARGS,
    "bernstein_polynomial(i, n, t): calculates the ith bernstein_polynomial at t for n-degrees"},

    {"bezier_curve", (PyCFunction)BezierCurve_bezier_curve, METH_VARARGS,
    "bezier_curve(t, control_points): calculates the bezier curve at point t for control_points"},

    {NULL, NULL, 0, NULL}};

static struct PyModuleDef BezierCurveModule = {
    PyModuleDef_HEAD_INIT,
    "BezierCurveModule", "Functions to Calculate Bezier Curves.",
    -1, BezierCurve_funcs};

PyMODINIT_FUNC PyInit_BezierCurve(void){
    return PyModule_Create(&BezierCurveModule);
}