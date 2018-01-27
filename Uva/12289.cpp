#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i;
    char s[7];
    scanf("%d",&t);
    while(t--)
    {
        int one = 0, two = 0;
        scanf("%s",s);
        if(strlen(s)==5) printf("3\n");
        else if(strlen(s)==3) {
            if((s[0]=='o' && s[1]=='n') || (s[1]=='n' && s[2] == 'e') || (s[0]=='o' && s[2]=='e'))  one++;
            //printf("%d\n",one);
            if(one) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
