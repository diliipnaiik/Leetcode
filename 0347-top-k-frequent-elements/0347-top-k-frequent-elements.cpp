class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
         
         for(int num : nums){
            map[num]++;
         }

        int n = nums.size(); 
        vector<vector<int>> bucket(n+1);
        for(auto& p : map){
            bucket[p.second].push_back(p.first);
        }

        for(int i = n ; i >= 0 && k > ans.size() ; i--){
            for(auto num : bucket[i]){
                ans.push_back(num);
                if(k == ans.size()){
                    return ans;
                }
            }
        }
        return ans;
    }
};