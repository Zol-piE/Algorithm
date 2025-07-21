#include<bits/stdc++.h>
using namespace  std;
int coinrow(vector<int> &coins,int n)
{
    for(int i =2;i<=n;i++)
    {
        coins[i] = max(coins[i-1],coins[i-2]+coins[i]);
    }
    return coins[n];
}
int main()
{
    int n ; cin>>n;
    vector<int> coins(n+1);

    for(int i=1;i<=n;i++) cin>>coins[i];

    cout<<coinrow(coins,n)<<endl;

    return 0;
}
