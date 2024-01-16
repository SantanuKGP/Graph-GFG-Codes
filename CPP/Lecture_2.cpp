#include<bits/stdc++.h>
using namespace std;
// topological ordering for directed acyclic graph

// We will use BFS traversal
vector<int> topological_sorting_bfs(int V, vector<int> adj []){
    vector<int> order;
    queue<int> q;
    vector<int> incoming_edges(V,0);
    for(int i=0;i<V;i++){
        for(int j: adj[i])
            incoming_edges[j]++;
    }
    for(int i=0;i<V;i++){
        q.push(i);
    }
    // using this
    vector<int> isVisited(V,0);

    // this will work for single component
    // for multiple component we need to add 
    // a for loop over nodes
    
    while (!q.empty()){
        int ele = q.front();
        q.pop();
        if(!isVisited[ele])
            order.push_back(ele);
        else 
            continue;

        for(int i: adj[ele]){
            incoming_edges[i]--;
            if(!incoming_edges[i] && !isVisited[i])
                q.push(i);
        }
        
        isVisited[ele] = 1;
        
    }
    if(order.size()<V){
        cout<<"This Directed Graph is not Acyclic Directed Graph\n";
    }
    // print
    for(int i: order){
        cout<<i<<" ";
    }
    cout<<"\n";
    return order;
}
// we will use DFS traversal
void dfs(int u, vector<int>&isVisited, stack<int>&st,vector<int> adj[]);
vector<int> topological_sorting_dfs(int V, vector<int> adj []){
    vector<int> isVisited(V,0);
    stack<int> st;

    for(int i=0;i<V;i++)
        if(!isVisited[i])
            dfs(i,isVisited,st, adj);
    
    vector<int> v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    // print
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<"\n";
    return v;
}

void dfs(int u, vector<int>&isVisited, stack<int>&st,vector<int> adj[]){
    isVisited[u] = 1;
    for(int v: adj[u]){
        if(isVisited[v]==0){
            dfs(v,isVisited, st, adj);
        }
    }
    st.push(u);
}
int main(){

    // created example for directed graph
    cout<<"==========================================================================\n";
    cout<<"Testing for topological sorting in directed graph\n";
    cout<<"==========================================================================\n";
    // No of testcases
    int t = 2;
    // Collection of number of nodes
    vector<int> vList = {3, 5, };
    // Collection of number of edges
    vector<int> eList = {2, 5, };
    // Collection of expected answers
    vector<int> answers = {};
    // Collection of edges
    vector<vector<int>> edges = {
        // Testcase-1
        {0,1},{2,1},
        // Testcase-2
        {0,2}, {0,3},{3,2},{0,4},{2,4},
    };

    // Create graph
    int start = 0,end; 
    int success=0, success_=0;
    string failed = "";
    string failed_ = "";
    for(int i=0;i<t;i++){
        end = start+ eList[i];
        // Adjacency list
        vector<int> adj[vList[i]];
        for(int j=start;j<end;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            adj[u].push_back(v);
        }
        topological_sorting_bfs(vList[i], adj);
        topological_sorting_dfs(vList[i], adj);
        
        
        start = end;
    }
    cout<<"==========================================================================\n";
    
    return 0;
}