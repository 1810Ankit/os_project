#include<stdio.h>
struct process
{
 int process_number;
 int arrival_time,burst_time,waiting_time,turnaround_time;
 int flag;
}p[10];

int n;

int main()
{
 int i,j,time,sum_burst_time=0;
 char c;
 float sum=0,sum1=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
}
