// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/contest/1393/problem/C
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

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> count(n+1, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            count[a]++;
        }
        sort(count.rbegin(), count.rend());
        int max = count[0];
        //cout << "a " << max << endl;
        int max_count = 0;
        int remain_sum = 0;
        for (int i = 0; i <= n; ++i) {
            if (count[i] == max)
                max_count++;
            else
                remain_sum += count[i];
        }
        int ans = remain_sum / (max-1) + (max_count-1);
        printf("%d\n", ans);
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
