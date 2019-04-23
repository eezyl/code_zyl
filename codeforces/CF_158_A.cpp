//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/158/A
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
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n+1, 0);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int count = 0;
    int num = a[k-1];
    for (int i = 0; i < n && a[i] >= num; i++)
    {
        if (a[i] == 0)
            break;

        count++;
    }
    printf("%d\n", count);

    return 0;
}
