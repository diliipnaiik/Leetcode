class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> window(26,0);

        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;

        for(int right = 0 ; right < s.size() ; right++){
            window[s[right] - 'A']++;

            maxFreq = max(maxFreq,window[s[right] - 'A']);

            while((right - left + 1) - maxFreq > k){
                window[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};