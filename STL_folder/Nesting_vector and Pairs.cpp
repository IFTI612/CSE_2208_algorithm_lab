#include<bits/stdc++.h>
using namespace std;

void printVec_pair(vector<pair<int,int>>&v)
{
    cout<<"Size: "<<v.size()<<endl;

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}

void printVec(vector<int>&v)
{
    cout<<"Size: "<<v.size()<<endl;

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";

    }
    cout<<endl;
}

int main()
{
    vector<pair<int,int>> vp = {{1,2},{3,4},{5,6},{7,8}};///this is way to initialize
    printVec_pair(vp);

    ///now how can we take user input///

    vector<pair<int,int>> vp_user;
    int n;
    cout<<"Take the number of pair...."<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int x, y;

        cin>>x>>y;
        vp_user.push_back({x,y});///again {}<- this is make pair short version....

    }
    cout<<endl;///this the way to take user input

    printVec_pair(vp_user);

    vector<int>v_arry[10];///this vector of array there are 10 vectors that are initialize

    vector<vector<int>>v_vector;///this is vector of vector... 2d vector
    ///for input make a temp vector otherwise the vector would not exist

    int N;

    cout<<"Enter Input For Vector of Vector....."<<endl;
    cout<<"enter the number of vectors."<<endl;


    cin>>N;

    for(int i=0; i<N; i++) ///this is how we should take vector vector input
    {
        cout<<i<<" vector size....";
        int vecSize;
        cin>>vecSize;

        vector<int>temp;
        for(int j= 0 ; j<vecSize; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);

        }
        v_vector.push_back(temp);
        cout<<endl;
    }

    for(int i=0; i<v_vector.size(); i++)///this is how to take the output
    {

        printVec(v_vector[i]);
    }










    return 0;
}
