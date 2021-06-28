// Problem Link : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    
     void solve(vector<int> ip, vector<int> op, set<vector<int>> &ans){
        if(ip.size()==0){
            sort(op.begin(), op.end());
            ans.insert(op);
            return;
        }
            
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> op;
        
        solve(nums, op, ans);
        
        vector<vector<int>> v;
        for(auto i : ans){
            v.push_back(i);
        }
        ans.clear();
        
        return v;
    }
};