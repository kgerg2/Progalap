#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class Complex
{
private:
    double re, im;
public:
    Complex(double re = 0, double im = 0): re(re), im(im) {}

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

    friend ostream& operator<<(ostream &o, const Complex &c)
    {
        o << c.re;
        if (c.im > 0)
        {
            o << "+" << c.im << "i";
        }
        else if (c.im < 0)
        {
            o << c.im << "i";
        }
        return o;
    }

    friend istream& operator>>(istream &o, Complex &c)
    {
        o >> c.re >> c.im;
        o.ignore(1);
        return o;
    }
};

int main()
{
    vector<Complex> v;
    Complex c;
    ifstream f("input.txt");
    if (!f.fail())
    {
        while (f >> c)
        {
            v.push_back(c);
        }
    }
    if (v.size() < 2)
    {
        cout << "Hiba" << endl;
        return 1;
    }
    c = v[1];
    int ind = 1;
    for (int i = 2; i < v.size(); i++)
    {
        if ((c - v[0]).abs() < (v[i] - v[0]).abs())
        {
            c = v[i];
            ind = i;
        }
    }
    cout << ind << ". pont, távolság: " << (c - v[0]).abs() << endl;
    return 0;
}
