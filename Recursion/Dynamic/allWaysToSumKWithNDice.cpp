
/*
Problem: Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X.
 
Let the function to find X from n dice is: Sum(m, n, X)
The function can be represented as:
Sum(m, n, X) = Finding Sum (X - 1) from (n - 1) dice plus 1 from nth dice
               + Finding Sum (X - 2) from (n - 1) dice plus 2 from nth dice
               + Finding Sum (X - 3) from (n - 1) dice plus 3 from nth dice
                  ...................................................
                  ...................................................
                  ...................................................
              + Finding Sum (X - m) from (n - 1) dice plus m from nth dice

So we can recursively write Sum(m, n, x) as following
Sum(m, n, X) = Sum(m, n - 1, X - 1) + 
               Sum(m, n - 1, X - 2) +
               .................... + 
               Sum(m, n - 1, X - m)

Following is C++ implementation of Dynamic Programming approach.
// C++ program to find number of ways to get sum 'x' with 'n'
// dice where every dice has 'm' faces
*/

// Time = O(m*n*X)
#include <iostream>
#include <string.h>
using namespace std;
 
// The main function that returns number of ways to get sum 'x'
// with 'n' dice and 'm' with m faces.
int findWays(int m, int n, int x)
{
    // Create a table to store results of subproblems.  One extra
    // row and column are used for simpilicity (Number of dice
    // is directly used as row index and sum is directly used
    // as column index).  The entries in 0th row and 0th column
    // are never used.
    int **table = new int*[n + 1];
	for(int i=0; i<n+1; i++){
		table[i] = new int[x + 1];
	}
    memset(table, 0, sizeof(table)); // Initialize all entries as 0
 
    // Table entries for only one dice
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;
 
    // Fill rest of the entries in table using recursive relation
    // i: number of dice, j: sum
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];
 
    /* Uncomment these lines to see content of table
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= x; j++)
        cout << table[i][j] << " ";
      cout << endl;
    } */
    return table[n][x];
}
