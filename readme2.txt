STEPS TO COMPILE AND RUN PROGRAM 2:
1-cd into folder with source code files
2-enter "make program2" into command line prompt
**entering "make" will build executables for program1, program2, and program3**
3-enter into prompt $./program2 <filex.txt> <filey.txt> <output2.txt>

TO DELETE OBJECT FILES AND EXECUTABLES:
enter "make clean" into command line prompt

DATA STRUCTURE:
Does not use major data structures. Only uses string varibles to hold data from input files.

ANALYSIS OF COMPUTATION TIME:
Runtime is 2^i or 2^j depending on which ever varible (i or j) is smaller. This value represents the number of subproblems solved in the recursive tree to achieve the result. Varible i represents the length of the X string and varible j represents the length of the Y string. These varibles are passed through the recursive function until the basecase is satisfied, at which point the function terminates and returns.
Potentially result in recursive tree of i+j hieght, where each node represents a subproblem.

CLASSES USED:
fstream -- used for inputting string from files and outputting information such as matrix, runtime, LCS string, and LCS size to output file.
string -- C++ type used to hold input strings, and used length() function to calculate size of string varibles.
algorithm -- used to max() to find maximum values of different slots in matrix.
chrono -- used for timing algorithm and formulating runtime analysis.


