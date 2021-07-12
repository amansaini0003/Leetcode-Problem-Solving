/* Problem Link : https://www.interviewbit.com/problems/matrix-median/

 Approach : Using Binary Search
            T.C = O(Nlogm)
*/


int upperBound(vector<int> &v, int key){
    int low = 0, high = v.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(key >= v[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
int count(vector<vector<int> > &mat, int key){
    int cnt = 0;
    for(int i=0; i<mat.size(); i++){
        cnt += upperBound(mat[i], key);
    }
    return cnt;
}

int Solution::findMedian(vector<vector<int> > &mat) {
    int low = 1, high = 1e9;
    int n =mat.size(), m = mat[0].size();
    int k = (m*n)/2;

    while(low <= high){
        int mid = low + (high-low)/2;
        int cnt = count(mat, mid);

        if(k >= cnt)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
