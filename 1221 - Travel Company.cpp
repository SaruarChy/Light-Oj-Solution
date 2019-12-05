#include<bits/stdc++.h>
using namespace std;
struct edge
{
    long long u,v,w;
    edge() {};
    edge(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
};
vector<edge>adj;
long long dis[105],n,e;

//bellmanford algorithm
bool bellmanford()
{
    memset(dis,0,sizeof dis);
    for(int i=1; i<n; i++)
        for(int j=0; j<adj.size(); j++)
        {
            edge k=adj[j];
            if(dis[k.v] > dis[k.u]+k.w)
                dis[k.v]=dis[k.u]+k.w;
        }
    for(int i=0;i<adj.size();i++)
    {
        edge k = adj[i];
        if(dis[k.u]+k.w < dis[k.v])
        {
          return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,p,test=1;
    cin>>t;
    while(t--)
    {
        int u,v,w;
        adj.clear();
        long long in,ex;
        cin>>n>>e>>p;
        for(int i=0; i<e; i++)
        {
            cin>>u>>v>>in>>ex;
            w = p*ex-in;
            adj.push_back(edge(u,v,w));
        }

        cout<<"Case "<<test<<": ";
        if(bellmanford())
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
        test++;
    }
    return 0;
}
