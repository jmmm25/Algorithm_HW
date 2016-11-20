//2014057938_김정민(Kimjeongmin)_508

#include<stdio.h>

#define MAX_BUFFER  1001
#define TRUE 1
#define FALSE 0

int number[MAX_BUFFER];
int check[MAX_BUFFER]={0,};
int arr[MAX_BUFFER][MAX_BUFFER]={0,};

void DFS(int index, int eachVerNum, int vertexCnt);

int main(void)
{
    int x=0,y=0,vertexCnt=0;
    scanf("%d",&vertexCnt);
    int i=0,cnt=0,eachVerNum=0;
    //cnt is the number of Connected Component.
    //eachVerNum is the component number of each vertex.

    /*
    for (i = 1; i <= vertexCnt; i++) {
        if (2 != scanf("%d %d", &x, &y))
            break;
        else
            arr[x][y] = arr[y][x] = TRUE;
    }
    */
    while(2 == scanf("%d %d", &x,&y)){
        arr[x][y] = arr[y][x] = TRUE;
    }

    for (i = 1; i <= vertexCnt; i++) {
        if (check[i] == TRUE)
            continue;
        else
            DFS(i, ++eachVerNum, vertexCnt);
            cnt++;
    }
    printf("%d\n", cnt);
    
    for (i = 1; i <= vertexCnt; i++) {
        printf("%d\n", number[i]);
    }

    return 0;
       
}

//DFS is recursive function.
void DFS(int index, int eachVerNum, int vertexCnt)
{
    int i;
    if(check[index] == TRUE)
        return;
    number[index] = eachVerNum;
    check[index] = TRUE;

    for (i = 1; i <= vertexCnt; i++) {
       if(arr[index][i] == TRUE && check[i] == FALSE)
           DFS(i,eachVerNum,vertexCnt);
    }

}










