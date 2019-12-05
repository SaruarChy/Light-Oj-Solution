#include<bits/stdc++.h>
using namespace std;

struct edge
{
    long long u,v,w;
    edge() {};
    edge(int a,int b,int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

vector<edge> adj;
long long dis[305],n,e;
void bellmanford(int s)
{
    fill(dis,dis+305,1000000);
    dis[s]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<adj.size();j++)
        {
            edge k = adj[j];
            if(dis[k.u] < 1000000 && dis[k.v] > dis[k.u]+k.w)
            {
                dis[k.v] = dis[k.u]+k.w;
            }
        }
    }
}

int main()
{
    int t,p;
    cin>>t;
    for(p=1;p<=t;p++)
    {
        adj.clear();
        cin>>n;
        long long busy[n+2],u,v,w;
        for(int i=1;i<=n;i++)
        {
            cin>>busy[i];
        }
        cin>>e;
        for(int i=0;i<e;i++)
        {
            cin>>u>>v;
            w = busy[v]-busy[u];
            adj.push_back(edge(u,v,w*w*w));
        }
        bellmanford(1);
        int q;
        cin>>q;
        cout << "Case " <<p << ":"<<endl;
        while(q--)
        {
            cin >> u;
            if(dis[u] == 1000000 || dis[u] < 3){
                cout << "?"<<endl;
            }
            else{
                cout <<dis[u]<< endl;
            }
        }
    }
    return 0;
}
