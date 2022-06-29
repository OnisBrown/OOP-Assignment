// WallyC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LargeI.h"
#include "matchImage.h"

using namespace std;

int main()
{
	int menu = 0; // bool for the menu switch
	bool quit = false;
	clock_t start = clock();// starts a clock to time execution
	int CM = 768; int CN = 1024; // values for large image size
	int WM = 49; int WN = 36; //image sizes for wally image
	double* input_large = 0; //pointer for array to hold image that's read in
	double* input_wally = 0;
	cout << endl;
	
	char* inputFileName = "images/Cluttered_scene.txt"; // text image is stored in inputfilename
	char* searchFileName = "images/Wally_grey.txt"; //wally image is stored to searchfileName
	input_large = readTXT(inputFileName, CM, CN); //reads file into array and stores array address to input_data
	input_wally = readTXT(searchFileName, WM, WN);
	LargeI input(CM, CN, input_large);// create instance of image class for image read in
	matchImage wally(WM, WN, input_wally); //create instance of image for wally

	clock_t end = clock(); // stores the end time 
	clock_t clockTicksTaken = end - start;
	double rtime = clockTicksTaken / (double)CLOCKS_PER_SEC;
	cout << "ready to perform search, " << rtime << " seconds elapsed" << endl; //prints time taken to read in all images.
	
	
	cout << endl;
	while(quit == false)
	{
		cout << "1. perform search" << endl << "2.quit" << endl << "select option: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			wally >> input; //overloaded operator for comparing search image to large image
			break;
		case 2:
			quit = true;
			break;
		default:			
			throw menu;
		}
	}
	return 0;
}







