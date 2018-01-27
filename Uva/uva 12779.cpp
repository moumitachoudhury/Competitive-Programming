#include<bits/stdc++.h>
int main()
{
    int ara[10],i;
    float dia1,dia2,l1,l2,r1,r2,s1,s2,a1,a2;
    for(i=0;i<8;i++){
        scanf("%d",&ara[i]);
    }
    dia1=sqrt(((ara[0]-ara[4])*(ara[0]-ara[4]))+((ara[1]-ara[5])*(ara[1]-ara[5])));
    dia2=sqrt(((ara[2]-ara[6])*(ara[2]-ara[6]))+((ara[3]-ara[7])*(ara[3]-ara[7])));
    l1=sqrt(((ara[0]-ara[2])*(ara[0]-ara[2]))+((ara[1]-ara[3])*(ara[1]-ara[3])));
    l2=sqrt(((ara[0]-ara[6])*(ara[0]-ara[6]))+((ara[1]-ara[7])*(ara[1]-ara[7])));
    s1=((dia1/2)+(dia2/2)+l1)/2;
    s2=((dia1/2)+(dia2/2)+l2)/2;
    a1=sqrt(s1*(s1-(dia1/2))*(s1-(dia2/2))*(s1-l1));
    a2=sqrt(s2*(s2-(dia1/2))*(s2-(dia2/2))*(s2-l2));
    r1=(2*a1)/l1;
    r2=(2*a2)/l2;
    float r;
    if(r1<r2) r=r1;
    else r=r2;
    printf("%f*pi",r*r);
    return 0;
}
