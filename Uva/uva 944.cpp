#include<bits/stdc++.h>

int main()
{
    int a,b,i,sum,squ,ekhon,emni;
    while(scanf("%d %d",&a,&b)==2){
         for(i=a;i<=b;i++){
            ekhon=i;
            emni=1;
            sum=0;
            if(i==1) printf("%d %d",1,1);
            else
            {
                while(1){
                    while(ekhon>0){
                        squ=ekhon%10;
                        sum+=squ*squ;
                        ekhon/=10;
                    }
                    if(sum==1) {
                            printf("%d %d",i,emni+1);
                    }
                    else if (sum == 4)	break;

					else{
						ekhon = sum;	sum = 0;	emni++;

					}
                }
            }
         }
    }


    return 0;
}
