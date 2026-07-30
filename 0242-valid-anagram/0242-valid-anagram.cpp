class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mp;

        int len1 = s.size();
        int len2 = t.size();

        if(len1 != len2){
            return false;
        }

        for(char ch : s){
            mp[ch]++;
        }

        for(char ch : t){
            mp[ch]--;

            if(mp[ch] < 0){
                return false;
            }
        }
        return true;
    }
};