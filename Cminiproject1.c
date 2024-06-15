//C mini project on Attendance Management system
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
   char name[20];
   char usn[20];
   int age;
   int sem;
   int indivisualMarks;
   int NoOFDSclass;
   int NoOFADEclass;
   int NOOFCOAclass;
   int NoOFMATHSclass;
   int NoOFOOPSclass;
   float marks;
};
typedef struct Student S;
struct node
{
    S info;
    struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not Allocated\n");
        exit(0);
    }
    return x;
}
int totalClasses;
void Showdetails(S s1)
{
    printf("Name of the Student=%s\n",s1.name);
    printf("USN:%s\n",s1.usn);
    printf("AGE of the Student:%d\n",s1.age);
    printf("Semester of the Student:%d\n",s1.sem);
}
NODE insert_front(NODE first,S s1)
{
     NODE temp;
     temp=getnode();
     temp->info=s1;
     temp->link=first;
     return temp;
}
void ClassesInitialization(NODE first)
{
    NODE curr;
    curr=first;
    while(curr!=NULL)
    {
        (curr->info).NoOFDSclass=0;
        (curr->info).NoOFADEclass=0;
        (curr->info).NoOFMATHSclass=0;
        (curr->info).NoOFOOPSclass=0;
        (curr->info).NOOFCOAclass=0;
        curr=curr->link;
    }
}
void sort(NODE first)
{
    S temp;
    NODE curr,next;
    int i=0;
    curr=first;
    while(curr->link!=NULL)
    {
        next=curr->link;
        while(next!=NULL)
        {
            if((curr->info).name[i]>(next->info).name[i])
            {
                temp=curr->info;
                curr->info=next->info;
                next->info=temp;
            }
            next=next->link;
        }
        curr=curr->link;
    }
}
void Attendence_Calculation(NODE first) {
    int ispresent, days = 1, lastDay, ispresentSubject;
    char subjects[5][6]; // make the subject strings 6 characters long to hold the null terminator
    printf("Enter the 5 subjects\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", subjects[i]);
    }
    printf("Enter total no of classes for all the subjects\n");
    scanf("%d", &totalClasses);
    printf("Enter no of Days till which Attendance is to be considered\n");
    scanf("%d", &lastDay);
    while (1) {
        NODE curr;
        curr = first;
        if (lastDay < 1 || totalClasses < 1 || totalClasses < lastDay) { // check for invalid input
            printf("Invalid input. Please try again.\n");
            return;
        }
        int count = 0;
        while (curr != NULL) {
            printf("Enter 0 -> if student %s is absent on day %d, 1 -> if the student is present\n", curr->info.name, days);
            scanf("%d", &ispresent);
            if (ispresent == 1) {
                for (int i = 0; i < 5; i++) {
                    printf("Enter 0 -> if student %s is absent for %s class, 1 -> if student is present\n", curr->info.name, subjects[i]);
                    scanf("%d", &ispresentSubject);
                    if (ispresentSubject == 1) {
                        if (strcmp(subjects[i], "DS") == 0) {
                            (curr->info).NoOFDSclass++;
                        } else if (strcmp(subjects[i], "COA") == 0) {
                            (curr->info).NOOFCOAclass++;
                        } else if (strcmp(subjects[i], "ADE") == 0) {
                            (curr->info).NoOFADEclass++;
                        } else if (strcmp(subjects[i], "MATHS") == 0) {
                            (curr->info).NoOFMATHSclass++;
                        } else if (strcmp(subjects[i], "OOPS") == 0) {
                            (curr->info).NoOFOOPSclass++;
                        }
                        Showdetails(curr->info);
                    } else {
                        printf("Student %s is absent for %s class.\n", curr->info.name, subjects[i]);
                    }
                }
                count++;
            }
            curr = curr->link;
        }
        printf("Number of students present on day %d: %d\n", days, count);
        days++;
        if (days > lastDay) {
            break;
        }
    }
    NODE curr;
    curr=first;
    while(curr!=NULL)
    {
        printf("No of DS classes attended by the student %s is %d out of %d\n",(curr->info).name,(curr->info).NoOFDSclass,totalClasses);
        printf("No of ADE classes attended by the student %s is %d out of %d\n",(curr->info).name,(curr->info).NoOFADEclass,totalClasses);
        printf("No of MATHS classes attended by the student %s is %d out of %d\n",(curr->info).name,(curr->info).NoOFMATHSclass,totalClasses);
        printf("No of OOPS classes attended by the student %s is %d out of %d\n",(curr->info).name,(curr->info).NoOFOOPSclass,totalClasses);
        printf("No of COA classes attended by the student %s is %d out of %d\n",(curr->info).name,(curr->info).NOOFCOAclass,totalClasses);
        curr=curr->link;
    }
}
void display(NODE first)
{
    if(first==NULL)
        return;
    NODE t;
    t=first;
    int i=0;
    while(t!=NULL)
    {
       printf("Displaying the details of Student %d\n",i+1);
       printf("Name=%s\n",(t->info).name);
       printf("USN=%s\n",(t->info).usn);
       printf("Age=%d\n",(t->info).age);
       printf("Semester=%d\n",(t->info).sem);
       printf("Marks=%f\n",(t->info).marks);
       i++;
       t=t->link;
    }    
}
int count(NODE first)
{
    if(first==NULL)
         return 0;
    int count2=0;
    NODE t=first;
    while(t!=NULL)
    {
        count2++;
        t=t->link;
    }     
    return count2;
}
void Calculate_Marks(NODE first)
{
     printf("*** flag3***");
     NODE curr;
     int totalMarks=0;
     curr=first;
     int n=count(first);
     int marks[5];
     while(curr!=NULL)
     {
        (curr->info).marks=0.0;
        printf("Entering the Marks of Student %s in 5 subjects,each of which is out of 60 marks,pls Enter within 60.",(curr->info).name);
        for(int i=0;i<5;i++)
        {
            scanf("%d",&marks[i]);
        }
        for(int i=0;i<5;i++)
        {
            (curr->info).marks+=marks[i];
        }
        (curr->info).indivisualMarks=(((curr->info).marks/300)*30)+10+10;
        printf("Marks of the Student %s out of 50 is %d\n",(curr->info).name,(curr->info).indivisualMarks);
        totalMarks+=(curr->info).indivisualMarks;
        curr=curr->link;
     }
     printf("\n\n flag2\n");
    int AvgMarks=totalMarks/n;
     printf("The Average Marks of All Students is %d\n",AvgMarks);
     curr=first;
     while(curr!=NULL)
     {
        if((curr->info).indivisualMarks>AvgMarks)
        {
            printf("Very Good Effort %s.Keep it Up.",(curr->info).name);
            Showdetails(curr->info);
        }
        else
        {
            printf("Can Do better Next time.Please improve and work Harder %s.All the best",(curr->info).name);
        }
        curr=curr->link;
     }
}
void file_display(NODE first)
{
    if(first==NULL)
        return;
    FILE *fptr;
    fptr=fopen("Student_Attendence.txt","w+");    
    NODE t;
    t=first;
    int i=0; 
    while(t!=NULL)
    {
       fprintf(fptr,"Displaying the details of Student %d\n",i+1);
       fprintf(fptr,"Name=%s\n",(t->info).name);
       fprintf(fptr,"USN=%s\n",(t->info).usn);
       fprintf(fptr,"Age=%d\n",(t->info).age);
       fprintf(fptr,"Semester=%d\n",(t->info).sem);
       fprintf(fptr,"Marks=%.2f\n\n",(t->info).marks);
       fprintf(fptr,"No of DS classes attended by the student %s is %d out of %d\n",(t->info).name,(t->info).NoOFDSclass,totalClasses);
       fprintf(fptr,"No of ADE classes attended by the student %s is %d out of %d\n",(t->info).name,(t->info).NoOFADEclass,totalClasses);
       fprintf(fptr,"No of MATHS classes attended by the student %s is %d out of %d\n",(t->info).name,(t->info).NoOFMATHSclass,totalClasses);
       fprintf(fptr,"No of OOPS classes attended by the student %s is %d out of %d\n",(t->info).name,(t->info).NoOFOOPSclass,totalClasses);
       fprintf(fptr,"No of COA classes attended by the student %s is %d out of %d\n",(t->info).name,(t->info).NOOFCOAclass,totalClasses);
       i++;
       t=t->link;
    }    
    fclose(fptr);
}
void read_file(NODE first)
{
    FILE *fptr;
    fptr=fopen("Student_Attendence.txt","r+");
    if(fptr==NULL)
    {
        printf("File opening unsuccesfull\n");
        exit(1);
    }
    NODE curr;
    curr=first;
    long int size=sizeof(curr->info);
    int no=count(first);
    char str[size*no];
    printf("\nReading contents from file\n");
    while(curr!=NULL)
    {
        
        while(fgets(str,sizeof(curr->info),fptr)!=NULL)
        {
            fputs(str,stdout);
            
        }
        curr=curr->link;
    }
}
int main()
{
    NODE first=NULL;
    S student;
    int n;
    printf("Accept the no of Students\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Enter the Details of Student %d\n",i+1);
       printf("Initially please Enter Name,USN,Age,and Semester only");
       scanf("%s%s%d%d",student.name,student.usn,&student.age,&student.sem);
       student.marks=0; 
       if(student.name[0]>90)
       {
            printf("Oops!Error!!\nWrite the first letter of the Name in Capitals");
            exit(0);
       }
       if(student.marks>0)
       {
         printf("Invalid.Please enter Marks as Zero initially\n");
         exit(0);
       }
      first=insert_front(first,student);
    }
    ClassesInitialization(first);
    printf("Displaying the Unsorted list of Students\n");
    display(first);
    printf("\n\nflag1\n\n");
    sort(first);
    printf("Displaying the Sorted list of Students\n");
    display(first);
    printf("\nAttendance of Students:");
    Attendence_Calculation(first);
    printf("\n\nMarks Calculation\n");
    Calculate_Marks(first);
    file_display(first);
    read_file(first);
    return 0;
}