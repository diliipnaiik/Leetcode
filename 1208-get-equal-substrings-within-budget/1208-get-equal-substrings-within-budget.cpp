class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currentCost = 0;
        int left = 0;
        int ans = 0;

        for(int right = 0 ; right < s.size() ; right++){
            currentCost += abs(s[right] - t[right]);

            while(currentCost > maxCost){
                currentCost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};