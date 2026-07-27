class Solution {
public:
    bool fun(const vector<int>& nums, int maxOperations, int mid){
        long long operations  = 0;
        for(int num : nums){
            operations += ((num + mid - 1)/mid) - 1;
        }
        return operations <= maxOperations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(fun(nums,maxOperations,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};