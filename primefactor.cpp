#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define endl "\n";
typedef long long int ll;
using namespace std;
vector<int> se(1000000, 1);
void precompute()
{
    int n = se.size();
    se[0] = 0;
    se[1] = 1;
    for (int i = 2; i < n; i++)
    {
        se[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (se[i] == i)
        {
            for (int j = i * i; j < n; j += i)
            {
                if (se[j] == j)
                    se[j] = i;
            }
        }
    }
}
vector<int> primefactor(int n)
{
    vector<int> v;
    while (n != 0)
    {
        v.push_back(se[n]);
        n = n / se[n];
        if (n == 1)
            break;
    }

    return v;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int n;
    cin >> n;
    vector<int> v = primefactor(n);
    n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
}