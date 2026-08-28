class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> minHeap;
        int range_start = 0;
        int range_end = INT_MAX;
        int current_max = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
           minHeap.push({nums[i][0],i,0});
            current_max = max(current_max,nums[i][0]);
        }

        while(minHeap.size() == nums.size()){
            auto curr = minHeap.top();
            minHeap.pop();

            int current_min = curr[0];
            int listIdx = curr[1];
            int eleIdx = curr[2];

            if((long long )current_max - current_min < (long long)range_end - range_start){
                range_start = current_min;
                range_end = current_max;
            }

            if(eleIdx + 1 < nums[listIdx].size()){
                int nextVal = nums[listIdx][eleIdx+1];
                minHeap.push({nextVal,listIdx,eleIdx+1});
                current_max = max(current_max,nextVal);
            }
        }
        return {range_start , range_end};
    }
};