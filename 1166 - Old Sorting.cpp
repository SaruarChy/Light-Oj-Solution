#include<iostream>
#include<algorithm>
#define     Copy_maris_nah      int main()
#define     Okay_bye            return 0

using namespace std;

Copy_maris_nah
{
    int t,n,a[100],ans,i,j,k=1;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(i=1; i<=n; i++)
            if(a[i]!=1)
                for(j=i+1; j<=n; j++)
                {
                    if(a[j]==i)
                    {
                        swap(a[j],a[i]);
                        ans++;
                        break;
                    }
                }
        cout<<"Case "<<k<<": "<<ans<<endl;
        k++;
    }

    Okay_bye;
}
