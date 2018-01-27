#include<stdio.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define pfcs(cs,n) printf("Case %d: %d\n",cs,temp)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int t,a,cs=1;
    isc(t);
    while(t--)
    {

        int n;
        isc(n);
        isc(a);
        int temp = 1;
        for(int i=1;i<n;i++)
        {
            isc(a);
            if(i+1-temp<=a) temp++;
        }

       pfcs(cs++,n);

    }

    return 0;
}

