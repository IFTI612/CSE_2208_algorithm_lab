#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string path;
    int cost;
    vector<vector<int>> arr ;


    Node(string p, int c, vector<vector<int>> a)
    {
        //cout<<"Hello"<<endl;
        path = p;
        cost =c;
        arr = a;
    }
};


struct Comp
{
    bool operator()(Node a, Node b)/// etar syntax ta utapalta
    {
        return a.cost<b.cost;

    }


};



int main()
{
//    priority_queue<Node,vector<Node>,Comp>pq;///eta ekta function
//
//    pq.push(25);
//    pq.push(30);
//    pq.push(40);
//    pq.push(3);
//    pq.push(10);
//    pq.push(11);
//    pq.push(31);


    Node data1("A->B",4, {{23,2,1,11}, {4,5,4}, {3,4,1}});
    Node data2("b->c",5, {{10,4,3,5}, {4,5,6}, {4,51,3}});
    Node data3("c->e",6, {{30,5,4,3}, {6,6,6,}, {5,5,5}});
    Node data4("f->g",9, {{40,55,3,3}, {7,7,7}, {9,9,9}});
    Node data5("A->f",3, {{45,3,5,42}, {2,2,2}, {4,4,4,4}});

    priority_queue<Node,vector<Node>,Comp>pq;///eta main jinish

    pq.push(data1);
    pq.push(data2);
    pq.push(data3);
    pq.push(data4);
    pq.push(data5);



    while(!pq.empty())
    {
        Node a = pq.top();

        cout<<a.cost<<"     "<<a.path<<"       ";
        for(int i = 0; i<a.arr.size(); i++)
        {
            for(int j = 0; j<a.arr[i].size(); j++)
            {
                cout<<a.arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        pq.pop();
    }
    return 0;
}
