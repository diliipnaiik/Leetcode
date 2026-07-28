class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = k - 1;
        int vowels = 0;

        for(int i = 0 ; i <= right ; i++){
            if(string("aeiou").find(s[i]) != string::npos){
                vowels++;
            }
        }

        int maxVowels = vowels;

        while(right < s.size() - 1){
            if(string("aeiou").find(s[left]) != string::npos){
                vowels--;
            }

            left++;
            right++;

            if(string("aeiou").find(s[right]) != string::npos){
                vowels++;
            }

            maxVowels = max(vowels,maxVowels);
        }
        return maxVowels;
    }
};