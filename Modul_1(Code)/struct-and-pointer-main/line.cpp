#include "line.h"
#include <cmath>

double gradient(const Line *l, const Point *p) {
    return (l->a * p->x) + (l->b * p->y) + l->c;
}

std::string CheckPointPosition(double val) {
    if (std::abs(val) < EPSILON) {
        return "On Line";
    } else if (val > 0) {
        return "Left";
    } else {
        return "Right";
    }
}