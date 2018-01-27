#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,cs=1;
    int bamboo[1005], panda[1005];
    cin>>t;
    while(t--)
    {
        long long ans = 1;
        cin>>n;
        for(int i=0;i<n;i++) cin>>bamboo[i];
        for(int i=0;i<n;i++) cin>>panda[i];
        sort(panda,panda+n);
        sort(bamboo,bamboo+n);
        int ager = 0;
        for(int i=n-1;i>=0;i--)
        {
            int l = lower_bound(panda,panda+n,bamboo[i]) - panda;
        //    int u = upper_bound(panda,panda+n,bamboo[i]) - panda;
//cout<<"l : "<<l<<" "<<u<<endl;
            ans *= (n-l-ager);
            ans %=1000000007;
            ager++;

          //  cout<<l<<" "<<u<<endl;
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
    return 0;
}
