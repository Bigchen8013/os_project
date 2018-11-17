#include<stdio.h>
#define N 50
struct PCB
{
	int pn;   //process name进程名字
	int at;   //arrival time到达时间
	int st;   //service time服务时间
	int ct;   //完成时刻
	int sc;  //标志是否完成
	int st1;  //剩余服务时间  
	int wt;   //等待时间 
	int zz;   //周转时间 
}process[N];
int T=4;//时间片
int pid[N],starTime[N];
int a=0,b=0,sumT=0;
int RR(int n)
{
	FILE *fp=NULL;
	fp=fopen("input.txt","r");
	
	int i,j;
	for(i=1;i<=n;i++)      //收集进程信息 
	{
		process[i].sc=0;
		fscanf(fp,"%d %d %d",&process[i].pn,&process[i].at,&process[i].st);
		process[i].st1=process[i].st;
		process[i].wt=0;
		process[i].zz=0;
	}
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)   //按照各进程到达时间升序，对进程排序 注意：稳定的排序 
	{
		if(process[j].at<process[i].at)
		{
			process[0]=process[j];
			process[j]=process[i];
			process[i]=process[0];	
		}
	}
	
	int time=process[1].at;      //当前时间的初值 
	int flag=1;
	int sum=0;					//记录完成的进程数 
	printf("-------------------------运行过程图--------------------------------------\n");
	printf("\n第几次调度进程 运行的进程pn 开始运行时间 运行时间 剩余服务时间 结束时间\n");
	int z=1;   //记录第几次调度进程 
	
while(sum<n){
	
	flag=0;	     //标志就绪队列中是否还有进程 
	for(i=1;i<=n;i++)    //时间片轮转法执行各进程 
	{
		if(process[i].sc==1) 
		  continue;  //已完成的进程 
		else
		 {
		 	if(process[i].st1<=T&&time>=process[i].at)//未完成的进程但是还需服务的时间少于等于一个时间片 
		 	{
		 	flag=1;
		 	time=time+process[i].st1;
		 	process[i].sc=1;
		 	process[i].ct=time;
		 	process[i].zz=time;
		 	process[i].wt=process[i].zz-process[i].st;
		 	
		 	pid[++a]=process[i].pn;
		 	starTime[++b]=time-process[i].st1;
		 	
		 	printf("%8d%12d%15d%11d%11d%11d\n",z++,process[i].pn,time-process[i].st1,process[i].st1,0,time); 
		 	process[i].st1=0;
		 	}
		 	
		 	else if(process[i].st1>T&&time>=process[i].at)//未完成的进程但其还需服务时间至少大于一个时间片 
		 	{
		 		flag=1;
		 		time=time+T;
				process[i].st1-=T;
				process[i].zz=time;
				process[i].wt=process[i].zz-process[i].st;
				
				pid[++a]=process[i].pn;
				starTime[++b]=time-T;
				
				printf("%8d%12d%15d%11d%11d%11d\n",z++,process[i].pn,time-T,T,process[i].st1,time);
			} 
			if(process[i].sc==1) 
			    sum++;     //一个进程执行完就+1 
		}
	}
	
	if(flag==0&&sum<n)   // 还有没执行的进程，且没进入就就绪队列 
	{
	  for(i=1;i<=n;i++)
	     if(process[i].sc==0) {
	        time=process[i].at;
	        break;
	       }
	}
	
}
printf("-------------------------------------------------------------------------\n");
fclose(fp);
}
 
void zt_and_wt(int n)
{
	float average_zt,average_wt;
	int zt=0,wt=0;
	printf("-------------------------------------------------------------------------\n");
	printf("Processes   Burst time   Arrival time   Waiting time   Turn around time\n");
	for(int i=1;i<=n;i++){
		zt+=process[i].zz;
		wt+=process[i].wt;
		sumT+=process[i].st;
		printf("%5d",i); 
        printf("%13d", process[i].st); 
        printf("%13d", process[i].at);
        printf("%14d", process[i].wt); 
        printf("%16d\n",process[i].zz); 
	}
	average_zt=zt*1.0/n;
	average_wt=wt*1.0/n;
	printf("-------------------------------------------------------------------------\n");
	printf("Average waiting time = %.2f\n",average_wt); 
    printf("Average turn around time = %.2f\n",average_zt);
    printf("-------------------------------------------------------------------------\n");
}
int main()
{
	int n;
	printf("\t\t时间片轮转调度算法\n");
	printf("请输入总进程数：\n");
	scanf("%d",&n);
	RR(n);
	zt_and_wt(n);
	printf("------------------------Gantt chart--------------------------------------\n");
	for(int i=0;i<=b;i++)
	{
	 if(i==0)
		printf("%d",starTime[i]);
	 else if(i==a)
		printf("%d-P%d-%d",starTime[i],pid[i],sumT);
		else{
			if(starTime[i]==0)
			  printf("-P%d-",pid[i]);
			  else
		      printf("%d-P%d-",starTime[i],pid[i]);	
		}
		
	}
		printf("\n-------------------------------------------------------------------------\n");
	return 0;
}
