#include<bits/stdc++.h>
using namespace std;
/*
Detecting cycle in Undirected Graph
*/
class UndirectedGraph{

public:
    // nodes are numbered as 0, 1, ..., V-1
    // adj is adjacency list, where adj[i] contains all connecting edges
    // Checks whether graph has cycle or not
    // return true if it has cycle, else return false
    bool hasCycle(int V, vector<int> adj[]){
        // BFS based solution
        vector<int> isVisited(V, 0);
        vector<int> parent(V, -1);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(isVisited[i])
                continue;
            q.push(i);
            while (!q.empty())
            {
                int ele = q.front();
                q.pop();
                for(int j: adj[ele]){
                    // starting index has no parent
                    // store parent node for rest
                    if(i!=j && parent[j]==-1)
                        parent[j]=ele;
                    if(isVisited[j]==1 && parent[ele]!=j)
                        return true;
                    if(!isVisited[j])
                        q.push(j);

                }
                isVisited[ele] = 1;
            }
            
        }
        return false;
    }
};

/*
Detecting cycle in Directed Graph
*/
class DirectedGraph{

public:
    // nodes are numbered as 0, 1, ..., V-1
    // adj is adjacency list, where adj[i] contains all connecting edges
    // Checks whether graph has cycle or not
    // return true if it has cycle, else return false
    bool hasCycle(int V, vector<int> adj[]){
        
        // Dfs based solution
        
        vector<int> isVisited(V, 0);

        for(int i=0;i<V;i++){
            if(isVisited[i]==0 && dfs(i, isVisited, adj))
                return true;
        }

        return false;
    }

private:
    bool dfs(int source, vector<int> &isVisited, vector<int> adj[]){
        isVisited[source] = 1;
        for(int i: adj[source]){
            if(isVisited[i]==1) 
                return true;
            if(isVisited[i]==0 && dfs(i, isVisited, adj))
                return true;
        }
        isVisited[source] = 2;
        return false;
    }
public:
    bool hasCycleBfs(int V, vector<int> adj[]){
        // Kahn' BFS based algorithm

        // count the incoming nodes for each node to detect the source
        vector<int> incoming_nodes(V,0);
        for(int i=0;i<V;i++){
            for(int j: adj[i]){
                incoming_nodes[j]++;
            }
        }

        // BFS traversal
        queue<int> q;
        // push the source node to queue
        for(int i=0;i<V;i++){
            if(!incoming_nodes[i])
                q.push(i);
        }
        // traverse
        // count the number of loops, it executes
        int count = 0;
        // closest depency near source will be zero first.
        while(!q.empty()){
            int ele = q.front();
            for(int i: adj[ele]){
                incoming_nodes[i]--;
                // add the node to queue
                if(!incoming_nodes[i])
                    q.push(i);
            }
            q.pop();
            // count the number of node traversal
            count++;
        }

        // if count < V, it has cycle, because for that case loop will stop first
        return count<V;

    }
};



int main(){
    // created example for undirected graph
    cout<<"Testing for undirected graph\n";
    // No of testcases
    int t = 1;
    // Collection of number of nodes
    vector<int> vList = {};
    // Collection of number of edges
    vector<int> eList = {};
    // Collection of expected answers
    vector<int> answers = {};
    // Collection of edges
    vector<vector<int>> edges = {};

    // Create graph
    UndirectedGraph ugraph;
    int start = 0,end, success=0;
    string failed = "";
    for(int i=0;i<t;i++){
        end = start+ eList[i];
        // Adjacency list
        vector<int> adj[vList[i]];
        for(int j=start;j<end;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = ugraph.hasCycle(vList[i], adj);
        if(answers[i]==res){
            cout<<" Testcase-"<<(i+1)<<": Passed";
            success += 1;
        }
        else{
            cout<<" Testcase-"<<(i+1)<<": Failed";
            failed = failed + " "+ to_string(i+1);
        }
        
        start = end;
    }
    cout<< (success)<<"/"<< t <<" Testcases passed.\n";
    cout<< "Failed testcases:"<< failed <<"\n";

    // created example for Directed graph
    cout<<"Testing for directed graph\n";

    return 0;
}

