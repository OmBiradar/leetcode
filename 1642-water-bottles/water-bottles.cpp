class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empties = numBottles;
        
        while (empties >= numExchange) {
            int newBottles = empties / numExchange;
            total += newBottles;
            empties = newBottles + (empties % numExchange);
        }
        
        return total;
    }
};