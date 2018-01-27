#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[1000005];
    long long int cnt = 0;
    while(scanf(" %[^\n]s",s)==1){

    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]== '"'){
                cnt++;
        if(cnt%2 == 1) printf("``");
        else printf("''");

    }
    else printf("%c",s[i]);

    }
     printf("\n");

    }
    return 0;
}
