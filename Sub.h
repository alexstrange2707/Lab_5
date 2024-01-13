#ifndef SUB_H
#define SUB_H

#include <stdio.h>

typedef struct Sub{
	char number[17];
	char* fullName;
	int numb;
} Sub;

int cmpNumber(const Sub* s1, const Sub* s2);
int rCmpNumber(const Sub* s1, const Sub* s2);
int cmpFullName(const Sub* s1, const Sub* s2);
int rCmpFullName(const Sub* s1, const Sub* s2);
int cmpNumb(const Sub* s1, const Sub* s2);
int rCmpNumb(const Sub* s1, const Sub* s2);
void writeCar(const Sub* s, FILE* out);

#endif
