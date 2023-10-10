/**
 * Provides implementations for the Sine Approximation Algorithms
 * and related auxiliary functions
 * @author William Duncan, Anindo Hazra
 * <pre>
 * Date: 1 September 2023
 * Course: CSc 3102
 * Project # 0
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <stdexcept>

using namespace std;

class SineUtil 
{
    
private:

    /**
     * Computes the factorial of the specified number
     * @param n the number whose factorial is to be determined
     * @return n!
     * @throw invalid_argument when n < 0 
     */
     
    static double factorial(int n);
    
    /**
     * Computes the specified power
     * @param x the base of the power
     * @param n the exponent of the power
     * @return x^n
     * @throw invalid_argument when x = 0 and n <= 0 
     */
     
    static double pow(double x, int n);

public:
    
    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and naive exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
    static double naiveSine(double x, int n);
    
    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and fast exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
    static double fastSine(double x, int n);
};

    /**
     * Computes the factorial of the specified number
     * @param n the number whose factorial is to be determined
     * @return n!
     * @throw invalid_argument when n < 0 
     */
double SineUtil::factorial(int n) 
{
    if (n < 0) 
    {
        throw invalid_argument("invalid_argument");
    }

    double fact = 1;
    
    for (int i = 1; i <= n; i++) 
    {
        fact *= i;
    }
    return fact;
}

    /**
     * Computes the specified power
     * @param x the base of the power
     * @param n the exponent of the power
     * @return x^n
     * @throw invalid_argument when x = 0 and n <= 0 
     */
     
double SineUtil::pow(double x, int n) 
{
    if (x == 0 && n < 0) 
    {
        throw invalid_argument("invalid_argument");
    }

    double result = 1;
    
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and naive exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
     
double SineUtil::naiveSine(double x, int n) 
{
    if (n <= 0) 
    {
        throw invalid_argument("invalid_argument");
    }

    double result = 0;

    for (int i = 1; i <= n; i++) 
    {
        if (i % 2 == 0) 
        {
            result = result - pow(x, 2 * i - 1) / factorial(2 * i - 1);
        } 
        
        else 
        {
            result = result + pow(x, 2 * i - 1) / factorial(2 * i - 1);
        }
    }
    return result;
}

    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and fast exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
     
double SineUtil::fastSine(double x, int n) 
{
    if (n <= 0) 
    {
        throw invalid_argument("invalid_argument");
    }

    double result = x;
    int denom = 3;
    int factor = -1;
    double base = x;

    for (int i = 2; i <= n; i++) {
        base = (base * (x / denom) * (x / (denom - 1)));
        denom = (denom + 2);
        result = (result + (factor * base));
        factor = (factor * (-1));
    }
    return result;
};
