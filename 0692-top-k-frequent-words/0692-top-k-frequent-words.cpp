class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> ans; 

        for(string ch : words){
            mp[ch]++;
        }

        int n = words.size();
        vector<vector<string>> bucket(n+1);

        for(auto& p : mp){
            bucket[p.second].push_back(p.first);
        }

        for(int i = n ; i >= 0 && ans.size() < k ; i--){
            sort(bucket[i].begin(), bucket[i].end());

            for(string ch : bucket[i]){
                ans.push_back(ch);

                if(k == ans.size()){
                    return ans;
                }
            }
        }
        return ans;
    }
};