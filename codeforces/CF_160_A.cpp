//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/160/A
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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a.rbegin(), a.rend());
    int ans = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1;
        total += a[i];
        if (total*2 > sum)
            break;
    }

    printf("%d\n", ans);

    return 0;
}
