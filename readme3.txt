STEPS TO COMPILE AND RUN PROGRAM 3:
1-cd into folder with source code files
2-enter "make program3" into command line prompt
**entering "make" will build executables for program1, program2, and program3**
3-enter into prompt $./program3 <filex.txt> <filey.txt> <output3.txt>

TO DELETE OBJECT FILES AND EXECUTABLES:
enter "make clean" into command line prompt

DATA STRUCTURE:
Used a 2D integer vector to hold data from <vector> class. It is implemented as a global varible.

ANALYSIS OF COMPUTATION TIME:
Runtime is 2^i or 2^j depending on which ever varible (i or j) is smaller. Varible i represents the length of the X string and varible j represents the length of the Y string. These varibles are passed through the recursive function until the basecase is satisfied, at which point the function terminates and returns.

CLASSES USED:
fstream -- used for inputting string from files and outputting information such as matrix, runtime, LCS string, and LCS size to output file.
string -- C++ type used to hold input strings, and used length() function to calculate size of string varibles.
algorithm -- used to max() to find maximum values of different slots in matrix.
vector -- used as for creating and initalizing the main data structure used. Also used the resize() function to change the size of the vector in the function init_table().
chrono -- used for timing algorithm and formulating runtime analysis.
