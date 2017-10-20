STEPS TO COMPILE AND RUN PROGRAM 1:
1-cd into folder with source code files
2-enter "make program1" into command line prompt
**entering "make" will build executables for program1, program2, and program3**
3-enter into prompt $./program1 <filex.txt> <filey.txt> <output.txt>

TO DELETE OBJECT FILES AND EXECUTABLES:
enter "make clean" into command line prompt

DATA STRUCTURE:
Used 2D integer array to implement LCS matrix to store the longest common string length at that index. 
Used 2D boolean array to signal whether their was a matching letter between string X and Y. The position of the boolean value corresonds to the indices of the matching letters, where the i value corresponds to the letter index in the X string and the j value corresponds to the index in the Y string.

ANALYSIS OF COMPUTATION TIME:
Runtime is i*j, where i is the length of the X string and j is the length of the Y string, because the algorithm uses a nested for loop of string X and Y to iterate find the LCS.

CLASSES USED:
fstream -- used for inputting string from files and outputting information such as matrix, runtime, LCS string, and LCS size to output file.
string -- C++ type used to hold input strings, and used length() function to calculate size of string varibles.
algorithm -- used to max() to find maximum values of different slots in matrix.
chrono -- used for timing algorithm and formulating runtime analysis.
