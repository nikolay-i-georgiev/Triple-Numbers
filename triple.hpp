struct Triple{
double a,b,c;

Triple(double a, double b, double c) : a(a), b(b), c(c) {}
Triple(double a) : a(a), b(0), c(0) {}
};

Triple operator+(const Triple& t1, const Triple& t2);
Triple operator-(const Triple& t1, const Triple& t2);
Triple operator*(const Triple& t1, const Triple& t2);
Triple operator/(const Triple& t1, const Triple& t2);
Triple intpow(Triple &t, int &n);
Triple exp(const Triple &t);
Triple log(const Triple &t);
Triple pow(const Triple &b, const Triple &e);