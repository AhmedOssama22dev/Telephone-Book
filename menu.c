#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 100
void main_menu()
    {

        load();
        int final_choice;
        while(1)
        {
            printf("\t\t\tWelcome to your PhoneBook\nPlease make a choice :) :\n=================\n");
        printf("1) Search for a contact\n2)Add new contact\n3)Delete contact\n4)Modify contact\n5)Save changes\n6)sort contacts\n7)Display all contact\n8)Exit program\n\n");
        printf("Enter your choice:\n");scanf("%d",&final_choice);if (final_choice >= 0x41 && final_choice <= 0x7A) {printf("you entered a letter");scanf("%d",&final_choice);}

             if(final_choice==1)
        {
        query(contacts,key,count);
        printf("Press any key to continue........\n");
        getch(); //for windows users ,getchar() for smth called  windows turbo C...
        }
        else if(final_choice==2)
        {
            add_new_contact();
        }
        else if(final_choice==3)
        {
           deleterec();
            printf("Press any key to continue........\n");
            getch();
        }


       else if(final_choice==4)
        {

            sort(ptr);
             printf("Press any key to continue........\n");
             getch();

        }
        else if(final_choice==4)
        {
           modify();
             printf("Press any key to continue........\n");
             getch();
        }
        else if(final_choice==5)
        {
            //save_file();
        else if(final_choice==6)
        {
            sort(ptr2);
            printf("Press any key to continue........\n");
            getch();
        }
        else if(final_choice==7)
        {
            print_contacts();
            printf("Press any key to continue........\n");
            getch();
        }
        else if(final_choice==8)
        {
            break;
        }

    }
        }
    /*printf("\t\t\tWelcome to your PhoneBook\nPlease make a choice :) :\n=================\n");
        printf("1) Search for a contact\n2)Add new contact\n3)Delete contact\n4)Modify contact\n5)Save changes\n6)sort contacts\n7)Display all contact\n8)Exit program\n\n");
        printf("Enter your choice:\n");scanf("%d",&final_choice);if (final_choice >= 0x41 && final_choice <= 0x7A) {printf("you entered a letter");scanf("%d",&final_choice);}
        switch(final_choice)

            case 1:
            query();
            printf("Press any key to continue........\n");
            getch();
            break;
            case 2:
            add_new_contact();
            printf("Press any key to continue........\n");
            getch(); //for windows users ,getchar() for smth called  windows turbo C...
            break;
            case 3:
            deleterec();
            printf("Press any key to continue........\n");
            getch();
            break;
        case 4:
            modify();
            printf("Press any key to continue........\n");
            getch();
            break;
       /* case 5:
           save();
            printf("Press any key to continue........\n");
            getch();
            break;*/
