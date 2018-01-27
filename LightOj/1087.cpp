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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t,cs=1;
    isc(t);
    while(t--)
    {
        vector<int>d;
        int n,q;
        isc(n);isc(q);
        pfcs(cs++);
        loop(i,1,n)
        {
            int id;
            isc(id);
            d.push_back(id);
        }
        loop(i,1,q)
        {
            getchar();
            char c;int idx;
            //getchar();
            scanf("%c %d", &c, &idx);
            if(c=='c')
            {

                if(!d.empty() && d.size()>=idx)
                {
                   pf(d[idx-1]);
                  d.erase(d.begin()+idx-1);
                }
                else
                {
                    printf("none\n");

                }
               // cout<<"c te"<<endl;
            }
            else if(c=='a')
            {
                d.push_back(idx);
            }
        }

    }
    return 0;
}

