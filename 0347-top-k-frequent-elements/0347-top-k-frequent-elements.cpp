class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
         
         for(int num : nums){
            map[num]++;
         }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;

        for(auto& p : map){
            minHeap.push({p.second,p.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};