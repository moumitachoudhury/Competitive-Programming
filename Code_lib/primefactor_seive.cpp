#include<bits/stdc++.h>
using namespace std;
int spf[1000006];
void smallest_prime_factor(int n)
{
    long long int i,j,limit = sqrt(n*1.)+2;
    spf[1] = 1;
    for(i=1; i<=n; i+=2) spf[i] = i;
    for(i=2; i<=n; i+=2) spf[i] = 2;

    for(i=3; i<=n; i+=2)
    {
        if(spf[i]==i)
        {

            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=i*2)
                {
                    if(spf[j]==j)
                        spf[j] = i;
                }
            }

        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        //cout<<x<<" "<<spf[x]<<endl;
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    smallest_prime_factor(20000);

    vector<int> ans = getFactorization(45);
    for (int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

