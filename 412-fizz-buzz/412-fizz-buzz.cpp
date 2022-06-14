class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
         for(int i=1; i<=n; i++) {
             
             bool isDivisibleByFive = (i%5 == 0);
             bool isDivisibleByThree = (i%3 == 0);
             string str = "";
             
             if(isDivisibleByThree){
                 str += "Fizz";
             }  
             if(isDivisibleByFive){
                 str += "Buzz";
             } 
             if(str == "") {
                 str = to_string(i);
             } 

            v.push_back(str);
             
         }
        
        return v;
    }
};