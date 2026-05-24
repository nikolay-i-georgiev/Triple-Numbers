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

Triple pow(Triple t, int n){
    if(n<0)return Triple(1)/pow(t,-n);
    Triple ans=1;
    for(int i=0;i<n;i++){
        ans=ans*t;
    }
    return ans;
}