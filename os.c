#include<stdio.h>
struct process
{
 int process_number;
 int arrival_time,burst_time,waiting_time,turnaround_time;
 int flag;
}p[10];

int n;
void sorting()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
 if(p[i].arrival_time<=p[j].arrival_time)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
 }
}
}
int main()
{
 int i,j,time,sum_burst_time=0;
 char c;
 float sum=0,sum1=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 p[i].process_number=i;
 printf("ENTER THE ARRIVAL AND BURST TIME OF THE PROCESS %d\n",(p[i].process_number+1));
 printf("ENTER THE ARRIVAL TIME: ");
 scanf("%d",&p[i].arrival_time);
 printf("ENTER THE BURST TIME: ");
 scanf("%d",&p[i].burst_time);
 p[i].flag=0;
 sum_burst_time+=p[i].burst_time;
}
sorting();
}
