#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stringlist.h>

struct socialnetwork
{
    char firstname[100];
    char lastname[100];
    int age;
    char school[100];
    char email[100];
    char favhobby[100];
    char loginPassword[100];
    char Inbox[100];
    
    struct socialnetwork *next;
    struct socialnetwork *prev;
};

//Friends List Pointers
struct socialnetwork *head = NULL;
struct socialnetwork *tail = NULL;

//People List Pointers
struct socialnetwork *headPeople = NULL;
struct socialnetwork *tailPeople = NULL;

void updateProfile(struct socialnetwork *profile)
{
    FILE *fptr;
    fptr = fopen("/Users/Muaz/Desktop/LoginProfile", "w+");
    fprintf(fptr, "%s\n", profile->firstname);
    fprintf(fptr, "%s\n", profile->loginPassword);
    fprintf(fptr, "%s\n", profile->lastname);
    fprintf(fptr, "%d\n", profile->age);
    fprintf(fptr, "%s\n", profile->school);
    fprintf(fptr, "%s\n", profile->email);
    fprintf(fptr, "%s\n", profile->favhobby);
    
    fclose(fptr);
    
}

void joinNetwork(char email[100], char emessage[200])
{
    
    FILE *fptr = fopen("/Users/Muaz/Desktop/JoinNetwork.txt", "a+");
    fprintf(fptr, "%s\n", email);
    fprintf(fptr, "%s\n\n", emessage);
    
    printf("\nMessage successfully sent");
    
    fclose(fptr);
    
}

void showsuggestedFriends(struct socialnetwork* profile)
{
    struct socialnetwork* ptr = headPeople;
    
    printf("\nPeople w/ same age as you:\n");
    while(ptr != NULL)
    {
        if(ptr->age == profile->age)
            printf("%s %s\n", ptr->firstname, ptr->lastname);
        ptr = ptr->next;
    }
    
    ptr = headPeople;
    printf("\nPeople that go to the same school as you:\n");
    while(ptr != NULL)
    {
        if(strcmp(ptr->school, profile->school) == 0)
            printf("%s %s\n", ptr->firstname, ptr->lastname);
        ptr = ptr->next;
    }
    
    ptr = headPeople;
    printf("\nPeople that have the same favorite hobby as you:\n");
    while(ptr != NULL)
    {
        if(strcmp(ptr->favhobby, profile->favhobby) == 0)
            printf("%s %s\n", ptr->firstname, ptr->lastname);
        ptr = ptr->next;
    }
    
}

void searchPeople(char firstName[100], char lastName[100], int a, char school[100], char email[100], char fh[100], int state)
{
    struct socialnetwork *ptr = headPeople;
    printf("\n");
    switch(state)
    {
        case 1:
            printf("People found that have this name:\n");
            while(ptr != NULL)
            {
                if(strcmp(ptr->firstname,firstName) == 0 && strcmp(ptr->lastname,lastName) == 0)
                {
                    printf("%s %s\n", ptr->firstname, ptr->lastname);
                    ptr = ptr->next;
                }
                else
                    ptr = ptr->next;
            }
            break;
            
        case 2:
            printf("People found that are of this age:\n");
            while(ptr != NULL)
            {
                if(ptr->age == a)
                {
                    printf("%s %s\n", ptr->firstname, ptr->lastname);
                    ptr = ptr->next;
                }
                else
                    ptr = ptr->next;
                
            }
            break;
        
        case 3:
            printf("People found that go to this school:\n");
            while(ptr != NULL)
            {
                if(strcmp(ptr->school, school) == 0)
                {
                    printf("%s %s\n", ptr->firstname, ptr->lastname);
                    ptr = ptr->next;
                }
                else
                    ptr = ptr->next;
            }
            break;
            
        case 4:
            printf("People found that have this email address:\n");
            while(ptr != NULL)
            {
                if(strcmp(ptr->email, email) == 0)
                {
                    printf("%s %s\n", ptr->firstname, ptr->lastname);
                    ptr = ptr->next;
                }
                else
                    ptr = ptr->next;
                
            }
            break;
        
        case 5:
            printf("People found that have this favorite hobby:\n");
            while(ptr != NULL)
            {
                if(strcmp(ptr->favhobby, fh) == 0)
                {
                    printf("%s %s\n", ptr->firstname, ptr->lastname);
                    ptr = ptr->next;
                }
                else
                    ptr = ptr->next;
            }
            break;
    }
}

struct socialnetwork* addPeople(char fn[100], char ln[100], int a, char school[100], char email[100], char fh[100])
{
    if(NULL == headPeople)
    {
        struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
        
        strcpy(profile->firstname, fn);
        strcpy(profile->lastname, ln);
        profile -> age = a;
        strcpy(profile->school, school);
        strcpy(profile->email, email);
        strcpy(profile->favhobby, fh);
        
        headPeople = profile;
        tailPeople = profile;
        profile -> next = NULL;
        profile -> prev = NULL;
        
        return profile;
        
    }
    
    else
    {
        struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
        
        strcpy(profile->firstname, fn);
        strcpy(profile->lastname, ln);
        profile -> age = a;
        strcpy(profile->school, school);
        strcpy(profile->email, email);
        strcpy(profile->favhobby, fh);
        
        profile -> next = headPeople;
        headPeople = profile;
        profile -> prev = NULL;
        
        return headPeople;
    }
    
}


struct socialnetwork* addfriend(char fn[100], char ln[100], int a, char school[100], char email[100], char fh[100])
{
    if(NULL == head)
    {
        struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
        
        strcpy(profile->firstname, fn);
        strcpy(profile->lastname, ln);
        profile -> age = a;
        strcpy(profile->school, school);
        strcpy(profile->email, email);
        strcpy(profile->favhobby, fh);
        
        head = profile;
        tail = profile;
        profile -> next = NULL;
        profile -> prev = NULL;
        
        printf("\nNew Friend Successfully Added!!\n\n");
        return profile;
        
    }
    
    else
    {
        struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
        
        strcpy(profile->firstname, fn);
        strcpy(profile->lastname, ln);
        profile -> age = a;
        strcpy(profile->school, school);
        strcpy(profile->email, email);
        strcpy(profile->favhobby, fh);
        
        profile -> next = head;
        head = profile;
        profile -> prev = NULL;
        
        printf("\nNew Friend Successfully Added!!\n");
        return head;
    }
    
}

struct socialnetwork* searchpeople(char fn[50], char ln[50])
{
    struct socialnetwork *ptr = headPeople;
    
    while(ptr != NULL)
    {
        if(strcmp(ptr->firstname,fn) == 0 && strcmp(ptr->lastname,ln) == 0)
        {
            return ptr;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    
    return NULL;
}

struct socialnetwork* searchfriend(char fn[50], char ln[50])
{
    struct socialnetwork *ptr = head;
    
    while(ptr != NULL)
    {
        if(strcmp(ptr->firstname,fn) == 0 && strcmp(ptr->lastname,ln) == 0)
        {
            return ptr;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    
    return NULL;
}

int deletefriend(char fn[50], char ln[50])
{
    struct socialnetwork *del = NULL;
    
    del = searchfriend(fn, ln);
    
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        
        if(del == tail)
        {
            tail = del -> prev;
        }
        if(del == head)
        {
            head = del->next;
        }
        else
            free(del);
    }
    
    free(del);
    del = NULL;
    
    return 1;
    
}

void viewallFriends()
{
    struct socialnetwork* ptr = head;
    int x = 1;
    
    while(ptr != NULL)
    {
        printf("Friend Number %d:\n", x);
        printf("Firstname: %s\n", ptr->firstname);
        printf("Lastname: %s\n", ptr->lastname);
        printf("Age: %d\n", ptr->age);
        printf("School: %s\n", ptr->school);
        printf("Email: %s\n", ptr->email);
        printf("Favorite Hobby: %s\n", ptr->favhobby);
        printf("\n");
        
        ptr = ptr-> next;
        x++;
    }
}

void savefriendstofile()
{
    FILE *fptr = fopen("/Users/Muaz/Desktop/FriendsExport", "w+");
    
    struct socialnetwork* ptr = head;
    
    while(ptr != NULL)
    {
        fprintf(fptr, "%s\n", ptr->firstname);
        fprintf(fptr, "%s\n", ptr->lastname);
        fprintf(fptr, "%d\n", ptr->age);
        fprintf(fptr, "%s\n", ptr->school);
        fprintf(fptr, "%s\n", ptr->email);
        fprintf(fptr, "%s\n", ptr->favhobby);
        fprintf(fptr, "%s\n\n", ptr->Inbox);

        ptr = ptr-> next;
    }
    
    fprintf(fptr, "%d\n", 1);
    
    fclose(fptr);
    
}

void analyzeFriends()
{
    struct socialnetwork *ptr = head;
    struct socialnetwork *ptr2 = head;
    
    printf("\nAge Analysis:\n");
    for(ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for(ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(ptr->age == ptr2->age)
                printf("%s %s and %s %s both are %d years old\n", ptr->firstname, ptr->lastname, ptr2->firstname, ptr2->lastname, ptr->age);
        }
    }
    
    printf("\nSchool Analysis:\n");
    for(ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for(ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(strcmp(ptr->school, ptr2->school) == 0)
                printf("%s %s and %s %s both go to %s\n", ptr->firstname, ptr->lastname, ptr2->firstname, ptr2->lastname, ptr->school);
        }
    }
    
    printf("\nHobby Analysis:\n");
    for(ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for(ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(strcmp(ptr->favhobby, ptr2->favhobby) == 0)
                printf("%s %s and %s %s both like %s\n", ptr->firstname, ptr->lastname, ptr2->firstname, ptr2->lastname, ptr->favhobby);
        }
    }
}

void printfriendsnames()
{
    struct socialnetwork* ptr = head;
    int x = 1;
    
    while(ptr != NULL)
    {
        printf("%d) %s ", x, ptr->firstname);
        printf("%s\n", ptr->lastname);
        ptr = ptr-> next;
    }
    printf("\n");
}

void printpeoplesnames()
{
    struct socialnetwork* ptr = headPeople;
    int x = 1;
    
    while(ptr != NULL)
    {
        printf("%d) %s ", x, ptr->firstname);
        printf("%s\n", ptr->lastname);
        ptr = ptr-> next;
    }
    printf("\n");
}

struct socialnetwork* messageFriend(char firstname[50], char lastname[50], char message[100])
{
    struct socialnetwork* ptr = searchfriend(firstname, lastname);
    
    if(ptr != NULL)
    {
        strcpy(ptr->Inbox, message);
        printf("\nMessage Successfully sent to Friend\n");
        return ptr;
    }
    else if(ptr == NULL)
    {
        printf("\nFriend does not exist\n");
        return NULL;
    }
    
    return ptr;
}

    
struct socialnetwork* makeprofile(char fn[100], char ln[100], int a, char school[100], char email[100], char fh[100], char lp[100], int state)
{
        struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
        
        strcpy(profile->firstname, fn);
        strcpy(profile->lastname, ln);
        profile -> age = a;
        strcpy(profile->school, school);
        strcpy(profile->email, email);
        strcpy(profile->favhobby, fh);
        strcpy(profile->loginPassword, lp);
    
        profile -> next = NULL;
        profile -> prev = NULL;
    
        if(state == 2)
        {
        FILE *fptr;
        fptr = fopen("/Users/Muaz/Desktop/LoginProfile", "w");
        fprintf(fptr, "%s\n", fn);
        fprintf(fptr, "%s\n", lp);
        fprintf(fptr, "%s\n", ln);
        fprintf(fptr, "%d\n", a);
        fprintf(fptr, "%s\n", school);
        fprintf(fptr, "%s\n", email);
        fprintf(fptr, "%s\n\n", fh);
    
        fclose(fptr);

        printf("\nSuccessfully created personal profile!\n");
        }
    
        return profile;
}

int main()
{
    int state = 0;
    int insidestate = 0;
    int option = 0;
    int flag = 0;
   
    char firstname[100];
    char password[100];
    
    char firstnamepersonal[100];
    char lastnamepersonal[100];
    int age;
    char school[100];
    char email[100];
    char favhobby[100];
    char loginPassword[100];
    
    struct socialnetwork *profile = (struct socialnetwork*)malloc(sizeof(struct socialnetwork));
    
    
    while(1)
    {
        switch(state)
        {
            case 0:
                //Start Screen
                printf("Welcome to The Social Network\n\n");
                printf("1) Login w/ Existing\n");
                printf("2) Create New Profile\n");
                scanf("%d", &option);
                
                if(option == 1){
                    state = 1;
                    break;
                
                }else if(option == 2){
                    state = 2;
                    break;
                
                }else
                {
                    printf("Wrong Input. Try again. \n\n");
                    state = 0;
                    break;
                }
                
                break;
            
            case 1:
                //Login Screen
                printf("Enter First Name: ");
                scanf("%s", firstname);
                printf("Enter Password: ");
                scanf("%s", password);
                
                //Specificy file location. Change name only, not anything else. I.E. swap out Muaz for your user folder on your computer. Note: May not always be your name. Check.
                FILE *fptr = fopen("/Users/Muaz/Desktop/LoginProfile", "r");
                
                if(fptr)
                {
                    fscanf(fptr, "%s\n", firstnamepersonal);
                    fscanf(fptr, "%s\n", loginPassword);
                    fscanf(fptr, "%s\n", lastnamepersonal);
                    fscanf(fptr, "%d\n", &age);
                    fscanf(fptr, "%s\n", school);
                    fscanf(fptr, "%s\n", email);
                    fscanf(fptr, "%s\n", favhobby);
                    
                    if(strcmp(firstname, firstnamepersonal) == 0 && strcmp(password, loginPassword) == 0)
                    {
                        profile = makeprofile(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, loginPassword, 1);
                        
                        printf("\nCredentials Found. You are now logged in. \n\n");
                        
                        printf("Quick details of profile are:\n");
                        printf("%s ", profile->firstname);
                        printf("%s\n", profile->lastname);
                        printf("%s\n", profile->email);
                        state = 3;
                        break;
                    }
                    else
                    {
                        printf("No logins exist. Sorry. \n\n");
                        state = 0;
                        break;
                    }
                    break;
                }
                
                else if(fptr == NULL)
                {
                    printf("\nNo logins exist. Sorry. \n\n");
                    state = 0;
                    break;
                }
                
                break;
                
            case 2:
                //Creating Personal Profile
                printf("\nEnter the following information to create personal profile:\n\n");
                
                printf("First Name: ");
                scanf("%s", firstnamepersonal);
                
                printf("Last Name: ");
                scanf("%s", lastnamepersonal);
                
                printf("Enter Age: ");
                scanf("%d", &age);
                
                printf("Enter School: ");
                scanf("%s", school);
                
                printf("Enter Email: ");
                scanf("%s", email);
                
                printf("Enter Favorite Hobby: ");
                scanf("%s", favhobby);
                
                printf("Enter Login Password: ");
                scanf("%s", loginPassword);
                
                profile = makeprofile(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, loginPassword, 2);
                
                state = 3;
                break;
            
            case 3:
                //Main Screen
                printf("\nWelcome to your main screen. Choose from the following: \n");
                printf("1) Manage Profile\n");
                printf("2) Manage Friends\n");
                printf("3) Go to Inbox\n");
                printf("4) Logout\n");
                
                scanf("%d", &option);
                
                if(option == 1)
                {
                    state = 9;
                    break;
                }
                
                if(option == 2)
                {
                    state = 7;
                    break;
                }
                
                if(option == 3)
                {
                    state = 6;
                    break;
                }
                
                if(option == 4)
                {
                    printf("\nLogout Successful\n\n");
                    state = 0;
                    break;
                }
                break;
            
            case 6:
                //Manage Inbox Section
                printf("\nWelcome to your Personal Inbox. Choose from the following: \n");
                printf("1) View Messages\n");
                printf("2) Send Messages\n");
                printf("3) Go Back");
                
                scanf("%d", &insidestate);

                if(insidestate == 1)
                {
                    if(flag == 0)
                    {
                        printf("\n1 Unread Message:\n");
                        printf("\nMessage 1:\n");
                        printf("This is a message from the creators of The Social Network. We hope you are enjoying your new experience. Thank you.\n");
                        flag++;
                        break;
                    }
                    else
                        printf("\n0 Unread Messages.\n");
                    
                    state = 6;
                    break;
                }
                
                //Send Message
                if(insidestate == 2)
                {
                    char fnfriend[50];
                    char lnfriend[50];
                    char message[100];
                    printf("\nList of Friends: \n");
                    printfriendsnames();
                    printf("Choose Friend to Message (First & Last Name): ");
                    scanf("%s %s", fnfriend, lnfriend);
                    printf("\nCompose Message: ");
                    scanf("%s", message);
                    
                    messageFriend(fnfriend, lnfriend, message);
                    savefriendstofile();
                    
                    state = 6;
                    break;
                }
                
                //Previous Screen
                if(insidestate == 3)
                {
                    state = 3;
                    break;
                }

                break;
            
            case 7:
                //Manage Friends Section
                printf("\nWelcome to your Manage Friends Section. What would you like to do?\n");
                printf("1) Add Friends\n");
                printf("2) Delete Current Friends\n");
                printf("3) Search for Potential Friends\n");
                printf("4) View all Current Friends\n");
                printf("5) Go Back\n");
                    //printf("5) Export Current Friends List to File");
                
                scanf("%d", &insidestate);
                
                //Add Friends
                if(insidestate == 1)
                {
                    state = 8;
                    break;
                }
                
                //Delete Current Friends
                if(insidestate == 2)
                {
                    char fname[50];
                    char lname[50];
                    
                    printf("\nEnter first name of friend to be deleted: ");
                    scanf("%s", fname);
                    printf("Enter last name of friend to be deleted: ");
                    scanf("%s", lname);
                    
                    printf("\nProgram is now searching for friend and if found, will delete....\n");
                    
                    if(deletefriend(fname, lname) == 1)
                    {
                        printf("Friend has been found and has been successfully deleted.\n");
                        state = 7;
                        break;
                    
                    }else
                    {
                        printf("Sorry. Friend was not found.\n");
                        state = 7;
                        break;
                    }
                    
                    break;
                }
                
                //Search for Potential Friends
                if(insidestate == 3)
                {
                    FILE *fptr = fopen("/Users/Muaz/Desktop/PeopleList", "r");
                    while(1)
                    {
                        int temp = fscanf(fptr,"%d", &temp);
                        if (temp == 1)
                            break;
                        else
                        {
                            fscanf(fptr,"%s\n", firstnamepersonal);
                            fscanf(fptr,"%s\n", lastnamepersonal);
                            fscanf(fptr,"%d\n", &age);
                            fscanf(fptr,"%s\n", school);
                            fscanf(fptr,"%s\n", email);
                            fscanf(fptr,"%s\n\n", favhobby);
                            addPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby);
                        }
                    }
                    
                    fclose(fptr);
                    
                    printf("\nSearch by one of the following categories\n");
                    printf("1) Name\n");
                    printf("2) Age\n");
                    printf("3) School\n");
                    printf("4) Email\n");
                    printf("5) Favorite Hobby\n");
                    
                    scanf("%d", &option);
                    printf("\n");
                    
                    if(option == 1)
                    {
                        printf("First Name: ");
                        scanf("%s", firstnamepersonal);
                        printf("Last Name: ");
                        scanf("%s", lastnamepersonal);
 
                        searchPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, 1);
                        printf("\n");
                        break;
                    }
                    if(option == 2)
                    {
                        printf("Age: ");
                        scanf("%d", &age);

                        searchPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, 2);
                        printf("\n");

                        break;
                    }
                    if(option == 3)
                    {
                        printf("School: ");
                        scanf("%s", school);
                        
                        searchPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, 3);
                        printf("\n");

                        break;
                    }
                    if(option == 4)
                    {
                        printf("Email: ");
                        scanf("%s", email);
                    
                        searchPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, 4);
                        printf("\n");

                        break;
                    }
                    if(option == 5)
                    {
                        printf("Favorite Hobby: ");
                        scanf("%s", favhobby);
                       
                        searchPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby, 5);
                        printf("\n");
                        break;
                    }
                    
                    state = 7;
                    break;
                }
                
                //View all Current Friends
                if(insidestate == 4)
                {
                    printf("------Beginning of friends list------\n\n");
                    viewallFriends();
                    printf("------End of friends list------\n");
                    
                    printf("\nPress 1 to Export/Save Friends list\n");
                    printf("Press 2 to Analyze Friends\n");
                    printf("Press 3 to Go Back\n");
                    
                    scanf("%d", &option);
                    
                    //Export/Save Friends List to File
                    if(option == 1)
                    {
                        savefriendstofile();
                        printf("\nFriends successfully saved on Desktop\n");
                        
                        state = 7;
                        break;
                    }
                    
                    //Analyze Friends
                    if(option == 2)
                    {
                        analyzeFriends();
                        state = 7;
                        break;
                    }
                    
                    //Previous Screen
                    if(option == 3)
                    {
                        state = 7;
                        break;
                    }
                    
                    state = 7;
                    break;
                }
                
                //Previous Screen
                if(insidestate == 5)
                {
                    state = 3;
                    break;
                }
                
                break;
            
            case 8:
                //Add Friends Section (subsection of Manage Friends Section)
                printf("\nWhat would you like to do?\n");
                printf("1) Add Friend Manually\n");
                printf("2) Add Friend from People List\n");
                printf("3) Ask Friend to Join Network\n");
                printf("4) Import Personal Friends List\n");
                printf("5) See Suggested Friends\n");
                printf("6) Go Back");
                
                scanf("%d", &insidestate);
                
                //Add Friend Manually
                if(insidestate == 1)
                {
                    printf("\nIn order to add a friend please enter the following information:\n");
                    
                    printf("Firstname: ");
                    scanf("%s", firstnamepersonal);
                    
                    printf("Lastname: ");
                    scanf("%s", lastnamepersonal);
                    
                    printf("Age: ");
                    scanf("%d", &age);
                    
                    printf("School: ");
                    scanf("%s", school);
                    
                    printf("Enter Email: ");
                    scanf("%s", email);
                    
                    printf("Enter Favorite Hobby: ");
                    scanf("%s", favhobby);
                    
                    addfriend(firstnamepersonal, lastnamepersonal, age, school, email, favhobby);
                    
                    printf("%s", head->firstname);
                    
                    state = 8;
                    break;
                }
                
                //Add Friend from People List
                if(insidestate == 2)
                {
                    FILE *fptr = fopen("/Users/Muaz/Desktop/PeopleList", "r");
                    while(1)
                    {
                        int temp = fscanf(fptr,"%d", &temp);
                        if (temp == 1)
                            break;
                        else
                        {
                            fscanf(fptr,"%s\n", firstnamepersonal);
                            fscanf(fptr,"%s\n", lastnamepersonal);
                            fscanf(fptr,"%d\n", &age);
                            fscanf(fptr,"%s\n", school);
                            fscanf(fptr,"%s\n", email);
                            fscanf(fptr,"%s\n\n", favhobby);
                            addPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby);
                        }
                    }
                    
                    fclose(fptr);
                    
                    printf("\nList of Persons: \n");
                    printpeoplesnames();
                    printf("Choose Person to Add (First & Last Name): ");
                    scanf("%s %s", firstnamepersonal, lastnamepersonal);
                    
                    struct socialnetwork* ptr = searchpeople(firstnamepersonal, lastnamepersonal);
                    
                    if(ptr == NULL)
                        printf("Sorry. Person does not exist");
                    else
                        addfriend(ptr->firstname, ptr->lastname, age, school, email, favhobby);
                    
                    break;
                }
                
                //Ask Friend to Join Network
                if(insidestate == 3)
                {
                    char email[100];
                    char emessage[200];
                    printf("Enter Friends Email Address: ");
                    scanf("%s", email);
                    printf("Compose Message: ");
                    scanf("%s", emessage);
                    
                    joinNetwork(email, emessage);
                    
                    state = 8;
                    
                    break;
                }
                
                //Import Personal Friends List
                if(insidestate == 4)
                {
                    FILE *fptr = fopen("/Users/Muaz/Desktop/FriendsImport.txt", "r");
                    if(fptr)
                    {
                    head = NULL;
                    while(1)
                    {
                        int temp = fscanf(fptr,"%d", &temp);
                        if (temp == 1)
                            break;
                        else
                        {
                            fscanf(fptr,"%s\n", firstnamepersonal);
                            fscanf(fptr,"%s\n", lastnamepersonal);
                            fscanf(fptr,"%d\n", &age);
                            fscanf(fptr,"%s\n", school);
                            fscanf(fptr,"%s\n", email);
                            fscanf(fptr,"%s\n\n", favhobby);
                            addfriend(firstnamepersonal, lastnamepersonal, age, school, email, favhobby);
                        }
                    
                    }
                    }
                    else
                        printf("\nSorry, no friends file found.\n");
                    
                    printf("---------------------\n");
                    printf("Finished Importing All Friends.\n");
                    fclose(fptr);
                    break;
                }
                
                //See Suggested Friends
                if(insidestate == 5)
                {
                    FILE *fptr = fopen("/Users/Muaz/Desktop/PeopleList", "r");
                    while(1)
                    {
                        int temp = fscanf(fptr,"%d", &temp);
                        if (temp == 1)
                            break;
                        else
                        {
                            fscanf(fptr,"%s\n", firstnamepersonal);
                            fscanf(fptr,"%s\n", lastnamepersonal);
                            fscanf(fptr,"%d\n", &age);
                            fscanf(fptr,"%s\n", school);
                            fscanf(fptr,"%s\n", email);
                            fscanf(fptr,"%s\n\n", favhobby);
                            addPeople(firstnamepersonal, lastnamepersonal, age, school, email, favhobby);
                        }
                    }
                    fclose(fptr);
                    
                    showsuggestedFriends(profile);
                    
                    break;
                }
                
                //Previous Screen
                if(insidestate == 6)
                {
                    state = 7;
                    break;
                }
                
                break;
            
            case 9:
                
                printf("\n1) View Profile\n");
                printf("2) Edit Profile\n");
                printf("3) Delete Profile\n");
                printf("4) Go Back To Main Screen\n\n");
                
                scanf("%d", &option);
                if(option == 1)
                {
                    printf("Name: %s %s\n", profile->firstname, profile->lastname);
                    printf("Age: %d\n", profile->age);
                    printf("School: %s\n", profile->school);
                    printf("Email: %s\n", profile->email);
                    printf("Favorite Hobby: %s\n\n", profile->favhobby);
                    state = 9;
                    break;
                    
                }
                else if(option == 2)
                {    printf("Choose From the Following\n\n");
                    printf("1) Edit First Name\n");
                    printf("2) Edit Last Name\n");
                    printf("3) Edit Age\n");
                    printf("4) Edit School\n");
                    printf("5) Edit Email\n");
                    printf("6) Edit Favorite Hobby\n");
                    printf("7) Return to Previous Page\n");
                    
                    scanf("%d", &option);
                    
                    if(option == 1){
                        printf("Enter New First Name: ");
                        scanf("%s", profile->firstname);
                        updateProfile(profile);
                        break;
                        
                    }
                    
                    if(option == 2){
                        printf("Enter New Last Name: ");
                        scanf("%s", profile->lastname);
                        updateProfile(profile);
                        break;
                    }
                    if(option == 3){
                        printf("Enter New Age: ");
                        scanf("%d", &profile->age);
                        updateProfile(profile);
                        break;
                    }
                    if(option == 4){
                        printf("Enter New School: ");
                        scanf("%s", profile->school);
                        updateProfile(profile);
                        break;
                    }
                    if(option == 5){
                        printf("Enter New Email: ");
                        scanf("%s", profile->email);
                        updateProfile(profile);
                        break;
                    }
                    if(option == 6){
                        printf("Enter New Favorite Hobby: ");
                        scanf("%s", profile->favhobby);
                        updateProfile(profile);
                        break;
                    }
                    if(option == 7){
                        state = 9;
                        break;
                    }
                }
                else if(option == 3){
                    printf("Are you sure you would like to delete you profile? Yes<1>/No<0>: ");
                    scanf("%d", &option);
                    if(option == 1){
                        profile = NULL;
                        FILE *fptr;
                        fptr = fopen("/Users/Muaz/Desktop/LoginProfile", "w+");
                        fclose(fptr);
                        printf("\nProfile deleted, exiting application\n");
                        exit(EXIT_SUCCESS);
                        break;
                        
                    }
                    if(option == 0){
                        state = 9;
                        break;
                    }
                    
                    break;
                }
                
                else if(option == 4)
                {
                    state = 3;
                    break;
                }
                break;
            
        }
        
    }
    
}

