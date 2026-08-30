class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;
        int startIdx = 0;
        int currentTank = 0;

        for(int i = 0 ; i < gas.size() ; i++){
            totalCost += cost[i];
            totalGas += gas[i];
            currentTank += gas[i] - cost[i];

            if(currentTank < 0){
                startIdx = i + 1;
                currentTank = 0;
            }
        }
        return (totalGas < totalCost) ? -1 : startIdx;
    }
};