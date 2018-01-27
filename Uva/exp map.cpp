#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,c=1;
    string s;
    map<string,string> m;
    m["HELLO"] = "ENGLISH";

    while(1){
    cin>>s;
    if(s=="#") break;

    //else if(s=="HELLO") printf("Case %d: ENGLISH\n",c++);
    printf("Case %d: ",c++);
    cout<<m[s];
    puts("");

    }
    return 0;
}
 //HOLA HALLO BONJOUR CIAO ZDRAVSTVUJTE

 //Case 1: ENGLISH Case 2: SPANISH Case 3: GERMAN Case 4: FRENCH Case 5: ITALIAN Case 6: RUSSIAN

