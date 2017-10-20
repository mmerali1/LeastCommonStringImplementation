#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

vector <vector<int>> lcs_table;
int init_table(string str_x, string str_y);
int lcs_table_filler(string str_x, string str_y, int i, int j);

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

	//CALLING FUNCTION, CALCULATING RUNTIME, AND WRITING DATA TO FILE
	ti = high_resolution_clock::now();
	int lcs_val = init_table(linex, liney);
	tf = high_resolution_clock::now();
	duration = duration_cast<microseconds>(tf-ti).count();	
	outfile << lcs_val << '\n' << duration << " microseconds" << endl;
	cout << lcs_table[linex.length()][liney.length()] << endl;
	outfile.close();
	return 0;
}

/**
Function init_table resizes the global 2D vector to the size of string X plus 1 for the rows and the size of string Y plus 1 for the columns. It then calls lcs_table_filler which is a helper function which fills in the table and finds the LCS length.
@param str_x is the X string input
@param str_y is the Y string input
@return returns call to lcs_table_filler which fills the arrays and gets the LCS length which it returns to this function. This function returns that LCS length value back to where it was called
*/
int init_table(string str_x, string str_y){
	lcs_table.resize(str_x.length()+1, vector<int>(str_y.length()+1,-1));
	return lcs_table_filler(str_x, str_y, str_x.length(), str_y.length());
}

/** 
Function lcs_table_filler uses takes in two string inputs and two indicies inputs. It uses the indices to compare the strings at i (for string X) and j (for string Y) and find common values. If found it recursively calls itself with the indices decremented and sets the table at that location to 1 plus the value found at that call. If no common value is found between the strings, it sets tha table at that location to the max of two recursive calls to itself. One call checks the row above it for matching values while the other checks the slot at the column to its right.
@param str_x is the X string input
@param str_y is the Y string input
@param i is the index that traces through the letters of str_x
@param j is the index that traces through the letters of str_y
@return it returns the lcs_table value at index (i,j)
*/
int lcs_table_filler(string str_x, string str_y, int i, int j){
	if (lcs_table[i][j] == -1){
		if (i == 0 || j == 0){
	  		lcs_table[i][j] = 0;
		}
		else if (str_x[i-1] == str_y[j-1]){
	  		lcs_table[i][j] = 1 + lcs_table_filler(str_x, str_y, i-1, j-1);
		}
		else{
	  		lcs_table[i][j] = max(lcs_table_filler(str_x, str_y, i-1, j),
						lcs_table_filler(str_x, str_y, i, j-1));
		}

	}
	return lcs_table[i][j];
}
