#include <stdio.h>
void waitingTime(int n, int bt[], int wt[]){
	wt[0] = 0;

	for(int i=1;i<n;i++){
		wt[i] = bt[i-1] + wt[i-1];
	}
}
void turnAroundTime(int n, int bt[], int wt[], int tat[],int wtat[]){
	for(int i=0;i<n;i++){
		tat[i] = bt[i] + wt[i];
	}

	for(int i=0;i<n;i++){
		wtat[i] = tat[i]/bt[i];
	}
}
void printGanttChart(int bt[],int n){
	printf("--------------------Gantt chart----------------------\n");
	int sum=0;
	for(int i=0;i<n;i++){
	sum+=bt[i];
	if(i==0)
	printf("0-P%d-%d-",i,sum);
	else if(i==n-1)
	printf("P%d-%d",i,sum);
	else
	printf("P%d-%d-",i,sum);
	}
	printf("\n-----------------------------------------------------\n");
}
void findTime(int n,int bt[]){
	int wt[n],tat[n],wtat[n],total_wt=0,total_tat=0,total_wtat=0;
	waitingTime(n,bt,wt);
	turnAroundTime(n,bt,wt,tat,wtat);
	printGanttChart(bt,n);
	printf("Processes   Burst time   Waiting time   Turn around time\n");
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        total_wtat = total_wtat + wtat[i];
        printf("%3d",(i+1)); 
        printf("%13d", bt[i] ); 
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
}
int main(int argc, char const *argv[]){
	int i=0;
    FILE *fp=NULL;
    fp=fopen("input.txt","r");
	int bt[50] ;  
    while(fscanf(fp,"%d",&bt[i])!=EOF){
        i++;
    }
	findTime(i,bt);
	fclose(fp);
}
