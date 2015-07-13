#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "poly-class.h"

using namespace std;


Polynomial::Polynomial(vector<double> v)
{
    data = v;
    degree = v.size() - 1;
}

int Polynomial::coeff_at(int power)
{
    return this->data[this->degree - power];
}

int Polynomial::eval_at(int x)
{
    int result = 0;
    int len = this->data.size();
    for (int e = 0; e < len; ++e) {
        result = this->data[e] + (x * result);
    }
    return result;
}

int Polynomial::degree_of()
{
    return this->degree;
}

vector<double> Polynomial::lo_to_hi()
{
    vector<double> a = this->data;
    vector<double> result(a.size());
    reverse_copy(a.begin(), a.end(), result.begin());
    return result;
;}

vector<double> Polynomial::hi_to_lo()
{
    return this->data;
}


Polynomial Polynomial::operator+(const Polynomial& b)
{
    int aLen = this->data.size();
    int bLen = b.data.size();

    Polynomial v = (aLen > bLen) ? *this : b;
    Polynomial w = (aLen > bLen) ? b : *this;
    vector<double> result(max(aLen, bLen));

    int diff = abs(aLen - bLen);

    for (int i = 0; i < aLen; ++i) { result[i] += v.data[i]; }
    for (int j = 0; j < bLen; ++j) { result[j + diff] += w.data[j]; }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& b)
{
    int aLen = this->data.size();
    int bLen = b.data.size();

    Polynomial v = (aLen > bLen) ? *this : b;
    Polynomial w = (aLen > bLen) ? b : *this;
    vector<double> result(max(aLen, bLen));

    int diff = abs(aLen - bLen);

    for (int i = 0; i < aLen; ++i) { result[i] += v.data[i]; }
    for (int j = 0; j < bLen; ++j) { result[j + diff] -= w.data[j]; }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& b)
{
    Polynomial* a = this;
    vector<double> result(a->degree + b.degree + 1);
    for (int i = 0; i <= a->degree; ++i) {
        for (int j = 0; j <= b.degree; ++j) {
            result[i + j] += a->data[i] * b.data[j];
        }
    }
    return Polynomial(result);
}

bool Polynomial::operator==(const Polynomial& b)
{
    Polynomial* a = this;
    if (a->degree != b.degree) { return false; }
    for (int i = 0; i <= a->degree; ++i) {
        if (a->data[i] != b.data[i]) { return false; }
    }
    return true;
}

Polynomial Polynomial::differentiate()
{
    Polynomial* a = this;

    int len = a->data.size();
    vector<double> result(len - 1);
    for (int i = 0; i < len - 1; ++i) {
        result[i] = a->data[i] * (len - i - 1);
    }
    return Polynomial(result);
}

Polynomial Polynomial::integrate()
{
    Polynomial* a = this;

    int len = a->data.size();
    vector<double> result(len + 1);
    for (int i = 0; i < len; ++i) {
        result[i] = a->data[i] / (len - i);
    }
    return Polynomial(result);
}

string dble_to_str(double n)
{
        int p = 4;
        stringstream o;
        o << setprecision(p) << n;
        return o.str();
}

string Polynomial::to_string()
{
    string result = "";
    vector<double> a = this->data;
    int len = this->data.size();
    for (int i = 0; i < len; ++i) {
        if (a[i] == 0)  { continue; }

        if (i != 0)     { result += " + "; }

        if (a[i] < 0)   { result += "-"; }
        if (a[i] != 1 || i == len - 1) {result += dble_to_str(abs(a[i])); }
        if (i == len - 2) {result += "x";
        } else if (i < len - 2) {result += "x^" + dble_to_str(len - i - 1); }

    }
    return result;
}
