//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/59/A
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
    #endif // LOCAL


    char str[110];
    scanf("%s", str);
    int up = 0, low = 0;
    for (int i = 0; str[i]; i++)
    {
        if (islower(str[i]))
            low++;
        if (isupper(str[i]))
            up++;
    }

    if (low >= up)
        for (int i = 0; str[i]; i++)
            printf("%c", tolower(str[i]));
    else
        for (int i = 0; str[i]; i++)
            printf("%c", toupper(str[i]));
    printf("\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
