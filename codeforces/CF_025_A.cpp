//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/25/A
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

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n;
    scanf("%d", &n);
    vector<int> a(n+1, 0);
    int even = 0, odd = 0;
    int anse, anso;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2)
        {
            odd++;
            anso = i;
        }
        else
        {
            even++;
            anse = i;
        }
    }
    if (odd == 1)
        printf("%d\n", anso);
    else
        printf("%d\n", anse);


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
