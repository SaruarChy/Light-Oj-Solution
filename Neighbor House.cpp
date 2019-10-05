#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,j;
    int a[23][5];
    int ans[23][5];
    int x;
    int pre;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int result=0;
        cin>>n;
        for(i=0; i<n; i++)
            for(j=0; j<3; j++)
                cin>>a[i][j];

        for(i=n; i>=0; i--)
            for(pre=2; pre>=0; pre--)
            {
                x=INT_MAX;
                if(i==n)
                {
                    ans[i][pre]=0;
                    continue;
                }
                for(j=0; j<3; j++)
                {
                    if(j!=pre)
                    {
                        x=min(x,a[i][j]+ans[i+1][j]);
                    }
                }
                ans[i][pre]=x;
            }
        result=min(ans[0][0],min(ans[0][1],ans[0][2]));
        cout<<"Case "<<k<<": "<<result<<endl;
    }
    return 0;
}
