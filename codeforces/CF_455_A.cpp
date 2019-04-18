//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/455/A
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
    scanf("%d", &n);
    vector<LL> a(1e5+5, 0);
    vector<LL> score(1e5+5, 0);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%I64d", &t);
        a[t]++;
    }
    score[1] = a[1];
    score[2] = max(score[1], (LL)a[2] * 2);

    for (int i = 3; i <= 1e5+1; i++)
        score[i] = max(score[i-1], score[i-2] + i * a[i]);
    printf("%I64d\n", score[1e5+1]);








    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
