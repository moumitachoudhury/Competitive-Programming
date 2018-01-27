#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 16
int n;
int A[MAX], B[MAX];
int k;

//long long temp1[1<<15+2],temp2[1<<15 + 2];
int subset2[1<<15], subset[1<<15];
int s1,s2;

//vector<long long > subset;
//vector<long long > subset2;
void getAllSubsets(int a[], int m)
{

    subset[s1++] = 0;
    //subset.push_back(0);

    for (int i = 0; i < m; i++)
    {
        int sizee =  s1;
  //      long long temp = 0;

        for (int j = 0; j < sizee; j++)
        {
            if(subset[j]<=(k-a[i]))
            {
                subset[s1] = subset[j] + a[i];
                s1++;

            }
        }
    }

     //for(int i=0; i<subset.size(); i++) cout<<subset[i]<<" ";
     //cout<<endl;
//    return subset;
}

void getAllSubsets2(int a[], int m)
{

    subset2[s2++] = 0;

    for (int i = 0; i < m; i++)
    {
        int sizee =  s2;
//        long long temp = 0;

        for (int j = 0; j < sizee; j++)
        {
            if(subset2[j]<=(k-a[i]))
            {
                subset2[s2] = subset2[j] + a[i];
                s2++;

            }
        }
    }

     //for(int i=0; i<subset2.size(); i++) cout<<subset2[i]<<" ";
     //cout<<endl;
//    return subset;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        s1 = 0;
        s2 = 0;

        scanf("%d %d",&n,&k);
        //int j=0;
        // int sz = n/2;
        for(int i=0; i<n/2; i++)
        {
            scanf("%d",&A[i]);
           // j++;
        }
        //j=0;
        for(int i=0; i<n-(n/2); i++)
        {
            scanf("%d",&B[i]);
            //j++;
        }
        int ans = 0;

        getAllSubsets(A,n/2);
        ans+=s1-1;

        getAllSubsets2(B,n-(n/2));
        sort(subset2, subset2+s2);

        ans += s2-1;

        for(int i=1; i<s1; i++)
        {
            int up = upper_bound(subset2, subset2+s2, (k-subset[i]))-subset2;
            ans = ans + up - 1;
//              cout<<"up "<<up<<endl;

        }

        printf("Case %d: %d\n",cs++,ans + 1);
    }

    return 0;
}



