#include<bits/stdc++.h>
using namespace std;

int node, edge, visit[100], dist[100], out[100], out1[100];
vector<int>adjmat[100];

class graph{
public:
    void get()
    {
        int a, b, i;
        cin>>node>>edge;
        for(i=1; i<=edge; i++){
            cin>>a>>b;
            adjmat[a].push_back(b);
            adjmat[b].push_back(a);
        }
    }

    void DFS(int a)
    {
        stack<int>s;
        s.push(a);
        int l=0;
        out1[l++]=a;
        memset(visit, -1, sizeof(visit));
        visit[a]=1;

        while(!s.empty()){
            int p=s.top();
            int c=0, i;
            for(i=0; i<adjmat[p].size(); i++){
                int sim = adjmat[p][i];
                if(visit[sim]==-1){
                    s.push(sim);
                    visit[sim]=1;
                    out1[l++]=sim;
                    c=1;
                    break;
                }
            }
            if(c==0){
                s.pop();
            }
        }
    }

    void BFS(int a)
    {
        memset(visit, -1, sizeof(visit));
        visit[a]=1;
        int l=0;
        out[l++]=a;
        queue<int>q;
        q.push(a);
        while(!q.empty()){
            int m = q.front();
            q.pop();
            for(int i=0; i<adjmat[m].size(); i++){
                int p = adjmat[m][i];
                if(visit[adjmat[m][i]] ==-1){
                    visit[p]=1;
                    out[l++]=p;
                    q.push(p);
                }
            }
        }
    }

    void DISTAN(int a)
    {
        memset(dist, -1, sizeof(dist));
        dist[a]=0;
        queue<int>q;
        q.push(a);
        while(!q.empty()){
            int m = q.front();
            q.pop();
            for(int i=0; i<adjmat[m].size(); i++){
                int p = adjmat[m][i];
                if(dist[adjmat[m][i]] ==-1){
                    dist[p] = dist[m]+1;
                    q.push(p);
                }
            }
        }
    }
};

int main()
{
    graph ob;
    ob.get();
    ob.DFS(1);
    cout<<"Depth first Search : ";
    for(int i=0; i<node; i++){
        cout<<out1[i]<<" ";
    }
    cout<<endl;

    ob.get();
    ob.BFS(1);
    cout<<"Breadth first Search : ";
    for(int i=0; i<node; i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;

    ob.DISTAN(5);
    cout<<"Distance from node 5 : ";
    for(int i=1; i<=node; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}
-----------------------------------------------------------------------


https://pastebin.ubuntu.com/p/xrqkcW55vg/
