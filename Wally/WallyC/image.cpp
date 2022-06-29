#include "stdafx.h"
#include "image.h"

using namespace std;

image::image(int sizeR, int sizeC, double* val)
{
	_M = sizeR; //row size
	_N = sizeC; // column size
	_data = val; // copy pointer of array
	_data = new double[_M*_N]; 

	for (int i = 0; i <_M*_N; i++)
	{
		_data[i] = val[i]; //copies original image to new matrix to be processed and printed
	}
}

image::image(const image &c) //copy constructor for image class
{
	_M = c._M;
	_N = c._N;
	_data = new double[_M*_N]; // pointer to array of same size as original object
	
	for (int i = 0; i <_M*_N; i++)
	{
		_data[i] = c._data[i]; //copies data to new object
	}
	
	cout << "copy created" << endl;
}

void image::operator=(const image& c)
{
	_M = c._M;
	_N = c._N;
	_data = new double[_M*_N]; // pointer to array of same size as original object

	for (int i = 0; i <_M*_N; i++)
	{
		_data[i] = c._data[i]; //copies data to new object
	}

	cout << "copy created" << endl;
}

image::~image()
{
	delete[] _data; // delete pointer to _data for object
}
