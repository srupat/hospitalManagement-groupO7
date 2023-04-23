#include<stdio.h>
#include<stdlib.h>

struct Node * front = NULL;
struct Node * rear = NULL;
// struct patient
// {
//     char name[50];
//     int age;
//     char description[100];
// };
struct Node 
{
    //struct patient * data;
    int age;
    struct Node * next;
};

// void newPatient()
// {
//     struct Node * p = (struct Node *)malloc(sizeof(struct Node));
//     printf("Enter the name of the patient\n");
//     fgets(p->data->name,100,stdin);
//     printf("Enter the age of the patient \n");
//     scanf("%d",p->data->age);
//     printf("Enter the problem\n");
//     fgets(p->data->description,100,stdin);
// }
void queueTraversal(struct Node * ptr)
{
    printf("Printing the elements of the priority queue\n");
    while (ptr->next != NULL)
    {
        printf("The age of the patient is %d\n",ptr->age);
        ptr = ptr->next;
    }
    printf("The age of the patient is %d\n",ptr->age);
    
}
void newAppointment(int age)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if (p==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        p->age = age;
        if (front==NULL) // if queue is empty
        {
            front = rear = p;
        }
        else // queue is not empty
        {
            if(p->age>=rear->age)
            {
                //insert in between second last element and rear
                struct Node * ptr = front;
                while (ptr->next != rear)
                {
                    ptr = ptr->next;
                }
                p->next = rear; 
                ptr->next = p;
                               
            }
            else
            {
                // insert at end
                p->next = NULL;
                rear->next = p;
                rear = p;
            }
            
        }
    }

}

// set up a system such that whenever a new node arrives, you have to just check whether the age is greater 
// than or less than the age of the previous node and insert new node accordingly
int grantAppointment()
{
    int val = -1;
    struct Node * ptr = front;
    if (front==NULL)
    {
        printf("No one to grant an appointment to!\n");
    }
    else
    {
        front = front->next;
        val = ptr->age;
        free(ptr);
    }
    return val;
}


int main()
{
    //queueTraversal(front);
    newAppointment(10);
    newAppointment(20);
    newAppointment(15);
    newAppointment(47);
    queueTraversal(front);
    //printf("patient with age %d has been granted an appointment \n",grantAppointment());
    
    //queueTraversal(front);

    
    
    

    return 0;
}