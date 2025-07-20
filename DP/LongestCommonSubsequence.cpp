#include<bits/stdc++.h>
using namespace std;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int LCSrec(string s1,string s2, int i,int j)
{
    if(s1[i] =='\0' || s2[j]== '\0') return 0;
    if(s1[i]==s2[j]) return 1 + LCSrec(s1,s2,i+1,j+1);
    else
    {
        return max(LCSrec(s1,s2,i+1,j),LCSrec(s1,s2,i,j+1));
    }
}
int LCSrec(string s1,string s2,vector<vector<int>> &memo,int i,int j)
{
    if(memo[i][j] == -1)
    {
        if(s1[i] =='\0' || s2[j]== '\0') return memo[i][j] = 0;
        if(s1[i]==s2[j]) return memo[i][j] = 1 + LCSrec(s1,s2,i+1,j+1);
        else
        {
            return memo[i][j] =  max(LCSrec(s1,s2,i+1,j),LCSrec(s1,s2,i,j+1));
        }
    }
    return memo[i][j];
}
int LCSrec(vector<vector<int>> &memo,string s1,string s2,int s1n,int s2n)
{
    for(int i=1;i<=s2n;i++)
    {
        for(int j =1;j<=s1n;j++)
        {
            if(s1[j-1] == s2[i-1] ) memo[i][j] = 1 + memo[i-1][j-1];
            else memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
        }
    }
    return memo[s2n][s1n];
}
int main()
{
    OP
    string s1,s2;
    cin>>s1>>s2;
    cout<<"Longest Common Subsequence : S1-> " <<s1<<" S2 -> "<<s2<<endl;
    cout<<"Recursion Solve "<<LCSrec(s1,s2,0,0)<<endl;
    int s1n = s1.size();
    int s2n = s2.size();
    vector<vector<int>> memo(s2n+1,vector<int>(s1n+1,-1));
    cout<<"Memorization SOlve-> "<<LCSrec(s1,s2,memo,0,0)<<endl;
    memo.assign(s2n+1,vector<int>(s1n+1,0));
    cout<<"Bottom UP Solve-> "<<LCSrec(memo,s1,s2,s1n,s2n);
    return 0;
}
