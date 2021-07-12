/* Problem Link : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

    Approach 1 : Do Linear Scan and make new sorted array 
                 T.C = O(N+M)
                 S.C = O(N+M)
    Approach 2 : Using Max Heap of K-size
                 T.C = O(N+M)
                 S.C = O(logK)
    Approach 3 : Using Max Heap of K-size
                 T.C = O(logN + logM)
                 S.C = O(logN)
*/

// Approach 3 : 






// Approach 2 : 0.50ms
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> pq;
        
        for(int i=0; i<n; i++){
            pq.push(arr1[i]);
            if(pq.size() > k)
                pq.pop();
        }
        for(int i=0; i<m; i++){
            pq.push(arr2[i]);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};