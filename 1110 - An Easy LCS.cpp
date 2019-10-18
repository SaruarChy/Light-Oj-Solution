#include<bits/stdc++.h>
using namespace std;
char s1[105],s2[105];
int dp[105][105];
string ans[105][105];
int n,m;

void LCS()
{
    for(int i=0; i<n; i++)
    {
        dp[i][0]=0;
        ans[i][0]="";
    }
    for(int i=0; i<m; i++)
    {
        dp[0][i]=0;
        ans[0][i]="";
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(s1[i-1]==s2[j-1])
        {
            dp[i][j]=dp[i-1][j-1]+1;
            ans[i][j]=ans[i-1][j-1]+s1[i-1];
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            dp[i][j]=dp[i-1][j];
            ans[i][j]=ans[i-1][j];
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            dp[i][j]=dp[i][j-1];
            ans[i][j]=ans[i][j-1];
        }
        else
        {
            dp[i][j]=dp[i-1][j];
            ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
        }
    }
}

int main()
{
    int t,i=1;;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        n=strlen(s1);
        m=strlen(s2);
        LCS();
        cout<<"Case "<<i<<": ";
        if(dp[n][m]==0)
            cout<<":("<<endl;
        else
            cout<<ans[n][m]<<endl;
        i++;
    }
    return 0;
}
