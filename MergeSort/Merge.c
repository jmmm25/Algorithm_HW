//2014057938_김정민(KimJeongMin)_508

#define MAX_SIZE 100000
#define CALLOC(data,num)	( (data*)calloc(sizeof(data),(num)) )

#include<stdio.h>
#include<stdlib.h>

void merge_sort(int num[],int start, int end,int nsize);
void merge(int num[], int start, int median, int end,int size);
void Print(int* Num,int nsize);


int main(void)
{
    int size =0 ;
    int data;

    scanf("%d",&size);
    
    int *Num = CALLOC(int,size);
    for(int i =0;i<size;i++)
    {
        Num[i]  = 0 ;
    }

    for( int i=0 ; i<size ; i++)
    {
      	scanf("%d",&Num[i]);       
    }
    
    merge_sort(Num, 0, size-1, size);
    Print(Num,size);

    return 0;
}

void merge_sort(int num[],int start, int end,int nsize){
    int median = (start + end)/2;
    if(start < end){
        merge_sort(num, start, median,nsize);		//좌측분할
        merge_sort(num, median+1, end,nsize);		//우측분할
        merge(num, start, median, end,nsize);
    }
}

void merge(int num[], int start, int median, int end,int size){
    int i,j,k,m,n;
    int tempArr[size];
    i = start;
    j = median+1;
    k = start;
    
    while (i <= median && j <= end){
        tempArr[k++] = (num[i] > num [j]) ? num [j++] : num [i++];
      
    }
    
    m = (i > median) ? j : i;
    n = (i > median) ? end : median;
    for (; m<=n; m++){
        tempArr[k++] = num[m];
    }
    
    for (m=start; m<=end; m++){
        num[m] = tempArr[m];
    }
}

void Print(int* Num,int nsize)
{
    for( int i=0 ; i<nsize ; ++i )
    {
            printf( "%d\n", Num[nsize-i-1] );
    }
}
