#include<stdio.h>
#include<stdlib.h>

struct patient
{
    char name[50];
    int age;
    char description[100];
};
struct Node 
{
    struct patient * data;
    int priority;
    struct Node * next;
};

void newPatient()
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the name of the patient\n");
    fgets(p->data->name,100,stdin);
    printf("Enter the age of the patient \n");
    scanf("%d",p->data->age);
    printf("Enter the problem\n");
    fgets(p->data->description,100,stdin);
}
int main()
{
    //struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    newPatient();
    

    return 0;
}