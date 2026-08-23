class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(char c : s){
            mp[c]++;
        }

        int n = s.size();
        vector<vector<char>> bucket(n+1);
        for(auto& ch : mp){
            bucket[ch.second].push_back(ch.first);
        }

        string ans = "";
        for(int i = n ; i >= 0 ; i--){
            for(char ch : bucket[i]){
                ans.append(i,ch);
            }
        }
        return ans;
    }
};