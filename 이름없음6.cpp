#include <stdio.h>
int main(){
	int arr[19][19]={0,};
	int n,i,a,b,j,x,y;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			scanf("%d", &arr[a][b]);
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		for(j=0;j<n;j++){
			if(arr[x-1][j]=1)
			arr[x-1][j]=0;
			else
			arr[x-1][j]=1;
		}
		for(j=0;j<n;j++){
			if(arr[j][y-1]=1)
			arr[j][y-1]=0;
			else
			arr[j][y-1]=1;
			
		}
	}
	
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
