//2014057938_kimjeongmin_508

#define MAX_BUFFER  100000

#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
  int arr1[MAX_BUFFER]={0};
  int arr2[MAX_BUFFER]={0};

  int n,m;
  int i=0,j=0,cnt=0;
  scanf("%d %d", &n, &m);

  int origin1[n];
  int origin2[m];
  for(i=0 ; i<n ; i++)
  {
    scanf("%d",&arr1[i]);

    // scanf("%d",&origin1[i]);
    // arr1[origin1[i]] = 1;
  }
  for(i=0 ; i<m ; i++)
  {
    scanf("%d",&arr2[i]);
    // scanf("%d",&origin2[i]);
    // arr2[origin2[i]] = 1;
  }

/*  for(j =0;j < MAX_BUFFER ; j++)

    if(arr1[j] == 1 && arr2[j]==1)
    {
      cnt += 1;
    }
  }*/
 int aa;
  sort(arr1,arr1+n);
  for(int i=0; i<m; i++){
    aa=  binary_search(arr1,arr1+n,arr2[i]);
    if(aa==1)
      cnt++;
  }

  printf("%d",cnt);

  return 0;

}
