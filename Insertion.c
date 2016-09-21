//2014057938_김정민_508
#include <stdio.h>

void insert_Sort(int arr[],int idx);

int main()
{
    int idx=0;
    int i=0;
    
    scanf("%d",&idx);
    
    int arr[30001] = {0,};
    for(i=0; i<idx; i++){
        scanf("%d",&arr[i]);
    }
    insert_Sort(arr, idx);
    
    
    for(i=idx-1 ; i>=0 ; i--)
    {
        printf("%d\n",arr[i]);
    }
    
    
    return 0;
}


void insert_Sort(int arr[],int idx)
{
    int i=0,j=0;
    int temp=0;

    for(i=1; i<idx ; i++)
    {
        temp = arr[i];
        for(j=i ; j>0 ; j--)
        {
            if(arr[j-1] > temp)
            {
                arr[j] = arr[j-1];
                if(j==1)
                {
                    arr[j-1] = temp;
                    break;
                }
            }
            else
            {
                arr[j] = temp;
                break;
            }
        }
    }
}
