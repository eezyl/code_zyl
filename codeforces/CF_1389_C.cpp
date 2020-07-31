// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1389/C
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

int helper(vector<int>& num, int a, int b) {
    int flag = 0;
    int c = 0;
    for (int i = 0; i < num.size(); ++i) {
        if (!flag && num[i] == a) {
            ++c;
            flag = 1;
        } else if (flag && num[i] == b) {
            ++c;
            flag = 0;
        }
    }
    if (c%2)
        return (int)num.size()-c+1;
    return (int)num.size()-c;
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
        string str;
        cin >> str;
        vector<int> num(str.size());
        vector<int> digit(10, 0);
        for (int i = 0; i < str.size(); ++i) {
            num[i] = str[i] - '0';
            digit[str[i]-'0']++;
        }
        int res = str.size() - 2;
        for (int i = 0; i < 10; ++i)
            res = min(res, (int)str.size() - digit[i]);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) if (i != j) {
                res = min(res, helper(num, i, j));
            }
        }

        printf("%d\n", res);
    }


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
