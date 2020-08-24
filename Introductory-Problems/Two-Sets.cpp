
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

void test_case()
{
    ll n;
    cin >> n;
    if( ((n * (n + 1)) / 2 ) & 1)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES" << endl;
        vector <ll> a(n + 1);
        ll cur = n;
        a[n] = 1;
        ll sum = (n * (n + 1)) / 4;
        while(sum != 0)
        {
            sum -= cur;
            if(sum < cur)
            {
                a[sum] = 1;
                break;
            }
            else 
            {
                --cur;
                a[cur] = 1;
            }
        }

        vector <ll> p, q;

        for(int i = 1; i <= n ; i ++ )
        {
            if(a[i])
                q.push_back(i);
            else 
                p.push_back(i);
        }


        cout << p.size() << endl;
        for(ll x : p)
            cout << x << ' ';
        cout << endl;

        cout << q.size() << endl;
        for(ll x : q)
            cout << x << ' ';
        cout << endl;
    }
    return;
}
int main()
{
	FAST_IO
    int t = 1;
    //cin >> t;
    while(t--)
        test_case();
	return 0;
}