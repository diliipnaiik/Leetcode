class Solution {
public:
    bool fun(const vector<int>& position , int m , int mid){
        int ballPlaced = 1;
        int lastBallPlaced = position[0];

        for(int i = 1 ; i < position.size() ; i++){
            if(position[i] - lastBallPlaced >= mid){
                lastBallPlaced = position[i];
                ballPlaced++;
            }
        }
        return ballPlaced >= m;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low = 1;
        int high = position.back() - position.front();

        while(low <= high){
            int mid = low + (high - low)/2;

            if(fun(position,m,mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};