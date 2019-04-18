//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/230/A
//   Date    :   2019/04/17 (upload date)
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


    int s, n;
    scanf("%d %d", &s, &n);
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end());

    int flag = 1;
    for (int i = 0; i < n && flag; i++)
    {
        if (s <= v[i].first)
            flag = 0;
        s += v[i].second;
    }

    if (flag)
        printf("YES\n");
    else
        printf("NO\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
