//********************************************************//
//                                                        //
//   File    :   Arithmetic.h                             //
//   Author  :   eezyl                                    //
//   Synopsis:   Collection of common arithmetic functions//
//   Date    :   2019/04/17                               //
//                                                        //
//********************************************************//

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <cstdlib> // abs
#include <vector>
#include <algorithm> // max, min

// =====================================================
// return n! mod m, O(n)
// =====================================================
template<class T>
long long factorial_mod(int n, T m)
{
    long long result = 1;
    for (int i = 2; i <= n ; i++)
        result = (result*i) % m;
    return result;
}

// =====================================================
// Return b^e mod m, O(log(e))
// =====================================================
template<class T>
T power_mod(T b, T e, T m)
{
    b %= m;
    T result = 1;
    while (e>0) {
        if (e&1)
            result = (result * b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return result;
}

// =====================================================
// Miller-Rabin Primality Test
// =====================================================
class PrimeChecker {
public:
    PrimeChecker() {} // constructor
    bool isPrime(long long n) 
    {
        if (n < 2)
            return false;
        if (n < 4)
            return true;
        if (!(n&1))
            return false;
        long long a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for (int i = 0; i < 12; i++)
            if (!MRPrimalityTest(n, a[i], n-1))
                return false;
        return true;
    }
private:
    bool MRPrimalityTest(long long n, long long a, long long d) 
    {
        if (n == a)
            return true;
        while (!(d&1))
            d >>= 1;
        long long t = power_mod(a, d, n);
        while ( d!=n-1 && t!=1 && t!=n-1) {
            t = (t*t) % n;
            d <<= 1;
        }
        return t==n-1 || d&1;
    }
};

// =====================================================
// Return the positive value of x mod m although x is negative
// =====================================================
long long pos_mod(long long x, long long m)
{
    x = x%m; 
    if (x < 0) x += m;
    return x;
}

// =====================================================
// Given m,n > 0, return the greatest common divisor
// =====================================================
long long gcd (long long m, long long n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

// =====================================================
// Given m,n > 0, return the least common mutiple
// =====================================================
long long lcm (long long m, long long n)
{
    return (m/gcd(m, n)) * n;
}

// =====================================================
// Given ax+by=gcd(a,b),
// return value is gcd(a, b) and x, y (paseed by reference)
// =====================================================
template<class T>
T exgcd(T a, T b, T &x, T &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T g = exgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) *y1;
    return g;
}

// =====================================================
// Solve ax+by=c, return false if there is no solution
// =====================================================
template<class T>
bool exgcd(T a, T b, T c, T &x0, T &y0, T &g)
{
    g = exgcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 /= g;
    y0 /= g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

// =====================================================
// Only for floating point, return if they are equal
// =====================================================
template<class T>
inline bool isEqualForFloating(T num1, T num2, double delta = 0.0001)
{
    return std::abs(num1 - num2) < delta;
}

// =====================================================
// interpolate a + (b-a) * ratio    (0 <= ratio <= 1)
// =====================================================
inline double interpolate(double a, double b, double ratio){
        return a + ((b-a)*ratio);
}

// =====================================================
// 1D differtial function f'(i) = f(i) - f(i-1), f'(0) = f(0)
// =====================================================
template<class T>
std::vector<T> differtialArray(const std::vector<T>& inArray)
{
    std::vector<T> outArray = inArray;
    for (unsigned i = 1; i < inArray.size(); i++)
        outArray[i] = inArray[i] - inArray[i-1];
    return outArray;
}

// =====================================================
// 1D integral function f'(i) = f(i) + f(i-1), f'(0) = f(0)
// =====================================================
template<class T>
std::vector<T> integralArray(const std::vector<T>& inArray)
{
    std::vector<T> outArray = inArray;
    for (unsigned i = 1; i < inArray.size(); i++)
        outArray[i] = inArray[i] + inArray[i-1];
    return outArray;
}

// =====================================================
// Given an array, find the largest possible sum of
// a sequence of consecutive values in the array
// 
// Assume empty subarray is allowed -> at least 0
// also be known as Kadane method
// =====================================================
template<class T>
T maximumSubarraySum(const std::vector<T>& inArray)
{
    T best = 0, sum = 0;
    for (unsigned i = 0; i < inArray.size(); i++) {
        sum = std::max(inArray[i], inArray[i]+sum);
        best = std::max(best, sum);
    }
    return best;
}

#endif