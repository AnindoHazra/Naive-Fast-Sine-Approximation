/**
 * A program to profile sine approximation algorithms that use 
 * the Taylor series expansion of the sine function: 
 * sine(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! .....   
 * @author William Duncan, Anindo Hazra
 * @see SineUtil.h
 * <pre>
 * Date: 1 September 2023
 * Course: CSc 3102
 * Project # 0
 * Instructor: Dr. Duncan
 * </pre>
 */
 
#include <iostream>
#include <chrono>
#include <iomanip>

#include "SineUtil.h"

using namespace std;
using namespace std::chrono;

int main()
{
    double x;
    double n;
    cout << "Enter the angle in radians ->";
    cin >> x;
    cout << endl;
    
    cout << "naive-sine("<< x <<") = "<< SineUtil::naiveSine(x, n = 100) <<endl;
    cout << "fast-sine("<< x <<") = "<< SineUtil::fastSine(x, n = 100) << endl << endl;
    
    cout << "n" << setw(20) << "Naive Time(us)" << setw(20) << "Fast Time(us)" << setfill(' ') << endl;
    cout << setfill('=') << setw(41) << '=' << endl;
    
    n = 1000;
    
    for(int i = 1; i <= 15; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        SineUtil::naiveSine(x, n);
        auto elapsed = chrono::high_resolution_clock::now() - start;
        long nTime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    
        start = chrono::high_resolution_clock::now();
        SineUtil::fastSine(x, n);
        elapsed = chrono::high_resolution_clock::now() - start;
        long fTime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        
        cout << setw(10) << left << setfill(' ') << n << setfill(' ') << left << setw(20) << nTime << setw(20) << fTime << endl;
        
        n = n + 1000;
    }
	return 0;
}