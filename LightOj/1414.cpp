#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d1,y1,d2,y2,i,j,cnt=0,t,c=1;
    char m1[20],m2[20];
    scanf("%d",&t);
    while(t--){
    cnt = 0;
    scanf("%s",m1);
    scanf(" %d, %d",&d1,&y1);
    scanf("%s",m2);
    scanf(" %d, %d",&d2,&y2);
    int cnt1 = (y1/4) - (y1/100) + (y1/400);
     int cnt2 = (y2/4) - (y2/100) + (y2/400);
     cout<<cnt1<<" "<<cnt2<<endl;

    cnt = cnt2 - cnt1 + 1;
   // if(y1==y2) cnt++;
    if(y1%4==0 && (strcmp(m1,"January")!=0 && strcmp(m2,"February")!=0))
    {
        //cout<<m1<<endl;
        cnt--;
    }
    else if(y2%4==0 && strcmp(m2,"January")==0) cnt--;
    else if(y2%4==0 && strcmp(m2,"February")==0 && d2<29) cnt--;
    //if(cnt<0) cnt = 0;
    printf("Case %d: %d\n",c++,cnt);
    }


    return 0;
}

