//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/41/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void solve()
{
    char str1[105];
    char str2[105];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        printf("NO\n");
        return;
    }

    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[len1-i-1])
        {
            printf("NO\n");
            return;
        }

    printf("YES\n");
    return;
}

int main()
{
    solve();
    return 0;
}
