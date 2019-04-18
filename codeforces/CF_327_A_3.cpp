//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/327/A
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
#include <map>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    int n;
    int ans = 0;
    int sum = 0;
    int max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            ans++;
            sum--;
        }
        else if (a == 0)
        {
            sum++;
        }
        if (max < sum)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    if (n == 1)
        printf("%d\n", !ans);
    else if (n == ans)
        printf("%d\n", ans-1);
    else
        printf("%d\n", ans + max);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
