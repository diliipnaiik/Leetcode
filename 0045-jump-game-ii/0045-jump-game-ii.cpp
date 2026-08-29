class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curr_end = 0;
        int max_Reach = INT_MIN;

        for(int i = 0 ; i < nums.size() - 1; ++i){
            max_Reach = max(max_Reach,nums[i]+i);

            if(curr_end == i){
                jumps++;
                curr_end = max_Reach;
            }
            if(curr_end >= nums.size() - 1){
                    return jumps;
                }
        }
        return jumps;
    }
};