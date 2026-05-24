struct Triple{
double a,b,c;

Triple(double a, double b, double c) : a(a), b(b), c(c) {}

Triple operator+(const Triple& o) const;
Triple operator*(const Triple& o) const;
};