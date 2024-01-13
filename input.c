#include "input.h"
#include <stdio.h>

int getUIntNumb(int* n){
	if (getIntType(n) == 1){
		return 1;
	}
	while ( (*n) <= 0){
		printf("Wrong input, please, try again: ");
		scanf("%*[^\n]");
		getUIntNumb(n);
	}
	return 0;
}

int getIntType(int* numb){
	int c = scanf("%d", numb);
	while (c != EOF){
		if (c != 1){
			printf("Wrong input, please, try again: ");
			scanf("%*[^\n]");
			c = scanf("%d", numb);
		}
		else{
			return 0;
		}
	}
	return 1;
}
