#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
    double re, im;
public:
    Complex(double re, double im): re(re), im(im) {}

    Complex operator+(const Complex &z) const
    {
        return Complex(re + z.re, im + z.im);
    }

    Complex operator-(const Complex &z) const
    {
        return Complex(re - z.re, im - z.im);
    }

    Complex operator*(const Complex &z) const
    {
        return Complex(re * z.re - im * z.im, im * z.re + re * z.im);
    }

    Complex operator/(const Complex &z) const
    {
        Complex n = *this * z.conj();
        float d = (z * z.conj()).re;
        return Complex(n.re / d, n.im / d);
    }

    Complex conj() const
    {
        return Complex(re, -im);
    }

    Complex add_inv() const
    {
        return Complex(-re, -im);
    }

    Complex recipr() const
    {
        return Complex(1, 0) / *this;
    }

    double abs() const
    {
        return sqrt(re*re + im*im);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
