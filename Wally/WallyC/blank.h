#ifndef Glob_H
#define Glob_H

//header file to allow read and write functions 

// Reads .txt file representing an image of R rows and C Columns stored in filename 
double* readTXT(char *fileName, int sizeR, int sizeC);
// Converts a 1D array of doubles of size R*C to .pgm image of R rows and C Columns 
void WritePGM(char *filename, double *data, int sizeR, int sizeC, int Q);

#endif