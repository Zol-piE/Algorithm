#include<bits/stdc++.h>
using namespace std;
int minCoin(vector<int> &arr,int n,int sum)
{
    sort(arr.begin(),arr.end(),greater<int>());
    int res =0;
    for(int i=0;i<n;i++)
    {
        if((sum - arr[i]) >= 0)
        {
            int c = sum / arr[i];
            res += c;
            sum = sum - ( arr[i] *c );
//            cout<<sum<<endl;
            if(sum == 0) break;
        }
    }
    if(sum != 0 ) return -1;
    return res;
}
/* 4 1 5 10 25 30*/

vector<int> minCoin(int n,int sum,vector<int> &arr)
{
    sort(arr.rbegin(),arr.rend());
    vector<int>res;
    for(int c : arr)
    {
        while(sum>=c)
        {
            sum-=c;
            res.push_back(c);
        }
    }
    if(sum != 0 ) return {};
    return res;
}
int main()
{
    cout<<"Size of Denominations ";
    int n; cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum ; cin>>sum;
    int mCoin = minCoin(arr,n,sum);

    (mCoin != -1) ? cout<<"Min Coin : "<<mCoin<<endl : cout<<"not Possible"<<endl;

    vector<int> res = minCoin(n,sum,arr);

    if(res.empty()) cout<<"Not Possible"<<endl;
    cout<<"Coins : ";
    for(int c : res) cout<<c<<" ";
    cout<<endl;

    return 0;
}
