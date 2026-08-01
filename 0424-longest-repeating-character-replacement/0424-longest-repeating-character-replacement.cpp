class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> window;
        int maxFreq = 0;
        int ans = 0;
        int left = 0;

        for(int right = 0 ; right < s.size() ; right++){
            window[s[right]]++;

            maxFreq = max(maxFreq,window[s[right]]);

            while((right - left + 1) - maxFreq > k){
                window[s[left]]--;
                left++;
            }

            ans = max(right - left + 1,ans);
        }
        return ans;
    }
};