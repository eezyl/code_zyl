//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/189/A
//   Date    :   2019/04/17 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);

    vector<int> ans(n+1, -n-n-n);
    if (a < n+1)
        ans[a] = 1;
    if (b < n+1)
        ans[b] = 1;
    if (c < n+1)
        ans[c] = 1;
    for (int i = 0; i <= n; i++)
    {
        if (i - a >= 0)
            ans[i] = max(ans[i], ans[i-a]+1);
        if (i - b >= 0)
            ans[i] = max(ans[i], ans[i-b]+1);
        if (i - c >= 0)
            ans[i] = max(ans[i], ans[i-c]+1);
        //printf("%d\n", ans[i]);
    }
    /*
    for (int i = 0; i*a <= n; i++)
        for (int j = 0; i*a + j*b <= n; j++)
                if ( (n-(i*a + j*b))%c == 0)
                    ans = max (ans, i+j+(n-(i*a + j*b))/c);
                    */
    printf("%d\n", ans[n]);
    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
