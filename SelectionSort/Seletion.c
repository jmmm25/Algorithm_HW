//2014057938_김정민(KimJeongMin)_508
#include <stdio.h>

void selection_Sort(int arr[], int cnt, int idx);

int main()
{
    int i=0,cnt=0,f_num=0;
    int arr[30001] = {0,};
    
    scanf("%d %d",&cnt,&f_num);
    
    for(i=0;i<cnt;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    selection_Sort(arr,cnt,f_num);
    
    
    for(i=0 ; i<cnt; i++)
    {
        printf("%d\n",arr[i]);
    }
        
    
    return 0;
    
}

void selection_Sort(int arr[], int cnt, int idx)
{
    int i,j;
    int min=9019401;
    int temp=0;	//temp is standard number.
    int num=0;
    
    for(i=0 ; i<cnt ; i++)
    {
        if(i==idx)
            break;
        
        temp = arr[i];
        for(j=i+1 ; j<cnt ; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                num = j;
            }
            
        }
        
        if(temp > min)
        {
            arr[num] = arr[i];
            arr[i] = min;
            min = 12312313;
        }
        else		//temp < min
        {
            min = 12313123;
            continue;
        }
        
    }
}
