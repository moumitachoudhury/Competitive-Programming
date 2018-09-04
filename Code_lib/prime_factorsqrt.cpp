#include<bits/stdc++.h>
using namespace std;

//O(sqrt(n))
vector<int> getFactorizationSqrt(int n)
{
    vector<int> ret;
    if(n==1)
    {
        ret.push_back(1);
        return ret;
    }

    while(n%2==0)
    {
        cout<<"2"<<endl;
        ret.push_back(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            cout<<i<<endl;
            ret.push_back(i);
            n/=i;
        }
    }

    if(n>2) ret.push_back(n);

    return ret;
}
int main()
{
    vector<int> ans = getFactorizationSqrt(12246);
    for (int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
