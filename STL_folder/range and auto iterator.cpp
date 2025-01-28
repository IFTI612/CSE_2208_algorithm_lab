//printing something using itarator


#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*vector<int> v = {1,2,3,4,5,6};

    vector <int> ::iterator it = v.begin();///init it .... not gonna use that :)
    for(it=v.begin();it!=v.end();++it)///printing the vector using it :) not gonna...
    {
        cout<<(*it)<<endl;/// :)
    }

    ///lets start with the vector pair
    cout<<endl;

    vector<pair<int,int>>vp={{1,2},{3,4},{5,6},{7,8}};
    //making vp data type of iterator :)

    vector<pair<int,int>>::iterator it_vp = vp.begin();///init.....this iterator is pointer type....so use that as a pointer :')

    for(it_vp=vp.begin();it_vp!=vp.end();++it_vp)///printing the vector pair using it :) not gonna...
    {
        //cout<<(*it_vp).first<<" "<<(*it_vp).second<<" "<<endl;///never gonna use that:)
        cout<<(it_vp->first)<<" "<<(it_vp->second)<<" "<<endl; ///this is kinda helpful
    }
*/

    ///ranged based loop , it gets every property one by one
    vector<int> v = {1,2,3,4,5,6};

    ///go through c++ reference for & confusion
    for(int &value:v)///&is for ref this will not copy the value we can also use without &
    {
        cout<<value<<" ";
    }
    cout<<endl;

    ///ranged based loop using in vector pair
    vector<pair<int,int>>vp={{1,2},{3,4},{5,6},{7,8}};


    for(pair<int,int> &value:vp)///&is for ref this will not copy the value we can also use without &
    {
        cout<<value.first<<" "<<value.second<<" "<<endl;

    }
    cout<<endl;
    /// now lets talk about auto
    ///auto dynamically determine the data type of a variable like javascript 'let'

    ///we can use the auto to iterate the ranged based for loop
    ///like............

    for(auto &value:vp)///this is combination of auto and ranged loop
    {
       cout<<value.first<<" "<<value.second<<" "<<endl;
    }
    ///that will give the same value
    ///and if we dont use the & in the value. then it will create a new copy so
    ///we cannot be able to customize it after that
    ///for example we can customize it now

    cout<<endl;

    for(auto &value:v)
    {
        cout<<value<<" ";
    }
    cout<<"after increment"<<endl;

    for(auto &value:v)
    {
        value++;
    }

    for(auto &value:v)
    {
        cout<<value<<" ";
    }










    return 0;
}

