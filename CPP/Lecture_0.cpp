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


int main(){
    // created example for undirected graph
    cout<<"==========================================================================\n";
    cout<<"Testing for detecting cycles in undirected graph\n";
    cout<<"==========================================================================\n";
    // No of testcases
    int t = 1;
    // Collection of number of nodes
    vector<int> vList = {3,};
    // Collection of number of edges
    vector<int> eList = {2,};
    // Collection of expected answers
    vector<int> answers = {0,};
    // Collection of edges
    vector<vector<int>> edges = {
        // test case 1
        {1,2},{2,3},
    };

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
            cout<<"Testcase "<<(i+1)<<": Passed\n";
            success += 1;
        }
        else{
            cout<<"Testcase "<<(i+1)<<": Failed\n";
            failed = failed + " "+ to_string(i+1);
        }
        
        start = end;
    }
    cout<<"==========================================================================\n";
    cout<<"Result: \n";
    cout<< (success)<<"/"<< t <<" Testcases passed.\n";
    if(failed!="")
        cout<< "Failed testcases:"<< failed <<"\n";
    cout<<"==========================================================================\n";
    return 0;
}

