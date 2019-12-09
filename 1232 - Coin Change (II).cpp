#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t,test=1;

    int  n,k;
    int coin[101];
    int dp[10001];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<= n; i++)
            cin>>coin[i];

    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1; i<=n; i++ )
        for(int j=1; j<=k; j++){
            if(coin[i] <= j)
                dp[j] = dp[j] + dp[j-coin[i]];
            if(dp[j] > 100000007)
                dp[j] %= 100000007;
        }
    cout<<"Case "<<test<<": "<<dp[k]<<endl;
    test++;
    }
    return 0;
}
