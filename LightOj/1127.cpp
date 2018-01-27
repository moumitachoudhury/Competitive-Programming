#include<bits/stdc++.h>
using namespace std;
#define MAX 32
int n;
int A[MAX], B[MAX];
long long cnt, k;

long long temp1[1<<15+2],temp2[1<<15 + 2];
int cnttemp1, cnttemp2;

void solve(int a[], int m, bool type)
{

    int i,j;
    bool flag = true;
//id = 0;
    cnt=0;
    for(i=1; i<1<<m; i++)
    {
        flag = true;
        long long temp = 0;
        for(j=0; j<m; j++)
        {
            if((1<<j)&i)
            {

                if(temp>(k-a[j]))
                {
                    flag = false;
                    break;
                }
                else temp = temp+a[j];

            }
        }
        if(flag)
        {
            if(!type)
            {
                // temp1.push_back(temp);
                temp1[cnttemp1] = temp;
                cnttemp1++;
            }

            else
            {
                // temp2.push_back(temp);
                temp2[cnttemp2] = temp;
                cnttemp2++;
            }

            cnt++;
        }
    }
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        cnttemp1 = 0;
        cnttemp2 = 0;
        //temp1.clear();
        //temp2.clear();
        scanf("%d %lld",&n,&k);
        int j=0;
        for(int i=1; i<=n/2; i++)
        {
            scanf("%d",&A[j]);
            j++;
        }
        j=0;
        for(int i=n/2+1; i<=n; i++)
        {
            scanf("%d",&B[j]);
            j++;
        }
        long long ans = 0;
        int sz = n/2;
        solve(A, sz, false);
        ans+=cnt;

        solve(B,n-sz, true);
        sort(temp2, temp2+cnttemp2);
        ans += cnt;
        //cout<<"ans "<<ans<<" "<<cnttemp1<<endl;
        for(int i=0; i<cnttemp1; i++)
        {
            int up = upper_bound(temp2, temp2+cnttemp2, (k-temp1[i]))-temp2;
            ans = ans + up;
          //  cout<<"up "<<up<<endl;

        }

        printf("Case %d: %lld\n",cs++,ans+1);
    }

    return 0;
}


