//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1166/A
//   Date    :   2019/05/17
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<string> name(n);
    vector<int> first(128, 0);
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        first[name[i][0]]++;
    }
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (first[i] != 0) {
            int num = first[i] / 2;
            ans += num * (num-1) / 2;
            num = first[i] - num;
            ans += num * (num-1) / 2;
        }
    }
    printf("%d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
