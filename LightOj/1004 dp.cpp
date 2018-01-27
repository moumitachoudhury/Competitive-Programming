#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int num[220][220];
int dp[220][220];
int n;
LL call(LL a,LL b)
 {
     if(num[a][b]==0) return 0;
     if(dp[a][b]!=-1) return dp[a][b];
     LL ret=num[a][b];
     if(a<=n)
      ret+=max(call(a-1,b),call(a-1,b-1));
     else
     ret+=max(call(a-1,b),call(a-1,b+1));
     return dp[a][b]=ret;
 }
int main()
 {
     int t;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)
      {
          scanf("%lld",&n);
          for(int j=0;j<=200;j++)
            for(int k=0;k<=200;k++)
              {
                   num[j][k]=0;
                   dp[j][k]=-1;
              }
          for(int j=1;j<n;j++)
           for(int k=1;k<=j;k++)
             scanf("%lld",&num[j][k]);
          for(int j=n;j<2*n;j++)
           for(int k=1;k<=2*n-j;k++)
             scanf("%lld",&num[j][k]);
          LL ans=num[2*n-1][1];
          ans+=max(call(2*n-2,1),call(2*n-2,2));
          printf("Case %d: %lld\n",i,ans);
      }
      return 0;
 }
