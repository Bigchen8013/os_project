#include <stdio.h>
void waitingTime(int n, int bt[], int wt[]){
	
}
void turnAroundTime(int n, int bt[], int wt[], int tat[]){
	
}
void printGanttChart(int bt[],int n){
	printf("--------------------Gantt chart----------------------\n");
	
	
	printf("\n-----------------------------------------------------\n");
}

void findTime(int n,int bt[]){

}
int main(int argc, char const *argv[]){
	int i=0;
    FILE *fp=NULL;
    fp=fopen("input.txt","r");
	int bt[50] ;
	int p[50];
    while(fscanf(fp,"%d",&bt[i])!=EOF){
        i++;
    }
	findTime(i,bt);

}