#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "input.h"
#include "Sub.h"
#include "sort.h"

int main(){
	printf("Input numb of elems: ");
	int c1, c2;
	if(1 == getUIntNumb(&c1)){
		printf("End");
		return 0;
	}
	
	printf("Input numb of arrs: ");
	if(1 == getUIntNumb(&c2)){
		printf("End");
		return 0;
	}
	
	int type;
	printf("Input type of sort(1 - bubble, 2 - shell, 3 - qsort): ");
	int c = getUIntNumb(&type);
	if(1 == c){
		printf("End");
		return 0;
	}
	else{
		while(type != 1 && type != 2 && type != 3){
			printf("Wrong, try again: ");
			c = getUIntNumb(&type);
			if(1 == c){
				printf("End");
				return 0;
			}
		}
	}
	
	int field;
	printf("Input field of sort(1, 2, 3): ");
	c = getUIntNumb(&field);
	if(1 == c){
		printf("End");
		return 0;
	}
	else{
		while(field != 1 && field != 2 && field != 3){
			printf("Wrong, try again: ");
			c = getUIntNumb(&field);
			if(1 == c){
				printf("End");
				return 0;
			}
		}
	}
	
	int way;
	printf("Input way of sort(1, 2): ");
	c = getUIntNumb(&way);
	if(1 == c){
		printf("End");
		return 0;
	}
	else{
		while(way != 1 && way != 2){
			printf("Wrong, try again: ");
			c = getUIntNumb(&way);
			if(1 == c){
				printf("End");
				return 0;
			}
		}
	}

	srand(time(NULL));
	
	for (int i = 0; i < c2; i++){
		Sub* arr = malloc(c1*sizeof(Sub));
		for (int i = 0; i < c1; i++){
			arr[i].fullName = malloc(5);
			for(int j = 0; j < 4; j++){
				arr[i].fullName[j] = rand()%92+32;
			}
			arr[i].fullName[4] = '\0';
			arr[i].number[0] = '+';
			for (int j = 1; j < 16; j++){
				arr[i].number[j] = 48 + rand()%10;
			}
			arr[i].number[16] = '\0';
			arr[i].numb = rand()%86400;
		}
		clock_t t_1, t_2;
		double t;
		if(type == 1){
			if(field == 1){
				if(way == 1){
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))cmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))rCmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else if(field == 2){
				if(way == 1){
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))cmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))rCmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else{
				if(way == 1){
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))cmpNumb);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))rCmpNumb);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
		}
		else if(type == 2){
			if(field == 1){
				if(way == 1){
					t_1 = clock();
					shellSort(arr, c1, (int(*)(const void*,const void*))cmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					shellSort(arr, c1, (int(*)(const void*,const void*))rCmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else if(field == 2){
				if(way == 1){
					t_1 = clock();
					shellSort(arr, c1, (int(*)(const void*,const void*))cmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					shellSort(arr, c1, (int(*)(const void*,const void*))rCmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else{
				if(way == 1){
					t_1 = clock();
					shellSort(arr, c1, (int(*)(const void*,const void*))cmpNumb);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					bubbleSort(arr, c1, (int(*)(const void*,const void*))rCmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
		}
		else{
			if(field == 1){
				if(way == 1){
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))cmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))rCmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else if(field == 2){
				if(way == 1){
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))cmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))rCmpFullName);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
			else{
				if(way == 1){
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))cmpNumb);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
				else{
					t_1 = clock();
					qsort(arr, c1, sizeof(Sub), (int(*)(const void*,const void*))rCmpNumber);
					t_2 = clock();
					t = (double)(t_2-t_1)*1000.0/CLOCKS_PER_SEC;
					printf("%.11lf\n", t);
				}
			}
		}

		for(int i = 0; i < c1; i++){
			free(arr[i].fullName);
		}
			
		free(arr);
	}

	return 0;
}
