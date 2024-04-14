#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char song[30];
    char artist[30];
    char language[20];
    int likes;
    int year;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL,*temp=NULL;

struct node  *getnode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the name of the song: ");
    fflush(stdin);
    scanf("%[^\n]s",newnode->song);
    printf("\nEnter the name of the artist: ");
    fflush(stdin);
    scanf("%[^\n]s",newnode->artist);
    printf("\nEnter the language of the song: ");
    fflush(stdin);
    scanf("%[^\n]s",newnode->language);
    printf("\nEnter the likes of the song: ");
    scanf("%d",&newnode->likes);
    printf("\nEnter the year of release of the song: ");
    scanf("%d",&newnode->year);

    newnode->next=newnode;
    newnode->prev=newnode;

    return newnode;
}

void insert_song()
{
    if(head==NULL)
    {
        head=getnode();
    }
    else
    {
        struct node *newnode=getnode();
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        head->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void display()
{
    struct node *newnode=NULL;

    char song[30];
    char artist[30];
    char language[20];
    int likes;
    int year;

    temp=head;

    if(head==NULL)
    {
        printf("\nNo songs in the playlist");
        return;
    }
    else
    {
        do
        {
        printf("Song : %s\n",temp->song);
        printf("Artist : %s\n",temp->artist);
        printf("Language : %s\n",temp->language);
        printf("Likes : %d\n",temp->likes);
        printf("Year : %d\n",temp->year);
        temp=temp->next;
        }while(temp!=head);
    }
}

void writeData()
{
    if(head)
    {
    FILE *fp = fopen("Student.txt", "w");
    temp = head;
    do
    {
        fprintf(fp,"\n%s %s %s %d %d",temp->song, temp->artist, temp->language, temp->likes, temp->year);
        temp = temp->next;
    } while (temp!=head);
    fclose(fp);
    printf("Linked list data is written to the File . . .\n");
    }
    else 
    printf("No songs in the playlist");
}

void readData()
{
    char s[30], a[30], l[20];
    int x, y;
    FILE *fp = fopen("Student.txt", "r");
    do
    {
    fscanf(fp,"%s%s%s%d%d",s,a,l,&x,&y);
    
    if(head==NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->song,s);
        strcpy(head->artist,a);
        strcpy(head->language,l);
        head->likes = x;
        head->year = y;
        head->next = head;
        head->prev = head;
    }
    else
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        strcpy(temp->song,s);
        strcpy(temp->artist,a);
        strcpy(temp->language,l);
        temp->likes = x;
        temp->year = y;
        newnode->next=head;
        head->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
    } while (!feof(fp));
    fclose(fp);
}

int main()
{

    int choice;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Exit\n4.Write LL into file\n5.Read LL from file");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert_song();
            break;

        case 2:
            display();
            break;


        case 4:
            writeData();
            break;

        case 3:
            exit(0);

        case 5:
            readData();
            break;
        }
    }
    return 0;
}