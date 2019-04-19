//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1151/D
//   Date    :   2019/04/18
//
//********************************************************

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <stack>
#include <bitset>


using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

struct my_data{
    my_data(LL x=-1, LL y=-1) : a(x), b(y) {}
    LL a;
    LL b;
    bool operator< (my_data& d) {
        return (a-b) > (d.a-d.b);
    }
};

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<my_data> v(n);
    for (int i = 0; i < n; i++) {
        LL a, b;
        scanf("%I64d %I64d", &a, &b);
        v[i] = my_data(a, b);
    }
    sort(v.begin(), v.end());

    LL ans = 0;

    for (int i = 0; i < n; i++) {
        // cout << v[i].a << " " << v[i].b << endl;
        ans += v[i].a * i + v[i].b * (n-i-1);
    }
    printf("%I64d\n", ans);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
