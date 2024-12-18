#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *prev;
    struct node *next;
    char song[30];
    char artist[30];
    char language[20];
    int likes;
    int year;
};

struct node *head=NULL,*temp=NULL, *curr_song=NULL, *temp1=NULL, *temp2=NULL, *tail=NULL;

void writeData()
{
    if(head)
    {
        FILE *fp = fopen("Details.txt", "w");
        temp = head;
        do
        {
            fprintf(fp,"\n%s %s %s %d %d",temp->song, temp->artist, temp->language, temp->likes, temp->year);
            temp = temp->next;
        }
        while (temp!=head);
        fclose(fp);
        //printf("Linked list data is written to the File . . .\n");
    }
    else
    {
        remove("Details.txt");
    }
}

void readData()
{
    char s[30], a[30], l[20];
    int x, y;
    FILE *fp=NULL;

    fp=fopen("Details.txt","r");

    if(fp==NULL)
    {
        printf("\nThe playlist is empty");
    }
    else
    {

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
                strcpy(newnode->song,s);
                strcpy(newnode->artist,a);
                strcpy(newnode->language,l);
                newnode->likes = x;
                newnode->year = y;
                newnode->next=head;
                head->prev=newnode;
                temp->next=newnode;
                newnode->prev=temp;
            }
        }
        while (!feof(fp));

        fclose(fp);
    }
}

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
    writeData();
}

void delete_song()
{
    int d=0;
    char song[30];
    printf("\nEnter the name of the song you want to delete : ");
    fflush(stdin);
    scanf("%[^\n]s",song);

    if(head==NULL)
    {
        printf("\nThe playlist is empty");
    }
    else if(head->next == head)
    {
        temp=head;
        if(!strcasecmp(song,temp->song))
        {
            printf("\n%s deleted",song);
            d=1;

            if(curr_song==temp)
            {
                curr_song = NULL;
            }

            head=NULL;
            free(temp);
        }
    }
    else
    {

        if(!strcasecmp(head->song,song))
        {
            temp=head;

            if(curr_song==temp)
            {
                curr_song=NULL;
            }
            temp1=temp->prev;
            temp2=temp->next;

            temp1->next=temp2;
            temp2->prev=temp1;
            temp->next=NULL;
            temp->prev=NULL;

            temp=NULL;
            free(temp);

            head=temp2;

            printf("\n%s deleted",song);
            d=1;
        }

        else
        {
            temp=head->next;
            do
            {
                if(!strcasecmp(temp->song,song))
                {
                    if(curr_song==temp)
                    {
                        curr_song=NULL;
                    }
                    temp1=temp->prev;
                    temp2=temp->next;

                    temp1->next=temp2;
                    temp2->prev=temp1;
                    temp->next=NULL;
                    temp->prev=NULL;

                    temp=NULL;
                    free(temp);

                    printf("\n%s deleted",song);
                    d=1;
                    break;
                }

                temp=temp->next;

            }
            while(temp!=head);
        }
    }
    writeData();
}


void display()
{
    if(head==NULL)
    {
        printf("\nThe playlist is empty");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            printf("Song : %s\n",temp->song);
            printf("Artist : %s\n",temp->artist);
            printf("Language : %s\n",temp->language);
            printf("Likes : %d\n",temp->likes);
            printf("Year : %d\n\n",temp->year);
            temp=temp->next;
        }
        printf("Song : %s\n",temp->song);
        printf("Artist : %s\n",temp->artist);
        printf("Language : %s\n",temp->language);
        printf("Likes : %d\n",temp->likes);
        printf("Year : %d\n\n",temp->year);
    }
}

struct node *play_first_song()
{
    if(head==NULL)
    {
        printf("\nThe playlist is empty");
        return NULL;
    }
    else
    {
        temp = head;
        printf("\nNow Playing : %s",temp->song);
        return temp;
    }
}

struct node *play_last_song()
{
    if(head==NULL)
    {
        printf("\nThe playlist is empty");
        return NULL;
    }
    else
    {
        temp = head;
        printf("\nNow Playing : %s",(temp->prev)->song);
        return (temp->prev);
    }
}

void display_by_language()
{
    char language[20];
    printf("\nEnter the language : ");
    fflush(stdin);
    scanf("%[^\n]s",language);

    if(head==NULL)
    {
        printf("\nThe playlist is empty");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            if(!strcasecmp(language,temp->language))
            {
                printf("\n%s",temp->song);
            }
            temp=temp->next;
        }
        if(!strcasecmp(language,temp->language))
        {
            printf("\n%s",temp->song);
        }
    }
}

struct node *play_prev(struct node *curr_song)
{
    if(head==NULL)
    {
        printf("\nThe playlist is empty");
        return NULL;
    }
    if(curr_song==NULL)
    {
        printf("\nPlay a song first");
        return NULL;
    }
    else
    {
        temp=head;
        while(1)
        {
            if(!strcasecmp(temp->song,curr_song->song))
            {
                printf("\nNow Playing : %s",(temp->prev)->song);
                break;
            }
            temp=temp->next;
        }
        return (temp->prev);
    }
}

struct node *play_next(struct node *curr_song)
{
    if(head==NULL)
    {
        printf("\nThe playlist is empty");
        return NULL;
    }
    if(curr_song==NULL)
    {
        printf("\nPlay a song first");
        return NULL;
    }
    else
    {
        temp=head;
        while(1)
        {
            if(!strcasecmp(temp->song,curr_song->song))
            {
                printf("\nNow Playing : %s",(temp->next)->song);
                break;
            }
            temp=temp->next;
        }
        return (temp->next);
    }
}

int count()
{
    int c=0;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            c++;
            temp=temp->next;
        }
        c++;
        return c;
    }
}

struct node *search_and_play()
{
    int found=0;
    char song[30];
    printf("\nEnter the name of the song you want to play : ");
    fflush(stdin);
    scanf("%[^\n]s",song);

    if(head==NULL)
    {
        printf("\nThe playlist is empty");
        return NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            if(!strcasecmp(song,temp->song))
            {
                printf("\nNow Playing : %s",temp->song);
                found = 1;
                break;
            }
            temp=temp->next;
        }
        if(!found)
        {
            if(!strcasecmp(song,temp->song))
            {
                printf("\nNow Playing : %s",temp->song);
                found = 1;
            }
        }

        if(!found)
        {
            printf("\nSong not found in the playlist");
            return curr_song;

        }
        else
        {
            return temp;
        }

    }
}

int main()
{

    readData();

    int choice;
    while(1)
    {
        printf("\n1.Add song to the playlist\n2.Display all songs of the playlist\n3.Play first song of playlist\n4.Play last song of playlist\n5.Display songs by language\n6.Play previous song\n7.Play next song\n8.Count the number of songs in the playlist\n9.Search a song and play\n10.Delete a song from the playlist\n11.Exit");
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

        case 3:
            curr_song = play_first_song();
            break;

        case 4:
            curr_song = play_last_song();
            break;

        case 5:
            display_by_language();
            break;

        case 6:
            curr_song = play_prev(curr_song);
            break;

        case 7:
            curr_song = play_next(curr_song);
            break;

        case 8:
            printf("%d",count());
            break;

        case 9:
            curr_song = search_and_play();
            break;

        case 10:
            delete_song();
            break;

        case 11:
            exit(0);
        }
    }
    return 0;
}

