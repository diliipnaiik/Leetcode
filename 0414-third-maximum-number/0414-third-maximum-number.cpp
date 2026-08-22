class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long thrid = LLONG_MIN;

        for(int num :  nums){
            if(num == first || num == second || num == thrid){
                continue;
            }

            if(num > first){
               thrid = second;
                second = first;
                first = num;
            }
            else if(second < num){
                thrid = second;
                second = num;
            }
            else if(thrid < num){
                thrid = num;
            }
        }
        return (thrid == LLONG_MIN) ? first : thrid;
    }
};