// https://leetcode.com/problems/gas-station/
// https://www.interviewbit.com/problems/gas-station/

// very nice problem. Proving solution exists is main imp
// Consider tGas>tCost and prove by contradiction that no such config exists where travelling is not possible

class Solution {
    // If tGas > tCost. Then there always is a soultion.
    // travel from i->k and exhaust fuel at k means, no j where i<j<k exists where we could have started. Coz we came to j with some surplus but still didn't pass through
    int isTravellingPossible(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tGas=0, tCost=0;
        for(int i=0; i<n; i++) {
            tGas += gas[i];
            tCost += cost[i];
        }
        return tCost > tGas;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), start=0, fuelStock = 0;
        if(!isTravellingPossible(gas, cost)){
            for(int i=0; i<n; i++) {
                if(fuelStock+gas[i]<cost[i]){
                    start = i+1;
                    fuelStock = 0;
                } else {
                    fuelStock = fuelStock + gas[i] - cost[i];
                }
            }
            return start;
        }
        return -1;
    }
};