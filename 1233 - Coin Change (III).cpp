#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int coin[101];
int times[101];
int used[1000101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,k;
    int ans,test=1,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1; i<=n; i++)
            cin>>coin[i];
        for(i=1; i<=n; i++)
            cin>>times[i];
        memset(dp,0,sizeof dp);
        dp[0]=1;
        ans=0;
        for(i=1; i<=n; i++)
        {
            memset(used,0,sizeof used);
            for(j=coin[i]; j<=k; j++)
                if (!dp[j] && dp[j-coin[i]] && used[j-coin[i]] < times[i])
                {
                    ans++;
                    used[j]=used[j-coin[i]]+1;
                    dp[j] = 1;
                }
        }
        cout<<"Case "<<test<<": "<<ans<<endl;
        test++;
    }
}
