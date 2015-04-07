#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <array>
#include <algorithm>
#include <numeric>
#include "format_array.h"

template<class X, int n>
class Vertex : public std::array<X,n>
{
private:
    typedef Vertex<X,n> ThisClass;
public:
    enum { dim = n };
    Vertex() {}
    explicit Vertex(const X* data) {
        std::copy(data, data+n, begin());
    }
    ThisClass operator+(const ThisClass& r) const {
        ThisClass result;
        std::transform(begin(), end(), r.begin(), result.begin(), std::plus<X>());
        return result;
    }
    ThisClass operator-(const ThisClass& r) const {
        ThisClass result;
        std::transform(begin(), end(), r.begin(), result.begin(), std::minus<X>());
        return result;
    }
    ThisClass operator-() const {
        ThisClass result;
        std::transform(begin(), end(), result.begin(), [](const X& c){ return -c; });
        return result;
    }
    X operator*(const ThisClass& r) const {
        return std::inner_product(begin(), end(), r.begin(), X());
    }

    ThisClass& operator+=(const ThisClass& r) {
        std::transform(begin(), end(), r.begin(), begin(), std::plus<X>());
        return *this;
    }
    ThisClass operator-=(const ThisClass& r) {
        std::transform(begin(), end(), r.begin(), begin(), std::minus<X>());
        return *this;
    }
    ThisClass operator*=(const X& x) {
        std::transform(begin(), end(), begin(), [&x](const X& c){ return c*x; });
        return *this;
    }
    ThisClass operator/=(const X& x) {
        std::transform(begin(), end(), begin(), [&x](const X& c){ return c/x; });
        return *this;
    }
    ThisClass operator*(const X& x)
    {
        Vertex<X,n> result;
        std::transform(begin(), end(), result.begin(), [&x](const X& c){ return c*x; });
        return result;
    }
    ThisClass operator/(const X& x)
    {
        Vertex<X,n> result;
        std::transform(begin(), end(), result.begin(), [&x](const X& c){ return c/x; });
        return result;
    }
};

template<class X, int n>
Vertex<X,n> operator*(const X& x, const Vertex<X,n>& v)
{
    Vertex<X,n> result;
    std::transform(v.data(), v.data()+n, result.data(), [&x](const X& c){ return x*c; });
    return result;
}

template<class S, class X, int n>
S& operator<<(S& s, const Vertex<X,n>& v) {
    return format_array(s, v, ", ", "[", "]");
}

template<class X>
class Vertex2 : public Vertex<X, 2>
{
private:
    typedef Vertex<X,2> BaseClass;
    typedef Vertex2<X> ThisClass;
public:
    Vertex2() {}
    Vertex2(const BaseClass& b) : BaseClass(b) {}
    Vertex2(const X& x1, const X& x2) {
        (*this)[0] = x1;
        (*this)[1] = x2;
    }
    X operator%(const ThisClass& r) const {
        return (*this)[0]*r[1] - (*this)[1]*r[0];
    }
    ThisClass rot90Cw() const {
        return ThisClass((*this)[1], -(*this)[0]);
    }
    ThisClass rot90Ccw() const {
        return ThisClass(-(*this)[1], (*this)[0]);
    }
};

typedef Vertex2<double> V2d;
typedef Vertex2<int> V2i;

#endif // _VERTEX_H_
