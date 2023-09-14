#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
class Complex1 {
    double rPart, iPart;
public:
    Complex1(double r=0, double i=0) : rPart(r), iPart(i) {}
    Complex1 conj() const {
        return Complex1(rPart, -iPart);
    }
    Complex1 add(const Complex1& c) const {
        return Complex1(rPart + c.rPart, iPart + c.iPart);
    }
    Complex1 sub(const Complex1& c) const {
        return Complex1(rPart - c.rPart, iPart - c.iPart);
    }
    Complex1 mul(const Complex1& c) const {
        return Complex1(rPart * c.rPart - iPart * c.iPart, rPart * c.iPart + iPart * c.rPart);
    }
    Complex1 div(const Complex1& c) const {
        return Complex1(((rPart * c.rPart) + (iPart * c.iPart)) / ((c.rPart * c.rPart) + (c.iPart * c.iPart)), ((iPart * c.rPart) - (rPart * c.iPart)) / ((c.rPart * c.rPart) + (c.iPart * c.iPart)));
    }
    void display() const;
};
#endif