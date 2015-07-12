#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Polynomial
{
    vector<double> data;
    int degree;

    public:
        Polynomial(vector<double> v);
        int coeff_at(int power);
        int eval_at(int x);
        int degree_of();
        vector<double> lo_to_hi();
        vector<double> hi_to_lo();
        string to_string();
        Polynomial operator+(const Polynomial& b);
        Polynomial operator-(const Polynomial& b);
        Polynomial operator*(const Polynomial& b);
        bool operator==(const Polynomial& b);
        Polynomial differentiate();
};

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
}

vector<double> Polynomial::hi_to_lo()
{
    return this->data;
}


Polynomial Polynomial::operator+(const Polynomial& b)
{
    Polynomial* a = this;
    vector<double> result;
    for (int i = 0; i <= a->degree; ++i) {
        result[i] = a->data[i];
    }
    for (int j = 0; j <= b.degree; ++j) {
        result[j] = b.data[j];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& b)
{
    Polynomial* a = this;
    vector<double> result(max(a->data.size(),b.data.size()));
    for (int i = 0; i <= a->degree; ++i) { result[i] += a->data[i]; }
    for (int j = 0; j <= b.degree; ++j) { result[j] -= b.data[j]; }
    while (result[0] == 0 && result.size() > 1) {result.erase(result.begin()); }
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
    vector<double> result(len);
    for (int i = 0; i < len; ++i) {
        result[i] = (i + 1) * a->data[i + 1];
    }
    return Polynomial(result);
}


// const string T[3][3] = {
//     {"", "", ""}
//     {"%d", "%"}

// }

// string Polynomial::to_string()
// {
//     string result = "";
//     int len = this->data.size();
//     for (int i = 0; i < len; ++i) {

//     }
// }


int main()
{
    //Test suite
    return 0;
;}
