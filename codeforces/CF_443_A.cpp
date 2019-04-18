//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/443/A
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


    char str[10000];
    fgets(str, 10000, stdin);

    set<char> ch_s;
    for (char* ptr = strtok(str, " {,}"); ptr != NULL; ptr = strtok(NULL, " {,}"))
    {
        if (ptr[0] >= 'a' && ptr[0] <= 'z')
            ch_s.insert(ptr[0]);
    }

    printf("%d\n", ch_s.size());



    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
