//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/144/A
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
    vector<int> num(n);

    int max = -10;
    int max_it = -1;
    int min = 101;
    int min_it = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > max)
        {
            max = num[i];
            max_it = i;
        }

        if (num[i] <= min)
        {
            min = num[i];
            min_it = i;
        }
    }

    int ans = max_it + (n - min_it-1);
    if (max_it > min_it)
        printf("%d\n", ans - 1);
    else
        printf("%d\n", ans);
    return 0;
}
