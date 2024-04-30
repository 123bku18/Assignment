#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACT 100
#define MAX_NAME 50
#define MAX_ADDRESS 100
#define MAX_PHONE 30

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char address[MAX_ADDRESS];
} Contact;

void ADD_CONTACT(const Contact *contact){
    FILE *file = fopen("contacts.txt", "a");
    if (file == NULL){
        printf("Can not open folder Contact!\n");
        return;
    }
    fprintf(file, "%s\n%s\n%s\n", contact->name, contact->phone, contact->address);
    fclose(file);
}

void SHOW_CONTACT(){
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL){
        printf("Can not open contact file!\n");
        return;
    }
    Contact contact;
    while (fscanf(file, "%49[^\n]%*c%19[^\n]%*c%99[^\n]%*c", contact.name, contact.phone, contact.address) != EOF){
        printf("Name: %s\nPhone: %s\nAddress: %s\n\n", contact.name, contact.phone, contact.address);
    }
    fclose(file);
}

void FIND_CONTACT_BY_NAME(const char *name){
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL){
        printf("Can not open contact file!\n");
        return;
    }

    Contact contact;
    int found = 0;
    while (fscanf(file, "%49[^\n]%*c%19[^\n]%*c%99[^\n]%*c)", contact.name, contact.phone, contact.address) != EOF){
        if (strcmp(contact.name, name) ==0){
            printf("Name: %s\nPhone: %s\nAddress: %s\n\n", contact.name, contact.phone, contact.address);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Can not find out contact with the name \"%s\"\n", name);
    }
    fclose(file);
}

int main(){
    
    int choice;
    char name[MAX_NAME];
    Contact newContact;

    do {
        printf("\nProgram to monitor Contacts List\n");
        printf("1. Add contact\n");
        printf("2. Display contacts list\n");
        printf("3. Find contacts\n");
        printf("4. Quite the program\n");
        printf("Choose your option: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]s", newContact.name);
            printf("Enter phone number: ");
            scanf(" %[^\n]s", newContact.phone);
            printf("Enter address: ");
            scanf(" %[^\n]s", newContact.address);
            ADD_CONTACT(&newContact);
            break;

        case 2:
            SHOW_CONTACT();
            break;

        case 3:
            printf("Enter name: ");
            scanf(" %[^\n]s", name);
            FIND_CONTACT_BY_NAME(name);
            break;
        
        case 4:
            printf("Goodbye!\n");
            break;
        
        default:
            printf("Invalid option. Choose other options, please!\n");
            break;
        }
    } while (choice != 4);

    return 0;
}