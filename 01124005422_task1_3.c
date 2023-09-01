#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Task//creating structure containing id and description and boolean value
{
    int id;
    char description[200];
    bool completed;
};
void main()
{
    int numtasks=0;
    struct Task *tasks=NULL;//setting linked list pointer to null
    while(1){//looping until exit is pressed
    printf("\nMenu:\n");
    printf("1)Add Task\n");
    printf("2)View Tasks\n");
    printf("3)Remove Task\n");
    printf("4)mark task as complete\n");
    printf("5)completed tasks\n");
    printf("6)incomplete tasks\n");
    printf("7)Exit\n");
    printf("Choose an option: ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
case 1:{
    struct Task newtask;//creating an object of the structure Task
    newtask.id=numtasks+1;//giving the newly created task a unique id
    printf("insert a new task ");
    scanf(" %[^\n]", newtask.description);//entering the task to do
    tasks=(struct Task *)realloc(tasks,(numtasks+1)*sizeof(struct Task));//changing the size to fit the newly created task
    tasks[numtasks] = newtask;//putting the newly created task in array of tasks
    numtasks++;//incrementing the number of tasks
    printf("task has been added to id: %d\n",newtask.id);
    break;
}
case 2:{
    for(int i=0;i<numtasks;i++){//looping on the tasks to show them
    printf("ID : %d, Description: %s\n", tasks[i].id,tasks[i].description);
    }
   break;
}
case 3:{
    int task_id;
    printf("Enter task ID to remove: ");
    scanf("%d",&task_id);
     int taskIndex = -1;
     //checking for the id entered if it is actually in tasks
    for (int i = 0; i < numtasks; i++) {
        if (tasks[i].id == task_id) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex != -1) {//if id entered is located inside the linked list
        for (int i = taskIndex; i < numtasks - 1; i++) {
            //shifting the content and the id's of the tasks to not let them overlap when entering new tasks
            tasks[i] = tasks[i+1];
            tasks[i].id = i + 1;
        }
        numtasks--;
        tasks = (struct Task *)realloc(tasks, numtasks * sizeof(struct Task));//changing the size of the linked list
        printf("Task with ID %d removed\n", task_id);
    } else {//if there is no id found
        printf("Task with ID %d not found\n", task_id);
    }
    break;
}
case 4:
    {
        int task_comp;//the task id to enter as completed
        printf("enter task id to mark as complete: ");
        scanf("%d",&task_comp);
        for(int i=0;i<numtasks;i++){
            if(tasks[i].id==task_comp){//to loop until the task id is found
                tasks[i].completed=true;//making the boolean true to state that task is completed
                printf("task added successfully\n");
            }
        }
           if(task_comp<1 || task_comp>numtasks){//if user entered an invalid id
                printf("not a valid id\n");
            }


        break;
    }
case 5:
    {
        printf("tasks completed\n");
        for(int i=0;i<numtasks;i++){
                //if task is marked as complete from case 4 its shown
            if(tasks[i].completed){
             printf("ID: %d, Description: %s\n",tasks[i].id, tasks[i].description);

            }
        }
        break;
    }
case 6:
    {
      printf("incomplete tasks\n");
       for (int i = 0; i < numtasks; i++) {
         if (!tasks[i].completed) {
                //if task is not stated true for completed it will appear
             printf("ID: %d, Description: %s\n",tasks[i].id, tasks[i].description);
                    }
                }
                break;
    }
case 7:{
    printf("exiting minions task manager.Have a great day!");
    free(tasks);//deleting the space of the linked list
    return 0;
}
default :
    printf("invalid id\n");
    }
    }

}
