/*
    Approach : Using Binary Search
            T.C = O(logn * log2(M*10^d))

            d = decimal upto which we want answer.
*/
    

double fastPow(double a, double b){         // O(logb)
    if(b==0)return 1;
    if(b==1)return a;
    
    int ans;
    
    if(b%2==0){
        int temp = fastPow(a, b/2);
        ans = temp*temp;
    }
    else{
        int temp = fastPow(a, (b-1)/2);
        ans = a * temp * temp;
    }
    return ans;
}

int NthRoot(int n, int m)               // O(log2(M*10^d)
{
    double low = 1, high = m, eps = 1e-6;
    
    while((high-low) > eps){
        double mid = low + (high-low)/2;
        double power = fastPow(mid,n)
        if(m == power)
            return mid;
        else if(power > m)
                high = mid;
        else 
                low = mid;
    }
    
    return -1;
}  