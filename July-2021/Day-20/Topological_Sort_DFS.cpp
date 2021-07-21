// Problem Link :https://practice.geeksforgeeks.org/problems/topological-sort/1#


class Solution
{
	public:
	
	void sort(int node, stack<int> &stk, vector<int> &visited, vector<int> adj[]){
	    visited[node] = 1;
	    
	    for(int i=0; i<adj[node].size(); i++){
	        int child = adj[node][i];
	        if(!visited[child])
	            sort(child, stk, visited, adj);
	    }
	    stk.push(node);
	    return;
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0), v;
	    stack<int> stk;
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            sort(i, stk, visited, adj);
	        }
	    }
	    
	    while(!stk.empty()){
	        int top = stk.top();
	        v.push_back(top);
	        stk.pop();
	    }
	    
	    return v;
	}
};