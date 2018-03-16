#include<stdio.h>
struct process
{
 int process_number;
 int arrival_time,burst_time,waiting_time,turnaround_time;
 int flag;
}p[10];

int n;
void sorting_on_arrival_time()
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
    int i,time,sum_burst_time;
    sum_burst_time=a;
    float sum=0,sum1=0;
    printf("\nName\t\tArrival Time\tBurst Time\tWaiting Time");
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
   sum+=p[biggest_priority_process].waiting_time;
   sum1=p[biggest_priority_process].waiting_time+p[biggest_priority_process].burst_time;
printf("\nProcess%d\t\t%d\t\t%d\t\t%d\t\t%",(p[biggest_priority_process].process_number+1),p[biggest_priority_process].arrival_time,p[biggest_priority_process].burst_time,p[biggest_priority_process].waiting_time);
  }

printf("\nAverage waiting time:%f\n",sum/n);
}
int main()
{
 int i,j,sum_burst_time=0;
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
sorting_on_arrival_time();
Priority(sum_burst_time);
}
