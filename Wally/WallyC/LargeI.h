#ifndef Large_H
#define Large_H

#include "image.h"
using std::vector; // allows std to be omited from instances of vector class 

class LargeI : public image //class for large image
{

	public:
		double compare(int pos, double walmean, double walsd, double const *img, int M, int N) const; // computes NC values for selection and search image
		void print( int M, int N) const;
		void boxing(int pos, int _M, int _N) const;
		LargeI(int sizeR, int sizeC, double* val); // constructor for LargeI class
		~LargeI(); // deconstructor for largeI class
		int getM() const { return _M; }; // getter for m value
		int getN() const { return _N; }; // getter for n value
};

#endif