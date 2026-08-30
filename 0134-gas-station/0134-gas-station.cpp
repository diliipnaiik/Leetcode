class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;
        int currentTank = 0;
        int startIndex = 0;

        for(int i = 0 ; i < gas.size() ; i++){
            totalCost += cost[i];
            totalGas += gas[i];
            currentTank += cost[i] - gas[i];

            if(currentTank > 0){
                startIndex = i + 1;
                currentTank = 0;
            }
        }

        return (totalGas < totalCost) ? -1 : startIndex;
    }
};