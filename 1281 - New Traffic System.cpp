#include<bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
struct Edge{
    int to, cost;
    bool newly;
    Edge(int to,int cost,int newly):to(to),cost(cost),newly(newly){}
};
vector<Edge> graph[maxn];
int n, m, k, d;
int dis[maxn][12];
int dijkstra()
{
    int st = 0, ed = n - 1;
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(ii(0, 0), 0));
    memset(dis, INF,sizeof dis);
    dis[0][0] = 0;
    while(!q.empty())
    {
        iii tmp = q.top();
        q.pop();
        int u = tmp.second;
        int w = tmp.first.first;
        int cnt = tmp.first.second;
        if (u == ed)
            return dis[u][cnt];
        if (w > dis[u][cnt])
            continue;
        if (cnt > d)
            continue;
        int size = graph[u].size();
        for (int i = 0;i < size;++i)
        {
            int v = graph[u][i].to;
            int cost = graph[u][i].cost;
            bool is = graph[u][i].newly;
            if (is)
            {
                if (cnt + 1 <= d && dis[v][cnt + 1] > dis[u][cnt] + cost)
                {
                    dis[v][cnt + 1] = dis[u][cnt] + cost;
                    q.push(iii(ii(dis[v][cnt + 1],cnt + 1), v));
                }
            }
            else
            {
                if (dis[v][cnt] > dis[u][cnt] + cost)
                {
                    dis[v][cnt] = dis[u][cnt] + cost;
                    q.push(iii(ii(dis[v][cnt], cnt), v));
                }
            }
        }
    }
    int ans = INF;
    // for (int i = 0;i <= d;++i)
    //     ans = min(ans, dis[n-1][i]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te,test=1,i;
    cin>>te;
    while(te--)
    {
        cin>>n>>m>>k>>d;
        for(i=0; i<n; i++)
            graph[i].clear();
        int u,v,w;
        //cin the number of existing roads
        for(i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(Edge(v,w,false));
        }
        //cin newly proposed roads.
        for(i=0; i<k; i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(Edge(v,w,true));
        }
        int ans=dijkstra();
        cout<<"Case "<<test<<": ";
        if(ans==INF)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
        test++;
    }
    return 0;
}
