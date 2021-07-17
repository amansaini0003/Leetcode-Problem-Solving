// Problem Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

                    
                    // Method 1 : Using BFS

                    
class Solution 
{
    public:
    bool checkCycle(int source, vector<int> &visited, vector<int> adj[]){
	    queue<pair<int,int>> q;
	    pair<int,int> current = {source , -1};
	    
	    q.push(current);
	    visited[current.first] = 1;
	    
	    while(!q.empty()){
	        current = q.front();
	        q.pop();
	        
	        for(int i=0; i<adj[current.first].size(); i++){
	            int child = adj[current.first][i];
	            
	            if(!visited[child]){
	                q.push({child, current.first});
	                visited[child] = 1;
	            }
	            else if(current.second != child)
	                return true;
	            
	        }
	    }
	    return false;
	}

    //Function to detect cycle in an undirected graph.
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> visited(V+1,0);
	   	
	   	for(int i=0; i<V; i++){
	   	    if(!visited[i]){
	   	        if(checkCycle(i, visited, adj))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};



                            // Method 2 : Using DFS




class Solution 
{
    public:
    
    bool checkCycleDFS(pair<int,int> curr, vector<int> &visited, vector<int> adj[]){
        int node = curr.first;
        int parent = curr.second;
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            int child = adj[node][i];
            
            if(!visited[child]){
                if(checkCycleDFS({child, node}, visited, adj))
                    return true;
            }
            else if(parent != child)
                return true;
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> visited(V+1, 0);
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            if(checkCycleDFS({i,-1}, visited, adj))return true;
	        }
	    }
	    return false;
	}
};