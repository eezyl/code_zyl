//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/734/A
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

using namespace std;

typedef long long LL;



int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n;
    char str[100005];
    scanf("%d", &n);
    scanf("%s", str);

    int A = 0;
    int D = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == 'A')
            A++;
        else
            D++;

    if (A > D)
        printf("Anton\n");
    else if (A < D)
        printf("Danik\n");
    else
        printf("Friendship\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
