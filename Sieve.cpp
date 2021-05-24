#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl "\n";
typedef long long int ll;
using namespace std;
vector<bool> Sieve(100, 1);
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
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = Sieve.size();
    precompute();
    for (int i = 0; i < n; i++)
    {
        if (Sieve[i] == 1)
        {
            cout << i << endl;
        }
    }
}