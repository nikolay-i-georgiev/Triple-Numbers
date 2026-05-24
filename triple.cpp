#include "triple.hpp"

Triple Triple::operator+(const Triple& o) const{
    return Triple(a+o.a, b+o.b, c+o.c);
}

Triple Triple::operator*(const Triple&o) const{
    return Triple(a*o.a, a*o.b+b*o.a, a*o.c+b*o.b+c*o.a);
}