#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h" 

struct array {
	int * values;
	int capacity;
	int growthFactor;
	int size;
}; 

int Array_Size(Array * array){
	return array->size;
}

void Array_Add(Array * array, int value){
	if(array->size == array->capacity){
		Array_Resize(array);
	}
	*(array->values+array->size) = value;
	array->size += 1;
}

void Array_Resize(Array * array){
	int newCapacity = array->capacity*array->growthFactor;
	int * newValues = (int *) malloc(sizeof(int) * newCapacity);
	int i;
	for(i = 0; i < array->capacity; i++){
		*(newValues + i) = *(array->values + i);
	}
	free(array->values);
	array->values = newValues;
	array->capacity = newCapacity;
	
}


Array * Array_Create(int capacity, int growthFactor){
	Array * array = (Array *) malloc(sizeof(Array));
	array->values = (int *) malloc(sizeof(int) * capacity);
	array->size = 0;
	array->capacity = capacity;
	array->growthFactor = growthFactor;
	return array;
}


void Array_Destroy(Array * array){
	free(array->values);
	free(array);
}


void Array_Print(Array * array){
	printf("Size = %d\n", Array_Size(array));
	int i;
	for(i = 0; i < array->capacity; i++){
		if(i < array->size){
			int value = *(array->values + i);
			printf("%d ", value);
		}
		else{
			printf("X ");
		}
	}
	printf("\n");
}

