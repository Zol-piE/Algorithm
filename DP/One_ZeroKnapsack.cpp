#include<bits/stdc++.h>
using namespace std;

int knapsack(pair<int,int> arr[],int w,int n)
{
    vector<vector<int>> m(n+1,vector<int>(w+1,0));

    for(int i =1;i<n+1;i++)
    {
        for(int j =1;j<w+1;j++)
        {
            if( arr[i-1].first > j ) { m[i][j] = m[i-1][j];  }
            else
            {
                m[i][j] = max(m[i-1][j],m[i-1][j - arr[i-1].first ] + arr[i-1].second) ;
            }
        }
    }
    for(int i =1;i<n+1;i++)
    {
        for(int j =1;j<w+1;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return m[n][w];
}

int main()
{
    int n; cin>>n;

    pair<int,int> arr[n];
    for(int i =0;i<n;i++) cin>>arr[i].first;
    for(int j =0;j<n;j++) cin>>arr[j].second;
    int w;cin>>w;
    sort(arr,arr+n);
    cout<<knapsack(arr,w,n)<<endl;
    return 0;
}
