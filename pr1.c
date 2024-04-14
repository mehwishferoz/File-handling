#include<stdio.h>
#include<ctype.h>
int main()
{
    FILE *fp, *newF;
    char ch;
    fp = fopen("abc.txt","r");
    newF = fopen("new.txt", "w+");
    while((ch=getc(fp))!=-1)
        fputc(toupper(ch),newF);
    rewind(newF);
    while((ch=fgetc(newF))!=-1)
        printf("%c", ch);


    // ch=getchar();
    // fputc(ch,fp);
    // rewind(fp);
    // printf("%c",fgetc(fp));

    // while((ch=getchar())!='~')
    // {
    //     fputc(ch,fp);
    // }
    // rewind(fp);
    // while((ch=fgetc(fp))!=-1)
    // {
    //     printf("%c", ch);
    // }



    fclose(fp);
    return 0;
}