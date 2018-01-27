#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,c=1,l,w,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&l,&w,&h);
        if(l<=20 && w<=20 && h<=20) printf("Case %d: good\n",c++);
        else printf("Case %d: bad\n",c++);

    }
    return 0;
}
