// Problem Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(int current, vector<int> &visited, vector<int> adj[], vector<int> &storeDfs){
	    storeDfs.push_back(current);
	    visited[current] = 1;
	    for(int i=0; i<adj[current].size(); i++){
	        int child = adj[current][i];
	        if(!visited[child])
	           dfs(child, visited, adj, storeDfs);
	    }
	    return;
	}
	
	vector<int> dfsOfGraph(int V, vector<int> adj[])
	{   
	    vector<int> storeDfs;
	    vector<int> visited(V+1, 0);
	    
	     for(int i=0; i<V; i++){
	         if(!visited[i]){
	             dfs(i, visited, adj, storeDfs);
	         }
	     } 
	     return storeDfs;
	}
};