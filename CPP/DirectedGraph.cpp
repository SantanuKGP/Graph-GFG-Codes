#include<bits/stdc++.h>
using namespace std;

/*
I want to create a Directed Graph Class, which takes some parameters
*/
class DirectedGraph
{
public:
    DirectedGraph(/* args */);
    
private:
    vector<int> topological_order;
    bool isDAG ;

    bool hasCycle(int V, vector<int> adj[]){
        
        // Dfs based solution
        
        vector<int> isVisited(V, 0);

        for(int i=0;i<V;i++){
            if(isVisited[i]==0 && dfs(i, isVisited, adj))
                return true;
        }

        return false;
    }

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
    // Most important code
    void topological_sorting(int V, vector<int> adj[]){
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
            topological_order.push_back(ele);
        }

        // if count < V, it has cycle, because for that case loop will stop first
        // for DAG, it will run for V times
        isDAG = (count==V);
    }
};

int main(){

    return 0;
}