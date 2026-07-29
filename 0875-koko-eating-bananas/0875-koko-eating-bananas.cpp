class Solution {
public:
    bool fun(const vector<int>& piles, int h, int mid){
        long long totalHrs = 0;
        for(int pile : piles){
            totalHrs += (pile + mid - 1)/mid;
        }

        return totalHrs <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            long long mid = low + (high - low)/2;

            if(fun(piles,h,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};