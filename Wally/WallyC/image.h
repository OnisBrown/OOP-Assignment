#ifndef image_H
#define image_H


class image // class for image that's read in and will be sent back.
{
protected:
	int _M; // number of rows in image
	int _N; // number of columns in the image
	double* _data;// pointer for the image loaded into array

public:
	image(int sizeR, int sizeC, double* val); //constructor for image class
	void operator=(const image& c);
	image::image(const image& c);//copy constructor for image class
	~image();//deconstructor for image class 
	
};

#endif