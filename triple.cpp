#include "triple.hpp"

Triple Triple::operator+(const Triple& o) const{
    return Triple(a+o.a, b+o.b, c+o.c);
}

Triple Triple::operator*(const Triple&o) const{
    return Triple(a*o.a, a*o.b+b*o.a, a*o.c+b*o.b+c*o.a);
}

Triple Triple::operator-(const Triple& o) const{
    return Triple(a-o.a, b-o.b, c-o.c);
}

Triple Triple::operator/(const Triple& o) const{
    return Triple(a/o.a, b/o.a-a*o.b/(o.a*o.a), c/o.a-b*o.b/(o.a*o.a)-a*o.c/(o.a*o.a)+a*o.b*o.b/(o.a*o.a*o.a));
}

