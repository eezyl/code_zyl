//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/469/A
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
    vector<int> finish(n+1, 0);
    int X;
    scanf("%d", &X);
    for (int i = 0; i < X; i++)
    {
        int num;
        scanf("%d", &num);
        finish[num]++;
    }
    int Y;
    scanf("%d", &Y);
    for (int i = 0; i < Y; i++)
    {
        int num;
        scanf("%d", &num);
        finish[num]++;
    }

    int ok = 1;
    for (int i = 1; i <= n; i++)
        if (finish[i] == 0)
            ok = 0;
    if (ok)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    return 0;
}
