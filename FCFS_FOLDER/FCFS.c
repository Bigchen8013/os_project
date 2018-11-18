#include <stdio.h>
struct Process{
	int pid;
	int bt;
	int arr;
};
void waitingTime(int n, int bt[], int wt[]){
	wt[0] = 0;

	for(int i=1;i<n;i++){
		wt[i] = bt[i-1] + wt[i-1];
	}
}
void turnAroundTime(int n, int bt[], int wt[], int tat[],float wtat[]){
	for(int i=0;i<n;i++){
		tat[i] = bt[i] + wt[i];
	}

	for(int i=0;i<n;i++){
			wtat[i] = tat[i]/(float)bt[i];
	}
}
void printGanttChart(int bt[],int n){
	printf("--------------------Gantt chart----------------------\n");
	int sum=0;
	for(int i=0;i<n;i++){
	sum+=bt[i];
	if(i==0)
	printf("0-P%d-%d-",i+1,sum);
	else if(i==n-1)
	printf("P%d-%d",i+1,sum);
	else
	printf("P%d-%d-",i+1,sum);
	}
	printf("\n-----------------------------------------------------\n");
}
void findTime(int n,int bt[],struct Process p[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	float wtat[n],total_wtat=0;
	waitingTime(n,bt,wt);
	turnAroundTime(n,bt,wt,tat,wtat);
	printGanttChart(bt,n);
	printf("Processes   Arrival time   Burst time   Waiting time   Turn around time\n");
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        total_wtat = total_wtat + wtat[i];
        printf("%3d",(i+1)); 
        printf("%13d",p[i].arr);
        printf("%14d", bt[i] ); 
        printf("%13d",wt[i] ); 
        printf("%19d\n",tat[i] ); 
	}
	float s=total_wt / (float)n; 
    float t=total_tat / (float)n; 
    float t2=total_wtat/ (float)n;
    printf("Average waiting time = %.2f",s); 
    printf("\n"); 
    printf("Average turn around time = %.2f",t);
    printf("\n"); 
    printf("Average weighted turn around time = %.2f",t2);
    printf("\n"); 
}
int main(int argc, char const *argv[]){
	int i=0;
    FILE *fp=NULL;
    fp=fopen("input.txt","r");
    struct Process p[50];
	int bt[50] ;  
    while(fscanf(fp,"%d %d %d",&p[i].pid,&p[i].arr,&p[i].bt)!=EOF){
        bt[i]=p[i].bt;
		i++;
    }
	findTime(i,bt,p);
	fclose(fp);
}
