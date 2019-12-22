#ifndef PHONEBOOK_DEC_H_INCLUDED
#define PHONEBOOK_DEC_H_INCLUDED
#define max_size 100
//type declaration
typedef struct contact{
 char last_name[max_size];
 char first_name[max_size];
 int day_of_birth;
 int month_of_birth;
 int year_of_birth;
 char street_address[max_size];
 char email[max_size];
 char phone_number[max_size];
}contact;
//Some declarations
contact contacts[max_size];
contact *ptr[max_size];
char key[max_size];
int count=0;int a=0;
contact *ptr2[max_size];
//Functions declarations
void load();
void query();
void add_new_contact();
int validnumber(char*);
void deleterec();
void modify();
void sort_lastName(contact arr[],int);
void save();
void print_contacts();
void main_menu();


#endif // PHONEBOOK_DEC_H_INCLUDED
