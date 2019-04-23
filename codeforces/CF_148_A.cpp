//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/148/A
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
    int k, l, m, n, d;
    scanf("%d%d%d%d%d", &k, &l, &m, &n, &d);
    // vector<bool> hit(d+1, false);

    int ans = 0;
    for (int i = 1; i <= d; i++)
    {
        if (i%k == 0 || i%l == 0 || i%m == 0 || i%n == 0)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
