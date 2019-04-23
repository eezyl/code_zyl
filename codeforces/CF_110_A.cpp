//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/110/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long int LL;

int main()
{
    LL num;
    scanf("%I64d", &num);
    int count = 0;
    while (num != 0)
    {
        LL t = num % 10;
        if (t == 4 || t == 7)
            count++;
        num /= 10;
    }

    if (count == 4 || count == 7)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
