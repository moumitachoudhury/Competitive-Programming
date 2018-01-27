#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,c=1;
    string s;

    while(1){
    cin>>s;
    if(s=="#") break;
    printf("Case %d: ",c++);
    if(s=="HELLO") printf("ENGLISH\n");
    else if(s=="HOLA") printf("SPANISH\n");
    else if(s=="HALLO") printf("GERMAN\n");
    else if(s=="BONJOUR") printf("FRENCH\n");
    else if(s=="CIAO") printf("ITALIAN\n");
    else if(s=="ZDRAVSTVUJTE") printf("RUSSIAN\n");
    else printf("UNKNOWN\n");

    }
    return 0;
}
 //HOLA HALLO BONJOUR CIAO ZDRAVSTVUJTE

 //Case 1: ENGLISH Case 2: SPANISH Case 3: GERMAN Case 4: FRENCH Case 5: ITALIAN Case 6: RUSSIAN
