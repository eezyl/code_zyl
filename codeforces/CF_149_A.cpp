//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/149/A
//   Date    :   2019/04/17 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <iostream>
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

    int k;
    scanf("%d", &k);
    vector<int> month(12);
    for (int i = 0; i < 12; i++)
        scanf("%d", &month[i]);
    sort(month.rbegin(), month.rend());

    int sum = 0;
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < 12 && !flag; i++)
    {
        sum += month[i];
        if (sum >= k)
        {
            flag = 1;
            ans = i+1;
        }
    }
    if (k == 0)
        printf("0\n");
    else if (flag)
        printf("%d\n", ans);
    else
        printf("-1\n");


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
