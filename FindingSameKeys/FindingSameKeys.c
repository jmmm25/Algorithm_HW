//2014057938_kimjeongmin_508
#define MAX_BUFFER  100001

#include<stdio.h>
int main()
{
	int A[MAX_BUFFER]={0,};
	int B[MAX_BUFFER]={0,};
	int tempA=0,tempB=0;
	int n=0,m=0;
	int i=0,j=0,cnt=0;
	scanf("%d %d", &n, &m);

	int originA[MAX_BUFFER]={0,};
	int originB[MAX_BUFFER]={0,};
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&originA[i]);
		tempA = originA[i];
		A[tempA] = 1;
	}
	for(i=0 ; i<m ; i++)
	{
		scanf("%d",&originB[i]);
		tempB = originB[i];
		B[tempB] = 1;
	}

	for(j =0;j < MAX_BUFFER;j++)
	{
		if(A[j] == 1 && B[j] == 1)
		{
			cnt++;
		}
	}

	printf("%d\n",cnt);

	return 0;

}
