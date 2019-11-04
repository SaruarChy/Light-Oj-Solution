#include<iostream>
#include<cstring>
#include<algorithm>

#define     Copy_maris_nah      int main()
#define     Okay_bye            return 0

using namespace std;
Copy_maris_nah
{
    int l,t,i,j,k=1;
    int dp[102][102];
    string s,r;
    cin>>t;
    while(t--)
    {
        cin>>s;
        l=s.size();
        r=s;
        reverse(r.begin(),r.end());
        memset(dp,0,sizeof(dp));
        for(i=1; i<=l; i++)
            for(j=1; j<=l; j++)
            {
                if(s[i-1]==r[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        cout<<"Case "<<k<<": "<<l-dp[l][l]<<endl;
        k++;
    }
    Okay_bye;
}
