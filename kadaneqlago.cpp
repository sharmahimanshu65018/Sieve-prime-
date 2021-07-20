#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef vector<vector<pair<int,int>> > vvp;
typedef vector<pair<int,int>> vp;
typedef vector<pair<long long,long long>> vpl;
#define     mod 1000000007
#define     mod2 998244353
#define rep(i,n) for(int i = 0; i < n; i++)
#define repm(i,s,m) for(int i = s; i < e; i++)
#define rrep(i,n) for(ll i = n-1; i >= 0; i--)
#define     endl "\n" 
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
//#define     int long long
#define all(x) (x).begin(), (x).end()
 

void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL); 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}







//********************************************code**********************************************************//


int kadanealgo(vi &v,int n)
{
    int max=v[0],sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return max;
}
void work()
{
    int n;
    cin>>n;
    vi v(n);
    rep(i,n)cin>>v[i];
    cout<<kadanealgo(v,n)<<endl;
}


signed main()
{
    fast();
    
    ll t;
    t=1;
    //cin >> t;
    while(t--) 
        {
            work();
            cout<<endl; 
        }
    
    return 0;
}