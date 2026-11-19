class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int p : prices) {
            buy1  = max(buy1,  -p);       // buy as cheap as possible
            sell1 = max(sell1, buy1 + p); // sell at best profit after buy1
            buy2  = max(buy2,  sell1 - p); // reinvest sell1 profit into second buy
            sell2 = max(sell2, buy2 + p);  // final profit after second sell
        }
        return sell2;
    }
};