#include <stdio.h>
#include <string.h>
#include "Sub.h"

int cmpNumber(const Sub* s1, const Sub* s2){
	return strcmp(s1->number, s2->number);
}

int rCmpNumber(const Sub* s1, const Sub* s2)
{
	return -strcmp(s1->number, s2->number);
}

int cmpFullName(const Sub* s1, const Sub* s2)
{
	return strcmp(s1->fullName, s2->fullName);
}

int rCmpFullName(const Sub* s1, const Sub* s2)
{
	return -strcmp(s1->fullName, s2->fullName);
}

int cmpNumb(const Sub* s1, const Sub* s2)
{
	return s1->numb < s2->numb;
}

int rCmpNumb(const Sub* s1, const Sub* s2)
{
	return -(s1->numb < s2->numb);
}

void writeCar(const Sub* s, FILE* out)
{
	fprintf(out, "%s\n", s->number);
	fprintf(out, "%s\n", s->fullName);
	fprintf(out, "%d\n", s->numb);
}
