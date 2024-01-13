#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "input.h"
#include "Sub.h"
#include "sort.h"

char* freadline(FILE* f){
	char *ptr = (char*)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = fscanf(f, "%80[^\n]", buf);
		if(n < 0){
			free(ptr);
			ptr = NULL;
			continue;
		}
		if(n == 0)
			fscanf(f, "%*c");
		else{
			len += strlen(buf);
			ptr = (char*) realloc(ptr, len+1);
			strcat(ptr, buf);
		}

	}while(n > 0);
	return ptr;
}

char* readline(char *in){
	printf("%s", in);
	char* ptr = (char*) malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]", buf);
		if (n < 0){
			free(ptr);
			ptr = NULL;
			continue;
		}

		if (n == 0){
			scanf("%*c");
		}
		else{
			len += strlen(buf);
			ptr = (char*) realloc(ptr, len+1);
			ptr = strcat(ptr, buf);
		}
	}while (n > 0);
	return ptr;
}

Sub* getArr(int inp, int size, int* realSize){
	if(inp == 1){
		Sub *arr = malloc(sizeof(Sub) * size);
		char *s1, *s2;
		int c;
		for(int i = 0; i < size; i++){
			s1 = readline("Input full name: ");
			s2 = readline("Input number: ");
			int flag = 1;
			for(int i = 1; i < strlen(s2); i++){
				if(s2[i] < '0' || s2[i] > '9'){
					flag = 0;
					break;
				}
			}
			while(strlen(s2) > 16 || s2[0] != '+' || !flag){
				printf("Try again: ");
				s2 = readline("");
				flag = 1;
				for(int i = 0; i < strlen(s2); i++){
					if(s2[i] < '0' || s2[i] > '9'){
						flag = 0;
						break;
					}
				}
			}
			
			printf("Input tyme: ");
			int k = getUIntNumb(&c);
			if(1 == k){
				printf("End");
				return NULL;
			}
			else{
				while(c >= 86400){
					printf("Wrong, try again: ");
					c = getUIntNumb(&c);
					if(1 == k){
						printf("End");
						return NULL;
					}
				}
			}
			scanf("%*c");
			
			arr[i].fullName = (char*)malloc(strlen(s1)+1);
			strcpy(arr[i].fullName, s1);
			strcpy(arr[i].number, s2);
			arr[i].numb = c;
			free(s1);
			free(s2);
		}
		*realSize = size;
		return arr;
	}
	else if(inp == 2){
		char* name = readline("Enter filename: ");
		int n = 0;
		Sub *arr = NULL;
		FILE *f1 = fopen(name, "r");
		if(f1 == NULL){
			printf("Bad file");
			return NULL;
		}
		char *s1, *s2;
		int j = 0;
		while(j < size){
			s1 = freadline(f1);
			s2 = freadline(f1);
			int c;
			int k = fscanf(f1, "%d", &c);
			if(k == 1 && strlen(s2) <= 16 && s2[0] == '+' && c >= 0 && c < 86400){
				int flag = 1;
				for(int i = 1; i < strlen(s2); i++){
					if(s2[i] < '0' || s2[i] > '9'){
						flag = 0;
						break;
					}
				}
				if(flag){
					arr = realloc(arr, (n+1)*sizeof(Sub));
					arr[n].fullName = (char*)malloc(strlen(s1)+1);
					strcpy(arr[n].fullName, s1);
					strcpy(arr[n].number, s2);
					arr[n].numb = c;
					n++;
					free(s1);
					free(s2);
				}
				else{
					printf("Bad elem of arr. Skiped\n");
				}
			}
			else{
				printf("Bad elem of arr. Skiped\n");
			}
			fgetc(f1);
			j++;
		}
		fclose(f1);
		*realSize = n;
		return arr;
	}
	else{
		char* name = readline("Enter filename: ");
		int n = 0;
		Sub *arr = NULL;
		FILE *f1 = fopen(name, "rb");
		if(f1 == NULL){
			printf("Bad file");
			return NULL;
		}
		char *s1, *s2;
		int j = 0;
		while(j < size){
			int c;
			int len;
			fread(&len, sizeof(len), 1, f1);
			s1 = malloc(len);
			c = fread(s1, sizeof(char), len, f1);
			if(c != len){
				
			}
			fread(&len, sizeof(len), 1, f1);
			s2 = malloc(len);
			c = fread(s1, sizeof(char), len, f1);
			if(len > 16 || c != len){
				
			}
			if(s2[0] != '+'){
				
			}
			int flag = 1;
			for(int i = 1; i < strlen(s2); i++){
				if(s2[i] < '0' || s2[i] > '9'){
					flag = 0;
					break;
				}
			}
			if(!flag){
			
			}
			int k;
			fread(&k, sizeof(int), 1, f1);
			
			if(k < 0 || k >= 86400){
			
			}
			arr = realloc(arr, (n+1)*sizeof(Sub));
			arr[n].fullName = (char*)malloc(strlen(s1)+1);
			strcpy(arr[n].fullName, s1);
			strcpy(arr[n].number, s2);
			arr[n].numb = k;
			free(s1);
			free(s2);
			n++;
			j++;
		}
		fclose(f1);
		*realSize = n;
		return arr;
	}
}

void writeArr(Sub* arr, int size, int inp){
	if(inp == 1){
		for(int i = 0; i < size; i++){
			printf("%s\n%s\n%d\n", arr[i].fullName, arr[i].number, arr[i].numb);
		}
	}
	else if(inp == 2){
		char* name = readline("Enter filename: ");
		FILE *f1 = fopen(name, "a+");
		if(f1 == NULL){
			printf("Bad file");
			return;
		}
		for(int i = 0; i < size; i++){
			fprintf(f1, "%s\n%s\n%d\n", arr[i].fullName, arr[i].number, arr[i].numb);
		}
		fclose(f1);
	}
	else{ 
		char* name = readline("Enter filename: ");
		FILE *f1 = fopen(name, "wb");
		if(f1 == NULL){
			printf("Bad file");
			returnl];
		}
		for(int i = 0; i < size; i++){
			int len = strlen(arr[i].fullName)+1;
			fwrite(&len, sizeof(len), 1, f1);
			fwrite(arr[i].fullName, sizeof(char), len, f1);
			len = strlen(arr[i].number)+1;
			fwrite(&len, sizeof(len), 1, f1);
			fwrite(arr[i].number, sizeof(char), len, f1);
			fwrite(&arr[i].numb, sizeof(len), 1, f1);
		}
		fclose(f1);
	}
}

int main(){	
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
	printf("Input field of sort(1 - number, 2 - full name, 3 - tyme): ");
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
	
	int inp;
	printf("Input type of input (1 - keyboard, 2 - file, 3 - bin file): ");
	c = getUIntNumb(&inp);
	if(1 == c){
		printf("End");
		return 0;
	}
	else{
		while(inp != 1 && inp != 2 && inp != 3){
			printf("Wrong, try again: ");
			c = getUIntNumb(&inp);
			if(1 == c){
				printf("End");
				return 0;
			}
		}
	}
	
	int size;
	printf("Input size: ");
	c = getUIntNumb(&size);
	if(1 == c){
		printf("End");
		return 0;
	}
	
	int realSize;
	scanf("%*c");
	
	Sub* arr = getArr(inp, size, &realSize);
	if(arr == NULL){
		return 0;
	}
	
	if(type == 1){
		if(field == 1){
			if(way == 1){
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))cmpNumber);
			}
			else{
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))rCmpNumber);
			}
		}
		else if(field == 2){
			if(way == 1){
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))cmpFullName);
			}
			else{
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))rCmpFullName);
			}
		}
		else{
			if(way == 1){
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))cmpNumb);
			}
			else{
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))rCmpNumb);
			}
		}
	}
	else if(type == 2){
		if(field == 1){
			if(way == 1){
				shellSort(arr, realSize, (int(*)(const void*,const void*))cmpNumber);
			}
			else{
				shellSort(arr, realSize, (int(*)(const void*,const void*))rCmpNumber);
			}
		}
		else if(field == 2){
			if(way == 1){
				shellSort(arr, realSize, (int(*)(const void*,const void*))cmpFullName);
			}
			else{
				shellSort(arr, realSize, (int(*)(const void*,const void*))rCmpFullName);
			}
		}
		else{
			if(way == 1){
				shellSort(arr, realSize, (int(*)(const void*,const void*))cmpNumb);
			}
			else{
				bubbleSort(arr, realSize, (int(*)(const void*,const void*))rCmpNumber);
			}
		}
	}
	else{
		if(field == 1){
			if(way == 1){
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))cmpNumber);
			}
			else{
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))rCmpNumber);
			}
		}
		else if(field == 2){
			if(way == 1){
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))cmpFullName);
			}
			else{
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))rCmpFullName);
			}
		}
		else{
			if(way == 1){
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))cmpNumb);
			}
			else{
				qsort(arr, realSize, sizeof(Sub), (int(*)(const void*,const void*))rCmpNumber);
			}
		}
	}
	
	writeArr(arr, realSize, inp);
	
	for(int i = 0; i < realSize; i++){
		free(arr[i].fullName);
	}
	free(arr);

	return 0;	
}
