#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int lcs_rec(string str_x, string str_y, int i, int j);

int main(int argc, char **argv){
	//DECLARING VARIBLES FOR PROGRAM
	string linex;	//declare variable that holds string value from filex
	string liney;	//declare variable that holds string value from filey
	//ti holds the start time of the algorithm	
	high_resolution_clock::time_point ti;
	//tf holds the finish time of the algorithm
	high_resolution_clock::time_point tf;
	//duration holds tf-ti, which is the elapsed time between ti and tf
	auto duration = 0;

	//READ IN INPUTS FROM FILES
	ifstream filex(argv[1]);
	ifstream filey(argv[2]);
	filex >> linex;	//set variable linex to string in filex
	filey >> liney;	//set variable liney to string in filey
	filex.close();
	filey.close();

	//CREATE AND OPEN STREAM TO WRITE TO FILE
	ofstream outfile;
	outfile.open(argv[3]);
	
	//holds length of x string, used for index i
	int lenX = linex.length();	
	//holds length of y string, used for index j
	int lenY = liney.length();

	//CALLING FUNCTION, CALCULATING RUNTIME, AND WRITING DATA TO FILE
	ti = high_resolution_clock::now();
	int lcs_val = lcs_rec(linex, liney, lenX, lenY);
	tf = high_resolution_clock::now();
	duration = duration_cast<microseconds>(tf-ti).count();	
	outfile << lcs_val << '\n' << duration << " microseconds" << endl;
	outfile.close();
	return 0;
}
/**
Function lcs_rec recursivly finds the length of the longest common string given two input strings and two indices. First it checks the basecase, where if eiter index is equal to 0 it returns 0 and goes back up the recursive tree. If i,j > 0, the function checks if the strings X and Y are equal by comparing charecters when X is at index i and Y is at index j. Otherwise, the function recursively calls itself, and returns the maximum value of either subtree.
@param	str_x is a string which represents the X string
@param	str_y is a string which represents the Y string
@param	i is an integer which holds the index in the X string. It is initialized to the size of the X string and decremented as the function calls itself.
@param	j is an integer which holds the index in the Y string. It is initialized to the size of the Y string and decremented as the function calls itself 
@return basecase return 0
	if string X == string Y at index i and j respectively, return 1 + a recursive call with i and j decremented by 1
	otherwise return the max of a recursive call with only i decremented and a recursive call with only j decremented.
*/
int lcs_rec(string str_x, string str_y, int i, int j){
	if (i == 0 || j == 0){
	  	return 0;
	}
	else if (str_x[i-1] == str_y[j-1]){
	  return 1 + lcs_rec(str_x, str_y, i-1, j-1);
	}
	else{
	  return max(lcs_rec(str_x, str_y, i-1, j), lcs_rec(str_x, str_y, i, j-1));
	}
}
