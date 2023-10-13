#include<stdio.h>
#include <string.h>
struct user
{

	char fullname[50];
	char email[50];
	char pass[50];
    char pass2[50];
	char username[50];
};

void takeinput(char input[50])
{
	fgets(input,50,stdin);
    input[strlen(input)-1]=0;
};

char generatuser(char email[50],char username[50]) 
{
    for (int i = 0; i <= strlen(email); i++)
    {
        if (email[i]=='@')
        {
            break;
        }
        else
        {
            username[i]=email[i];
        }
        
    }
};
int main()
{
    FILE *us;
    int select,userfound=0;
    char userlogin[50],passlogin[50];
    struct user users;
    printf("\n");
    printf("\nWelcome To Our System:\nCreate By : eslam ");
    printf("\n------------------");
    printf("\nPlease select your operation");
    printf("\n------------------");
    printf("\n1-Register");
    printf("\n2-Login");
    printf("\n3-Exit");
    printf("\n------------------");
    printf("\nYour Select : ");
    scanf("%d",&select);
    fgetc(stdin);
    switch (select)
    {
    case 1:
    printf("\n");
    printf("Enter ur FullName :\t");
    takeinput(users.fullname);
    printf("\n");
    printf("Enter ur Email :\t");
    takeinput(users.email);
    printf("\n");    
    printf("Enter ur Pass :");
    takeinput(users.pass);
    printf("\n");
    printf("Confirm ur Pass :");
    takeinput(users.pass2);
    if (!strcmp(users.pass,users.pass2))
    {
        printf("\nMatched Pass");
        generatuser(users.email,users.username);
        us=fopen("Users.dat","a+");
        fwrite(&users,sizeof(struct user),1,us);
        if(fwrite!=0)
        {
            printf("\nUser Regester Done");
            printf("\nYour UseName Is : %s",users.username);
            fclose(us);
        }
        else
        {
            printf("\nSorry Try Again");
        }
    }
    else
    {
        printf("\nNot Matched Pass");
    }
    break;

    case 2:
    printf("Enter ur UserName :\t");
    takeinput(userlogin);
    printf("\n");    
    printf("Enter ur Password :");
    takeinput(passlogin);
    printf("\n");
    us=fopen("Users.dat","r");
    while (fread(&users,sizeof(struct user),1,us))
    {
        if (!strcmp(users.username,userlogin))
        {
            if (!strcmp(users.pass,passlogin))
            {
                printf("!!!!!!!!!! Login Completed !!!!!!!!!!");
                printf("\n");
                printf("Welcome %s",users.fullname);
                printf("\n");
                printf("Username %s",users.username);
                printf("\n");
                printf("Pass %s",users.pass);
                printf("\n");
                printf("Email %s",users.email);
            }
            else
            {
                printf("!!!!!! Error Password !!!!!!");
            }
            userfound=1;
        }
        if (userfound=0)
        {
            printf("Sorry !! Just Create New Account :) ");
        }
        
    }
    fclose(us);
    break;
    case 3:
    printf("Good Bye");
    printf("\n");
    printf("Create By eslam");
    return 0;
    break;
    default:
        break;
    }
    return 0;

}

