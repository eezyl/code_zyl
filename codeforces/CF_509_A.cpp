//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/509/A
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


    int n;
    scanf("%d", &n);
    vector<vector<int> > a(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
    {
        a[i][1] = 1;
        a[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            a[i][j] = a[i-1][j] + a[i][j-1];

    printf("%d\n", a[n][n]);







    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
