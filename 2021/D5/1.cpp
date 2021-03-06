#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    multiset<array<int,2>> grind;
    int x1, x2, y1, y2;
    string s;
    int res = 0;
    while (getline(cin, s))
    {
        sscanf(s.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        bool xe=x1==x2;
        bool ye=y1==y2;
        if(xe==ye)continue;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        
        while(x1 <= x2 and y1<=y2){
            grind.insert({x1, y1});
            if(!ye)y1++;
            if(!xe)x1++;
        }
    }
    array<int, 2> last = {-1, -1};
    for (auto c : grind)
    {
        if (c == last)
            continue;
        if (grind.count(c) >= 2)
            res++;
        last = c;
    }
    cout << res << endl;
}
