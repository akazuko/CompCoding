class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maxProfit(self, A):
        greatest_on_right = 0;
        profit = 0;
        for i in range(len(A) - 1, -1, -1):
            greatest_on_right = max(A[i], greatest_on_right);
            profit = max(profit, greatest_on_right - A[i]);
        return profit;