#include <stdio.h>

//First method: Recursive approach
int recursivePiecewise(int n) { // a recursive function that takes n as a parameter and return an interger
    if (n<=2) { //am saying if n<=2 then return n, because we already have the values defines that is F(0)=0, F(1)=1, F(2) = 2
        return n;
    }
    return recursivePiecewise(n -3) + recursivePiecewise(n-2); // but if any n value is greater than 2, then the recursivePiecewise function is recursively called and performs the calculation based  on [ F(n) = F(n-3) + F(n-2) ]
}

/*
Advantages of recursive approach
-- Much simpler and easier to calculate the output and straight forward to understand.
-- For recursive approach the implementations are clear and uncomplicated as oppose to other methods

Disadvantages of recursive approach
-- There would be exponential time complexity that is as more input is added or increased by 1, it causes the number of operations to double.
-- Overlapping might occur due to large values of n, so the more n increases the more the efficiency of this recursive method reduces.
*/

//Second method: Memoization( Top-Down dynamic programming, it involves storing already calculated data in cache, avoid redundancy and it reads from top - bottom
int memo[50];   //assuming n<=50

int memoizedPiecewise(int n) {  //this is a memoized function that avoids redundancy by check if the value of n is already present/computed in the array above first before creating a new value in the memo array above.
    if (n<=2) { //this checks if n is less than or equal to 2 as we already know/have the values for 0,1 and 2
        return n;
    }
    if (memo[n] != -1){ //this checks if the n value of memo is equal to -1(which means that "no value"), if it is not equal to -1 then there is a value, so i just return n
        return memo[n];
    }
    memo[n] = memoizedPiecewise(n-3) + memoizedPiecewise(n-2); //else then, memoized is called recursively to calculate the value for n
    return memo[n];
}

/*
Advantages of memoization approach:
--Unlike the pure recursive method the time complexity is reduced although still depends on the size of n
--The memo array above stores computed values thereby leading to no redundant calculations.

Disadvantages of memoization approach:
--If there is need for an increase in the array, then additional memory is required
--Function call is still present that is even tho its not recalculating values, process of computing values and returning the stored values still can add up and lead to function call overhead
*/

//Third method : Iterative(Bottom-Up Dynamic programming which ) which just iterate through and uses a for loop as well to get the n value

int iterativePiecewise(int n){ // takes integer n as a parameter and returns an integer value
    if(n<=2) { // since I already have F(0), F(1) and F(2) defined then i just return n
        return n;
    }
    int F[n + 1]; // declares an integer array to store the computed values of F(i) for i ranging from 0 to n.
    F[0] = 0; //base cases of the recurrence are defined already
    F[1] = 1;
    F10[2] = 2;
    for (int i = 3; i <= n; i++) { // a for loop to loop through the values in the array from i =3 till it gets to n
        F[i] = F[i -3] + F[i -2]; // F[i] here calculates the value of F(i) by summing up the previously calculated F(i-3) and F(i-2) from the F array
    }
    return F[n]; // after the loop get to the n value which is the end of the loop then it returns the calculated value of F(n)
    }

/*
Advantages of the iterative approach:
-- This iterative approach computes the values of F(i) in a bottom-up manner, starting from base cases and building up to the vale of F(n). This approach avoids function call bottlenecks where each function call involves additional time and resources, but it rather involves simple arithmetic operations.
-- Time complexity of calculation minimized since it involves simple arithmetic operations.

Disadvantages of the iterative appraoch:
-- It may not be as inherent as the recursive approach, or better said needs more understanding to be able to work with.
-- An array of size "n+1" is required to store values from 0 to n, and this introduces the need for additional memory.

*/
int main() { //the main function is the entry point of all C progarm
    int n; //declaring a variable called n


    printf("Enter the value of n: "); //This accepts the value of n to be calculated from user
    scanf("%d", &n); // storing the input of the user in the n variable declared earlier

    printf("Method 1: Recursive\n");
    printf("F(%d) = %d\n\n", n, recursivePiecewise(n)); //This prints out the value of the n using the recursive approach

    for (int i=0; i<50; i++) memo[i] = -1;  // The 50 here is based on the assumption i made while declaring the memo array in the method.
    printf("Method 2: Memoization\n");
    printf("F(%d) = %d\n\n", n, memoizedPiecewise(n)); //This prints out the value of the n using the  approach

    printf("Method 3: Iterative\n");
    printf("F(d) = %d\n", n, iterativePiecewise(n)); //This prints out the value of the n using the iterative approach

    return 0;
}




