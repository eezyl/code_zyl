//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/580/A
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
    vector<int> a(n);
    int ans = 0;
    int count = 0;
    int min = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] >= min)
        {
            count++;
            ans = max(ans, count);
        }
        else
        {
            count = 1;
        }
        min = a[i];
    }

    printf("%d\n", ans);

    return 0;
}
