//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/231/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0;
    while (n--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a+b+c >= 2)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
