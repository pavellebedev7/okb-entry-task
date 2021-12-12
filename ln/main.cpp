#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#define N 100000    // Taylor polynomial degree
#define w 14        // Output formatting

using namespace std;

/******************************************************************************
 *
 * Реализована функция double ln(double x) вычисляющая натуральный логарифм до
 * степени N предложенного ряда.
 *
 * Для проверки работы алгоритма использована функция log библиотеки cmath.
 * В тестовом цикле выводятся значения аргумента, эталонной функции,
 * реализованной функции, абсолютной и относительной ошибки. Для тестирования
 * использованы значения из диапазона типа float.
 *
 *****************************************************************************/
double ln(double x){
    if(x == 0) return -INFINITY;
    if(x < 0) return NAN;
    uint32_t denominator = 0;           // Denominator and current power
    double ans = 0;                     // Answer
    double base = (1.0 - x)/(1.0 + x);  // Base of series
    double squaredBase = base * base;   // Squared base for numerator calculation
    double numerator = base;            // Current numerator in current power
    for(uint32_t i = 0; i < N; i++){
        denominator = 1 + 2*i;
        ans += numerator/denominator;
        numerator *= squaredBase;
    }
    ans *= -2;
    return ans;
}

int main()
{
    vector<double> args = {-1E0, 0, 1E-38, 1E-19, 1E-6, 1E-5, 1E-3, 1E-2, 1E-1,
                            1E0, 1E1, 1E2, 1E3, 1E4, 1E5, 1E6, 1E19, 1E38};
    cout << "arg\t"
         << setw(w) << "log cmath"
         << setw(w) << "ln\t"
         << setw(w) << "absolute error\t"
         << setw(w) << "relative error\t" << endl;
    for(uint32_t i = 0; i < args.size(); i++){
        cout << args[i] << "\t"
             << setw(w) << log(args[i]) << "\t"
             << setw(w) << ln(args[i]) << "\t"
             << setw(w) << log(args[i]) - ln(args[i]) << "\t"
             << setw(w) << (log(args[i]) - ln(args[i]))/log(args[i]) << endl;
    }
    cin.get();
    return 0;
}

