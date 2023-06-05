#include<stdio.h>
#include<stdlib.h>
// search specific patient
// cancel appointment
// queue size display
struct Node * front = NULL;
struct Node * rear = NULL;
// struct patient
// {
//     char name[50];
//     int urgency;
//     char description[100];
// };
struct Node 
{
    //struct patient * data;
    int age;
    int sev;
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
    printf("\nPrinting the patients who have taken appointment according to priority\n");
    while (ptr->next != NULL)
    {
        printf("The age of the patient is %d\n",ptr->age);
        ptr = ptr->next;
    }
    printf("The age of the patient is %d\n",ptr->age);
    
}
void searchSpecificPatientByIndex(struct Node * ptr, int index)
{
    int i=0;
    struct Node * temp = ptr;
    while(i!=index-1 && temp != rear)
    {
        temp = temp->next;
        i++;
    }
    printf("The age of the required patient is %d and the severity of the patient is %d",temp->age,temp->sev);
}

int searchSpecificPatientByAge(struct Node * ptr, int age)
{
    int i=1;
    struct Node * temp = ptr;    
    while(temp!=rear)
    {
        if(temp->age==age) return i;
        temp = temp->next;
        i++;
    }
    return -1; //patient not found
}

void newAppointment(int age, int sev)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp = front;
    if (p==NULL)
    {
        printf("Queue is full\n");
    }
    
    else
    {
        p->age = age;
        p->sev = sev;
        if (front==NULL) // if queue is empty
        {
            front = rear = p;
            front->next = NULL;
        }
        
        else // queue is not empty
        {
            if(front->age <= age || front->sev <= sev) // if first element is less than incoming element
            {
                p->next = front;
                front = p;
                return;
            }
            while (temp->next != NULL && temp->next->age >= age && temp->next->sev >= sev)
            {
                temp = temp->next;
            }
            if (temp->next == NULL) // insert at end
            {
                p->next = NULL;
                rear->next = p;
                rear = p;
            }
            else 
            {
                p->next = temp->next;
                temp->next = p;                
            }    
           
        }
    }

}

int grantAppointment()
{
    int val = -1;
    struct Node * ptr = front;
    if (front==NULL)
    {
        printf("\nNo one to grant an appointment to!\n");
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
    printf("Welcome to Hospital VIT\n");
    int num,age,sev;
    char ch;
    while (1)
    {
        printf("\npress 1 to take appointment\npress 2 to grant appointment\npress 3 to show appointment log\npress 4 to exit\n");
        scanf("%d",&num);
        switch(num)
        {
            case 1:            
                printf("What is your age?\n");
                scanf("%d",&age);
                printf("What is the severity of your condition on a scale of 1 to 5\n");
                scanf("%d",&sev);
                if(sev>5)
                {
                    printf("Please enter severity range between 1 to 5\n");
                }
                else{newAppointment(age,sev);}
                break;
            case 2:
                printf("\nAppointment has been granted to patient with age %d\n",grantAppointment(front));
                break;
            case 3:
                queueTraversal(front);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid\n");
                break;
        }
    }
    
    return 0;
}