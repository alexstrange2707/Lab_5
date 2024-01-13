#include "sort.h"
#include "Sub.h"

void bubbleSort(Sub *arr, int n, int(*cmp)(const void*, const void*)){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(cmp(arr+j, arr+j+1) > 0){
				Sub tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void shellSort(Sub *arr, int n, int(*cmp)(const void*, const void*)){
	int k;
	for(int i = n/2; i > 0; i /= 2){
		for(int j = i; j < n; j++){
			Sub tmp = arr[j];
			for(k = j; k >= i; k -= i){
				if (cmp(arr+k-i, &tmp) > 0){
					arr[k] = arr[k-i];
				}
				else{
					break;
				}
			}
			arr[k] = tmp;
		}
	}
}
