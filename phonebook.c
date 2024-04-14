#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define debug printf("debug");
struct node
{
    char name[30];
    char l_name[30];
    char p_num[13];
    char add[100];
    char email[50];
    char n_id[25];
    struct node *next;
    struct node *prev;
};
struct node *start_node;
struct node *end_node;
struct node *root;
int c_node = 0;
void root_finder() /*a function to set a root node.the middle node of all node is the root node*/
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    root = (struct node *)malloc(sizeof(struct node));
    struct node *samp = (struct node *)malloc(sizeof(struct node));
    int cnt = 0;
    temp = start_node;
    while (temp->next != NULL && cnt != c_node / 2)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->prev != NULL)
    {
        samp = temp->prev;
    }
    if (strcmp(samp->name, temp->name) == 0)
    {
        while (strcmp(samp->name, temp->name) == 0)
        {
            if (samp->prev != NULL)
            {
                samp = samp->prev;
            }
            else
            {
                break;
            }
        }
        temp = samp->next;
    }
    root = temp;
}
int str_cmp(char *a, char *n) /*a string compare function which only compares the minimum number of character of both pointers */
{
    char j[30];
    int c = 0, i;
    i = strlen(a);
    while (c != i)
    {

        j[c] = *n++;
        c++;
    }
    j[c] = '\0';

    return strcmp(a, j);
}
void push(char *n, char *ln, char *p, char *a, char *e, char *i) /*for creating the first node of a double link list*/
{
    start_node = (struct node *)malloc(sizeof(struct node));
    end_node = (struct node *)malloc(sizeof(struct node));
    root = (struct node *)malloc(sizeof(struct node));
    if (start_node == NULL || end_node == NULL)
        return;
    else
    {

        strcpy(start_node->name, n);
        strcpy(start_node->l_name, ln);
        strcpy(start_node->p_num, p);
        strcpy(start_node->add, a);
        strcpy(start_node->email, e);
        strcpy(start_node->n_id, i);
        start_node->next = NULL;
        start_node->prev = NULL;
        end_node = start_node;
        root = start_node;
    }
}
int b_search(char *n) /*this is a search function for finding multiple records with same characters*/
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    temp = root;
    int a = 0;
    if (str_cmp(n, root->name) >= 0)
    {
        for (;;)
        {
            if (str_cmp(n, temp->name) < 0)
            {
                break;
            }
            else if (str_cmp(n, temp->name) > 0)
            {
                if (temp->next == NULL)
                {
                    break;
                }
                else if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            }
            else if (str_cmp(n, temp->name) == 0)
            {
                a++;
                printf("NAME: %s ", temp->name);
                printf("%s\n", temp->l_name);
                if (temp->next == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
    else if (str_cmp(n, root->name) < 0)
    {
        for (;;)
        {
            if (str_cmp(n, temp->name) > 0)
            {
                break;
            }
            else if (str_cmp(n, temp->name) < 0)
            {
                if (temp->prev == NULL)
                {
                    break;
                }
                else if (temp->prev != NULL)
                {
                    temp = temp->prev;
                }
            }
            else if (str_cmp(n, temp->name) == 0)
            {
                a++;
                printf("NAME: %s ", temp->name);
                printf("%s\n", temp->l_name);
                if (temp->prev == NULL)
                    break;
                temp = temp->prev;
            }
        }
    }
    return a;
}
void bst_append(char *n, char *ln, char *p, char *a, char *e, char *i) /*a function for adding records in a sorted way*/
{
    struct node *n_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    temp = root;
    strcpy(n_node->name, n);
    strcpy(n_node->l_name, ln);
    strcpy(n_node->p_num, p);
    strcpy(n_node->add, a);
    strcpy(n_node->email, e);
    strcpy(n_node->n_id, i);
    if (strcmp(n_node->name, root->name) >= 0)
    {
        for (;;)
        {
            if (strcmp(n_node->name, temp->name) < 0)
            {
                temp1 = temp->prev;
                temp1->next = n_node;
                temp->prev = n_node;
                n_node->prev = temp1;
                n_node->next = temp;
                break;
            }
            else if (strcmp(n_node->name, temp->name) >= 0)
            {
                if (temp->next == NULL)
                {
                    temp->next = n_node;
                    n_node->prev = temp;
                    n_node->next = NULL;
                    end_node = n_node;
                    break;
                }
                else if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            }
        }
    }
    else if (strcmp(n_node->name, root->name) < 0)
    {
        for (;;)
        {
            if (strcmp(n_node->name, temp->name) >= 0)
            {
                temp1 = temp->next;
                temp1->prev = n_node;
                temp->next = n_node;
                n_node->prev = temp;
                n_node->next = temp1;
                break;
            }
            else if (strcmp(n_node->name, temp->name) < 0)
            {
                if (temp->prev == NULL)
                {
                    temp->prev = n_node;
                    n_node->next = temp;
                    n_node->prev = NULL;
                    start_node = n_node;
                    break;
                }
                else if (temp->prev != NULL)
                {
                    temp = temp->prev;
                }
            }
        }
    }
}

void bst_search(char *n) /*This function is for searching a specific node*/
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    struct node *samp = (struct node *)malloc(sizeof(struct node));
    temp = root;
    int a;
    if (strcmp(n, root->name) >= 0)
    {
        for (;;)
        {
            if (strcmp(n, temp->name) < 0)
            {
                printf("no records\n");
                break;
            }
            else if (strcmp(n, temp->name) > 0)
            {
                if (temp->next == NULL)
                {
                    printf("no records\n");
                    break;
                }
                else if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            }
            else if (strcmp(n, temp->name) == 0)
            {
                if (temp->next != NULL)
                {
                    samp = temp->next;
                }
                if (strcmp(samp->name, temp->name) == 0)
                {
                    char ca[30];
                    printf("THERE ARE SEVERAL RECORDS IN THIS NAME.\n");
                    b_search(temp->name);
                    printf("ENTER THE LAST NAME:");
                    scanf("%s", ca);
                    while (strcmp(samp->name, temp->name) == 0)
                    {
                        if (strcmp(samp->l_name, ca) == 0)
                        {
                            temp = samp;
                            break;
                        }
                        else if (strcmp(temp->l_name, ca) == 0)
                        {
                            break;
                        }
                        else
                        {
                            if (samp->next != NULL)
                            {
                                samp = samp->next;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }

                printf("NAME: %s ", temp->name);
                printf("%s\n", temp->l_name);
                printf("PHONENUMBER: %s\n", temp->p_num);
                printf("ADDRESS: %s\n", temp->add);
                printf("EMAIL: %s\n", temp->email);
                printf("NATIONAL ID: %s\n", temp->n_id);
                printf("1.DELETE. 2.EDIT 3.GO BACK\n");
                scanf("%d", &a);
                if (a == 1) /*This is the delete part of the function for the right part of root node*/
                {
                    if (temp->next == NULL)
                    {
                        temp1 = temp->prev;
                        temp1->next = NULL;
                        free(temp);
                        end_node = temp1;
                    }
                    else
                    {
                        temp1 = temp->prev;
                        temp2 = temp->next;
                        temp1->next = temp2;
                        temp2->prev = temp1;
                        free(temp);
                    }
                }
                else if (a == 2) /*this is edit part of the function for the right part of root node*/
                {
                    int i;
                    printf("EDIT IN 1.LAST NAME. 2.PHONE NUMBER. 3.ADRESS. 4.EMAIL. 5.NATIONAL ID. 6.THE WHOLE RECORD(without first name).");
                    scanf("%d", &i);
                    if (i == 1)
                    {
                        printf("ENTER THE LAST NAME:");
                        scanf("%s", temp->l_name);
                    }
                    else if (i == 2)
                    {
                        printf("ENTER THE PHONE NUMBER:");
                        scanf("%s", temp->p_num);
                    }
                    else if (i == 3)
                    {
                        printf("ENTER THE ADDRESS(no space):");
                        scanf("%s", temp->add);
                    }
                    else if (i == 4)
                    {
                        printf("ENTER THE EMAIL:");
                        scanf("%s", temp->email);
                    }
                    else if (i == 5)
                    {
                        printf("ENTER THE NATIONAL ID:");
                        scanf("%s", temp->n_id);
                    }
                    else if (i == 6)
                    {
                        printf("ENTER THE LAST NAME:");
                        scanf("%s", temp->l_name);
                        printf("ENTER THE PHONE NUMBER:");
                        scanf("%s", temp->p_num);
                        printf("ENTER THE ADDRESS(no space):");
                        scanf("%s", temp->add);
                        printf("ENTER THE EMAIL:");
                        scanf("%s", temp->email);
                        printf("ENTER THE NATIONAL ID:");
                        scanf("%s", temp->n_id);
                    }
                }
                else if (a == 3)
                    break;
            }
        }
    }
    else if (strcmp(n, root->name) < 0)
    {
        for (;;)
        {
            if (strcmp(n, temp->name) > 0)
            {
                printf("no records\n");
                break;
            }
            else if (strcmp(n, temp->name) < 0)
            {
                if (temp->prev == NULL)
                {
                    printf("no records\n");
                    break;
                }
                else if (temp->prev != NULL)
                {
                    temp = temp->prev;
                }
            }
            else if (strcmp(n, temp->name) == 0)
            {
                if (temp->prev != NULL)
                {
                    samp = temp->prev;
                }
                if (strcmp(samp->name, temp->name) == 0)
                {
                    char ca[30];
                    printf("THERE ARE SEVERAL RECORDS IN THIS NAME\n");
                    b_search(temp->name);
                    printf("ENTER THE LAST NAME:");
                    scanf("%s", ca);
                    while (strcmp(samp->name, temp->name) == 0)
                    {
                        if (strcmp(samp->l_name, ca) == 0)
                        {
                            temp = samp;
                            break;
                        }
                        else if (strcmp(temp->l_name, ca) == 0)
                        {
                            break;
                        }
                        else
                        {
                            if (samp->prev != NULL)
                            {
                                samp = samp->prev;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                printf("NAME: %s ", temp->name);
                printf("%s\n", temp->l_name);
                printf("PHONENUMBER:%s\n", temp->p_num);
                printf("ADDRESS: %s\n", temp->add);
                printf("EMAIL: %s\n", temp->email);
                printf("NATIONAL ID: %s\n", temp->n_id);
                printf("1.DELETE. 2.EDIT 3.GO BACK\n");
                scanf("%d", &a);
                if (a == 1) /*This is the delete part of the function for the left part of root node*/
                {
                    if (temp->prev == NULL)
                    {
                        temp1 = temp->next;
                        temp1->prev = NULL;
                        free(temp);
                        start_node = temp1;
                    }
                    else
                    {
                        temp1 = temp->prev;
                        temp2 = temp->next;
                        temp1->next = temp2;
                        temp2->prev = temp1;
                        free(temp);
                    }
                }
                else if (a == 2) /*this is edit part of the function for the left part of root node*/
                {
                    int i;
                    printf("EDIT IN 1.LAST NAME. 2.PHONE NUMBER. 3.ADRESS. 4.EMAIL. 5.NATIONAL ID. 6.THE WHOLE RECORD(without first name).");
                    scanf("%d", &i);
                    if (i == 1)
                    {
                        printf("ENTER THE LAST NAME:");
                        scanf("%s", temp->l_name);
                    }
                    else if (i == 2)
                    {
                        printf("ENTER THE PHONE NUMBER:");
                        scanf("%s", temp->p_num);
                    }
                    else if (i == 3)
                    {
                        printf("ENTER THE ADDRESS(no space):");
                        scanf("%s", temp->add);
                    }
                    else if (i == 4)
                    {
                        printf("ENTER THE EMAIL:");
                        scanf("%s", temp->email);
                    }
                    else if (i == 5)
                    {
                        printf("ENTER THE NATIONAL ID:");
                        scanf("%s", temp->n_id);
                    }
                    else if (i == 6)
                    {
                        printf("ENTER THE LAST NAME:");
                        scanf("%s", temp->l_name);
                        printf("ENTER THE PHONE NUMBER:");
                        scanf("%s", temp->p_num);
                        printf("ENTER THE ADDRESS(no space):");
                        scanf("%s", temp->add);
                        printf("ENTER THE EMAIL:");
                        scanf("%s", temp->email);
                        printf("ENTER THE NATIONAL ID:");
                        scanf("%s", temp->n_id);
                    }
                }
                else if (a == 3)
                    break;
            }
        }
    }
}

void display() /*showing all the records*/
{
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    temp1 = start_node;
    while (temp1->next != NULL)
    {
        printf("NAME: %s ", temp1->name);
        printf("%s\n", temp1->l_name);
        temp1 = temp1->next;
    }
    printf("NAME: %s ", temp1->name);
    printf("%s\n", temp1->l_name);
}

void saveprogram() /*for saving all the records in the file system*/
{
    FILE *fp1;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = start_node;
    if ((fp1 = fopen("records.txt", "w")) == NULL)
    {
        printf("records in name file");
        exit(1);
    }

    while (temp->next != NULL)
    {
        fprintf(fp1, "\n%s %s %s %s %s %s", temp->name, temp->l_name, temp->p_num, temp->add, temp->email, temp->n_id);
        temp = temp->next;
    }
    fprintf(fp1, "\n%s %s %s %s %s %s", temp->name, temp->l_name, temp->p_num, temp->add, temp->email, temp->n_id);
    fclose(fp1);
}

void loadprogram() /*loading all the records into the link list from the file system*/
{
    FILE *fp1;
    int cnt = 0;
    char na[30], pa[13], aa[100], ea[50], ni[25], ln[30];

    if ((fp1 = fopen("records.txt", "r")) == NULL)
    {
        printf("records in name file");
        exit(1);
    }
    do
    {
        fscanf(fp1, "%s%s%s%s%s%s", na, ln, pa, aa, ea, ni);

        if (cnt == 0)
        {
            start_node = (struct node *)malloc(sizeof(struct node));
            end_node = (struct node *)malloc(sizeof(struct node));
            root = (struct node *)malloc(sizeof(struct node));
            if (start_node == NULL || end_node == NULL)
                return;
            else
            {

                strcpy(start_node->name, na);
                strcpy(start_node->l_name, ln);
                strcpy(start_node->p_num, pa);
                strcpy(start_node->add, aa);
                strcpy(start_node->email, ea);
                strcpy(start_node->n_id, ni);
                start_node->next = NULL;
                start_node->prev = NULL;
                end_node = start_node;
                root = start_node;
            }
            cnt++;
        }
        else
        {
            struct node *n_node = (struct node *)malloc(sizeof(struct node));
            strcpy(n_node->name, na);
            strcpy(n_node->l_name, ln);
            strcpy(n_node->p_num, pa);
            strcpy(n_node->add, aa);
            strcpy(n_node->email, ea);
            strcpy(n_node->n_id, ni);
            n_node->next = NULL;
            n_node->prev = end_node;
            end_node->next = n_node;
            end_node = n_node;
        }
        c_node++;
    } while (!feof(fp1));

    fclose(fp1);
}
int main()
{
    /*it is the interface*/
    loadprogram();
    root_finder();
    char na[30], pa[13], aa[100], ea[50], ni[25], ln[30];
    int a;
    printf("\t\t\t\t\tPHONE BOOK APPLICATION\n");
    printf("=======================================================================================================================\n");
    for (;;)
    {

        printf("1.ADD A NEW RECORD.\n2.SEARCH.\n3.FIND A RECORD.\n4.SHOW ALL RECORDS.\n5.SAVE AND EXIT.\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("ENTER YOUR FIRST NAME:");
            scanf("%s", na);
            printf("ENTER YOUR LAST NAME:");
            scanf("%s", ln);
            printf("ENTER YOUR PHONE NUMBER:");
            scanf("%s", pa);
            printf("ENTER YOUR ADDRESS(NO space):");
            scanf("%s", aa);
            printf("ENTER YOUR EMAIL ADDRESS:");
            scanf("%s", ea);
            printf("ENTER YOUR NATIONAL ID:");
            scanf("%s", ni);
            if (c_node == 0)
            {
                push(na, ln, pa, aa, ea, ni);
            }
            else
            {
                bst_append(na, ln, pa, aa, ea, ni);
            }
        }
        else if (a == 2)
        {
            int r;
            printf("ENTER THE FIRST NAME FOR SEARCHING:");
            scanf("%s", na);
            r = b_search(na);
            if (r == 0)
            {
                printf("NO RECORDS IN THIS NAME\nTHIS PROGRAM IS CASE SENSITIVE.\n");
            }
        }
        else if (a == 3)
        {
            printf("ENTER THE SPECIFIC NAME:");
            scanf("%s", na);
            bst_search(na);
        }
        else if (a == 4)
        {
            display();
        }
        else if (a == 5)
        {
            saveprogram();
            break;
        }
        printf("=======================================================================================================================\n");
    }

    return 0;
}
