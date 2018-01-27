#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    long long int x = 1;
    while(scanf("%d",&n)!=EOF){
    int cnt = 1;
        x = 1;
    while(x%n!=0)
    {
        x = (x*10) + 1;
        cnt++;
        x = x%n;
    }
    printf("%d\n",cnt);
    }
    return 0;
}
