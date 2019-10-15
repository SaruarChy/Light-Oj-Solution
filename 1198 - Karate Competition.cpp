#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k=1,n;

    cin>>t;
    while(t--)
    {
        int dp[60][60];
        cin>>n;
        int a[n],b[n];
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            cin>>b[i];
        //sorting a and b in descending
        sort(a,a+n);
        sort(b,b+n);

        for(i=0;i<=n;i++)
        {
            dp[i][n]=0;
            dp[n][i]=0;
        }
        for(i=n-1; i>=0; --i){
            for(j=n-1; j>=0; --j)
            {
                if(a[i] < b[j]){
                    dp[i][j]=dp[i+1][j];
                }
                else if(a[i] > b[j]){
                    dp[i][j]=2+dp[i+1][j+1];
                }
                else if(a[i]==b[j]){
                    dp[i][j]=max(1+dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        cout<<"Case "<<k<<": "<<dp[0][0]<<endl;
        k++;
    }
}
