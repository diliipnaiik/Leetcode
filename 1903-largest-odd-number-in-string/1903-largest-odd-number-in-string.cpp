class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        for(int right = n  ; right >= 0 ; right--){
            if(num[right] % 2 != 0){
                return num.substr(0,right+1);
            }
        }
        return "";
    }
};