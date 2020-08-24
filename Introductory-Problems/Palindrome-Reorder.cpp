
/**
 * Author : Deep Raval
 * There are no two words in the English language more harmful than "good job".
 * 1729 0_0
**/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;
#define endl '\n'
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define FAST_IO ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define bp(x) __builtin_popcount(x)
#define zf(x) __builtin_clz(x)
#define zl(x) __builtin_ctz(x)
#define par(x) __bultin_parity(x)
#define all(x) (x).begin(), (x).end()
/* **************************************************************************************** */
/*
*/
void test_case()
{
    string s;
    cin >> s;
    map <char, int> m;
    for(char c : s) m[c]++;

    string ans = "";

    if(s.length() & 1)
    {
        char mid;
        int odd = 0;
        for(auto p : m)
        {
            if(p.second && p.second & 1)
                odd ++;
        }
        if(odd != 1)
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
        else 
        {
            for(auto p : m)
            {
                if(p.second & 1)
                {
                    mid = p.first;
                    ans += string((p.second - 1) / 2, p.first);
                }
                else if(p.second)
                {
                    ans += string(p.second / 2, p.first);
                }
            }
        }
        cout << ans << mid;
        reverse(all(ans));
        cout << ans << endl;
    }
    else 
    {
        for(auto p : m)
        {
            if(p.second & 1)
            {
                cout << "NO SOLUTION" << endl;
                return;
            }
            else if(p.second)
            {
                ans += string(p.second / 2, p.first);
            }
        }
        cout << ans;
        reverse(all(ans));
        cout << ans;
    }
    return;
}
int main()
{
	FAST_IO
    int t = 1;
    // cin >> t;
    while(t--)
        test_case();
	return 0;
}