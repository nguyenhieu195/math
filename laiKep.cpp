#include <cstdlib>
#include <iostream>

using namespace std;

double p0 = 1000;
double d = 0.11;
int n = 10;

double P(double n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (1 + d) * P(n - 1);
    }
}

double p(double n)
{
    if (n == 0)
    {
        return p0;
    }
    else
    {
        return p(n - 1) + d * p(n - 1);
    }
}
////////
////////

/////////

//////////
///////
///////
//
/
/
/
    /


    //
int main(int argc, char *argv[])
{
    cout << "P (" << n << ") = " << P(n) << endl;
    cout << "p (" << n << ")= " << p(n) << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
