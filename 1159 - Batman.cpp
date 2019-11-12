#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,o,dp[100][100][100];
string x,y,z;

int lcs(int i, int j, int k)
{
    if( i < 0 || j < 0 || k < 0)
        return 0;
    if( dp[i][j][k] != -1)
        return dp[i][j][k];
    if(x[i] == y[j] && y[j] == z[k])
        return dp[i][j][k] =  1 + lcs(i-1, j-1, k-1);

    return dp[i][j][k] = max( max(lcs(i-1, j, k), lcs(i, j-1, k)), lcs(i,j,k-1));
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        m=x.length();
        n=y.length();
        o=z.length();
        memset(dp,-1,sizeof(dp));

        cout<<"Case "<<test<<": "<<lcs(m-1,n-1,o-1)<<endl;
        test++;
    }
    return 0;
}
