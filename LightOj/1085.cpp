#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

//bitmask//
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
////////////////////////////////////////////////////////
#define MOD 1000000007
#define maxi 100006
ll tree[4*maxi];
int a[maxi];
int n;
int cnt;

ll query(int node, int b, int e, int i)
{
    if (i > e || i < b)
        return 0;
    if (b==i)
        return tree[node]%MOD;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    if(mid>=i) return query(Left, b, mid, i);
    else return (tree[Left] + query(Right, mid + 1, e, i))%MOD;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] += newvalue;
        tree[node] %= MOD;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = (tree[Left]%MOD + tree[Right]%MOD)%MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

	int t,cs=1;
	ll result;
	ll ans;
    isc(t);
    map <int, int> mp;
	while(t--) {
		scanf("%d", &n);
		cnt = 0;
		ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		vector <int> b(a, a+n);

		memset(tree, 0, sizeof tree);

		mp.clear();

		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++) {
			if(mp[b[i]] == 0) {
				mp[b[i]] = ++cnt;
			}
		}

		for (int i = 0; i < n; i++) {


			result = query(1,1,cnt,mp[a[i]] - 1) + 1;
			cout<<i<<" "<<result<<endl;
			ans = (result  + ans) % MOD;
			update(1,1,cnt,mp[a[i]], result);
		}

		printf("Case %d: %lld\n", cs++, ans);
	}
		return 0;

}
