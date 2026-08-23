class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }

        priority_queue<pair<int,char>> maxHeap;

        for(auto& ch : mp){
            maxHeap.push({ch.second,ch.first});
        }

        string ans = "";

        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            int freq = top.first;
            char ch = top.second;

            ans.append(freq,ch);
            maxHeap.pop();
        }
        return ans;
    }
};