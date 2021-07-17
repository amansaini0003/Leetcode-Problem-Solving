// Problem Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	
	void bfs(int source, vector<int> &visited, vector<int> &storeBFS, vector<int> adj[]){
	    queue<int> q;
	    q.push(source);
	    
	    visited[source] = 1;
	    
	    while(!q.empty()){
	        int current = q.front();
	        storeBFS.push_back(current);
	        q.pop();
	        
	        for(int i=0; i<adj[current].size(); i++){
	            int child = adj[current][i];
	            if(!visited[child]){
	                q.push(child);
	                visited[child] = 1;
	            }
	        }
	    }
	    return;
	}
	
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> visited(V,0), storeBFS;
        bfs(0, visited, storeBFS, adj);
	    
	    return storeBFS;
	}
};