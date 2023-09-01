#include <stdio.h>
#include <stdlib.h>

void main()
{
int count_down; //defining the number to loop on
printf("please enter countdown number :");
scanf("%d",&count_down);//the user is entering the countdown
for(int descending=count_down;descending>0;descending--)//looping in descending order
{
   printf("%d\n",descending);//showing the numbers in descending order
   sleep(1);//the 1 second delay
}
printf("Blast off to the moon!");
}
