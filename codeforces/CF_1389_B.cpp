// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1389/B
//   Date    :   2020/07/29
// =====================================================

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

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, z;
        scanf("%d %d %d", &n, &k, &z);
        vector<int> num(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &num[i]);

        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i+1] = sum[i] + num[i];
        }
        vector<int> max_pair(n+1, 0);
        for (int i = 1; i < n; ++i) {
            max_pair[i+1] = max(max_pair[i], num[i] + num[i-1]);
        }

        int res = sum[k+1];
        int idx = k+1;
        int c = 0;
        while (z--) {
            if (idx > 3) {
                int b = sum[idx-2] + (c+1) * max_pair[idx-2];
                res = max(res, b);
            }
            if (idx >= 3) {
                int a = sum[idx-1] + num[idx-3] + c*max_pair[idx-1];
                res = max(res, a);
            } else {
                break;
            }
            ++c;
            idx -= 2;
        }
        printf("%d\n", res);
    }


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
