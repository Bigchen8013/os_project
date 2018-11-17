#include <stdio.h>
void waitingTime(int n, int bt[], int wt[],int p[]){
	int count=0;
	int tmp;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(p[j]==i){
				if(count==0){
					wt[j] = 0;
					tmp = j;//保存上一个优先级进程的ID
					count++;
				}
				else{
					wt[j] = bt[tmp] + wt[tmp];//上一个优先级进程的bt + 上一个优先级进程的wt
					tmp = j;//保存上一个优先级进程的ID
				}
			}
		}
	}
}
void turnAroundTime(int n, int bt[], int wt[], int tat[],int p[],int wtat[]){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(p[j]==i){
				tat[j] = bt[j]+wt[j];
				wtat[j] = tat[j]/bt[j];
			}
		}
	}

}
void printGanttChart(int bt[],int n,int p[],int wt[]){
	printf("--------------------Gantt chart----------------------\n");
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(p[j]==i){
			if(i==1){
				printf("0-");
				printf("P%d-%d-",j+1,wt[j]+bt[j]);
				break;
			}
			if(i==n){
				printf("P%d-%d", j+1,wt[j]+bt[j]);
				break;
			}
			else{
				printf("P%d-%d-",j+1,wt[j]+bt[j]);
				break;
			}
			}
		}
	}
	printf("\n-----------------------------------------------------\n");
}
void findTime(int n,int bt[],int p[]){
	int wt[n],tat[n],wtat[n],total_wt=0,total_tat=0,total_wtat=0;
	
	waitingTime(n,bt,wt,p);
	turnAroundTime(n,bt,wt,tat,p,wtat);
	printGanttChart(bt,n,p,wt);
	printf("Processes   Priority   Burst time   Waiting time   Turn around time\n");
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        total_wtat = total_wtat + wtat[i];
        printf("%3d ",(i+1)); 
        printf("%13d", p[i] );
        printf("%13d ", bt[i] ); 
        printf("%13d",wt[i] ); 
        printf("%13d",tat[i] ); 
        printf("\n");
	}
	float s=total_wt / (float)n; 
    float t=total_tat / (float)n; 
    float t2=total_wtat / (float)n; 
    printf("Average waiting time = %.2f",s); 
    printf("\n"); 
    printf("Average turn around time = %.2f ",t);
    printf("\n");
    printf("Average weighted turn around time = %.2f",t2 );
}
int main(int argc, char const *argv[]){
	int i=0;
	FILE *fp=NULL;
	int bt[50], p[50];//优先级  

    fp=fopen("input.txt","r");
    while(fscanf(fp,"%d %d",&bt[i],&p[i])!=EOF){
        i++;
    }
	findTime(i,bt,p);
	fclose(fp);
}
