#include <stdio.h>
struct Process{
	int pid;
	int bt;
	int arr;
};
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
void turnAroundTime(int n, int bt[], int wt[], int tat[],float wtat[]){
	for(int i=0;i<n;i++){
		tat[i] = bt[i] + wt[i];
		wtat[i] = tat[i]/(float)bt[i];
	}
}
void findTime(int n,int bt[],struct Process p[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	float wtat[n],total_wtat=0;
	waitingTime(n,bt,wt);
	turnAroundTime(n,bt,wt,tat,wtat);
	printf("Processes   Arrival time   Burst time   Waiting time   Turn around time\n");
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i]; 
        total_wtat = total_wtat + wtat[i]; 
        printf("%3d ",(i+1)); 
        printf("%13d",p[i].arr);
        printf("%13d ", bt[i] ); 
        printf("%13d",wt[i] ); 
        printf("%13d\n",tat[i] ); 
	}
	float s=total_wt / (float)n; 
    float t=total_tat / (float)n; 
    float t2=total_wtat / (float)n;
    printf("Average waiting time = %.2f",s); 
    printf("\n"); 
    printf("Average turn around time = %.2f",t); 
    printf("\n");
    printf("Average weighted turn around time = %.2f", t2);
}
void printGanttChart(int bt[],int bt1[],int n){
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
	struct Process p[50];
	int m=0;
	while(fscanf(fp,"%d %d %d",&p[m].pid,&p[m].arr,&p[m].bt)!=EOF){
	bt[m]=p[m].bt;
	m++; 
	} 
	fclose(fp);
	int n=m;
	int bt1[50];
	for(int i=0;i<n;i++)
	{
		bt1[i]=bt[i];
	}
    bubbleSort(bt,n);
    printGanttChart(bt,bt1,n);
    printf("\n");
    findTime(n,bt,p);
    printf("\n");
    
	return 0;
}
