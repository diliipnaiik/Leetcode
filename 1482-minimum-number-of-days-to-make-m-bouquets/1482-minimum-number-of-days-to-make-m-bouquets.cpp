class Solution {
public:
    bool fun(const vector<int>& bloomDay, int day, int m, int k){
        int consecutive = 0;
        int bouquets = 0;

        for(int bloom : bloomDay){
            if(bloom <= day){
                consecutive++;
            }
            else{
                consecutive = 0;
            }
            if(k == consecutive){
                bouquets++;
                consecutive = 0;
            }
        }
        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(fun(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};