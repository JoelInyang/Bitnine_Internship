Piecewise Recurrence Relation Implementation in C
=================================================

This repository contains C code for implementing a piecewise recurrence relation F(n) = F(n-3) + F(n-2), where F(0) = 0, F(1) = 1, and F(2) = 2.

Development Environment:
------------------------
The code provided in this repository has been developed and tested using the following environment:

- Operating System: Windows OS
- Compiler: gcc
- Development Environment: VSCODE

How to Compile:
----------------
Follow these steps to compile the source code:

1. Open a terminal or command prompt.
2. Navigate to the directory containing the source code files.

   ```bash
   cd path/to/source/code

Compile the code using the chosen compiler:
gcc -o piecewise piecewise.c


How To Run:
1 ./piecewise
2 The program will prompt you to enter a value for 'n', which represents the term for which you want to calculate the result of the recurrence relation

3. After entering the value of 'n', the program will display the result of F(n) according to the recurrence relation
