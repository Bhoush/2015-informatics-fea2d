#include "meshgen2d.h"
#include "Vertex.h"
//#include "Line.h"
//#include "Triangle.h"
//#include "format_array.h"
#include "IndexLine.h"
#include "IndexTriangle.h"
#include "Loop.h"
#include "IndexLoop.h"
#include <QTextStream>

QTextStream cout(stdout);

void MESHGEN2DSHARED_EXPORT f() {
    V2d v1(1,2);
    V2d v2(4,31);
    cout << 2.*(v1+v2) << endl;
    Line2d line = {v1, v2};
    cout << line << endl;
    cout << Triangle2d(v1, v2, v2) << endl;
    cout << IndexLine(1,2) << endl;
    cout << IndexTriangle(1,2,3) << endl;
    Loop2d loop;
    loop << V2d(1,2) << V2d(3,4);
    cout << loop << endl;
    cout << loop[0] << endl;
    cout << loop.line(0) << endl;
    cout << loop.line(1) << endl;
    cout << endl;
    IndexLoop iloop;
    iloop << 1 << 2 << 3 << 4 << 5;
    cout << iloop << endl;
    cout << iloop[0] << endl;
    cout << iloop.line(0) << endl;
    cout << iloop.line(1) << endl;
    cout << endl;
}

//struct _{_(){f();}}__;

Meshgen2d::Meshgen2d()
    {
    }
