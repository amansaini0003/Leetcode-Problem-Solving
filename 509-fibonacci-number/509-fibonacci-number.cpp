class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        
        if(n == 0)return a;
        if(n == 1)return b;
        int ans;
        
        for(int i=2; i<=n; i++){
            ans = a+b;
            a = b;
            b = ans;
        }
        return ans;
    }
};