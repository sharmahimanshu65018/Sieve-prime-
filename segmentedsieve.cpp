#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl "\n";
typedef long long int ll;
using namespace std;
vector<bool> Sieve(1000050, 1);
void precompute()
{
    int n, x;
    Sieve[0] = Sieve[1] = 0;
    n = Sieve.size();
    for (int i = 2; i * i <= n; i++)
    {
        if (Sieve[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            {
                Sieve[j] = 0;
            }
        }
    }
}
vector<bool> segmented(int l, int r)
{
    int n = r - l + 1;
    vector<bool> v(n, 1);
    int m = sqrt(r);
    m++;
    int k, x;
    //  int i=5;
    for (int i = 0; i < m; i++)
    {
        if (Sieve[i] == 1)
        {

            k = l / i;
            k *= i;
            if (k < l)
            {
                k = k + i;
            }
            for (int j = (k - l); j <= n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    return v;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = Sieve.size();
    precompute();
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        if ((l == 1) || (l == 2))
        {
            for (int i = l; i <= r; i++)
            {
                if (Sieve[i] == 1)
                {
                    cout << i << endl;
                }
            }
        }
        else
        {
            vector<bool> v = segmented(l, r);
            n = v.size();
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 1)
                {
                    cout << i + l << endl;
                }
            }
        }
        cout << endl;
    }
}