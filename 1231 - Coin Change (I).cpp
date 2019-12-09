#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long coin[55];
long long times[55];
long long dp[55][1010];
long long number_of_ways(long long i,long long j)
{
    if(j==0)
        return 1;
    if(i==n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=0;
    for(int d=0; d<=times[i] && j-d*coin[i]>=0; d++)
        dp[i][j]+=number_of_ways(i+1,j-d*coin[i])%100000007;
    return dp[i][j]%100000007;
}

int main()
{
    int t,i,j,test=1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>n>>k;
        for(i=0; i<n; i++)
            cin>>coin[i];
        for(i=0; i<n; i++)
            cin>>times[i];
        cout<<"Case "<<test<<": "<<number_of_ways(0,k)<<endl;
        test++;
    }
    return 0;
}
