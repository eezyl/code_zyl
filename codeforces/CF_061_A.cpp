//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/61/A
//   Date    :   2019/04/17 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    char str1[110];
    char str2[110];
    scanf("%s", str1);
    scanf("%s", str2);
    int len = strlen(str1);
    for (int i = 0; i < len; i++)
        if (str1[i] == str2[i])
            printf("0");
        else
            printf("1");
    printf("\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
