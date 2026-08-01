class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> window(26,0);
        vector<int> need(26,0);

        if(p.size() > s.size()){
            return {};
        }

        for(char c : p){
            need[c - 'a']++;
        }

        int windowSize = p.size();

        for(int i = 0 ; i < windowSize ; i++){
            window[s[i] - 'a']++;
        }

        int left = 0;

        if(window == need){
            ans.push_back(left);
        }

        for(int right = windowSize ; right < s.size() ; right++){
            window[s[right] - 'a']++;

            window[s[left] - 'a']--;
            left++;

            if(window == need){
                ans.push_back(left);
            }
        }
        return ans; 
    }
};