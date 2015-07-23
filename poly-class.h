#include <vector>
#include <string>

using namespace std;

class Polynomial {
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
        Polynomial mult_scalar(double b);
        Polynomial differentiate();
        Polynomial integrate();
        double root_newton(double guess, double tolerance = .00000001,
                           double epsilon = .000000000000001,
                           int maxIter = 20);
        double root_laguerre(double guess, double tolerance = .00000001,
                             double epsilon = .000000000000001,
                             int maxIter = 20);
};
