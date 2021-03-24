// COS30008, Problem Set 1, 2021

#include <iostream>

//#define P1
//#define P2
//#define P3
//#define Automate

using namespace std;

#ifdef P1

#include "Polynomial.h"
#include <sstream>

void runProblem1()
{
#ifdef Automate
    stringstream ss;

    // automate input
    ss << 1 << ' ' << -0.25 << ' ' << 4.0 << ' ' << 16;
#endif

    Polynomial A;
    cout << "Specify polynomial:" << endl;

#ifdef Automate
    ss >> A;
#else
    cin >> A;
#endif

    cout << "A = " << A << endl;

    double x;
    cout << "Specify value of x:" << endl;

#ifdef Automate
    ss >> x;
#else
    cin >> x;
#endif

    cout << "A(x) = " << A(x) << endl;


    Polynomial B;

    if (B == B.getDifferential())
    {
        cout << "Differential programmatically sound." << endl;
    }
    else
    {
        cout << "Differential is broken." << endl;
    }

    if (A == A.getIndefiniteIntegral().getDifferential())
    {
        cout << "Polynomial operations are sound." << endl;
    }
    else
    {
        cout << "Polynomial operations are broken." << endl;
    }

    cout << "Indefinite integral of A = "
        << A.getIndefiniteIntegral() << endl;

    cout << "Differential of A = "
        << A.getDifferential() << endl;

    cout << "Differential of indefinite integral of A = "
        << A.getIndefiniteIntegral().getDifferential() << endl;

    cout << "Definite integral of A(xlow=0, xhigh=12.0) = "
        << A.getDefiniteIntegral(0, 12.0) << endl;
}

#endif

#ifdef P2

#include "Combination.h"

void runProblem2()
{
    Combination a(6, 2);
    Combination b(5, 2);
    Combination c(28, 14);
    Combination d(52, 5);
    Combination e(5, 5);

    cout << a.getN() << " over " << a.getK() << " = " << a() << endl;
    cout << b.getN() << " over " << b.getK() << " = " << b() << endl;
    cout << c.getN() << " over " << c.getK() << " = " << c() << endl;
    cout << d.getN() << " over " << d.getK() << " = " << d() << endl;
    cout << e.getN() << " over " << e.getK() << " = " << e() << endl;
}

#endif

#ifdef P3

#include "BernsteinBasePolynomial.h"

void runProblem3()
{
    BernsteinBasePolynomial bba(0, 4);
    BernsteinBasePolynomial bbb(1, 4);
    BernsteinBasePolynomial bbc(2, 4);
    BernsteinBasePolynomial bbd(3, 4);
    BernsteinBasePolynomial bbe(4, 4);

    for (double i = 0.0; i < 1.1; i += 0.2)
    {
        cout << "4th degree Bernstein base polynomial at "
            << i << " = "
            << bba(i) + bbb(i) + bbc(i) + bbd(i) + bbe(i)
            << endl;
    }
}

#endif

int main()
{
#ifdef P1

    runProblem1();

#endif

#ifdef P2

    runProblem2();

#endif


#ifdef P3

    runProblem3();

#endif

    return 0;
}
