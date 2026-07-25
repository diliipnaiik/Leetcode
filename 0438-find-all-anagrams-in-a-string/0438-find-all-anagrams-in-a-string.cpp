class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map <char,int> need;
        unordered_map <char,int> window;

        for(char n : p){
            need[n]++;
        }

        int windowSize = p.size();

        int left = 0;

        for(int i = 0 ; i < windowSize ; i++){
            window[s[i]]++;
        }

        if(window == need){
            ans.push_back(left);
        }

        for(int right = windowSize ; right < s.size() ; right++){
            window[s[left]]--;

            if(window[s[left]] == 0){
                window.erase(s[left]);
            }

            left++;

            window[s[right]]++;

            if(window == need){
                ans.push_back(left);
            }
        }
        return ans;
    }
};