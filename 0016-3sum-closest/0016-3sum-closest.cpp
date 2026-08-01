class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0 ; i < n - 2 ; i++){

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int minSum = nums[i] + nums[i+1] + nums[i+2];
            if(minSum > target){
                if(abs(minSum - target) < abs(closestSum - target)){
                    closestSum = minSum;
                }

                if(minSum >= target){
                    break;
                }
            }

            int maxSum = nums[i] + nums[n-1] + nums[n-2];
            if(maxSum < target){
                if(abs(maxSum - target) < abs(closestSum - target)){
                    closestSum = maxSum;
                }
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int currentSum = nums[i] + nums[left] + nums[right];

                if(abs(currentSum - target) < abs(closestSum - target)){
                    closestSum = currentSum;
                }

                else if(currentSum < target){
                    left++;

                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                }

                else if(currentSum > target){
                    right--;

                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else{
                    return currentSum;
                }
            }
        }
        return closestSum;
    }
};