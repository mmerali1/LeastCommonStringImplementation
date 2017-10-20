#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


void lcs(string str_x, string str_y, ofstream &ofile);

int main(int argc, char **argv){
	//DECLARING VARIABLES FOR PROGRAM
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
	filex >> linex;	//set variable linex
	filey >> liney;	//set variable liney
	filex.close();	
	filey.close();	

	//CREATE AND OPEN STREAM TO WRITE TO FILE
	ofstream outfile;
	outfile.open(argv[3]);
	
	//CALLING FUNCTION, CALCULATING RUNTIME, AND WRITING DATA TO FILE
	ti = high_resolution_clock::now();
	lcs(linex, liney, outfile);
	tf = high_resolution_clock::now();
	duration = duration_cast<microseconds>(tf-ti).count();	
	outfile << duration << " microseconds"<< endl;
	outfile.close();

	return 0;
}

/**
Function lcs creates two 2D matrixs which it uses to track the longest common string and write data, such as the matrix, length of LCS, and LCS string to file. It is implemented using the bottom up dynamic programming approach. It works by traversing through each string X and Y using a nested for loop. If it finds a matching letter, it increments the location in the tabC array by 1 and sets the tabB array to true. It writes the matrix in tabC to file if the string inputs are less than or equal to 10. It will also write the LCS string to file if the strings are less than or equal to ten. If they are greater than 10, it will write the LCS length to file.
@param 	str_x is a string variable which represents the string from file X
@param	str_y is a string varible which represents the string from file Y
@param ofile is a ofstream which is created in main and used to write the matrix, LCS string, and LCS length to file
@return lcs function does not return anything. It only writes to file.
*/ 	
void lcs(string str_x, string str_y, ofstream &ofile){
	int lenX = str_x.length();	//stores length of X string
	int lenY = str_y.length();	//stores length of Y string
	bool tabB[lenX-1][lenY-1];	//holds true if letters match
	int tabC[lenX][lenY];		//LCS table, holds longest common string
	//print_flag holds true if str_x and str_y <=10
	bool print_flag = ((lenX<=10)&&(lenY<=10));
	for (int i=0; i<=lenX; i++){
		for (int j=0; j<=lenY; j++){
			if (i == 0 || j == 0){
				tabC[i][j] = 0;
			}
			else if (str_x[i-1] == str_y[j-1]){
				tabC[i][j] = tabC[i-1][j-1] + 1;
				tabB[i][j] = true;
			}
			else{
				tabC[i][j] = max(tabC[i][j-1], tabC[i-1][j]);
				tabB[i][j] = false;
			}

			if (print_flag) ofile << tabC[i][j] << " ";
		}
		if (print_flag) ofile << endl;
	}
	if (print_flag){
		//str_index holds the index of the length of the LCS
		//i holds the length of the X string minus 1
		//j holds the length of the Y string minus 1
		int str_index = tabC[lenX][lenY], i=lenX-1, j=lenY-1;
		//char array that will hold the final LCS string		
		char lcs_str[str_index+1];
		while (i>0 && j>0){
			if (tabB[i][j] == true){
				lcs_str[str_index-1] = str_x[i];
				i--; j--;
				str_index--;	
			}
			else if(tabC[i][j-1] < tabC[i-1][j]){
				i--;
			}
			else{
				j--;
			}
		
		}
		//Write LCS to file
		ofile << lcs_str << endl;
	}
	else {
		//Write LCS length to file
		ofile << tabC[lenX][lenY] << endl;
	}
}



