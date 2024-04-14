#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int rno;
    char name[20];
    struct subject
    {
        int scode;
        char sname[20];
        int mark;
    }sub[3];
    int total;
    float per;
}student;

void create()
{
    student *s;
    FILE *fp;
    fp = fopen("mystudents.txt","w");
    int n, i, j;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));

    for(i=0;i<n;i++)
    {
        s[i].total=0;
        s[i].per=0;
        printf("Enter the roll number: ");
        scanf("%d", &s[i].rno);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name);
        for(j=0;j<3;j++)
        {
            printf("Enter the marks of subject%d: ", j+1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}

void append()
{
    //same as that of create
    student *s;
    FILE *fp;
    fp = fopen("mystudents.txt","a");
    int n, i, j;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));

    for(i=0;i<n;i++)
    {
        s[i].total=0;
        s[i].per=0;
        printf("Enter the roll number: ");
        scanf("%d", &s[i].rno);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name);
        for(j=0;j<3;j++)
        {
            printf("Enter the marks of subject%d: ", j+1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
}

void display()
{
    student s1;
    FILE *fp;
    fp = fopen("mystudents.txt", "r");
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("%d %s ",s1.rno,s1.name);
        for (int i = 0; i < 3; i++)
        {
            printf("%d ",s1.sub[i].mark);
        }
        printf("%d %.2f\n",s1.total,s1.per);
    }
    fclose(fp);
}

void search()
{
    //same as that of display
    student s1;
    int r,found=0;
    FILE *fp;
    fp = fopen("mystudents.txt", "r");
    printf("Enter roll no. to be searched: ");
    scanf("%d", &r);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno == r)
        {
        found=1;
        printf("%d %s ",s1.rno,s1.name);
        for (int i = 0; i < 3; i++)
        {
            printf("%d ",s1.sub[i].mark);
        }
        printf("%d %.2f\n",s1.total,s1.per);
        }
    }
    if(!found)
    printf("Record not found :(\n");
    fclose(fp);
}

void update()
{
    //same as that of search
    student s1;
    int r,found=0;
    FILE *fp, *fp1;
    fp = fopen("mystudents.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("Enter roll no. to be searched: ");
    scanf("%d", &r);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.rno == r)
        {
        found=1;
        s1.total=0;
        s1.per=0;
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s1.name);
        for(int j=0;j<3;j++)
        {
            printf("Enter the marks of subject%d: ", j+1);
            scanf("%d", &s1.sub[j].mark);
            s1.total += s1.sub[j].mark;
        }
        s1.per = s1.total / 3.0;
        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp = fopen("temp.txt","r");
        fp = fopen("mystudents.txt", "w");

        while (fread(&s1,sizeof(student),1,fp))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }
        
        fclose(fp);
        fclose(fp1);
    }
}

void no_of_records()
{
    student s1;
    FILE *fp;
    fp = fopen("mystudents.txt", "r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    printf("No. of records: %d\n", n);
    fclose(fp);
}

int main()
{
    int ch;
    while(1)
    {
        printf("0.EXIT\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.APPEND\n");
        printf("4.NO. OF RECORDS\n");
        printf("5.SEARCH\n");
        printf("6.UPDATE\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 0:
            exit(0);
            break;
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3: 
            append();
            break;
            case 4:
            no_of_records();
            break;
            case 5:
            search();
            break;
            case 6:
            update();
            break;
            default:
            printf("Invalid input\n");
        }
    }
    return 0;
}