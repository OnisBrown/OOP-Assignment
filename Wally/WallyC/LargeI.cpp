#include "stdafx.h"
#include "LargeI.h"
#include <cstdlib> // library for additional features like abs

using namespace std;

LargeI::LargeI(int sizeR, int sizeC, double* val):image(sizeR, sizeC, val)
{
	cout << "large image ready for processing....." << endl;
}

double LargeI::compare(int pos, double walmean, double walsd, double const *img, int M, int N) const //function for computing NC values
{
	double score = 0; // holds the nc value
	double* cut = new double[M*N]; //array to hold selection of the large image
	double csd = 0;
	double cmean = 0; // variables for the selections mean and standard deviation
	double top = 0;
	double bottom = 0;
	int size = M*N;

	for (int i = 0; i < M; i++) // increments through columns
	{
		for (int j = 0; j < N; j++) // increments through a row
		{
			cut[j + (i*N)] = _data[pos + j + (i*_N)]; // copy a section of the large image into a vector using a for loop
		}
	}

	for (int i = 0; i < size; i++) //gets sum of cut pixel values for the mean
	{
		cmean += cut[i];
	}
	cmean /= size; // mean = total / number of pixels

	for (int i = 0; i < size; i++)
	{
		csd += (cut[i] - cmean)*(cut[i] - cmean); //getting variance for selection
	}

	bottom = sqrt(csd*walsd); // square rooting the product of the two variances to get the denominator

	for (int i = 0; i < size; i++)
	{
		top += (img[i] - walmean)*(cut[i] - cmean); // prepares the numerator
	}

	score = top / bottom;

	delete[] cut; // delete the array for the next call
	return score; // return the NC value
}

void LargeI::print( int M, int N) const
{
	// writes data back to .pgm file stored in outputFileName
	char* outputFileName = "solved/solved_scene.pgm";

	// Use Q = 255 for greyscale images and 1 for binary images.
	int Q = 255;
	WritePGM(outputFileName, _data, _M, _N, Q);
}

void LargeI::boxing(int pos, int M, int N) const // turns a series of pixels black
{
	for (int i = 0; i < N; i++)
	{
		_data[pos + i] = 0;
		_data[pos + i + _N*M] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		_data[pos + (i*_N)] = 0;
		_data[pos + (i*_N)+ N] = 0;
	}
		
	print(M, N);
}

LargeI::~LargeI()
{
	cout << "large image being freed" << endl;
}
