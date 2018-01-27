#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
double rat,ab;
bool can(double ad)
{
    double f = ad/ab;
    double rat2 =  rat / (1+rat);
    if(f*f<=rat2) return true;
    else return false;
}



int main()
{
    int t, c=1,i;
    double ac,bc,hi,lo,ans=0.0,mid;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&rat);
        hi = ab;
        lo = eps,mid=0.0,ans=0.0;
       while(abs(hi-lo)>eps)
        {
             mid = (lo+hi) / 2.0;
            /* f = mid / (ab-mid);
             if(f==rat)
             {
                 ans = mid;
                 break;
             }*/
            if(can(mid))
            {
                ans = mid;
                lo = mid;
            }
            else hi = mid;
        }
        printf("Case %d: %.7lf\n",c++,ans);
    }

    return 0;
}
