#include <iostream>
#include <cmath>
using namespace std;

// Bài 06: a_n = 7a_{n-1} - 6a_{n-2}, a_0 = 1, a_1 = 11
int A6(int n)
{
    return -1 + 2 * pow(6, n);
}

// Bài 07: a_n = -7a_{n-1} - 6a_{n-2}, a_0 = 1, a_1 = 9
int A7(int n)
{
    int a0 = 1, a1 = 9, an;
    if (n == 0)
        return a0;
    if (n == 1)
        return a1;
    for (int i = 2; i <= n; ++i)
    {
        an = -7 * a1 - 6 * a0;
        a0 = a1;
        a1 = an;
    }
    return an;
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
// Bài 08: a_n = 2a_{n-1} - 2a_{n-2}, a_0 = 1, a_1 = 2
int A8(int n)
{
    int a0 = 1, a1 = 2, an;
    if (n == 0)
        return a0;
    if (n == 1)
        return a1;
    for (int i = 2; i <= n; ++i)
    {
        an = 2 * a1 - 2 * a0;
        a0 = a1;
        a1 = an;
    }
    return an;
}

// Bài 09: a_n = a_{n-1} + 6a_{n-2} + 10n(2^n) - 3(2^n), a_0 = 8, a_1 = 5
int A9(int n)
{
    int a0 = 8, a1 = 5, an;
    if (n == 0)
        return a0;
    if (n == 1)
        return a1;
    for (int i = 2; i <= n; ++i)
    {
        int pow2 = pow(2, i);
        an = a1 + 6 * a0 + 10 * i * pow2 - 3 * pow2;
        a0 = a1;
        a1 = an;
    }
    return an;
}

// Bài 10: a_n = a_{n-1} + a_{n-2} + 2^{n-2}, a_0 = 1, a_1 = 0
int A10(int n)
{
    int a0 = 1, a1 = 0, an;
    if (n == 0)
        return a0;
    if (n == 1)
        return a1;
    for (int i = 2; i <= n; ++i)
    {
        an = a1 + a0 + pow(2, i - 2);
        a0 = a1;
        a1 = an;
    }
    return an;
}

// Bài 11: a_n = a_{n-1} - a_{n-2} + 2^{n-2}, a_0 = 0, a_1 = 1
int A11(int n)
{
    int a0 = 0, a1 = 1, an;
    if (n == 0)
        return a0;
    if (n == 1)
        return a1;
    for (int i = 2; i <= n; ++i)
    {
        an = a1 - a0 + pow(2, i - 2);
        a0 = a1;
        a1 = an;
    }
    return an;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "A6(" << n << ") = " << A6(n) << endl;
    cout << "A7(" << n << ") = " << A7(n) << endl;
    cout << "A8(" << n << ") = " << A8(n) << endl;
    cout << "A9(" << n << ") = " << A9(n) << endl;
    cout << "A10(" << n << ") = " << A10(n) << endl;
    cout << "A11(" << n << ") = " << A11(n) << endl;
    return 0;
}
