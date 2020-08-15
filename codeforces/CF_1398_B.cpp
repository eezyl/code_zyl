// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1398/B
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
        string str;
        cin >> str;
        vector<int> num;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '1') {
                int c = 1;
                while (++i<str.size() && str[i] == '1') {
                    ++c;
                }
                num.push_back(c);
            }
        }
        sort(num.rbegin(), num.rend());
        int ans = 0;
        for (int i = 0; i < num.size(); i+=2)
            ans += num[i];
        cout << ans << endl;
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
