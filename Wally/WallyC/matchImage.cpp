#include "stdafx.h"
#include "matchImage.h"

using namespace std;

matchImage::matchImage(int sizeR, int sizeC, double* val):image( sizeR, sizeC, val)
{
	
	for (int i = 0; i < _N*_M; i++)// for loop to calculate mean pixel value for wally image
	{
			walmean += _data[i]; // provides total of wally pixel values.
	}

	walmean /= _N*_M; // calculate mean

	for (int j = 0; j < _N*_M; j++) // calculates the variance of wally image
	{
		walsd += (_data[j] - walmean)*(_data[j] - walmean);
	}
	
	cout << "search image ready for comparisons...." << endl;
}

 void matchImage::operator>>(const LargeI& obj)
{
	 clock_t clockTicksTaken;// clock object for total clock ticks
	 clock_t start; // clock object for timer start
	 clock_t end; //clock object for end time
	 double rtime = 0; // holds time in seconds 
	int vert = obj.getM(); 
	int hori = obj.getN();
	//^^ fetches the row and column size of large image^^//
	//vv sets the limits for starting position of a comparison vv//
	int limitHori = hori - _N;
	int limitVert = vert - _M;

	int menu = 0;// menu options 
	int pos = 0;//starting position when comparison function is called
	int Hpos; // holds the position of highest match in plain format
	string coords[10]; // array matching coords to scores
	double score[10]; // array of top 10 NC scores
	double temp = 0; // temp value to hold NC score after comparison call
	count = 0; // counter for each comparison call
	cout << "please select how you would the comparison to progress horizontally"<< endl << "1. move selection one pixel at a time" << endl << "2. move selection by half the reference image size" << endl << "3. move selection by the full size of reference image" << endl << "4. go back to main menu"<< endl << "select option: ";
	cin >> menu;
	cout << endl;
	switch (menu) 
	{
	case 1: // case for the slowest but most effective way to
		start = clock();// starts a clock to time execution
		for (int i = 0; i < limitVert; i = i++)
		{
			for (int j = 0; j < limitHori; j = j++)
			{
				count++;
				pos = j + (i*hori);
				temp = obj.compare(pos, walmean, walsd, _data, _M, _N);

				if (score[0] < temp)
				{
					Hpos = pos; // moves pos of highest match to Hpos
				}

				for (int k = 0; k < 10; k++)
				{
					if (score[k] < temp)
					{
						score[k] = temp; // score becomes temp at k point in array
						coords[k] = to_string(j) + ", " + to_string(i); // writes coords to an array
						break;
					}	
				}
					
			}
		}
		break;

	case 2:// case for moderate sized traversal
		start = clock();// starts a clock to time execution
		for (int i = 0; i < limitVert; i = i++)
		{
			for (int j = 0; j < limitHori/(_N/2); j = j++)
			{
				count++;
				pos = j*(_N/2) + (i*hori);
				temp = obj.compare(pos, walmean, walsd, _data, _M, _N);

				if (score[0] < temp)
				{
					Hpos = pos; // moves pos of highest match to Hpos
				}

				for (int k = 0; k < 10; k++)
				{
					if (score[k] < temp)
					{
						score[k] = temp;
						coords[k] = to_string(j*(_N/2)) + ", " + to_string(i);
						break;
					}
				}

			}
		}
		break;

	case 3: //case for largest selection traversal
		start = clock();// starts a clock to time execution
		for (int i = 0; i < limitVert; i = i++)
		{
			for (int j = 0; j < limitHori/_N; j = j++)
			{
				count++;
				pos = j*_N + (i*hori);
				temp = obj.compare(pos, walmean, walsd, _data, _M, _N);

				if (score[0] < temp)
				{
					Hpos = pos; // moves pos of highest match to Hpos
				}

				for (int k = 0; k < 10; k++)
				{
					if (score[k] < temp)
					{
						score[k] = temp;
						coords[k] = to_string(j*_N) + ", " + to_string(i);
						break;
					}
				}

			}
		}
		break;

	default:
		cout << "invalid input, returning to main menu" << endl;
		break;
	}

	
	end = clock(); // stores the end time 
	clockTicksTaken = end - start;
	rtime = clockTicksTaken / (double)CLOCKS_PER_SEC; // search time
	cout << "search completed, " << rtime << " seconds elapsed. " << count << " comparisons made." << endl;// prints time taken for search
	cout << endl;

	cout << "top 10 results are:" << endl; 
	for (int i = 0; i < 10; i++)
	{
		cout << setw(3) << right << i + 1 << ". " << "position: " << coords[i] << " ||NC value: " << score[i] << endl; // prints table of top 10 results
	}

	cout << endl;

	cout << "would you like to highlight best match and output resulting image?" << endl << "1. just output image as is" << endl << "2.highlight best match then output" << endl <<"3. don't ouput image" << endl;//prints results
	cin >> menu;
	switch (menu) //switch for printing options
	{
	case 1: 
		obj.print( _M, _N); // prints current large image
		break;
	case 2:
		obj.boxing(Hpos, _M, _N); //places box around best match and calls print
		break;
	case 3:
		cout << "returning to main menu" << endl;
		break;
	default:
		cout << "invalid input, returning to main menu" << endl;
		break;
	}
	cout << endl;
}

matchImage::~matchImage()
{
	cout << "freeing search image" << endl;
}
