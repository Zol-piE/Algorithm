#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//const int MOD = 1e9 + 7;
//const int INF = LLONG_MAX >> 1;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int part(vector<int> &arr,int low,int high)
{
    int i = low,j = high;
    do
    {
        do { i++; }while(arr[low]>=arr[i] );
        do { j--; }while(arr[low]<arr[j] );
        if(i<j) swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr,int low,int high)
{
   if(low<high)
   {
       int j = part(arr,low,high);
       quickSort(arr,low,j);
       quickSort(arr,j+1,high);
   }
}
signed main()
{
    int n = 7;
    vector<int> arr = {3,6,4,8,2,1,11};
    quickSort(arr,0,n);
    for(int i=0;i<n;i++) cout<<arr[i]<< " ";
}

