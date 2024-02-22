/*
 ============================================================================
 Name        : Chapter_12_Challenge.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description : Challenge 2
               Tasks:
             • Declare 5x5 two-dimensional array rnd_matrix.
             • Initialize it with random integer values in range 0-100.
             • Write function that will find and print minimum and maximum value of rnd_matrix.
             • Declare another 25 element integer array named sorted_arr.
             • Write a function that will fill sorted_arr with sorted values from rnd_matrix.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define R 5
#define C 5

#define ELEMENTS 25

// Declaring a 5x5 two-dimensional array
int rnd_matrix[R][C];

// Declare 25 element integer array
int sorted_arr[ELEMENTS];


// Function to initialize matrix with random integer values in range 0-100
void initializeRandomMatrix(int matrix[][C])
{
	for(int i = 0; i < R; i++ )
	{
		for(int j = 0; j < C; j++)
		{
			matrix[i][j] = rand() % 101;
		}
	}
	printf("Print initialized matrix:\n\n");

	for(int i = 0; i < R; i++ )
	{
		for(int j = 0; j < C; j++)
		{
				printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

}

// Function to find and print the minimum and maximum values of rnd_matrix
void findMinMax(int matrix[][C])
{
	int min = matrix[0][0];
	int max = matrix[0][0];

	for(int i = 0; i < R; i++ )
	{
		for(int j = 0; j < C; j++)
		{
			if(matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
			else if(matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}

	printf("\n");
	printf("Minumim value: %d\n", min);
	printf("Maximum value: %d\n", max);
}

// Function that fills an array from a matrix
void fillSortedArrey(int array[])
{
	// Copy all elements of rnd_matrix to a temporary one-dimensional array
	int temp[R * C];
	int index = 0;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
	    {
			temp[index++] = rnd_matrix[i][j];

	    }
	}

	printf("\nFilled but not sorted array:\n");
	for(int i = 0; i < ELEMENTS; i++)
	{
		printf("%d ", temp[i]);
	}
    printf("\n");

	 // Sort the temporary array
	for (int i = 0; i < R*C - 1; i++)
	    {
	        for (int j = 0; j < R*C - i - 1; j++)
	        {
	        	if(temp[j] > temp[j + 1])
	        	{
	        		int tempVar = temp[j];
	        	    temp[j] = temp[j + 1];
	        	    temp[j + 1] = tempVar;
	        	}
	        }
	    }

	// Copy sorted elements from the temporary array to sorted_arr
	for(int i = 0; i < R * C; i++)
	{
		array[i] = temp[i];
	}

	printf("\nSorted array:\n");
	for(int i = 0; i < ELEMENTS; i++)
	{
		printf("%d ", temp[i]);
	}

}

// Main function
void main(void)
{

	initializeRandomMatrix(rnd_matrix);
	findMinMax(rnd_matrix);
	fillSortedArrey(sorted_arr);
}
