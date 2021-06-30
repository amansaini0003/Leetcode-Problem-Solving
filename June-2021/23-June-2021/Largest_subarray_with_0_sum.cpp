// Problem : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
// Approach : Using hashing 
//          T.C = O(nlogn)

int maxLen(int arr[], int n)
{
    int len = 0, sum=0;
    map<int,int> mp;
    mp[0] = 0;
    for(int i=0; i<n; i++){             // O(n)
        sum += arr[i];
        
        auto it = mp.find(sum);         // O(logn)
        if(it==mp.end())
            mp[sum] = i+1;
        else{
            len = max(len, (i+1 - it->second));
        }
    }    
    return len;
}