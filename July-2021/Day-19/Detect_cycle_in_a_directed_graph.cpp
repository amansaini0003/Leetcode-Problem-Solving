// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

// Approach : Using DFS

class Solution
{
    public:
    
    bool checkForCycleDFS(int node, vector<int> &visited, vector<int> &currVisited, vector<int> adj[]){
        
        visited[node] = 1;
        currVisited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            int child = adj[node][i];
            
            if(!visited[child]){
                if(checkForCycleDFS(child, visited, currVisited, adj))
                    return true;
            }
            else if(currVisited[child])
                return true;
                    
        }
        currVisited[node] = 0;
        
        return false;
    }
    
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> visited(V,0), currVisited(V,0);
	   	
	   	for(int i=0; i<V; i++){
	   	    if(checkForCycleDFS(i, visited, currVisited, adj))
	   	        return true;
	   	}
	   	return false;
	}
};