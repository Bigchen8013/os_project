#include <stdio.h>
//非抢占式优先级
struct Process{
	int pid;
	int bt;
	int arr;
	int p;
};
void waitingTime(int n,int wt[],struct Process pro[]){
	int count=0;
	int tmp;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(pro[j].p==i){
				if(count==0){
					wt[j] = 0;
					tmp = j;//保存上一个优先级进程的ID
					count++;
				}
				else{
					wt[j] = pro[tmp].bt + wt[tmp];//上一个优先级进程的bt + 上一个优先级进程的wt
					tmp = j;//保存上一个优先级进程的ID
				}
			}
		}
	}
}
void turnAroundTime(int n,int wt[], int tat[],float wtat[],struct Process pro[]){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(pro[j].p==i){
				tat[j] = pro[j].bt+wt[j];
				wtat[j] = tat[j]/(float)pro[j].bt;
			}
		}
	}

}
void printGanttChart(int n,int wt[],struct Process pro[]){
	printf("--------------------Gantt chart----------------------\n");
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(pro[j].p==i){
			if(i==1){
				printf("0-");
				printf("P%d-%d-",j+1,wt[j]+pro[j].bt);
				break;
			}
			if(i==n){
				printf("P%d-%d", j+1,wt[j]+pro[j].bt);
				break;
			}
			else{
				printf("P%d-%d-",j+1,wt[j]+pro[j].bt);
				break;
			}
			}
		}
	}
	printf("\n-----------------------------------------------------\n");
}
void findTime(int n,struct Process pro[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	float wtat[n],total_wtat=0;
	waitingTime(n,wt,pro);
	turnAroundTime(n,wt,tat,wtat,pro);
	printGanttChart(n,wt,pro);
	printf("Processes   Priority   Arrival time   Burst time   Waiting time   Turn around time\n");
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        total_wtat = total_wtat + wtat[i];
        printf("%3d ",(i+1)); 
        printf("%13d", pro[i].p );
        printf("%13d", pro[i].arr );
        printf("%13d ", pro[i].bt ); 
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
    printf("\n");
}
int main(int argc, char const *argv[]){
	int i=0;
	FILE *fp=NULL;
	struct Process pro[50];
    fp=fopen("input.txt","r");
    while(fscanf(fp,"%d %d %d",&pro[i].bt,&pro[i].p,&pro[i].arr)!=EOF){
// id 优先级 到达时间
        i++;
    }
	findTime(i,pro);
	fclose(fp);
}
