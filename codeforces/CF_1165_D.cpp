//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1165/D
//   Date    :   2019/05/14
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

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        //cout << "aaa" << n << endl;
        LL max_num = -LL_INF;
        LL min_num = LL_INF;
        vector<LL> num(n);
        for (int j = 0; j < n; j++) {
            scanf("%I64d", &num[j]);
            if (num[j] > max_num)
                max_num = num[j];
            if (num[j] < min_num)
                min_num = num[j];
        }
        LL ans = max_num * min_num;
        int flag = 1;
        for (int j = 0 ; j < n && flag; j++) {
            if (ans % num[j] != 0)
                flag = 0;
        }

        if (flag) {
            set<LL> div;
            div.insert(1);
            div.insert(ans);
            LL sq = sqrt(ans);
            for (int k = 2; k <= sq; k++) {
                if (ans%k == 0) {
                    div.insert(k);
                    div.insert(ans/k);
                }
            }
            if (div.size()-2 != n)
                flag = 0;
        }

        if (flag)
            printf("%I64d\n", ans);
        else
            printf("-1\n");
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
