#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,w,i;
        long long a,b;
        cin>>n>>w;
        for(i=0; i<n; i++)
        {
            cin>>a>>b;
            v.push_back(b);
        }
        sort(v.begin(),v.end());
        int ans=1;
        a=v[0];
        for(i=1; i<n; i++)
        {
            if(v[i]-a>w)
            {
                ans++;
                a=v[i];
            }
        }
        cout<<"Case "<<test<<": "<<ans<<endl;
        v.clear();
        test++;
    }
    return 0;
}
