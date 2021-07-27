// Problem Link : https://www.spoj.com/problems/PT07Y/


bool  checkCycleDFS(int node, int parent, vi &vis, vi adj[]){
    vis[node] = 1;
    for (int i=0; i<adj[node].size(); i++) {
        int child = adj[node][i];
        if(!vis[child]){
            if(checkCycleDFS(child, node, vis, adj))
                return true;
        }
        else if(child != parent)
            return true;
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    if(n != m+1){cout << "NO";return;}
    
    vector<int> adj[n+1];
    vector<int> vis(n+1, 0);
    
    int u,v;
    
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i=1; i<=n; i++) {
        if(!vis[i]){
            if(checkCycleDFS(i, -1, vis, adj)){
                cout << "NO";
                return;
            }
        }
    }
    
    cout << "YES";
    return;
}

