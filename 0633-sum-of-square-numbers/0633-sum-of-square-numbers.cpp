class Solution {
public:
    bool judgeSquareSum(int c) {

        for(long long a = 0 ; a*a <= c ; a++){

            int remaining = c - a*a;

            long long low = 0;
            long long high = sqrt(remaining);

            while(low <= high){
                long long mid = low + (high - low)/2;

                if(mid*mid == remaining){
                    return true;
                }

                else if(mid*mid < remaining){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};