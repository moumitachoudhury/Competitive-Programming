#include<bits/stdc++.h>
using namespace std;

bool check(int n, int pos)
{
    return (bool) (n & (1<<pos));
}

int Set(int n, int pos)
{
    return n = n | (1<<pos);
}

int reset(int n,int pos){
    return n = n & ~(1<<pos);
    }

int len(int n)
{
int l  = 0;
while (n> 0) {
    l++;
    n = n >> 1;
}
return l;
}

int main()
{
    int t,caseno=1,n,i,r,s,c=0;
    scanf("%d",&t);
   // int l = len(t);
    //printf("%d\n",l);

   // else t = Set(t,3);
  //  printf("%d\n",t);
   while(t--)
    {
        c = 0;
        scanf("%d",&n);
        int l = len(n);
        for(i=0;i<l;i++){
         if(check(n,i))
        {

        if(check(n,i+1)==false){
        n = reset(n,i);
        n = Set(n,i+1);
        break;

        }
        else {
            n = reset(n,i);
            n = Set(n,c++);
        }
    }
  }
  printf("Case %d: %d\n",caseno++,n);

    }

    return 0;
 }

// 11011110011000
// 11011110100001
