#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int cases,fn[10005],i,n,caseno=0;
    scanf("%lld",&cases);
    while(cases--){
    for(i=0;i<6;i++){
        scanf("%lld",&fn[i]);
    }
    scanf("%lld",&n);
    for(i=6;i<=n;i++){
            fn[i]=(fn[i-1]+fn[i-2]+fn[i-3]+fn[i-4]+fn[i-5]+fn[i-6])%10000007;
    }
    printf("Case %lld: %lld\n",++caseno,fn[n]%10000007);
    }
    return 0;
}
