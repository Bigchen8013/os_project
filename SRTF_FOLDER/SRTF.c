#include <stdio.h>
void waitingTime(){
	
}
void turnAroundTime(){
	
}
void findTime(){
	
}
void printGanttChart(){
	printf("--------------------Gantt chart----------------------\n");
 
	printf("\n-----------------------------------------------------\n");
	
}
int main(int argc, char const *argv[])
{
	FILE *fp=NULL;
	fp=fopen("input.txt","r");
	int bt[50];
	int arr[50];
	int i=0;
	while(fscanf(fp,"%d %d",&bt[i++],&arr[i++])!=EOF);
	fclose(fp);


    printGanttChart();
    printf("\n");
    findTime();
    printf("\n");
    
	return 0;
}
