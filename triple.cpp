#include "triple.hpp"

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
    return Triple(t1.a/t2.a, t1.b/t2.a-t1.a*t2.b/(t2.a*t2.a), t1.c/t2.a-t1.b*t2.b/(t2.a*t2.a)-t1.a*t2.c/(t2.a*t2.a)+t1.a*t2.b*t2.b/(t2.a*t2.a*t2.a));
}

Triple pow(const Triple &t,const int &n){
    if(n<0)return Triple(1)/pow(t,-n);
    Triple ans=1;
    for(int i=0;i<n;i++){
        ans=ans*t;
    }
    return ans;
}