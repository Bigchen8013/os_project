#include <stdio.h>
void bubbleSort(int bt[],int n)
{
  	for(int i=0;i<n;i++)
  		for(int j=0;j<n-i-1;j++)
  		{
  			if(bt[j]>bt[j+1])
  			{
  				int temp=bt[j];
  				bt[j]=bt[j+1];
  				bt[j+1]=temp;
  			}
  		}
}
void waitingTime(int n, int bt[], int wt[]){
	wt[0] = 0;
	for(int i=1;i<n;i++){
		wt[i] = bt[i-1] + wt[i-1];
	}
}
void turnAroundTime(int n, int bt[], int wt[], int tat[]){
	for(int i=0;i<n;i++){
		tat[i] = bt[i] + wt[i];
	}
}
void findTime(int n,int bt[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	waitingTime(n,bt,wt);
	turnAroundTime(n,bt,wt,tat);
	printf("Processes   Burst time   Waiting time   Turn around time\n");

	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("%3d ",(i+1)); 
        printf("%13d ", bt[i] ); 
        printf("%13d",wt[i] ); 
        printf("%13d\n",tat[i] ); 
	}
	int s=(float)total_wt / (float)n; 
    int t=(float)total_tat / (float)n; 
    printf("Average waiting time = %d",s); 
    printf("\n"); 
    printf("Average turn around time = %d ",t); 
}
void printfp(int bt[],int bt1[],int n){
 printf("--------------------Gantt chart----------------------\n");
 printf("         ");
 int sum=0;
	int a;
	for (int i = 0; i < n; ++i)
	{
		sum+=bt[i];
		for(int j=0;j<n;j++)
		{
			if(bt[i]==bt1[j])
			{
				a=j;
				bt1[j]=-1;
			}
		}
		if(i==0)
			printf("0-P%d-%d-",a+1,sum);
		else if(i==n-1)
			printf("P%d-%d",a+1,sum);
		else
			printf("P%d-%d-",a+1,sum);
	}
	printf("\n-----------------------------------------------------\n");
	
}
int main(int argc, char const *argv[])
{
	FILE *fp=NULL;
	fp=fopen("input.txt","r");
	int bt[50];
	int m=0;
	while(fscanf(fp,"%d",&bt[m++])!=EOF);
	fclose(fp);
	int n=m-1;
	int bt1[50];
	for(int i=0;i<n;i++)
	{
		bt1[i]=bt[i];
	}
    bubbleSort(bt,n);
    printfp(bt,bt1,n);
    printf("\n");
    findTime(n,bt);
    printf("\n");
    
	return 0;
}
