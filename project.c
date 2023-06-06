#include<stdio.h>
#include<stdlib.h>

struct Node * front = NULL;
struct Node * rear = NULL;

struct Node 
{
    
    int age;
    int sev;
    struct Node * next;
};


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
    printf("The age of the required patient is %d and the severity of the patient is %d\n",temp->age,temp->sev);
}

int searchSpecificPatientByAge(struct Node * ptr, int age)
{
    int i=1;
    struct Node * temp = ptr;
    while(temp!=NULL)
    {
        if(temp->age == age)
        {
            return i;
        }
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
            if(front->age <= age && front->sev <= sev) // if first element is less than incoming element
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

void cancelAppointment(int age, int severity)
{
    struct Node * ptr = front;
    if (front==NULL)
    {
        printf("\nNo one to cancel an appointment!\n");
    }
    else
    {
        if(front->age == age && front->sev == severity)
        {
            printf("Cancelled appointment of patient with age %d and severity %d\n",age,severity);
            grantAppointment(); //dequeue
        }
        else{    
        while(ptr!=rear)
        {
            ptr = ptr->next;
            if(ptr->next->age==age && ptr->next->sev == severity)
            {
                printf("Cancelled appointment of patient with age %d and severity %d",ptr->next->age,ptr->next->sev);
                struct Node * temp = ptr;
                temp->next = temp->next->next;
                ptr = ptr->next;
                free(ptr);
            }  
        }
        }
    }
    
}
int size(struct Node * ptr)
{
    int count = 0;
    while(ptr!=NULL)
    {        
        count++;
        ptr = ptr->next;
    }
    return count;
}


int main()
{
    printf("Welcome to Hospital VIT\n");
    int num,age,sev,app_num,search_age,cancel_age,cancel_sev;
    char ch;
    while (1)
    {
        printf("\npress 1 to take appointment\npress 2 to grant appointment\npress 3 to show appointment log\npress 4 to search specific patient according to appointment number\npress 5 to search specific patient by age\npress 6 to cancel appointment\npress 7 to display number of patients\npress 8 to exit\n");
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
                printf("\nPatient with what priority number in the appointment log do you want to search for?\n");
                scanf("%d",&app_num);
                searchSpecificPatientByIndex(front,app_num);
                break;
            case 5:
                printf("\nEnter the age of the patient that you want to search\n");
                scanf("%d",&search_age);
                printf("\nThe number of the patient in the appointment log is %d\n", searchSpecificPatientByAge(front,search_age));
                break;
            case 6:
                printf("Enter age of the patient\n");
                scanf("%d",&cancel_age);
                printf("Enter severity of the patient\n");
                scanf("%d",&cancel_sev);
                cancelAppointment(cancel_age,cancel_sev);
                break;
            case 7:
                printf("\nThe number of patients in the appointment log is %d\n",size(front));
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid\n");
                break;
        }
    }
    
    return 0;
}