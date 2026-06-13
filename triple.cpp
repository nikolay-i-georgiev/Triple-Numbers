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
    return Triple( //Derived from multiplying both the numerator and denominator by Triple(t2.a, -t2.b, t2.c) and then again by Triple(t.a^2, 0, 2*t.a*t.c-t.b^2)
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
    return Triple(ea, ea*t.b, ea*(t.b*t.b/2+t.c)); // Derived from Taylor series for e^x
}

Triple log(const Triple &t){
    return Triple(std::log(t.a), t.b/t.a, t.c/t.a-t.b*t.b/(2*t.a*t.a)); // Derived from Taylor series for ln(1+x)
}

Triple pow(const Triple &a, const Triple &b){
    return(exp(b*log(a))); // Derived from a^b=e^(log(a^b))=e^(b*log(a))
}

Triple sin(const Triple &t){
    double sina=std::sin(t.a), cosa=std::cos(t.a);
    return Triple(sina, cosa*t.b, cosa*t.c-sina*t.b*t.b/2); // Derived from sin(a+b*eps+c*eps^2)=sin(a)*cos(b*eps+c*eps^2)+cos(a)*sin(b*eps+c*eps^2) and applying the Taylor series for sin(x)
}