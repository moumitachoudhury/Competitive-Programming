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

ll histogram(int hist[], int n)
{
    stack<int> s;

    ll max_area = 0;
    int tp;
    ll area_with_top;

    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    int a[1005];
    char city[1005][1005];
    int cnt[1005];
    cin>>t;
    while(t--)
    {
        ll mx = -1;
        int m,n;
//        char get = getchar();
        memset(cnt,0,sizeof(cnt));
        scanf("%d %d",&m,&n);

        for(int i=0; i<m; i++)
        {
            //cout<<i<<endl;
            int j=0;
            while(j<n)
            {

                char x;
                scanf("%c",&x);
                if(x =='F')
                {

                    a[j]=1;
                    j++;
                }

                else if(x=='R')
                {
                    //cout<<i<<endl;
                    a[j]=0;
                    j++;
                }


            }
            for(int j=0;j<n;j++)
            {
                if(a[j]==1) cnt[j]++;
                else cnt[j]=0;
            }
            ll largestarea = histogram(cnt,n);
            if(largestarea>mx) mx = largestarea;

        }
        ll ans = 3*mx;printf("%lld\n",ans);
    }



        return 0;
    }


