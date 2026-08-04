class Solution {
public:
    void printF(vector<int>& nums, vector<vector<int>>& ds, vector<int> current, int ind){
        if(ind == nums.size()){
            ds.push_back(current);
            return;
        }
    
        current.push_back(nums[ind]);
        printF(nums,ds,current,ind+1);

        current.pop_back();

        while(ind < nums.size()-1 && nums[ind] == nums[ind+1]){
            ind++;
        }
        printF(nums,ds,current,ind+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ds;
        vector<int> current;
        printF(nums,ds,current,0);

        return ds;
    }
};