// Problem Link : https://practice.geeksforgeeks.org/problems/bipartite-graph/1#

                        // Method 1 : Using BFS

class Solution{
    public:
    
    bool isBipartiteGraph(int source, int color, vector<int> &visited, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({source,color});
        visited[source] = color;
        
        while(!q.empty()){
            int node = q.front().first;
            int parentColor = q.front().second;
            
            q.pop();
            
            for(int i=0; i<adj[node].size(); i++){
                int child = adj[node][i];
                
                if(visited[child] == -1){
                    q.push({child, !parentColor});
                    visited[child] = !parentColor;
                }
                else if(parentColor == visited[child])
                        return false;    
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
        vector<int> visited (V, -1);
        int color = 0;
        
        // 0 -> BLUE
        // 1 -> GREEN
        
        for(int i=0; i<V; i++){
            if(visited[i] == -1){
                if(isBipartiteGraph(i, color, visited, adj)==false)
                    return false;
            }
        }
        return true;
	}
}



                    // Method 2 : Using DFS

class Solution {
public:
    bool isBipartiteGraphDFS(int node, int color, vector<int> &visited, vector<int> adj[]){
      
        visited[node] = color;
        
        for(int i=0; i<adj[node].size(); i++){
            int child = adj[node][i];
            if(visited[child] == -1){
                visited[child] = !(color);
                if(isBipartiteGraphDFS(child, !color, visited, adj) == false)
                    return false;
            }
            else if(visited[child] == color)
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
        vector<int> visited (V, -1);
        int color = 0;
        
        // 0 -> BLUE
        // 1 -> GREEN
        
        for(int i=0; i<V; i++){
            if(visited[i] == -1){
                if(isBipartiteGraphDFS(i, color, visited, adj)==false)
                    return false;
            }
        }
        return true;
	}

};