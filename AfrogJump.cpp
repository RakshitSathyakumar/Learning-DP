// *****************************Divinity************************* //
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void read(vector<int> &a);
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forbn(i, n) for (int i = n; i > 0; i--)
#define nl "\n";
#define binary(n) std::bitset<32>(n).to_string()
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)
#define all(arr) arr.begin(), arr.end()
#define asort(a) sort(a.begin(), a.end())
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
#define cnl cout << endl
#define vll vector<int>
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int binpow(int a, int b);
bool ispowerof2(int x);
int digits(int n);
bool isPrime(int x);


int const N=1e5+7;
int dp[N];

int frog(int ht[],int n)
{
	int cst=INT_MAX;
	if(n==0 || n==1) return 0;

	//if already calculated return the value;
	if(dp[n]!=-1)
		return dp[n];
	//way one to choose path
	cst=min(cst,frog(ht,n-1) + abs(ht[n-1]-ht[n-2]));

	if(n>=2)
	{
		//way two to choose
	cst=min(cst,frog(ht,n-2)+abs(ht[n-1] - ht[n-3]));

	}
	return dp[n]=cst;
}

void solve()
{
	int n;cin>>n;
	memset(dp,-1,sizeof(dp));
	int ht[n];
	for(int i=0;i<n;i++)
		cin>>ht[i];

	cout<<frog(ht,n)<<nl;

}   

int32_t main()
{

    fastIO1;
    fastIO2;
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    // for (int tt = 1; tt <= t; tt++)
    // {
    //     // Google(tt);
        solve();
    // }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cnl;
    #ifndef ONLINE_JUDGE
    cout << "Finished in ____________________"<< clock() * 1.0 / CLOCKS_PER_SEC <<" sec"<< endl;
    #endif

    return 0;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
bool ispowerof2(int x)
{
    // Check if the number has only one set bit
    if ((x & (x - 1)) != 0)
        return false;
    return true;
}
int digits(int n)
{
    return floor(log10(n)) + 1;
}
bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

void read(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}