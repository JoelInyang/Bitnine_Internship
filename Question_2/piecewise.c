#include <stdio.h>

//First Method : Recursive Approach
int recursivePiecewise(int n) {
    if (n <= 2) {
        return n;
    }
    return recursivePiecewise(n - 3) + recursivePiecewise(n - 2);
}

/*
Advantages of Recursive approach:
--Reflects the recurrence relation directly
--The implementation is uncomplicated

Disadvantages of Recursive approach:
--There would be exponential time complexity
--Overlapping might occur due to large values of n
*/


//Second Method :  Memoization (Top-Down Dynamic Programming)
int memo[50]; // Assuming n <= 50

int memoizedPiecewise(int n) {
    if (n <= 2) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = memoizedPiecewise(n - 3) + memoizedPiecewise(n - 2);
    return memo[n];
}

/*
Advantages of Memoization:
--The time complexity is reduced (depending on the size of n)
--The memo array above stores computed values thereby leading to no redundant calculations

Disadvantages of Memoization:
--Function call overhead is still present
--Additional memory for the memoization array is required
*/


//Third Method : Iterative(Bottom-Up Dynamic Programming)
int iterativePiecewise(int n) {
    if (n <= 2) {
        return n;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    return dp[n];
}



/*
Advantages of Iterative Approach:
-- Additional memory overhead is required here
--Computes values interatively and is efficient thereby avoiding function call overhead 

Disadvantages of Iterative Approach:
--It may not be as inherent as the recursive approach.
--An array of size "n+1" is required to store intermediate values.
*/



int main() { //main() the entry point of this C program
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Method 1: Recursive\n");
    printf("F(%d) = %d\n\n", n, recursivePiecewise(n));

    for (int i = 0; i < 50; i++) memo[i] = -1;
    printf("Method 2: Memoization\n");
    printf("F(%d) = %d\n\n", n, memoizedPiecewise(n));

    printf("Method 3: Iterative\n");
    printf("F(%d) = %d\n", n, iterativePiecewise(n));

    return 0;
}
