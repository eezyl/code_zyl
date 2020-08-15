// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1391/C
//   Date    :   2020/08/09
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
/*
    int n;
    scanf("%d", &n);
    int c = 0;
    vector<int> a;
    for (int i = 1; i <= n; ++i)
        a.push_back(i);

    do {
        for (int i = 1; i < n-1; ++i) {
            if (a[i] < a[i-1] && a[i] < a[i+1]) {
                ++c;
                break;
            }
        }
    }while (next_permutation(a.begin(), a.end()));
    cout << c << endl;
*/
    int n;
    scanf("%d", &n);
    if (n == 3)
        printf("2\n");
    else {
        LL a = 2;
        LL fact = 2;
        for (int i = 4; i <= n; ++i) {
            fact = fact*(i-1) % MOD;
            a = 2*a + (i-2) * fact;
            a %= MOD;
        }
        cout << a << endl;
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
