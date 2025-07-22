#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1,pair<int,int> p2)
{
    double x  = 1.0 * (p1.first / p1.second);
    double y  = 1.0 * (p2.first / p2.second);
    return y < x;
}
double knapsack(pair<int,int> pi[],int n,int w)
{
    sort(pi,pi+n,comp);
    double res = 0.0;
    for(int i =0;i<n;i++)
    {
        if(w >= pi[i].second )
        {
            w -= pi[i].second;
            res += 1.0 * pi[i].first;
        }
        else
        {
            double f = 1.0 * w * pi[i].first / pi[i].second;
            res += f;
            break;
        }
    }
    return res;
}
int main()
{
    cout<<"Number of Items : ";
    int n; cin>>n;
    cout<<endl;
    pair<int,int> pi[n];
    for(int i =0;i<n;i++)
    {
        cout<<"Input item Value " ;
        cin>>pi[i].first; cout<<endl;
        cout<<"Input item Weight " ;
        cin>>pi[i].second; cout<<endl;
    }
    sort(pi,pi+n,comp);
    cout<<"Input total weight" <<endl;
    int w; cin>>w;
//    for(auto x : pi) cout<<x.first << " "<<x.second<<endl;
    cout<<knapsack(pi,n,w)<<endl;
    return 0;
}
