//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/266/A
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
    char str[55];
    scanf("%d", &n);
    scanf("%s", str);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        for (i = i + 1; i < n; i++)
            if (str[i] == ch)
                ans++;
            else
            {
                i--;
                break;
            }
    }

    printf("%d\n", ans);

    return 0;
}
