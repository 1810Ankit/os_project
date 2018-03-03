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
 if(p[i].arrival_time>p[j].arrival_time)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
 }
}
}
void Priority(int a)
{
    for(time=p[0].arrival_time;time<sum_burst_time;)
  {

   float check=-1;
    int biggest_priority_process;
  for(i=0;i<n;i++)
  {

   if(p[i].arrival_time<=time && p[i].flag!=1)
            {
              float temp=(p[i].burst_time + (time-p[i].arrival_time))/p[i].burst_time;
              if(check < temp)
               {
                check=temp;
                biggest_priority_process=i;
               }

   }
   }


   time+=p[biggest_priority_process].burst_time;
   p[biggest_priority_process].waiting_time=time-p[biggest_priority_process].arrival_time-p[biggest_priority_process].burst_time;
   p[biggest_priority_process].turnaround_time=time-p[biggest_priority_process].arrival_time;
   p[biggest_priority_process].flag=1;
printf("\nProcess%d\t\t%d\t\t%d\t\t%d\t\t%",(p[loc].process_number+1),p[loc].arrival_time,p[loc].burst_time,p[loc].waiting_time);
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
printf("\nName\t\tArrival Time\tBurst Time\tWaiting Time");

printf("\nAverage waiting time:%f\n",sum/n);
}
