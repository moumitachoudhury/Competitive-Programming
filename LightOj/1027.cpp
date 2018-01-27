#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,a[110],cs=1;
    cin>>t;
    while(t--)
    {
        int ngc = 0;
        int sum = 0;
        bool t = false;
        cin>>n;
        for(int i=0;i<n;i++) {
                cin>>a[i];
                sum += abs(a[i]);
                if(a[i]>=0) t=true;
                else ngc++;
        }
        if(!t)
        {
            printf("Case %d: inf\n",cs++);
        }
        else
        {
            int tmp = (n-ngc);
            int g = __gcd(sum,tmp);
            int p = (sum/g);
            int q = (tmp/g);
            printf("Case %d: %d/%d\n",cs++,p,q);

        }

        char ch = getchar();
    }
    return 0;
}

