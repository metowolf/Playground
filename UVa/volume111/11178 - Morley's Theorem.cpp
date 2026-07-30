#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

// 二维点（也用作向量）
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y * k); }
};

using Vector = Point;

double dot(const Vector& a, const Vector& b) { return a.x * b.x + a.y * b.y; }
double cross(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; }
double length(const Vector& a) { return sqrt(dot(a, a)); }

// 将向量 a 绕原点逆时针旋转 ang（弧度）
Vector rotate(const Vector& a, double ang) {
    double c = cos(ang), s = sin(ang);
    return Vector(a.x * c - a.y * s, a.x * s + a.y * c);
}

// 从向量 a 到向量 b 的有向角，范围 (-pi, pi]
double angle(const Vector& a, const Vector& b) {
    return atan2(cross(a, b), dot(a, b));
}

// 直线：由一点 p 和方向向量 v 确定
struct Line {
    Point p;
    Vector v;

    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}

    // 与另一条直线求交点（假设两线不平行）
    Point intersection(const Line& L) const {
        Vector u = p - L.p;
        double t = cross(L.v, u) / cross(v, L.v);
        return p + v * t;
    }
};

// 顶点 V 处，靠近边 V->P、朝 V->Q 方向偏转 1/3 内角的三等分线方向
Vector trisector(Point V, Point P, Point Q) {
    return rotate(P - V, angle(P - V, Q - V) / 3.0);
}

// D：由顶点 B、C 处靠近底边 BC 的两条三等分线相交得到（D 在对边 A 一侧）
Point getD(Point A, Point B, Point C) {
    Vector vB = trisector(B, C, A);
    Vector vC = trisector(C, B, A);
    return Line(B, vB).intersection(Line(C, vC));
}

// E：由顶点 C、A 处靠近底边 CA 的两条三等分线相交得到（E 在对边 B 一侧）
Point getE(Point A, Point B, Point C) {
    Vector vC = trisector(C, A, B);
    Vector vA = trisector(A, C, B);
    return Line(C, vC).intersection(Line(A, vA));
}

// F：由顶点 A、B 处靠近底边 AB 的两条三等分线相交得到（F 在对边 C 一侧）
Point getF(Point A, Point B, Point C) {
    Vector vA = trisector(A, B, C);
    Vector vB = trisector(B, A, C);
    return Line(A, vA).intersection(Line(B, vB));
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    while (N--) {
        int xa, ya, xb, yb, xc, yc;
        scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
        Point A(xa, ya), B(xb, yb), C(xc, yc);
        Point D = getD(A, B, C);
        Point E = getE(A, B, C);
        Point F = getF(A, B, C);
        printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",
               D.x, D.y, E.x, E.y, F.x, F.y);
    }
    return 0;
}
