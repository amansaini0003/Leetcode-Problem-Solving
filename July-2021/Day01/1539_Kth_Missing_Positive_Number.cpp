/* Problem Link : https://leetcode.com/problems/kth-missing-positive-number/


 Approach1: Bruteforce 
 Approach2: Using Binary Search
                T.C = O(logn)
                S.C = O(1)

*/

// Appraoch 1: 

class Solution {
    
public:
//     T.C = ??, S.C = O(1)
//                            O/P
//     Case1: [1 2 3]    k=2,  5
//     Case2: [3 4 5]    k=2,  2
//     Case3: [3 4 5 9]  k=3,  6
           
           
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int missed = 0, result;
        
        for(int i=0; i<n; i++){
            if(i==0){               // case1
                if(arr[i]-1>0)
                    missed += arr[i]-1;
                if(missed >= k)
                    return k;
            }       
            else{                                   // case3
                missed += arr[i] - arr[i-1] - 1;
                if(missed >= k){
                    missed -= arr[i] - arr[i-1] - 1;
                    result = arr[i-1];
                    while(missed < k){
                        missed++;
                        result++;
                    }
                    return result;
                }
            }
        }
                                // case2
        result = arr[n-1];
        while(missed < k){
            missed++;
            result++;
        }
        
        return result;
    }
};


/* Approach2: 

Explanation

Assume the final result is x,
And there are m number not missing in the range of [1, x].
Binary search the m in range [0, A.size()].

If there are m number not missing,
that is A[0], A[1] .. A[m-1],
the number of missing under A[m] is A[m] - 1 - m.

If A[m] - 1 - m < k, m is too small, we update left = m.
If A[m] - 1 - m >= k, m is big enough, we update right = m.

Note that, we exit the while loop, l = r,
which equals to the number of missing number used.
So the Kth positive number will be l + k.


Complexity

Time O(logN)
Space O(1)

*/



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high=arr.size();
        while(low < high){
            int m = low + (high-low)/2;
            if(arr[m]-1-m < k)
                low = m+1;
            else
                high = m;
        }
        return low + k;
    }
};