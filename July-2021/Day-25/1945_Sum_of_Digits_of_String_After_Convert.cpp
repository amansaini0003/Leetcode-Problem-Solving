// Problem Link : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        
        
        int sum = 0;
        for(char c : s){
            int digit = c-'a'+1;
            while(digit){
                sum += digit % 10;
                digit /= 10;
            }
        }
        
         int num = sum;
    
        while(--k){
            sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }
};