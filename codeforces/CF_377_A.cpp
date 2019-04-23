//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/377/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> f(m);

    for (int i = 0; i < m; i++)
        scanf("%d", &f[i]);
    sort(f.begin(), f.end());

    int ans = 10000;
    for (int j = 0; j+n <= m; j++)
        if (ans > f[j+n-1]-f[j])
            ans = f[j+n-1]-f[j];

    printf("%d\n", ans);

    return 0;
}
