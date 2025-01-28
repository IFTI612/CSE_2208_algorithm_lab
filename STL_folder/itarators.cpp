//printing something using itarator


#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6};

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

    return 0;
}
