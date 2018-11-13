#include <stdio.h>
#define true 1
#define false 0
struct Process{
	int pid;
	int bt;
	int arr;
};
void waitingTime(struct Process p[],int wt[],int n){
	int bt2[n];
	int c = 0, t = 0, min = 10000;
	int shortest = 0, finish_time;
	int flag = false;

	for(int i=0;i<n;i++){
		bt2[i] = p[i].bt;
	}
	while(c<n){
		//找出目前为止抵达的拥有最短剩余时间的进程
		for(int j=0;j<n;j++){
			if((p[j].arr<=t) && 
				(bt2[j]<min) && 
				(bt2[j]>0)){
				min = bt2[j];
				shortest = j;
				flag = true;
			}
		}
		if(flag == false){
			t++;
			continue;
		}
		bt2[shortest]--;//减少某个进程的剩余时间

		min = bt2[shortest];//更新最短剩余时间

		if(min == 0){
			min = 10000;
		}

		if(bt2[shortest] == 0){//如果某个进程跑完了
			c++;
			flag = false;
			//得出这个进程的完成时间
			finish_time = t + 1; 
  
            // 计算等待时间 
            wt[shortest] = finish_time - 
                        p[shortest].bt - 
                        p[shortest].arr; 
  
            if (wt[shortest] < 0){ 
                wt[shortest] = 0;
            }
		}

		t++;
	}
}
void turnAroundTime(struct Process p[],int wt[],int tat[],int n){
	for(int i=0;i<n;i++){
		tat[i] = p[i].bt + wt[i];
	}
}
void findTime(struct Process p[],int n){
	int wt[n],tat[n],total_wt = 0, total_tat = 0;

	waitingTime(p,wt,n);
	turnAroundTime(p,wt,tat,n);
	printf("Processes   Burst time   Arrival time   Waiting time   Turn around time\n");

	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("%3d",(i+1)); 
        printf("%13d", p[i].bt ); 
        printf("%13d", p[i].arr);
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
	struct Process p[50];
	int i=0;
	int n;
	while(fscanf(fp,"%d %d %d",&p[i].pid,&p[i].bt,&p[i].arr)!=EOF){
		i++;
	}
	fclose(fp);

	n = i;
    //printGanttChart();
    printf("\n");
    findTime(p,n);
    printf("\n");
    
	return 0;
}
