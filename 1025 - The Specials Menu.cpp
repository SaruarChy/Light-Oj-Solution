#include<bits/stdc++.h>
using namespace std;
long long int dp[75][75];
string x,y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,test=1;
    cin>>t;
    while(t--)
    {
        cin>>x;
        //y=x;
        //reverse(y.begin(),y.end());
        int l=x.length();
        memset(dp,0,sizeof(dp));
        for(int i=0; i<l; i++)
            dp[i][i]=1;
        for(int i = l-1;i >= 0; i--)
            for(int j = i+1;j <l; j++)
            {
                if(x[i] != x[j])
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                else
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
            }
        cout<<"Case "<<test<<": ";
        cout<<dp[0][l-1]<<endl;
        test++;
    }
    return 0;
}
