#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//const int MOD = 1e9 + 7;
//const int INF = LLONG_MAX >> 1;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool binary(vector<int> &arr,int key,int low,int high)
{
    if(low <= high)
    {
        int mid = low + (high - low ) /2;
        if(arr[mid] == key ) return true;
        if(key < arr[mid]) return binary(arr,key,low,mid-1);
        else return binary(arr,key,mid+1,high);
    }
    return false;
}
signed main()
{
    int n = 7;
    vector<int> arr = { 4,8,9,11,77,21,1};
    sort(arr.begin(),arr.end());
    int key = 77;
    if(binary(arr,key,0,n-1)) cout<<"Found"<<endl;
    else cout<<"NOT"<<endl;
}

