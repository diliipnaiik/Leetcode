class Solution {
public:
    bool fun(const vector<int>& quantities,int n,int mid){
        int storesNeeded = 0;
        for(int quantity : quantities){
            storesNeeded += (quantity + mid - 1)/mid;
        }
        return storesNeeded <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(fun(quantities,n,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};