//2014057938_Kimjeongmin(김정민)_508

#include<stdio.h>
#include<string.h>

#define MAX_BUFFER 500

int max(int a,int b)
{ 
    if(a>b) 
        return a; 
    else 
        return b; 
}

int BackTracking(int leng1, int leng2);

int compVal[MAX_BUFFER][MAX_BUFFER]={0,};
int arrowVal[MAX_BUFFER][MAX_BUFFER]={0,};
char input1[MAX_BUFFER],input2[MAX_BUFFER],output[MAX_BUFFER];

int main(void)
{
 
    int i,j,cnt;
    int leng1,leng2;

    gets(input1);
    gets(input2);

    leng1 = strlen(input1);
    leng2 = strlen(input2);
    

    for (i = 0; i < MAX_BUFFER; i++) {
        compVal[0][i] = 0;
        compVal[i][0] = 0;
    }

    for (i = 1; i < leng2+1; i++)
    {
        for (j = 1; j < leng1+1; j++)
        {
            /*
            if (i==0||j==0) 
            {
                compVal[i][j] = 0;
            }
            */
            if (i>0 && j>0 && input2[i-1] == input1[j-1]) 
            {
                compVal[i][j] = compVal[i-1][j-1] + 1; 
              
                if (arrowVal[i][j-1] == 3) 
                {
                    arrowVal[i][j] = 1; //diagonal arrow value is 3
                }
                else
                    arrowVal[i][j] = 3;
            }

            else if (i>0 && j>0 && input2[i-1] != input1[j-1]) 
            {
                if(compVal[i][j-1] <= compVal[i-1][j])
                {
                    compVal[i][j] = compVal[i-1][j];
                    arrowVal[i][j] = 2; //top arrow value is 2
                }
                
                else
                {
                    compVal[i][j] = compVal[i][j-1];
                    arrowVal[i][j] = 1;
                }
                //compVal[i][j] = max(compVal[i][j-1],compVal[i-1][j]);
            }
        }
    }

/*
    for (i = 0; i < leng2+1; i++) {
        for (j = 0; j < leng1+1; j++) {
            printf("%d  ",compVal[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");


    for (i = 0; i < leng2+1; i++) {
        for (j = 0; j < leng1+1; j++) {
            printf("%d  ",arrowVal[i][j]);
        }
        printf("\n");
    }
*/ 

    cnt = BackTracking(leng1,leng2);

    for (i = cnt; i >= 0; i--) {
        printf("%c",output[i]);
    }

    return 0;
}



int BackTracking(int leng1, int leng2)
{
     int k=0;
     int cnt=0;
     while(leng2 != 0 && leng1 != 0)
     {
        if(arrowVal[leng2][leng1] == 1)
        {
            leng1--;
        }

        else if( arrowVal[leng2][leng1] == 2)
        {
            leng2--;
        }
        
        else
        {
            output[k++] = input1[leng1-1];
            leng1--;
            leng2--;
            cnt++;
        }

     }
    
     return cnt;
}

