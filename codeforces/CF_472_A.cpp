//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/472/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

bool isnotprime(int num)
{
    if (num == 1 || num == 2)
        return false;

    if (num % 2 == 0)
        return true;
    int root = sqrt(num);

    for (int i = 3; i <= root; i += 2)
        if (num % i == 0)
            return true;

    return false;
}
int main()
{
    int n;
    scanf("%d", &n);

    if (n%2 == 0 && isnotprime(n/2))
        printf("%d %d\n", n/2, n/2);
    else
        for (int i = 4; i < n; i++)
            if (isnotprime(i) && isnotprime(n-i))
            {
                printf("%d %d\n", i, n-i);
                break;
            }
    return 0;
}
