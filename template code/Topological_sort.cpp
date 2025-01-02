#include<bits/stdc++.h>
using namespace std;

#define para cout<<endl;
#define WHITE -1
#define GRAY 0
#define BLACK 1


/*graph input
5 5
1 2 3
1 3 2
2 4 5
3 5 4
4 5 1
*/


struct Edge
{
    int dest;
    int weight;
};

vector<Edge> graph[12];
int color[12];
stack<int> path;



void DFS(int u)
{
    color[u]=GRAY;

    //cout<<u<<" ";
    for(int i=0; i<graph[u].size(); i++)
    {
        int v =graph[u][i].dest;
        if(color[v]==WHITE)
        {
             //cout << "Going deeper from " << u << " to " << v << endl;
            DFS(v);

        }

    }
    color[u]=BLACK;
    path.push(u);


}


void top_sort(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(color[i]==WHITE)
        {
            DFS(i);
        }
    }


}


int main()
{
    ///Graph input
    int node_number, edge_number;
    Edge e;

    fill(color, color + 12, WHITE);
    cout<<"Enter the number of Nodes and Edges: \n";
    cin>>node_number>>edge_number;

    for(int i= 1 ; i<=node_number; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;
        e = {d,w};
        graph[s].push_back(e);

    }
    ///Print Node Adjacency List by traversing the list
    for(int i = 1; i<=node_number; i++) //graph output adj list
    {
        cout<<i<<" -> ";

        for(int j = 0; j < graph[i].size(); j++)
        {
            cout<<" ("<<graph[i][j].dest<<", "<<graph[i][j].weight<<") ,";
        }
        cout<<endl;

    }


    ///

    para
    ///Top_sort call

    top_sort(node_number);
    ///

    ///print path
    para

    cout<<"The Path is  ";
    while (!path.empty())
    {
        cout << path.top() <<", ";
        path.pop();
    }
    para



    return 0;
}
