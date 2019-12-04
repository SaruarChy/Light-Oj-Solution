#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
#define Size 1200
#define inf 100000000
int n,e;
vector<pi>edges[Size];
int rgraph[Size][100];

bool bfs(int s,int t,int parent[]){

    bool visited[n+10];
    memset(visited,0,sizeof visited);
    memset(parent,0,sizeof parent);

    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    while(!q.empty()){


        int u = q.front();
        q.pop();

        for (int v=0; v<=n; v++)
        {
            if (visited[v]==false && rgraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t]==true);
}

int fordFulkerson(int s,int t)
{
    memset(rgraph,0,sizeof rgraph);
    for(int i=0; i<=n+10; i++)
        for(int j=0; j<edges[i].size(); j++)
        {
                int v=edges[i][j].first;
                int c=edges[i][j].second;
                rgraph[i][v]=c;
        }
    int parent[n];
    int max_flow=0;
    while(bfs(s,t,parent))
    {
        int path_flow = INT_MAX,u;
        for(int v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }

        for(int v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int u,v,c,s,t,test=1;
    cin>>t;
    while(t--)
    {
    cin>>n>>e;
    for(int i=0; i<=100; i++){
            edges[i].clear();
    }
    for(int i=2; i<n; i++){
        cin>>c;
        int p=i+n;
        edges[i].push_back(make_pair(p,c));
    }
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>c;
        edges[u+n].push_back(make_pair(v,c));
        edges[v+n].push_back(make_pair(u,c));
    }
    edges[1].push_back(make_pair(n+1,inf));
    edges[n].push_back(make_pair(n+n,inf));

    n+=n;
    cout<<"Case "<<test<<": ";
    test++;
    cout<<fordFulkerson(1,n)<<endl;
    }
    return 0;
}
