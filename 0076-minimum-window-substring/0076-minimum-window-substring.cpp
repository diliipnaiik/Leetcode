class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> need;
        unordered_map <char,int> window;

        for(char n : t){
            need[n]++;
        }

        int requried = need.size();       
        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0 ; right < s.size() ; right++){
            char ch = s[right];
            window[ch]++;

            if(need.count(ch) && window[ch] == need[ch]){
                formed++;
            }

            while(formed == requried){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                char ch = s[left];
                window[ch]--;


                if(need.count(ch) && window[ch] < need[ch]){
                    formed--;
                }
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start,minLen);
    }
};