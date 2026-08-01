class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26,0);
        vector<int> window(26,0);

        if(s1.size() > s2.size()){
            return false;
        }

        for(int i = 0 ; i < s1.size() ; i++){
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if(window == need){
            return true;
        }

        for(int right = s1.size() ; right < s2.size() ; right++){
            window[s2[right] - 'a']++;

            int left = right - s1.size();
            window[s2[left] - 'a']--;

            if(need == window){
                return true;
            }
        }
        return false;
    }
};