/*
 *Given a vector of integers, v[i] represent the stock price on day i. 
 Now you may do at most K transactions. you must sell your stock before you buy it again and 
 that means you can NOT have two stocks at the same time. write a program to find max profit you can get.
 * */

// Time: O(kN), Space:O(k)
// Solution:
// s0[i][j] - max possible balance on our cash account on ith day when at most j transactions were made and we don't have a stock
// s1[i][j] - max possible balance on our cash account on ith day when at most j transactions were made and we do have a stock 
// We start with the condition where we have 0 transactions - 0$ balance and we don't have a stock:
// s0[0][0] = 0$
// The initial condition where we have a stock is impossible - making it unfavorable by setting negatively-infinite balance:
// s1[0][0] = -INFINITY$
//
// Now we can use the following recurrent relationships:
// 1) If have stock at the end if ith day - this means we either just bought it (cash decreases by v[i]) or we did nothing.
// chose maximum of those two options - since we want to maximize
// s1[j] = max(s1[j], s0[j-1]-v[i]);
//
// 2) If don't have stock at the end if ith day - this means we ether just sold it (cash increases by v[i]) or we did nothing.
// chose maximum of those two options - since we want to maximize
// s0[j] = max(s0[j], s1[j-1]+v[i]);
//
// Now, if you notice that we always refer to [i-1] which means we don't have to store the whole matrix: we just need the last column.
// This gives O(N*k) time, O(k) memory algorithm.
int maximizeProfit(const vector<int> &v, int k)
{       // v = values of stock on each day
        // k = max. no. of transactions
        vector<int> s0(k+1), s1(k+1);
            s1[0] = INT_MIN;
            for (int j = 1; j <= k; j++) {
                s1[j] = -v[0];
            }

            for (int i = 1; i < v.size(); i++) {
                for (int j = k; j>=1; j--) {
                    s1[j] = max(s1[j], s0[j-1]-v[i]);
                    s0[j] = max(s0[j], s1[j-1]+v[i]);
                }
            }
            return s0[k];
}
