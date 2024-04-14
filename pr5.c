#include<stdio.h>

struct student
{
    int roll_no;
    char name[20];
};

int main()
{
    FILE *fp;
    struct student s[50];
    int n, i;
    fp = fopen("student.txt", "r");
    while(fread(&s, sizeof(struct student),1,fp))
    printf("%d %s\n",s->roll_no,s->name);

    fclose(fp);

    return 0;
}