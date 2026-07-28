class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        int sum = 0;
        
        for(int i = 0 ; i <= right ; i++){
            sum += nums[i];
        }

        int maxSum = sum;

        while(right < nums.size() - 1){
            sum -= nums[left];

            left++;

            right++;

            sum += nums[right];

            maxSum = max(sum,maxSum);
        }
        return (double)maxSum/k;
    }
};