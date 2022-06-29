#ifndef matchImage_H
#define matchImage_H

#include "image.h"
#include "LargeI.h"

class matchImage : public image
{
private:
	int count; // counter for iterations of the search
	double walsd; //variable for variance and standard deviation of wally image
	double walmean; // variables to store stats of wally image

public:
	matchImage(int sizeR, int sizeC, double* val);//constructor for matchImage class
	void operator>>(const LargeI& obj); // operator overload for matchimage 
	~matchImage(); // deconstructor for overload
};

#endif