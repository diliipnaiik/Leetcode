class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128,-1);
        int left = 0;
        int ans = 0;

        for(int right = 0 ; right < s.size() ; right++){
            if(lastSeen[s[right]] >= left){
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;

            ans = max(right - left + 1, ans);
        }   
        return ans;
    }
};