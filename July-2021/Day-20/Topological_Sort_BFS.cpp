// Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1#


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void calculateIndegree(vector<int> &indegree, int V, vector<int> adj[]){
	    
	    for(int i=0; i<V; i++){
	        for(int j=0; j<adj[i].size(); j++){
	            int child = adj[i][j];
	            indegree[child]++;
	        }    
	    }
	    
	    return;
	}
	
	vector<int> sortBfs(int V, vector<int> &indegree, vector<int> adj[]){
	    vector<int> v;
	    queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        v.push_back(node);
	        q.pop();
	        
	        for(int i=0 ; i<adj[node].size(); ++i){
	            int child = adj[node][i];
	            
	            indegree[child]--;
	            if(indegree[child]==0)
	                q.push(child);
	        }
	    }
	    
	    return v;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> indegree(V,0);
	   
	   calculateIndegree(indegree, V, adj);
	   
	   vector<int> v;
	   v = sortBfs(V, indegree, adj);
	       
	   return v;
	}
};