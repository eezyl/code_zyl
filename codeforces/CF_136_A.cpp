//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/136/A
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

    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        ans[num] = i;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
