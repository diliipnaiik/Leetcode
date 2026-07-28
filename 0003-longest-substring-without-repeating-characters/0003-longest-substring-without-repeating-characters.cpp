class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> window;
        int left = 0;
        int ans = 0;

        for(int right = 0 ; right < s.size() ; right++){
            if(window.find(s[right]) != window.end() && window[s[right]] >= left){
                left = window[s[right]] + 1;
            }

            window[s[right]] = right;

            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};