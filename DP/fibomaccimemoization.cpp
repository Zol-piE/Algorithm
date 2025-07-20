#include<bits/stdc++.h>
using namespace std;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int fibo(int n,vector<int> &arr)
{
    if(arr[n]==-1)
    {
        int res;
        if(n==0 || n==1) res = n;
        else  res = fibo(n-1,arr) + fibo(n-2,arr);
        arr[n] = res;
    }
    return arr[n];
}
int main()
{
    OP
    int n ; cin>>n;

    vector<int> arr(n+13,-1);

    cout<<fibo(n,arr)<<endl;

    return 0;
}

