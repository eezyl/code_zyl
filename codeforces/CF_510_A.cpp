//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/510/A
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

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> ss(n+1, string(m, '.'));

    for (int i = 1; i <= n; i++)
        if (i % 2)
            ss[i] = string(m, '#');
        else if (i / 2 % 2)
            ss[i][m-1] = '#';
        else
            ss[i][0] = '#';
    for (int i = 1; i <= n; i++)
        printf("%s\n", ss[i].c_str());


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
