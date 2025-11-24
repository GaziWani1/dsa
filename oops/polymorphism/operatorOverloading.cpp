#include <iostream>
using namespace std;

class Complex
{
public:
    int real, image;
    Complex(int r = 0, int i = 0)
    {
        this->real = r;
        this->image = i;
    }

    Complex operator+(Complex c)
    {
        cout << "Called : " << this->real << endl;
        Complex temp;
        temp.real = this->real + c.real;
        temp.image = this->image + c.image;
        return temp;
    }
};

int main()
{
    Complex c1(2, 4);
    Complex c2(3, 4);
    // c2's constructor is called and c1 acts like a parameter
    Complex c3 = c2 + c1;
    cout << "real : " << c3.real << " | " << "image : " << c3.image << "i" << endl;
    return 0;
}