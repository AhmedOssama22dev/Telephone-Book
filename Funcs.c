#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Phonebook_dec.h"


/*Main program functions*/
//1) Load function /*Load contacts from .txt file*/
void load(){
FILE *fp;   fp=fopen("phonebook.txt","r");
if (fp != NULL)
{
  printf("contacts have been loaded\n\n\n");
  while(!feof(fp))
  {
     fscanf(fp,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%s",contacts[count].last_name,\
    contacts[count].first_name,&contacts[count].day_of_birth,&contacts[count].month_of_birth,\
    &contacts[count].year_of_birth,contacts[count].street_address,contacts[count].email,contacts[count].phone_number);
    count++;
    fscanf(fp,"\n");
  }
}
else
    {
        printf("File not found\n");
    }
fclose(fp);
}
void query()
{
    //Search by last name only :
    char last[max_size];
    int found=0;
    int i;
    int k;
    int n=1;
    printf("Enter contact's last name:\n");
    scanf("%s", last);
    for(i=0;i<count;i++){
    if(strcasecmp(contacts[i].last_name,last)==0){
        n++;
    found=1;
               printf("Contact number : %d\nLast name:%s\nFirst name:%s\nDate of birth:%d/%d/%d\nE-mail:%s\nStreet Address:%s\nMobile:%s",i+1,contacts[i].last_name,contacts[i].first_name,contacts[i].day_of_birth,contacts[i].month_of_birth,contacts[i].year_of_birth,contacts[i].email,contacts[i].street_address,contacts[i].phone_number);


               }
    }
    if(found){printf("Found\n");}else{printf("Not found");}


}
//Multi search:
void multi_query()
{
    char last[max_size]; char first[max_size];
    int found=0;
    int i;
    int k;
    int n=1;
    printf("Enter contact's last name:\n");
    scanf("%s", last);
    printf("Enter contact's first name:\n");
    scanf("%s", first);
    for(i=0;i<count;i++){
    if(strcasecmp(contacts[i].last_name,last)==0&&strcasecmp(contacts[i].first_name,first)==0){
        n++;
    found=1;
               printf("Contact number : %d\nLast name:%s\nFirst name:%s\nDate of birth:%d/%d/%d\nE-mail:%s\nStreet Address:%s\nMobile:%s\n",i+1,contacts[i].last_name,contacts[i].first_name,contacts[i].day_of_birth,contacts[i].month_of_birth,contacts[i].year_of_birth,contacts[i].email,contacts[i].street_address,contacts[i].phone_number);


               }
    }
    if(found){printf("Contact Found\n");}else{printf("Contact not  found\n");}
}
//3)Adding new contact
void add_new_contact(){
printf("Please enter last name:");
scanf("%s",contacts[count].last_name);
printf("Please enter first name:");
scanf("%s",contacts[count].first_name);
printf("Please enter day of birth:");
scanf("%d",&contacts[count].day_of_birth);
printf("Please enter month of birth:");
scanf("%d",&contacts[count].month_of_birth);
printf("Please enter year of birth:");
scanf("%d",&contacts[count].year_of_birth);
printf("Please enter street address:");
scanf("%s",contacts[count].street_address);
printf("Please enter email:");
scanf("%s",contacts[count].email);
printf("Please phone number:");
scanf("%s",contacts[count].phone_number);
count++;
printf("Contact had been added successfully.\n\n");
}

//4)Delete a contact
void deleterec(){
char first[max_size];
char last[max_size];
int k=0;
printf("Enter the contact's first name:");
scanf("%s", first);
printf("Enter the contact's last name:");
scanf("%s", last);
int i;
int found=0;
for(i=0;i<count;i++){
        if(strcasecmp(last,contacts[i].last_name)==0&&strcasecmp(first,contacts[i].first_name)==0){
            found=1;
            printf("\n(%d)\nLast name:%s\nFirst name:%s\nDate of birth:%d/%d/%d\nE-mail:%s\nStreet Address:%s\nMobile:%s",i,contacts[i].last_name,contacts[i].first_name,contacts[i].day_of_birth,contacts[i].month_of_birth,
                   contacts[i].year_of_birth,contacts[i].email,contacts[i].street_address,contacts[i].phone_number);

                }

            }
if(!found) printf("\nContact is not found");
if (found){
        printf("\nEnter number of contact you want to delete:");
        scanf("%d", &k);
        for(int j=0;j<count;j++)
        {
            strcpy(contacts[k].first_name,contacts[k+1].first_name);
                    contacts[k].day_of_birth=contacts[k+1].day_of_birth;
                    contacts[k].month_of_birth=contacts[k+1].month_of_birth;
                    contacts[k].year_of_birth=contacts[k+1].year_of_birth;
                    strcpy(contacts[k].street_address,contacts[k+1].street_address);
                    strcpy(contacts[k].email,contacts[k+1].email);
                    strcpy(contacts[k].phone_number,contacts[k+1].phone_number);

        }
        count-=1;


                    printf("\nContact was successfully deleted.");

}
}
//5)Modify a certain contact
void modify(){
    char last[max_size];
    int found=0;
    int i;
    int k;
    int m;
    printf("Enter contact's last name:");
    scanf("%s", last);
    for(i=0;i<count;i++){
    if(strcasecmp(contacts[i].last_name,last)==0){
    found=1;
            printf("\n(%d)\nLast name:%s\nFirst name:%s\nDate of birth:%d/%d/%d\nE-mail:%s\nStreet Address:%s\nMobile:%s",i,contacts[i].last_name,contacts[i].first_name,contacts[i].day_of_birth,contacts[i].month_of_birth,
                   contacts[i].year_of_birth,contacts[i].email,contacts[i].street_address,contacts[i].phone_number);

                }
    }
    if(found){
    printf("\nEnter the index of the contact you want to modify:");
    scanf("%d", &k);
    printf("\nChoose the field of modification:\n1-Last name\n2-First name\n3-Date of birth\n4-Address\n5-Email\n6-Mobile\n");
    scanf("%d", &m);
    switch(m)
    {
    case 1:
        printf("\nEnter last name:");
scanf("%s",contacts[k].last_name);
break;

case 2:
    printf("\nEnter first name:");
scanf("%s",contacts[k].first_name);
break;

case 3:
    printf("\nEnter day of birth:");
scanf("%d",&contacts[k].day_of_birth);
printf("\nEnter month of birth:");
scanf("%d",&contacts[k].month_of_birth);
printf("\nEnter year of birth:");
scanf("%d",&contacts[k].year_of_birth);
break;

case 4:
    printf("\nEnter street address:");
scanf("%s",contacts[k].street_address);
break;

case 5:

printf("\nEnter email:");
scanf("%s",contacts[k].email);
break;

case 6:
    printf("\nEnter phone number:");
scanf("%s",contacts[k].phone_number);
break;


    }
      printf("\nThe contact is modified.\n");}
    else printf("\nContact is not found.");
}
//6)sorting by last name (bubble sort used)
void sort_lastName(contact arr[], int n)
{
    char temp[max_size];
    int temp_DOB;
    // Sorting strings using bubble sort
 for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strcmp(arr[j].last_name, arr[i].last_name) > 0)
            {

            strcpy(temp, arr[j].last_name);
                strcpy(arr[j].last_name, arr[i].last_name);
                strcpy(arr[i].last_name, temp);
                //Replacing first names
                strcpy(temp, arr[j].first_name);
                strcpy(arr[j].first_name, arr[i].first_name);
                strcpy(arr[i].first_name, temp);
                //Replacing Street address
                strcpy(temp, arr[j].street_address);
                strcpy(arr[j].street_address, arr[i].street_address);
                strcpy(arr[i].street_address, temp);
                //Replacing Email
                strcpy(temp, arr[j].email);
                strcpy(arr[j].email, arr[i].email);
                strcpy(arr[i].email, temp);
                //Replacing phone number
                strcpy(temp, arr[j].phone_number);
                strcpy(arr[j].phone_number, arr[i].phone_number);
                strcpy(arr[i].phone_number, temp);
                //Replacing DOB
                    //Day
                temp_DOB = arr[j].day_of_birth;
                arr[j].day_of_birth=arr[i].day_of_birth;
                arr[i].day_of_birth = temp_DOB;
                    //Month
                temp_DOB = arr[j].month_of_birth;
                arr[j].month_of_birth=arr[i].month_of_birth;
                arr[i].month_of_birth = temp_DOB;
                    //Year
                temp_DOB = arr[j].year_of_birth;
                arr[j].year_of_birth=arr[i].year_of_birth;
                arr[i].year_of_birth = temp_DOB;
            }
        }
    }
                    printf("Contacts successfully sorted according to the last name.\n\n");

}
//Sort by date of birth acsendingly
void sort_date_OF_birth(contact arr[], int n)
{
    char temp2[max_size];int temp2_DOB;

    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (arr[i].year_of_birth>arr[j].year_of_birth)
            {
                strcpy(temp2, arr[j].last_name);
                strcpy(arr[j].last_name, arr[i].last_name);
                strcpy(arr[i].last_name, temp2);
                //Replacing first names
                strcpy(temp2, arr[j].first_name);
                strcpy(arr[j].first_name, arr[i].first_name);
                strcpy(arr[i].first_name, temp2);
                //Replacing Street address
                strcpy(temp2, arr[j].street_address);
                strcpy(arr[j].street_address, arr[i].street_address);
                strcpy(arr[i].street_address, temp2);
                //Replacing Email
                strcpy(temp2, arr[j].email);
                strcpy(arr[j].email, arr[i].email);
                strcpy(arr[i].email, temp2);
                //Replacing phone number
                strcpy(temp2, arr[j].phone_number);
                strcpy(arr[j].phone_number, arr[i].phone_number);
                strcpy(arr[i].phone_number, temp2);
                //Replacing DOB
                    //Day
                temp2_DOB = arr[j].day_of_birth;
                arr[j].day_of_birth=arr[i].day_of_birth;
                arr[i].day_of_birth = temp2_DOB;
                    //Month
                temp2_DOB = arr[j].month_of_birth;
                arr[j].month_of_birth=arr[i].month_of_birth;
                arr[i].month_of_birth = temp2_DOB;
                    //Year
                temp2_DOB = arr[j].year_of_birth;
                arr[j].year_of_birth=arr[i].year_of_birth;
                arr[i].year_of_birth = temp2_DOB;
            }
            if(arr[i].year_of_birth==arr[j].year_of_birth&&arr[i].month_of_birth>arr[i].month_of_birth)
            {
                strcpy(temp2, arr[j].last_name);
                strcpy(arr[j].last_name, arr[i].last_name);
                strcpy(arr[i].last_name, temp2);
                //Replacing first names
                strcpy(temp2, arr[j].first_name);
                strcpy(arr[j].first_name, arr[i].first_name);
                strcpy(arr[i].first_name, temp2);
                //Replacing Street address
                strcpy(temp2, arr[j].street_address);
                strcpy(arr[j].street_address, arr[i].street_address);
                strcpy(arr[i].street_address, temp2);
                //Replacing Email
                strcpy(temp2, arr[j].email);
                strcpy(arr[j].email, arr[i].email);
                strcpy(arr[i].email, temp2);
                //Replacing phone number
                strcpy(temp2, arr[j].phone_number);
                strcpy(arr[j].phone_number, arr[i].phone_number);
                strcpy(arr[i].phone_number, temp2);
                //Replacing DOB
                    //Day
                temp2_DOB = arr[j].day_of_birth;
                arr[j].day_of_birth=arr[i].day_of_birth;
                arr[i].day_of_birth = temp2_DOB;
                    //Month
                temp2_DOB = arr[j].month_of_birth;
                arr[j].month_of_birth=arr[i].month_of_birth;
                arr[i].month_of_birth = temp2_DOB;
                    //Year
                temp2_DOB = arr[j].year_of_birth;
                arr[j].year_of_birth=arr[i].year_of_birth;
                arr[i].year_of_birth = temp2_DOB;
            }
            if(arr[i].year_of_birth==arr[j].year_of_birth&&arr[i].month_of_birth==arr[i].month_of_birth&&arr[i].day_of_birth>arr[j].day_of_birth)
            {
                strcpy(temp2, arr[j].last_name);
                strcpy(arr[j].last_name, arr[i].last_name);
                strcpy(arr[i].last_name, temp2);
                //Replacing first names
                strcpy(temp2, arr[j].first_name);
                strcpy(arr[j].first_name, arr[i].first_name);
                strcpy(arr[i].first_name, temp2);
                //Replacing Street address
                strcpy(temp2, arr[j].street_address);
                strcpy(arr[j].street_address, arr[i].street_address);
                strcpy(arr[i].street_address, temp2);
                //Replacing Email
                strcpy(temp2, arr[j].email);
                strcpy(arr[j].email, arr[i].email);
                strcpy(arr[i].email, temp2);
                //Replacing phone number
                strcpy(temp2, arr[j].phone_number);
                strcpy(arr[j].phone_number, arr[i].phone_number);
                strcpy(arr[i].phone_number, temp2);
                //Replacing DOB
                    //Day
                temp2_DOB = arr[j].day_of_birth;
                arr[j].day_of_birth=arr[i].day_of_birth;
                arr[i].day_of_birth = temp2_DOB;
                    //Month
                temp2_DOB = arr[j].month_of_birth;
                arr[j].month_of_birth=arr[i].month_of_birth;
                arr[i].month_of_birth = temp2_DOB;
                    //Year
                temp2_DOB = arr[j].year_of_birth;
                arr[j].year_of_birth=arr[i].year_of_birth;
                arr[i].year_of_birth = temp2_DOB;
            }
        }
    }
                    printf("\nContacts successfully sorted according to the date of birth in ascending order.\n\n");
}
//7)Save function
void save()
{
    FILE *fp;
    fp = fopen("phonebook.txt","w");
    for(int k =0;k<count;k++)
    {
        fprintf(fp,"%s,%s,%d/%d/%d,%s,%s,%s\n",contacts[k].last_name,contacts[k].first_name,contacts[k].day_of_birth,\
               contacts[k].month_of_birth,contacts[k].year_of_birth,contacts[k].street_address,\
               contacts[k].email,contacts[k].phone_number);
    }

    fclose(fp);
}
//8)print contacts
void print_contacts(){
for(int i=0;i<count;i++)
    {
        printf("\nContact number %d\n",i+1);
        printf("Last name:%s\nFirst name:%s\nDate of birth:%d/%d/%d\nStreet address:%s\nEmail:%s\nPhone number:%s\n\n",contacts[i].last_name,contacts[i].first_name,contacts[i].day_of_birth,\
               contacts[i].month_of_birth,contacts[i].year_of_birth,contacts[i].street_address,\
               contacts[i].email,contacts[i].phone_number);
    }
}

void main_menu()
    {

        load();
        int final_choice,sub_choice;
        while(1)
        {
            printf("\t\t\tWelcome to your PhoneBook\n\nPlease make a choice :) :\n=================\n\n");
        printf("1) Search for a contact\n2)Add new contact\n3)Delete contact\n4)Modify contact\n5)Save changes\n6)sort contacts by last name\n7)Sort by date of birth\n8)Display all contact\n9)Exit program\n\n");
        printf("Enter your choice:\n");scanf("%d",&final_choice);if (final_choice >= 0x41 && final_choice <= 0x7A) {printf("you entered a letter");scanf("%d",&final_choice);}

             if(final_choice==1)
        {
            printf("Please choose an option:\n1)Multi search\n2)Search by last name only");scanf("%d\n",&sub_choice);
            switch(sub_choice){
            case (1):multi_query();break;
            case (2):query();break;}
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
            modify();

             printf("Press any key to continue........\n");
             getch();

        }
        else if(final_choice==5)
        {
             save();
             printf("Press any key to continue........\n");
             getch();
        }
         else if(final_choice==6)
        {
            sort_lastName(contacts,count);
            printf("Press any key to continue........\n");
            getch();
        }
        else if(final_choice==7)
        {
            sort_date_OF_birth(contacts,count);
            printf("Press any key to continue........\n");
            getch();
        }
        else if(final_choice==8)
        {
            print_contacts();
            printf("Press any key to continue........\n");
            getch();
        }
        else if(final_choice==9)
        {
            break;
        }
    }
        }
