//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/158/B
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int a[5] = {0};
    int ans = 0;
    while (n--)
    {
        int s;
        scanf("%d", &s);
        a[s]++;
    }

    ans += a[4];

    if (a[3] > a[1])
    {
        ans += a[3];
        a[1] = 0;
    }
    else
    {
        ans += a[3];
        a[1] = a[1] - a[3];
    }

    ans += a[2] / 2;
    a[2] = a[2] % 2;
    if (a[2] == 1)
    {
        ans++;
        a[1] -= 2;
    }

    if (a[1] > 0)
        ans += (a[1] + 3) / 4;

    printf("%d\n", ans);
    return 0;
}
