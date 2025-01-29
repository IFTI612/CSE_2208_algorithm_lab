#include<bits/stdc++.h>
using namespace std;

void prinMap(map<int,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }

}

int main()
{
    map<int,string> m ;
    m[1]= "abc";///O(log(n)) time
    m[5]= "efe";
    m[3]= "mgl";
    m[6]= "oop";
    m[0]= "qrs";

    ///long way
//    map<int,string> ::iterator it;
//    for(it=m.begin();it!=m.end();it++)
//    {
//        cout<<(it->first)<<" "<<(it->second)<<endl;
//    }

    ///short way
//    for(auto &pr : m)
//    {
//        cout<<pr.first<<" "<<pr.second<<endl;
//    }

//    m[6];//kisu na dile by default ekta null value store hobe
//    // vector thak le , khali vector store hobe
//
//    m[9]=7;
 //prinMap(m);

 ///m.find() function will return a pointer of the key value


    m.erase(3); // it will take iterator or key value
    auto it = m.find(3);
    cout<<"Finding the value with the find function: "<<endl;
    if(it==m.end()){
        cout<<"NO VALUE";
    }
    else
    {
        cout<<it->first<<" "<<it->second<<endl;
    }


}
