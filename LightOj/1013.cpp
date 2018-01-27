#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
ll dp1[35][35];
ll dp2[35][35];
ll solve(int i, int j)
{
    if(i==0) return dp1[i][j] = j;
    if(j==0) return dp1[i][j] = i;
    if(dp1[i][j]!=-1) return dp1[i][j];
    ll ans = INT_MAX;
    if(s1[i-1]==s2[j-1]) ans =1 + solve(i-1,j-1);
    else ans = min(1 + solve(i-1,j), 1 + solve(i,j-1));

    return dp1[i][j] = ans;
}

ll solve2(int i, int j)
{
    if(i==0) return 1;
    if(j==0) return 1;
    if(dp2[i][j]!=-1) return dp2[i][j];
    ll ans = 0;
    if(s1[i-1]==s2[j-1]) ans = solve2(i-1,j-1);
    else if(dp1[i][j-1]<dp1[i-1][j]) ans = solve2(i,j-1);
    else if(dp1[i-1][j]<dp1[i][j-1]) ans = solve2(i-1,j);
    else ans = solve2(i-1,j) + solve2(i,j-1);
    //cout<<ans<<endl;
    return dp2[i][j] = ans;
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        ll ans = solve(s1.size(), s2.size());
        //cout<<ans<<endl;
        ll ans2 = solve2(s1.size(),s2.size());
        //cout<<ans2<<endl;
        cout<<"Case "<<cs++<<": "<<ans<<" "<<ans2<<endl;
    }
    return 0;
}
