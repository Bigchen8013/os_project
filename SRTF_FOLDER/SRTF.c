#include <stdio.h>

struct Process{
	int pid;
	int bt;
	int arr;
}
void waitingTime(Process p[],int wt[],int n){
	
}
void turnAroundTime(Process p[],int wt[],int tat[],int n){
	
}
void findTime(Process p[],int n){
	int wt[n],tat[n],total_wt = 0, total_tat = 0;

	waitingTime(wt,n);
	turnAroundTime(wt,tat,n);
	printf("Processes   Burst time   Waiting time   Turn around time\n");

	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("%3d",(i+1)); 
        printf("%13d", p[i].bt ); 
        printf("%13d", wt[i] ); 
        printf("%13d\n",tat[i] ); 
	}
}
void printGanttChart(){
	printf("--------------------Gantt chart----------------------\n");
 
	printf("\n-----------------------------------------------------\n");
	
}
int main(int argc, char const *argv[])
{
	FILE *fp=NULL;
	fp=fopen("input.txt","r");
	Process p[50];
	int i=0;
	int n;
	while(fscanf(fp,"%d %d %d",&p[i++].pid,&p[i++].bt,&p[i++].arr)!=EOF);
	fclose(fp);

	n = i;
    //printGanttChart();
    printf("\n");
    findTime(p,n);
    printf("\n");
    
	return 0;
}
