#include <stdio.h>
void ssort(int *secondarr, int remain);

int main(void)
{
	int arr[100]; 
	int num = 0;
  int i,n;
   
	while (1) {
		scanf("%d", &n);
		if (n == -1) 
			break;
		arr[num] = n;
		num++;
	}
    
	 for (i=0;i<num;i++) 
		 ssort(arr+i,num-i);
	 
  	for (i = 0;i<num; i++) {
    printf("%d ",arr[i]);
	}
	return 0;
}


void ssort(int *secondarr, int remain) 
{
 	int i, min, min_idx, temp; 
  min=secondarr[0];
	min_idx=0;
     for(i = 1 ; i < remain ; i ++) {
                if(secondarr[i] < min) {
                    min = secondarr[i];
					min_idx = i;
				}
    }
	temp=secondarr[0];
	secondarr[0]=min;
	secondarr[min_idx]=temp;
}