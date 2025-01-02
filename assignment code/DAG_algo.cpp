///DAG algo print all the path from the source and print the shortest path

///ID :20220204030
#include<bits/stdc++.h>
using namespace std;

#define Inf 1e3


///Variables
int node_A, node_B, weight,node, edge,src;
vector<int> node_vec[100];
vector<int> node_cost[100];
vector<int>top_sort;
int color[12];
//bool cycle = false;






void DFS(int u)
{
    color[u]=0;
    for(int i=0; i<node_vec[u].size(); i++)
    {
        int v =node_vec[u][i];
//        if(color[v]==0)//check cycle
//        {
//            cycle = true;
//
//            return;
//        }
        if(color[v]==-1)
        {
            DFS(v);
        }
    }
    color[u]=1;
    top_sort.insert(top_sort.begin(),u);

}





//void Top_sort(int node)
//{
//    ///
//
//}


void DAG_SP(int src)
{
    ///top_sort
    for(int i = 1 ; i<=node; i++)
    {
        if(color[i]==-1)
        {
            DFS(i);

        }
    }
//    if(cycle)
//    {
//        cout<<"Cycle Found"<<endl;
//        return;
//    }

    cout<<"Topologically Shorted : ";

    for(int i:top_sort)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    ///Init_single_scr
    int dis[100],pre[100];
    for(int i:top_sort)
    {
        dis[i]=Inf;//infinity
        pre[i]=0;//null
    }
    dis[src]=0;
    cout<<endl;

    ///relax
    for(int u:top_sort)
    {
        for(int i = 0 ; i<node_vec[u].size(); i++)
        {
            int v = node_vec[u][i];
            if(dis[v]>(dis[u]+node_cost[u][i]))
            {
                dis[v] = dis[u]+node_cost[u][i];
                pre[v]=u;
            }
        }
    }

    ///print_path
    for(int n:top_sort)
    {
        cout<<n<<": ";
        if(dis[n]==Inf)
        {
            cout<<"Infinity"<<endl;

        }
        else
        {
            cout<<src;
            stack<int>path;
            int x=n;
            while(n!=src)//pushes the path until the src is found
            {
                path.push(n);
                n = pre[n];

            }
            while (!path.empty()) // Pops them out in sequence for ease of printing
            {
                cout << " -> " << path.top();
                path.pop();
            }
            cout<<" Cost : "<<dis[x]<<endl;
        }
    }

}

int main()
{

    cout<<"Enter the number of Nodes and Edges"<<endl;
    cin>>node>>edge;

    ///Input Graph in DAG
    cout<<"Source -> Destination -> Weight"<<endl;
    for(int i=0; i<edge; i++)
    {

        cin>>node_A>>node_B>>weight;
        node_vec[node_A].push_back(node_B);
        node_cost[node_A].push_back(weight);

    }

    ///adj list

    for(int i = 0; i<node; i++)
    {
        cout<<i<<" -> ";
        for(int j = 0 ; j<node_vec[i].size() ; j++)
        {
            cout<<node_vec[i][j]<<" ";

        }
        cout<<endl;
    }

     for (int i = 1; i <= node; i++) // Initializes all nodes to white for DFS
    {
        color[i] = -1;
    }

    ///input source
    cout<<"Enter Source"<<endl;

    cin>>src;
    ///call dag
    DAG_SP(src);



    ///Output Topsort


    ///Output All possible Path and their cost


    return 0;
}
///ID : 20220204030
