#include "poly-class.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    vector<double> v = {1, 0, 2};
    vector<double> w = {2, 3};
    vector<double> x = {1};
    Polynomial P = Polynomial(v);
    Polynomial Q = Polynomial(w);
    Polynomial T = Polynomial(v);
    Polynomial U = Polynomial(x);

    cout << P.to_string() << "\n";
    cout << (P + Q).to_string() << "\n";
    cout << (P * Q).to_string() << "\n";

    vector<double> r = P.differentiate().hi_to_lo();
    for (int i = 0; i < int(r.size()); ++i) {
        cout << r[i] << " ";
    }
    cout << "\n";

    cout << P.differentiate().to_string() << "\n";
    cout << P.integrate().to_string() << "\n";
    cout << Q.integrate().to_string() << "\n";
    cout << int(P == T) << "\n";
    cout << (P - Q).to_string() << "\n";

    cout << P.eval_at(4) << "\n";
    cout << P.degree_of() <<  "\n";

    cout << U.degree_of() << "\n";
    cout << U.to_string() << "\n";
    cout << U.differentiate().to_string() << "\n";

    return 0;
}
