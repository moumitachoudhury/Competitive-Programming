//hoynai....... :(
//s2 er calculation bujhinai :'(

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

#define mx 100004
ll arr[mx];
inline ll cum(ll n)
{
    return (n*(n+1))/2;
}
ll r,l;
ll histogram(ll hist[], int n)
{
    stack<int> s;

    int tp;

    int i = 1;
    while (i <= n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            if(s.empty())
            {
                l = i;
                r = tp;
            }
            else
            {
                l = i-s.top()-1;
                r = tp;
            }
            // area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        if(s.empty())
        {
            l = i;
            r = tp;
        }
        else
        {
            l = i-s.top()-1;
            r = tp;
        }
    }

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t,cs=1;
    isc(t);
    while(t--)
    {
        int n;
        isc(n);
        loop(i,1,n)llsc(arr[i]);
        ll minuss = 0;
        arr[0] = INT_MIN;
        arr[n+1] = INT_MIN;


        stack<int> s;

        int tp;

        int i = 1;
        while (i <= n)
        {
            if (s.empty() || arr[s.top()] <= arr[i])
                s.push(i++);
            else
            {
                tp = s.top();
                s.pop();
                if(s.empty())
                {
                    l = tp;
                    r = i;
                    minuss += cum(i-l+1)*(r-i+1)*arr[i] + cum(r-i)*(i-l+1)*arr[i];
                }
                else
                {
                    l = i-s.top()-1;
                    r = tp;
                    if(l>r) swap(l,r);
                    minuss += cum(i-l+1)*(r-i+1)*arr[i] + cum(r-i)*(i-l+1)*arr[i];
                }
                // area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            }
        }
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            if(s.empty())
            {
                l = tp;
                r = i;
                minuss += cum(i-l+1)*(r-i+1)*arr[i] + cum(r-i)*(i-l+1)*arr[i];
            }
            else
            {
                l = i-s.top()-1;
                r = tp;
                minuss += cum(i-l+1)*(r-i+1)*arr[i] + cum(r-i)*(i-l+1)*arr[i];
            }
        }



        //cout<<arr[i]<<" "<<l<<" "<<r<<" "<<minuss<<endl;

        ll pluss = 0;
        int mul = n, inc = n-2;
        loop(i,1,n)
        {
            pluss += (abs(mul)*arr[i]);
            mul += inc;
            inc -= 2;
        }
        printf("Case %d: %lld\n",cs++,pluss-minuss);
    }
//


    return 0;
}


