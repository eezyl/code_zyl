//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/271/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

bool isbeatiful(int num)
{
    set<int> s;

    while (num != 0)
    {
        int d = num % 10;
        s.insert(d);
        num = num / 10;
    }

    if (s.size() == 4)
        return true;
    return false;
}

int main()
{
    int y;
    scanf("%d", &y);

    vector<int> beatiful_year;
    for (int i = 1000; i <= 9000; i++)
        if (isbeatiful(i))
            beatiful_year.push_back(i);
    beatiful_year.push_back(9012);

    for (int i = 0; i < beatiful_year.size(); i++)
        if (beatiful_year[i] > y)
        {
            printf("%d\n", beatiful_year[i]);
            break;
        }
    return 0;
}
