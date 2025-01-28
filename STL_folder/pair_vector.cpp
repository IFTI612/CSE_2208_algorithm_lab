#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int>&v)
{
    cout<<"Size: "<<v.size()<<endl;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>v(10,3);///initialize vector with 3
    printVec(v);///print vector function

    v.push_back(10);
    v.push_back(11);

    printVec(v);///proved that vector is a dynamic array

    ///we can copy vector....
    vector<int>v2 = v;//O(n)

    printVec(v2);

    ///or we can pass by referece

    vector<int>&v1=v;///if i change something on v1 it will effect on v vector//

    v1.pop_back();

    cout<<"printing v1"<<endl;
    printVec(v1);
    cout<<"printing v"<<endl;
    printVec(v);

    cout<<endl;


    cout<<endl;
    cout<<"Pair section"<<endl;
    pair<int,string>p;

    //p = make_pair(2,"abc");
    p={2,"abcd"};//this way is more easier then make_pair()

    pair<int,string>p1=p;///copying the p
    p1.first = 1;//wont effect anything in p

    //but......
    pair<int,string>&p2=p;///this is going by reference

    p2.first = 3;/// it will change the p.first element



    cout<<p.first<<" "<<p.second<<endl;

    ///now why do we need pair....
    ///if we have relation between two array or similar type of data we could use
    ///pair to track their data and change them both at a time

    int a[]={1,2,3};
    int b[]={4,5,6} ;

    pair<int,int>p_arry[3];

    p_arry[0]={1,4};
    p_arry[1]={2,5};
    p_arry[2]={3,6};///this is make_pair() by the way


    for(int i = 0;i<3;i++)
    {
        cout<<p_arry[i].first<<" "<<p_arry[i].second<<endl;
    }
    cout<<"After the swap........."<<endl;

    ///after swap the p_arry[0] and p_arry[2]

    swap(p_arry[0],p_arry[2]);

     for(int i = 0;i<3;i++)
    {
        cout<<p_arry[i].first<<" "<<p_arry[i].second<<endl;
    }
}
