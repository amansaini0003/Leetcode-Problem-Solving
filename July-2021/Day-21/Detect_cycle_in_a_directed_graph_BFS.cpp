// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

// Approach : Using BFS and TOPO_SORT


class Solution
{
    public:
    
    int topoSort(int V, vector<int> &indegree, vector<int> adj[]){
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(int i=0; i<adj[node].size(); i++){
                int child = adj[node][i];
                indegree[child]--;
                
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        
        return cnt;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> indegree(V,0);
	   	
	    for(int node=0; node<V; node++){
	        for(int j=0; j<adj[node].size(); j++){
	            int child = adj[node][j];
	            indegree[child]++;
	        }
	    }
	   	
	   	int noOfNodes = topoSort(V, indegree, adj);
	   	
	   	if(noOfNodes == V)
	   	    return false;
	   	return true;
	}
	
};