// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/contest/1393/problem/B
//   Date    :   2020/08/07
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

    int n;
    scanf("%d", &n);
    unordered_map<int, int> m;
    vector<int> count(100005, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        m[a]++;
        count[m[a]]++;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        char ch;
        int x;
        scanf(" %c %d", &ch, &x);
        if (ch == '+') {
            m[x]++;
            count[m[x]]++;
        } else {
            count[m[x]]--;
            m[x]--;
        }
        if (count[2] >= 3 && count[4] >= 1)
            printf("YES\n");
        else if (count[2] >= 2 && count[6] >= 1)
            printf("YES\n");
        else if (count[4] >= 2)
            printf("YES\n");
        else if (count[8] >= 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
