#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    vector<int> arr(20);
    map<int,int,greater<int> > m;
    for(auto& x:arr)
    {
        x = rand()%6;
        m[x]++;
    }
    for(auto x:arr)
        cout<<x<<' ';
    cout<<'\n';
    
    for(auto go:m)
        cout<<go.first<<' '<<++go.second<<'\n';
    cout<<'\n';

    for(map<int,int>::iterator go=m.begin();go!=m.end();++go)
        cout<<(go->first)<<' '<<++(*(go)).second<<'\n';
    cout<<'\n';

    for(auto& go:m)
        cout<<go.first<<' '<<++go.second<<'\n';
    cout<<'\n';

    for(auto go=m.begin();go!=m.end();++go)
        cout<<(go->first)<<' '<<(*(go)).second<<'\n';
    cout<<'\n';

  	return 0;
}
