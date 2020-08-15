// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1398/C
//   Date    :   2020/08/14
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
#include <unordered_map>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;
const int MOD = 1e9+7;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> num(n);
        vector<int> sum(n+1, 0);
        map<int, LL> m;
        for (int i = 0; i < n; ++i) {
            num[i] = str[i] - '0' - 1;
            sum[i+1] = sum[i]+num[i];
            m[sum[i+1]]++;
        }

        LL ans = 0;

        for (int i = 1; i <= n; ++i) {
            if (sum[i] == 0)
                ++ans;
            m[sum[i]]--;
            ans += m[sum[i]];
        }

        cout << ans << endl;
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
