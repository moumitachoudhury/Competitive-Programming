#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll dp[35][905];

ll solve(int i, int rem)
{
    if(i==rem) return 1;
    if(rem==1) return i;
    if(rem==0) return 1;
    if(dp[i][rem]!=-1) return dp[i][rem];

    ll ret = solve(i-1,rem) + solve(i-1,rem-1);
    return dp[i][rem] = ret;




    /* if(rem==0) return 1;
     if(i==n || j==n) return 0;

     if(dp[i][j][rem]!=-1) return dp[i][j][rem];
     ll ret = solve(i+1, j+1, rem-1) + solve(i,j+1,rem) + solve(i+1, j, rem);
     cout<<ret<<endl;
     return dp[i][j][rem] = ret;
     */
}

int main()
{
    int t,cs=1;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--)
    {

        cin>>n>>k;
        if(k>n)
        {
            cout<<"Case "<<cs++<<": 0"<<endl;
        }
        else
        {
            ll ans = solve(n,k);
            for(int i=0; i<k; i++)
            {
                ans *= (n-i);
            }
            cout<<"Case "<<cs++<<": "<<ans<<endl;
        }

    }
    return 0;
}
