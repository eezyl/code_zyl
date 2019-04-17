//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/141/A
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


    char str1[105];
    char str2[105];
    char str3[305];

    vector<int> letter1(26, 0);
    vector<int> letter2(26, 0);

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);

    for (int i = 0; str1[i]; i++)
        letter1[str1[i]-'A']++;
    for (int i = 0; str2[i]; i++)
        letter1[str2[i]-'A']++;
    for (int i = 0; str3[i]; i++)
        letter2[str3[i]-'A']++;

    int flag = 1;
    for (int i = 0; i < 26 && flag; i++)
        if (letter1[i] != letter2[i])
            flag = 0;

    if (flag == 1)
        printf("YES\n");
    else
        printf("NO\n");








    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
