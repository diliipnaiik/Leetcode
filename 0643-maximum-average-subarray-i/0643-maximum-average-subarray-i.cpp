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
            sum = sum - nums[left];
            left++;
            right++;
            sum = sum + nums[right];

            if(sum > maxSum){
                maxSum = sum;
            }
        }
        return double(maxSum)/k;
    }
};