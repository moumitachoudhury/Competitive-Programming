#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define pfcs(cs) printf("Case %d:\n",cs);
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;


int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        vector<int>start;
        vector<int>endi;
        //vector<int>::iterator it1,it2;
        int n,q;
        int que[50007];
        scanf("%d %d",&n,&q);
        //cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            start.push_back(a);
            endi.push_back(b);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d",&que[i]);
        }
        sort(start.begin(),start.end());
        sort(endi.begin(),endi.end());
        printf("Case %d:\n",cs++);
   //     cout<<"Case "<<cs++<<":"<<endl;
        for(int i=0;i<q;i++)
        {
            int up = upper_bound(start.begin(),start.end(),que[i]) - start.begin();
            int low = lower_bound(endi.begin(),endi.end(),que[i]) - endi.begin();
            printf("%d\n",up-low);
        }
    }
    return 0;
}
