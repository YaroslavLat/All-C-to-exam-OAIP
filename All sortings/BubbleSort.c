#include<stdio.h>


void Vivod(int size, int* arr)
{
	for (int i = 0; i < size; i++)
	{
		printf("Element[%d] = %d\n", (i + 1), arr[i]);
	}
}


int main()
{
	int arr[10] = { -3,0,32,5,-10,2,7,8,11,-2 };

	int sizeArr = sizeof(arr) / sizeof(arr[0]); // НАйти ращмер массива. Больше для дим массивов

	//Vivod(sizeArr, arr);

	for (int i = 0; i < sizeArr - 1; i++)
	{
		for (int j = 0; j < sizeArr - i -1; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	Vivod(sizeArr, arr);

	return 0;
}
