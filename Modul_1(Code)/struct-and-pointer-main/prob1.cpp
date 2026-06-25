#include <iostream>
#include "line.h"

int main() {
    Line l;
    Point p;

    std::cin >> l.a >> l.b >> l.c;
    std::cin >> p.x >> p.y;

    double hasil = gradient(&l, &p);

    std::cout << CheckPointPosition(hasil) << std::endl;

    return 0;
}