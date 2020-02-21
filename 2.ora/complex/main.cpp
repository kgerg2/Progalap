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

    Complex operator/(float x) const
    {
        return Complex(re / x, im / x);
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
