// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1395/D
//   Date    :   2020/08/12
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

    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        LL n, d, m;
        cin >> n >> d >> m;
        vector<LL> gr;
        vector<LL> le;
        for (int i = 0; i < n; ++i) {
            LL a;
            cin >> a;
            if (a > m)
                gr.push_back(a);
            else
                le.push_back(a);
        }

        sort(gr.rbegin(), gr.rend());
        sort(le.rbegin(), le.rend());
        gr.insert(gr.begin(), 0);
        le.insert(le.begin(), 0);
        for (int i = 1; i < gr.size(); ++i) {
            gr[i] += gr[i-1];
            //cout << gr[i] << " ";
        }
        //cout << endl;
        for (int i = 1; i < le.size(); ++i) {
            le[i] += le[i-1];
            //cout << le[i] << " ";
        }
        //cout << endl;
        LL ans = le.back();
        for (int i = 1; i < gr.size(); ++i) if ( (d+1)*(i-1)+1 <= n) {
                //cout << (d+1)*(i)+1 << endl;
            if (n-(d+1)*(i-1)-1 >= le.size())
                ans = max(ans, gr[i]+le.back());
            else
                ans = max(ans, gr[i] + le[n-(d+1)*(i-1)-1]);
        }

        cout << ans << endl;
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
