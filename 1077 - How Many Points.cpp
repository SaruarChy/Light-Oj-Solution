#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int x,long long int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main()
{
    int t,test=1;
    cin>>t;
    long long int a,b,c,d,x,y;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        x=abs(a-c);
        y=abs(b-d);
        cout<<"Case "<<test<<": "<<gcd(x,y)+1<<endl;
        test++;
    }
    return 0;
}
   //     cout<<"Case "<<test<<": "<<1LL+__gcd(abs(c-a),abs(d-b))<<endl;
