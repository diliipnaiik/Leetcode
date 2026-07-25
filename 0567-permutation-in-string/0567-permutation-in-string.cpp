class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        unordered_map <char,int> need;
        unordered_map<char,int>window;

        for(char n : s1){
            need[n]++;
        }

        int windowSize = s1.size();

        for(int i = 0 ; i < windowSize ; i++){
            window[s2[i]]++;
        }

        if(window == need){
            return true;
        }

        int left = 0;

        for(int right = windowSize ; right < s2.size() ; right++){
            window[s2[left]]--;

            if(window[s2[left]] == 0){
                window.erase(s2[left]);
            }

            left++;

            window[s2[right]]++;

            if(window == need){
                return true;
            }

        }
        return false;
    }
};