//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/467/A
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
    int ans = 0;

    while (n--)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        if (q - p >= 2)
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}
