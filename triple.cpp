#include "triple.hpp"
#include <cmath>

Triple operator+(const Triple& t1, const Triple& t2){
    return Triple(t1.a+t2.a, t1.b+t2.b, t1.c+t2.c);
}

Triple operator-(const Triple& t1, const Triple& t2){
    return Triple(t1.a-t2.a, t1.b-t2.b, t1.c-t2.c);
}

Triple operator*(const Triple& t1, const Triple& t2){
    return Triple(t1.a*t2.a, t1.a*t2.b+t1.b*t2.a, t1.a*t2.c+t1.b*t2.b+t1.c*t2.a);
}

Triple operator/(const Triple& t1, const Triple& t2){
    return Triple(
        t1.a/t2.a, 
        t1.b/t2.a - t1.a*t2.b/(t2.a*t2.a), 
        t1.c/t2.a - t1.b*t2.b/(t2.a*t2.a) - t1.a*t2.c/(t2.a*t2.a) + t1.a*t2.b*t2.b/(t2.a*t2.a*t2.a));
}

Triple intpow(const Triple &t,const int &n){
    if(n<0)return 1/intpow(t,-n);
    Triple ans=1;
    for(int i=0;i<n;i++){
        ans=ans*t;
    }
    return ans;
}

Triple exp(const Triple &t){
    double ea=std::exp(t.a);
    return Triple(ea, ea*t.b, ea*(t.b*t.b/2+t.c));
}

Triple log(const Triple &t){
    return Triple(std::log(t.a), t.b/t.a, t.c/t.a-t.b*t.b/(2*t.a*t.a));
}