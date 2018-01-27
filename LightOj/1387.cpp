#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i;
    int k,caseno=1;
    long long int amount=0;
    string s,a,b;
    a = "report";
    b = "donate";
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        printf("Case %d:\n",caseno++);
        amount = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%s",&s);
            if
            while(s!= a)
            {
                scanf("%d",&k);
                amount += t;
            }
            if(s == a)
                printf("%lld\n",amount);
        }
    }
    return 0;
}
