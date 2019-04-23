//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/69/A
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
    int sum_x = 0, sum_y = 0, sum_z = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        scanf("%d%d%D", &x, &y, &z);
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    if (sum_x == 0 && sum_y == 0 && sum_z == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
