#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>    pii;
typedef vector<int>        vi;
typedef vector<pii>        vpii;
typedef vector<vi>        vvi;

//=======================


void dfs(int node, int &farthestNode, int currLevel, int &maxLevel,vi &vis, vi adj[]){
    vis[node] = 1;
    
    if(currLevel > maxLevel){
        maxLevel = currLevel;
        farthestNode = node;
    }
    
    for(int i=0; i<adj[node].size(); i++){
        int child = adj[node][i];
        if(!vis[child]){
            dfs(child, farthestNode, currLevel + 1, maxLevel,vis, adj);
        }
    }
    return;
}

void solve() {
    int n, m; cin >> n;
    m = n-1;
    vi adj[n+1];
    vi vis(n+1, 0);
    
    int u,v;
    
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int farthestNode = -1;
    int currLevel = 0;
    int maxLevel = -1;
    
    // First DFS call to find the farthest node;
    dfs(1, farthestNode, currLevel, maxLevel, vis, adj);
    
    currLevel = 0;
    maxLevel = -1;
    
    fo(i,n+1)vis[i] = 0;
    
    // Second DFS call to find the distance from one farthest node to another;
    dfs(farthestNode, farthestNode, currLevel, maxLevel, vis, adj);

    cout << maxLevel;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
//    cin >> t;
    while(t--) {
      solve();
        cout << "\n";
    }

    return 0;
}