class Solution {
private:
    struct comp{
        bool operator()(const pair<int,string>& a , const pair<int,string>& b){
            if(a.first != b.first){
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> ans;

        for(string ch : words){
            mp[ch]++;
        }

        priority_queue<pair<int,string> , vector<pair<int,string>> , comp> minHeap;

        for(auto& p : mp){
            minHeap.push({p.second,p.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};