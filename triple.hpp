struct Triple{
double a,b,c;

Triple(double a, double b, double c) : a(a), b(b), c(c) {}
Triple(double a) : a(a), b(0), c(0) {}

Triple operator+(const Triple& o) const;
Triple operator-(const Triple& o) const;
Triple operator*(const Triple& o) const;
Triple operator/(const Triple& o) const;
};