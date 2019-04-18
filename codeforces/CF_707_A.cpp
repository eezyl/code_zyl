//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/707/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    int a, b;
    scanf("%d %d", &a, &b);
    int n = a*b;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %1c ", &ch);

        if (ch == 'C' || ch == 'M' || ch == 'Y')
            ans = 1;
    }

    if (ans == 1)
        printf("#Color\n");
    else
        printf("#Black&White\n");






    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
