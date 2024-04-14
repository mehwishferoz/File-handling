#include<stdio.h>
int main()
{
    int num;
    char ch;
    float pi;
    char name[30];

    FILE *fp;
    fp = fopen("formatted.txt", "r");
    fscanf(fp,"%d %c %f %s", &num, &ch, &pi, &name);
    printf("%d %c %f %s", num, ch, pi, name);

    fclose(fp);

    return 0;
}