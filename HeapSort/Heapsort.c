//2014057938_Kimjeongmin(김정민)_508

#define MAX_BUFFER 100000

#include<stdio.h>

void swap(int array[], int a, int b);
void Heap_Sort(int array[], int heap_size, int printNumber);
void Build_Maxheap(int array[], int heap_size);
void MaxHeapify(int array[], int parent, int heap_size);

int main()
{
		int array[MAX_BUFFER]={0,};
		int a=0,b=0,i=1;
		int heap_size, printNumber;

		scanf("%d %d", &heap_size, &printNumber);
		
		

		for (i = 1; i < heap_size+1; i++)
		{
				scanf("%d", &array[i]);
		}

		Heap_Sort(array,heap_size,printNumber);

		for(i=heap_size ; i>=heap_size-printNumber+1 ; i--)
		{
				printf("%d ",array[i]);
		}
		printf("\n");

		for(i=1 ; i<heap_size-printNumber+1 ; i++)
		{
				printf("%d ", array[i]);
		}
		
		printf("\n");

		return 0;
}


void swap(int array[], int a, int b)
{
		int temp;

		temp = array[a];
		array[a] = array[b];
		array[b] = temp;

}

void Heap_Sort(int array[], int heap_size, int printNumber)
{
		Build_Maxheap(array,heap_size);
		int last_number;
		int count = 0;
		
		for(last_number = heap_size ; last_number > 0 ; last_number--)
		{
				if(count == printNumber)
						return;

				swap(array,1,last_number);
				heap_size--;
				count++;
				MaxHeapify(array, 1 ,heap_size);

		}


}


void Build_Maxheap(int array[], int heap_size)
{
		int length, parent,i;
		length = heap_size;

		for(parent = length/2 ; parent>0 ; parent--)
		{
				MaxHeapify(array, parent ,heap_size);
		}

}

void MaxHeapify(int array[], int parent, int heap_size)
{
		int left,right,largest;
		left = 2*parent;
		right = 2*parent+1;

		if(left <= heap_size && array[left] > array[parent])
		{
				largest = left;
		}
		else
		{
				largest = parent;
		}

		if(right<=heap_size && array[right] > array[largest])
		{
				largest=right;
		}

		if(largest != parent)
		{
				swap(array,parent,largest);
				MaxHeapify(array, largest, heap_size);
		}


}

