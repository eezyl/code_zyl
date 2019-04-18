//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/489/C
//   Date    :   2019/04/18 (upload date)
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


    int m, s;
    scanf("%d %d", &m, &s);
    vector<int> max(10, 0);
    vector<int> min(10, 0);
    if (s == 0 && m == 1)
        printf("0 0\n");
    else if (s == 0 || m*9 < s)
        printf("-1 -1\n");
    else
    {
        // compute maxima
        max[9] = m;
        max[0] = (m*9 - s) / 9;
        max[9] -= max[0];
        if ((m*9-s) % 9 > 0)
        {
            max[9-(m*9-s) % 9]++;
            max[9]--;
        }

        // compute minima
        int has1 = 0;
        if ((m-1)*9 > (s-1))
        {
            has1 = 1;
            s--;
            m--;
        }

        min[0] = m;
        min[9] = (s - m*0) / 9;
        if ((s - m*0) % 9 > 0)
        {
            min[(s - m*0) % 9]++;
            min[0]--;
        }
        min[0] -= min[9];

/*
        if (min[1] && min[0])
        {
            min[1]--;
            has1 = 1;
        }
        else if (min[0])
        {
            min[0]--;
            has1 = 1;
            for (int i = 1; i < 10; i++)
                if (min[i] != 0)
                {
                    min[i]--;
                    min[i-1]++;
                    break;
                }
        }
*/
        // show answer
        if (has1 == 1)
            printf("1");
        for (int i = 0; i < 10 ; i++)
            for (int j = 0; j < min[i]; j++)
                printf("%d", i);
        printf(" ");

        for (int i = 9; i >= 0; i--)
            for (int j = 0; j < max[i]; j++)
                printf("%d", i);
        printf("\n");

    }


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
