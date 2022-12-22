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

//in this 0-1 knapsack problem we have check the profit that we can earned if we put the weights in the knapsack
//the point is not to full the knapsack but to earn max profut out it
//we cannot put any fraction of weight into the bag
//here {"w"} represemts the max weigtt that knapsack can hold

int recurr(int wt[],int vl[],int w,int n)
{
	int cst,ans=INT_MIN;
	if(w==0 || n==0)
		return 0;

	
	if(wt[n-1]<=w)
	{
		cst=max(recurr(wt,vl,w,n-1), (vl[n-1] + recurr(wt,vl,w-wt[n-1],n-1)));
	}
	else if(wt[n-1]>w)
	{
		cst=recurr(wt,vl,w,n-1);
	}
	ans=max(ans,cst);
	return ans;
}

//dp approach top-down approach we cereate a dp of size of the dimenation given + 4 so that we can the element of the 
//number required this is called memoizattion.
const int W=1e5+7;
int dp[103][W];

int BottomUp(int wt[],int vl[],int w,int n)
{
	int cst,ans=INT_MIN;
	if(w==0 || n==0)
		return 0;

	if(dp[n][w]!=-1)
		return dp[n][w];

	if(wt[n-1]<=w)
	{
		cst=max(recurr(wt,vl,w,n-1), (vl[n-1] + recurr(wt,vl,w-wt[n-1],n-1)));
	}
	else if(wt[n-1]>w)
	{
		cst=recurr(wt,vl,w,n-1);
	}
	ans=max(ans,cst);
	return dp[n][w]=ans;
}


// top down approach is the best dp approach ever as it does not make any muchrecuervsive calls which 
//does not lead to stackoverfloww eroor
// it is iterative dp as we use the calulated values of the previous subproblems to ssolve a new suproblem
// we intialize the matrix as step by step procedure according to the choice diagram

// int t[102][W];
int topDown(int wt[],int vl[],int w,int n)
{
	int t[n+1][w+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(wt[i-1]<=j)
			{
				t[i][j]=max(t[i-1][j],vl[i-1]+t[i-1][j-wt[i-1]]);
			}
			else if(wt[i-1]>j){
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][w];

}


void solve()
{
	memset(dp,-1,sizeof(dp));
	int n,w;cin>>n>>w;
	int wt[n];int vl[n];
	for(int i=0;i<n;i++)
		cin>>wt[i]>>vl[i];

	cout<<topDown(wt,vl,w,n);
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