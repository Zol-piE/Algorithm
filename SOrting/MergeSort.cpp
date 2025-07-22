#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//const int MOD = 1e9 + 7;
//const int INF = LLONG_MAX >> 1;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void mergeArray(vector<int> &arr,int low,int mid,int high)
{
    int N1 = mid - low +1;
    int N2 = high - mid ;
    vector<int> s1(N1,0),s2(N2,0);
    int k = low;
    for(int i =0;i<N1;i++) s1[i] = arr[low+i];
    for(int i =0;i<N2;i++) s2[i] = arr[mid+i+1];
    int i =0,j=0;
    while(i<N1 && j <N2)
    {
        if(s1[i] > s2[j] )
        {
            arr[k++] = s2[j++];
        }
        else arr[k++] = s1[i++];
    }
    while(i<N1) arr[k++] = s1[i++];
    while(j<N2) arr[k++] = s2[j++];
}
void mergeSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int mid = low + (high - low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeArray(arr,low,mid,high);
    }
}
signed main()
{
    int n; cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i =0;i<n;i++) cout<<arr[i]<< " ";

}

