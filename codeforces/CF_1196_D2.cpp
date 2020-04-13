//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1196/D2
//   Date    :   2019/07/27
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

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL


    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int n, k;
        scanf("%d%d", &n, &k);
        string str;
        cin >> str;
        string RGB("RGB");
        vector<int> preSum1(n+1, 0), preSum2(n+1, 0), preSum3(n+1, 0);
        for (int j = 0; j < n; ++j) {
            preSum1[j+1] = preSum1[j];
            if (str[j] != RGB[j%3])
                preSum1[j+1] += 1;
            preSum2[j+1] = preSum2[j];
            if (str[j] != RGB[(j+1)%3])
                preSum2[j+1] += 1;
            preSum3[j+1] = preSum3[j];
            if (str[j] != RGB[(j+2)%3])
                preSum3[j+1] += 1;
        }
        int ans = n;
        for (int j = k; j < n+1; ++j) {
            ans = min(ans, preSum1[j] - preSum1[j-k]);
            ans = min(ans, preSum2[j] - preSum2[j-k]);
            ans = min(ans, preSum3[j] - preSum3[j-k]);
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
