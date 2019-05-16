//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1165/C
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

    int n;
    scanf("%d", &n);
    string str;
    cin >> str;

    vector<int> deleted(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char bi_c = str[i];
        for (int j = i+1; j < n; j++) {
            i = j;
            if (bi_c == str[j]) {
                ans++;
                deleted[j] = 1;
            } else {
                break;
            }
        }
    }
    //cout << ans << endl;
    if ((n-ans) % 2 == 1) {
        ans++;
        for (int i = n-1; i >= 0; i--) if (deleted[i] == 0) {
            deleted[i] = 1;
            break;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) if (deleted[i] == 0)
        printf("%c", str[i]);
    printf("\n");

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
