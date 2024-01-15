#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Give the number of nodes and edges respectively\n";
    int V, E;
    cout<<"The number of nodes: ";
    cin>>V;
    cout<<"The number of edges: ";
    cin>>E;
    cout<< "Enter the edges\n";

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<"The Result: \n";
    cout<<"{";
    for(int i=0;i<E;i++){
        int u,v;
        cin>> u >> v;
        if(i!=E-1)
            cout<<"{"<<u<<","<<v<<"},";
        else
            cout<<"{"<<u<<","<<v<<"}}";
    }
    return 0;
}