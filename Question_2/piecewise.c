First Method : Recursive Approach

#include <stdio.h>

int piecewiseRecursion(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    return piecewiseRecursion(n - 3) + piecewiseRecursion(n - 2);
}

int main() {
    int n = 10; // Just an example value of n
    printf("F(%d) = %d\n", n, piecewiseRecursion(n));
    return 0;
}

/*
Advantages of Recursive approach:
--Simple and straightforward implementation
--Directly reflects the recurrence relation

Disadvantages of Recursive approach:
-- Inefficient for large values of n due to overlapping subproblems and repeated calculations
-- Leads to exponential time complexity.
*/


Second Method :  Memoization (Top-Down Dynamic Programming)
#include <stdio.h>

int memo[100]; // Assuming n <= 100

int piecewiseMemoization(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = piecewiseMemoization(n - 3) + piecewiseMemoization(n - 2);
    return memo[n];
}

int main() {
    int n = 10; // Just an example value of n
    for (int i = 0; i < 100; i++) memo[i] = -1; // Initializing memoization array
    printf("F(%d) = %d\n", n, piecewiseMemoization(n));
    return 0;
}

/*
Advantages of Memoization:
--Avoids redundant calculations by storing already computed values in the memo array
--Reduces time complexity to linear or near-linear (depending on the size of n)

Disadvantages of Memoization:
--Requires additional memory for the memoization array
--Still has a function call overhead
*/


Third Method : Iterative(Bottom-Up Dynamic Programming)
#include <stdio.h>

int piecewiseIteration(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10; // Just an example value of n
    printf("F(%d) = %d\n", n, piecewiseIteration(n));
    return 0;
}

/*
Advantages of Iterative Approach:
--Efficiently computes values iteratively, avoiding function call overhead.
--No additional memory overhead compared to memoization.

Disadvantages of Iterative Approach:
--May not be as intuitive as the recursive approach.
--Requires an array of size "n+1" to store intermediate values.
*/
