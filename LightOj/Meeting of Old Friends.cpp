#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
int main()
{
    long long int l1,r1,l2,r2,k,i,j,lo,up,cnt=0;

    scanf("%I64d %I64d %I64d %I64d %I64d",&l1,&r1,&l2,&r2,&k);
   for(i=l1;i<=r1;i++)
    {
        //cnt++;
        v.push_back(i);
    }

    lo = lower_bound(v.begin(),v.end(),l2) - v.begin();
    up = upper_bound(v.begin(),v.end(),r2) - v.begin();
    //cout<<v[lo]<<" "<<v[up-1];

    cnt = v[up-1] - v[lo] + 1;
    if(k>=v[lo] && k<=v[up-1]) cnt--;
   printf("%I64d\n",cnt);
    return 0;

}
