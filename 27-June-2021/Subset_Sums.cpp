/* Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

    Approch : Using Recursion
            T.C = O(2^N);
*/
class Solution{
public:
    void solve(vector<int> ip, int op, int n, vector<int> &ans){
        if(n==0){
            ans.push_back(op);
            return;
        }
        
        int op1 = op;
        int op2 = op;
        
        op2 += ip[n-1];
        
        solve(ip, op1, n-1, ans);
        solve(ip, op2, n-1, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int op = 0;
        solve(arr, op, N, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};