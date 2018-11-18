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
	int index = 0, finish_time;
	int flag = false;
	int lastIndex=-1;//存储上一个进程
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
				index = j;
				flag = true;

			}
		}
		
		if(flag == false){
			t++;
			continue;
		}
		if(lastIndex!=index){
			if(lastIndex==-1){
				printf("--------------------Gantt chart----------------------\n");
				printf("0-P%d",index+1);
			}
			else{
				printf("-%d-P%d",t,index+1);
			}	
				lastIndex = index;
			}
		bt2[index]--;//减少某个进程的剩余时间

		min = bt2[index];//更新最短剩余时间

		if(min == 0){
			min = 10000;
		}

		if(bt2[index] == 0){//如果某个进程跑完了
			c++;

			flag = false;
			if(c==n){
				printf("-%d",t+1);
			}
			//甘特图最后项
			//得出这个进程的完成时间
			finish_time = t+1; 
			 // 计算等待时间 
           
            wt[index] = finish_time - 
                        p[index].bt - 
                        p[index].arr; 
  
            if (wt[index] < 0){ 
                wt[index] = 0;
            }
		}

		t++;
	}
}
void turnAroundTime(struct Process p[],int wt[],int tat[],int n,float wtat[]){
	for(int i=0;i<n;i++){
		tat[i] = p[i].bt + wt[i];
		wtat[i] = tat[i]/(float)p[i].bt;
	}
}
void findTime(struct Process p[],int n){
	int wt[n],tat[n],total_wt = 0, total_tat = 0;
	float wtat[n],total_wtat=0;
	waitingTime(p,wt,n);
	turnAroundTime(p,wt,tat,n,wtat);
	printf("\n-----------------------------------------------------\n");
	printf("Processes   Burst time   Arrival time   Waiting time   Turn around time\n");

	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        total_wtat += wtat[i];
        printf("%3d",(i+1)); 
        printf("%13d", p[i].bt ); 
        printf("%13d", p[i].arr);
        printf("%13d", wt[i] ); 
        printf("%13d\n",tat[i] ); 
	}
	float s=total_wt / (float)n; 
    float t=total_tat / (float)n; 
    float t2 = total_wtat / (float)n;
    printf("Average waiting time = %.2f",s); 
    printf("\n"); 
    printf("Average turn around time = %.2f ",t);
    printf("\n");
    printf("Average weighted turn around time = %.2f", t2);
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
	n = i;
    printf("\n");
    findTime(p,n);
    printf("\n");
    fclose(fp);
	return 0;
}
