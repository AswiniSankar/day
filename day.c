/*
WELCOME TO THE CALENDER
  jan    feb    mar  
  apr    may    june  
  july    aug    sep  
  oct    nov    dec  

enter the date,month,year:: the month should be in the above formate
5
july
2020
5 : july : 2020

-----------------
|-- SUNDAY --|
-----------------

do you want to navigate to another day?1/0
0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int date,year,i,j,t,t1=1,r,n=0,t2=1,t3,t4,odd[12]={3,0,3,2,3,2,3,3,2,3,2,3},flag=0,sum=0,choice=1;
  char mon[5],month[][5]={ "jan","feb","mar","apr","may","june","july","aug","sep","oct","nov","dec"},day[][20]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
 printf("\nWELCOME TO THE CALENDER\n");
  while(choice)
 {t1=1;
  n=0;
  t2=1;
  flag=0;
  sum=0;
   for(i=0;i<4;i++)
   {
      for(j=0;j<3;j++)
        {printf("  %s  ",month[n]);
          n++;
         }
       printf("\n");
   
   }
  printf("\nenter the date,month,year:: the month should be in the above formate\n");
  scanf("%d%s%d",&date,mon,&year);
  printf("%d : %s : %d\n",date,mon,year);
   n=0;
   if(year%400==0 || year%4==0)
    { flag=1;
    }
  t=year-1;
  while(t && t1<3)
  {r=t%10;
   n=n+(r*t2);
   t/=10;
   t1++;
   t2*=10;
  }
  t=t*100;
  if(t%400==0)
   {  t3=0;t4=0;
   }
  else
  //printf("%d-%d\n",t,n);
  {
   t3=t/400;
  t3=t3*400;
  t4=t-t3;
 // printf("%d--%d\n",t3,t4);
  if(t3%400==0)
     t3=0;
  if(t4==400)
     t4=0;
  else if(t4==300)
    t4=1;
  else if(t4==200)
    t4=3;
   else if(t4==100)
     t4=5;


  }
  // printf("%d--%d\n",t3,t4);
  //n=n-1;
  t=0;
  t=n/4;
  n=n-t;
   //printf("%d--%d\n",n,t);
  t=t*2;
  n=n*1;
    //printf("%d--%d\n",n,t);
  n=n+t+t3+t4;
  //printf("%d\n",n);
  for(i=0;i<12;i++)
  {
    if(strcmp(month[i],mon)==0)
     {  break;
     }
  }
  //printf("%d\n",i);
  for(j=0;j<11;j++)
  {
     if(j<i)
      { sum+=odd[j];
      if(flag==1 && j==1)
         sum++;
      }
  }
  
  // printf("%d\n",sum);
  n=n+sum+date;
    //printf("%d\n",n);
  printf("\n-----------------\n|-- %s --|\n-----------------\n",day[n%7]);
  printf("\n");
  printf("do you want to navigate to another day?1/0\n");
  scanf("%d",&choice);
  if(choice==1)
    choice=1;
  else
    exit(1);
 }
  return 0;
}
