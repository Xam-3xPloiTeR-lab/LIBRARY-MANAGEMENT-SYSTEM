/*
	Usama Arshad
	SP18-BCS-132
*/

// header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include "xam.h"

// function prototypes
void welcome();
void menu();
void head();
void add_a_book();
void delete_a_book();
void search_a_book();
void search_by_author();
void search_by_name();
void search_by_isbn();
void modify_a_book();
void display_all_books();
void issue_a_book();

// Sructure
struct book{
	char serialno[10];
    char isbn[20];
    char name[40];
    char edition[10];
    char author[40];
    char reserved[10];
};
// Global Struct Variable
struct book b;

// Global file pointer
FILE* fp;

int main(){
	system("cls");
	system("color CE");
	welcome();
	head();
	menu();
	return 0;
}

/*This function shows animated output.
It prints one character at a time using
a timer which pauses the flow for 0.3 seconds*/
void welcome(){

	int i=0;
	while(i<4){

		gotoxy(50,10);
		printf("LOADING");
		gotoxy(55,13);
		printf("|");
		gotoxy(100,30);
		printf("......AUTHOR......");
		Sleep(200);
		system("cls");

		gotoxy(50,10);
		printf("LOADING.");
		gotoxy(55,13);
		printf("/");
		gotoxy(100,30);
		printf("CODED");
		Sleep(200);
		system("cls");

		gotoxy(50,10);
		printf("LOADING..");
		gotoxy(55,13);
		printf("-");
		gotoxy(100,30);
		printf("CODED BY");
		Sleep(200);
		system("cls");

		gotoxy(50,10);
		printf("LOADING...");
		gotoxy(55,13);
		printf("\\");
		gotoxy(100,30);
		printf("CODED BY Xam");
		Sleep(200);
		system("cls");

		gotoxy(50,10);
		printf("LOADING....");
		gotoxy(55,13);
		printf("|");
		gotoxy(100,30);
		printf("CODED BY Xam 3xPloieR");
		Sleep(200);
		system("cls");
		i++;
	}
}

void head(){

	int i=0,j;
    char a[]="  LIBRARY MANAGEMENT SYSTEM   ";
	for(i=0;i<35;i++){
		gotoxy(i,0);
		printf("%c",219);

		gotoxy(100-i,0);
		printf("%c",219);
		Sleep(30);
	}
	i=0;
	for(j=35;j<65;j++){
		gotoxy(j,0);
		printf("%c",a[i]);
		if(i==9||i==20){
			Sleep(300);
		}
		i++;
		Sleep(50);
	}

}

void menu(){
	system("cls");
	int i;
	for(i=0;i<35;i++){
		gotoxy(i,0);
		printf("%c",219);

		gotoxy(100-i,0);
		printf("%c",219);
	}
	gotoxy(35,0);
	printf("  LIBRARY MANAGEMENT SYSTEM   ");

	system("color E4");
	char choice = 'X';

	// Sentinel value control loop to stay in menu until exit fuction is called.
		printf("\n\n\n");
        printf("\n\t1): Add a Book.");
        printf("\n\t2): Delete a Book.");
        printf("\n\t3): Search a Book.");
        printf("\n\t4): Modify a Book Record.");
        printf("\n\t5): Display all Books.");
        printf("\n\t6): Issue a Book.");
        printf("\n\t7): Exit.");

        printf("\n\n\tEnter your choice = ");
        fflush(stdin);
        choice = getche();

        switch (choice)
        {
        case '1':
            {
                add_a_book();
                break;
            }
        case '2':
            {
                delete_a_book();
                break;
            }
        case '3':
            {
                search_a_book();
                break;
            }
        case '4':
            {
                modify_a_book();
                break;
            }
        case '5':
            {
                display_all_books();
                break;
            }
        case '6':
            {
                issue_a_book();
                break;
            }
        case '7':
            {
                printf("\n\n");
                exit(0);
            }
        default:
            {
                system("cls");
                printf("\n\t\t\t\t\t\t     Invalid Choice.");
                printf("\n\n\t\t\t\t\t   Please enter a valid choice again.");
                Sleep(1300);
                menu();
            }
        }
    }

void add_a_book(){
	system("color 1A");
	char choice;
	do{
		char isbn[40],authr[40],id[40];
		int i,l,flag;
		system("cls");
		fp=fopen("Books_DB.txt","a");
		if(fp==NULL){
			printf("\n\t\t\t File Inaccessable");
			exit(0);
		}
		fclose(fp);
    printf("\n\t\t\t\t\t\t   Book Addition Menu:");
    printf("\n\n\tThis will add the contents to Books_DB database.\n");

    printf("\n\tEnter ISBN = ");
    fflush(stdin);
	gets(isbn);
	i=0;l=strlen(isbn);flag=0;
	while(i<=l){
		if((isbn[i]>='0' && isbn[i]<='9') || isbn[i]=='-' || isbn[i]=='\0'){
			flag++;
			i++;
			continue;
		}
		else{
            system("cls");
            system("color C0");
            printf("\n\n\n\t\t\t You Can't use Alphabetic or any special character(Excepct:'-') as ISBN");
            Sleep(1500);
            add_a_book();
		}
	}
	if(flag>0){
		fflush(stdin);
		strcpy(b.isbn,isbn);
	}
	printf("\n\tEnter the name of book : ");
    // gets() function is used to get spaced inputs
    fflush(stdin);
	gets(b.name);

	printf("\n\tEnter Author's name = ");
    fflush(stdin);
    gets(authr);
    l=strlen(authr);
        for(i=0;i<=l;i++){
        if((authr[i]>='A' && authr[i]<='Z') || (authr[i]>='a' && authr[i]<='z') || authr[i]=='\0' || authr[i]==' ' || authr[i]=='.')
        {
            flag++;
            continue;
        }
        else{
            system("cls");
            system("color C0");
            printf("\n\n\n\t\t\t  You Can't use numeric values or any special character as author name");
            Sleep(1500);
            add_a_book();
        }
        }
    if(flag>0)
    strcpy(b.author,authr);

	printf("\n\tEnter book Serial NO : ");
	fflush(stdin);
	gets(id);
	i=0,flag=0,l=strlen(id);
	while(i<=l){
		if((id[i]>='0' && id[i]<='9') || id[i]=='\0'){
			flag++;
			i++;
			continue;
		}
		else{
			system("cls");
			system("color C0");
			printf("\n\n\n\n\t\t\t You Can't use Alphabetic or any special character as Serial Number");
			Sleep(1500);
			add_a_book();
		}
	}
	if(flag>0){
		fflush(stdin);
		strcpy(b.serialno,id);
	}

	printf("\n\tEnter Book Edition = ");
    fflush(stdin);
    gets(b.edition);
    fflush(stdin);
    strcpy(b.reserved,"NO");

	fp=fopen("Books_DB.txt","a");
    if(fp==NULL){
    	printf("\nFile inaccessible\n\n");
    	system("pause");
	}

	//This line will write all record at once in file
	fwrite(&b, sizeof(b), 1, fp);
	fclose(fp);

    printf("\n\n\tEnter another record : ");
    printf("\n\n\tPress 'y' to enter another record.\n\tPress any other key to return to main menu.\n\n");
    printf("\tChoice = ");
    fflush(stdin);
    choice=getche();
	}while (choice == 'y' || choice == 'Y');
	menu();

}

void delete_a_book(){

	system("color 1A");
	system("cls");

	char input[35],choice;
	int size=0,flag=0,i=0;

	fp=fopen("Books_DB.txt","r");

	if(fp==NULL){
		printf("\nFile inaccessible\n\n");
    	system("pause");
	}

	struct book tmp;

	while(1){
		fread(&tmp,sizeof(tmp),1,fp);
		if(feof(fp)){
			break;
		}
		size++;
	}

	struct book delete_book[size];

	printf("\n\t\t\t\t\t\t    Book Deletion Menu:");
    printf("\n\n\tThis will permanently delete the book record from Books_DB database.\n");

	printf("\n\n\tEnter Book Name : ");
	fflush(stdin);
    gets(input);

	rewind(fp);

	while(1){
    	fread(&delete_book[i],sizeof(delete_book[i]),1,fp);
    	if(feof(fp)){
    		break;
		}
		if((strcmp(delete_book[i].name,input)==0)){
			flag++;
		}		i++;
	}

	fclose(fp);

	fp=fopen("Books_DB.txt","w");

	if(fp==NULL){
		printf("\nFile inaccessible\n\n");
    	system("pause");
	}

    //In case particular book record not found in db
    if (flag == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\t\t    Book Deletion Menu:");
        printf("\n\n\tThis will permanently delete the contents of Books_DB database.\n");
        printf("\n\n\tEnter Book Name : %s", input);
        printf("\n\n\t'%s' was not found in Book_DB database.\n\n\t", input);
        system("pause");
    }

	flag=0;

	//loop till total records size of file
	for(i=0;i<size;i++){
		if((strcmp(delete_book[i].name, input) == 0)){
		    Sleep(30);
            printf("\n\tSerial No. = %s", delete_book[i].serialno);
            Sleep(30);
            printf("\n\tName       = %s", delete_book[i].name);
            Sleep(30);
            printf("\n\tAuthor     = %s", delete_book[i].author);
            Sleep(30);
            printf("\n\tISBN       = %s", delete_book[i].isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", delete_book[i].edition);
            Sleep(30);
            printf("\n\tReserved   = %s\n\n\t", delete_book[i].reserved);
            Sleep(30);

			printf("\n\tDelete this record : ");
            printf("\n\n\tPress 'y' to delete this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            fflush(stdin);
            choice = getche();

			//Book deletion confirmation
			if(choice=='y' || choice== 'Y'){
				flag++;
				continue;
			}
			else{
				fwrite(&delete_book[i],sizeof(delete_book[i]),1,fp);
			}
			}

		else{
			fwrite(&delete_book[i],sizeof(delete_book[i]),1,fp);
		}

	}

	if(flag==0){
		fclose(fp);
		menu();
	}
	    system("cls");

    printf("\n\t\t\t\t\t\t    Book Deletion Menu:");
    printf("\n\n\tThis will permanently delete the contents of Books_DB database.\n");

    printf("\n\tThe Record has been deleted.\n\n\t");
    system("pause");

    fclose(fp);
    menu();
}
void search_a_book(){

	system("color 1A");

	while(1){
		system("cls");
		char choice;

	printf("\n\t\t\t\t\t\t   Book Searching Menu :\n\n\n");

    printf("\n\t1): Search by Author.");
    printf("\n\t2): Search by Title.");
    printf("\n\t3): Search by ISBN.");
    printf("\n\t4): Goto Main Menu.");

    printf("\n\n\tEnter your choice (1, 2, 3, 4) = ");
    fflush(stdin);
    choice = getche();

    switch (choice){
    	case '1':{
    		search_by_author();
			system("pause");
			break;
			}
		case '2':{
    		search_by_name();
			system("pause");
			break;
			}
		case '3':{
    		search_by_isbn();
			system("pause");
			break;
			}
		case '4':{
    		menu();
			}
		default:{
    		system("cls");
            printf("\n\t\t\t\t\t\t     Invalid Choice.");
            printf("\n\n\t\t\t\t\t   Please enter a valid choice again.");
            Sleep(1300);
			}

		}
	}


}

void search_by_author(){

	system("cls");

    printf("\n\t\t\t\t\t\t    Book Searching Menu :");
    printf("\n\n\t\t\t\t\t        Search Book by Author Name :");

    char input[40];
    int i = 0;


    /*Flags are used to detect whether the specific book is present or not.
    The initial value is '0'. And if a book is detected then then at each iteration
    the value of flag is incremented. So a value greater then '0' shows that book is there.*/
    int flag = 0;

    printf("\n\n\tAuthor Name = ");
    fflush(stdin);
    gets(input);

    fp=fopen("Books_DB.txt","r");

    if(fp==NULL){
    	puts("\nFile inaccessible\n\n");
        system("pause");
	}

	while(1){
		fread(&b,sizeof(b),1,fp);
		if(feof(fp)){
			break;
		}

		if(strcmp(b.author,input)==0){
			Sleep(30);
            printf("\n\t%c Book#%d : \n", 254, i+1);
            Sleep(30);
            printf("\n\tSerial No. = %s", b.serialno);
            Sleep(30);
            printf("\n\tName       = %s", b.name);
            Sleep(30);
            printf("\n\tAuthor     = %s", b.author);
            Sleep(30);
            printf("\n\tISBN       = %s", b.isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", b.edition);
            Sleep(30);
            printf("\n\tReserved   = %s\n\n\t", b.reserved);
            Sleep(30);

            // increments value of flag
            ++flag;
		}

	}
	if (flag == 0)
    {
        printf("\n\tBooks written by Author '%s' are not present in Book_DB database.\n\n\t", input);
        return;
    }

}
void search_by_name()
{
    system("cls");

    printf("\n\t\t\t\t\t\t    Book Searching Menu :");
    printf("\n\n\t\t\t\t\t         Search Book by its Title :");


    char input[40];
    int i = 0, flag = 0; // just like search_by_author

    printf("\n\n\tBook Name = ");
    fflush(stdin);
    gets(input);

    fp = fopen("Books_DB.txt", "r");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        return;
    }

    while(1)
    {
        fread(&b, sizeof(b), 1, fp);

        if(feof(fp))
        {
            break;
        }

        if (strcmp(input, b.name) == 0)
        {
            Sleep(30);
            printf("\n\t%c Book#%d : \n", 254,i+1);
            Sleep(30);
            printf("\n\tSerial No. = %s", b.serialno);
            Sleep(30);
            printf("\n\tName       = %s", b.name);
            Sleep(30);
            printf("\n\tAuthor     = %s", b.author);
            Sleep(30);
            printf("\n\tISBN       = %s", b.isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", b.edition);
            Sleep(30);
            printf("\n\tReserved   = %s\n\n\t", b.reserved);
            Sleep(30);

            ++flag;
        }
    }

    if (flag == 0)
    {
        printf("\n\tBook '%s' was not found in Book_DB database.\n\n\t", input);
        return;
    }
}

void search_by_isbn()
{
    system("cls");

    printf("\n\t\t\t\t\t\t    Book Searching Menu :");
    printf("\n\n\t\t\t\t\t          Search Book by its ISBN :");


    char input[40];
    int i = 0, flag = 0; // just like search_by_author

    printf("\n\n\tISBN of the Book = ");
    fflush(stdin);
    gets(input);

    fp = fopen("Books_DB.txt", "r");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        return;
    }

    while(1)
    {
        fread(&b, sizeof(b), 1, fp);

        if(feof(fp))
        {
            break;
        }

        if (strcmp(input, b.isbn) == 0)
        {
            Sleep(30);
            printf("\n\t%c Book#%d : \n", 254, i+1);
            Sleep(30);
            printf("\n\tSerial No. = %s", b.serialno);
            Sleep(30);
            printf("\n\tName       = %s", b.name);
            Sleep(30);
            printf("\n\tAuthor     = %s", b.author);
            Sleep(30);
            printf("\n\tISBN       = %s", b.isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", b.edition);
            Sleep(30);
            printf("\n\tReserved   = %s\n\n\t", b.reserved);
            Sleep(30);

            ++flag;
        }
    }

    if (flag == 0)
    {
        printf("\n\tThere is no book with '%s' ISBN.\n\n\t", input);
        return;
    }
}

void modify_a_book(){
    system("color 1A");
    int i = 0, size = 0, flag = 0;

    char input[30], choice;



    system("cls");

    printf("\n\t\t\t\t\t\t    Modify a Record :");
    printf("\n\n\tThis will modify the contents of the record\n\tin Book_DB Database.\n\n");

    printf("\n\tName of the Book = ");
    fflush(stdin);
    gets(input);

    fp = fopen("Books_DB.txt", "r");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        return;
    }

    while(1)
    {
        fread(&b, sizeof(b), 1, fp);

        if (feof(fp))
        {
            break;
        }
        size++;
    }
    rewind(fp);

    struct book update[size];

    // records are read in array of structures
    while(1)
    {
        fread(&update[i], sizeof(update[i]), 1, fp);

        if (feof(fp))
        {
            break;
        }
        if((strcmp(update[i].name, input) == 0))
        {
            flag++;
        }
        i++;
    }

    if(flag == 0)
    {
        printf("\n\tBook '%s' is not present in Book_DB database.\n\n\t", input);
        Sleep(500);
        menu();
    }

    fclose(fp);

    fp = fopen("Books_DB.txt", "w");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        menu();
    }

    flag = 0;

    for(i = 0; i < size; i++)
    {
        // specified record is selected
        if((strcmp(update[i].name, input) == 0))
        {
            Sleep(30);
            printf("\n\t%c Book#%d : \n", 254, i+1);
            Sleep(30);
            printf("\n\tSerial No. = %s", update[i].serialno);
            Sleep(30);
            printf("\n\tName       = %s", update[i].name);
            Sleep(30);
            printf("\n\tAuthor     = %s", update[i].author);
            Sleep(30);
            printf("\n\tISBN       = %s", update[i].isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", update[i].edition);
            Sleep(30);
            printf("\n\tReserved   = %s\n\n", update[i].reserved);
            Sleep(30);

            printf("\n\tModify this record : ");
            printf("\n\n\tPress 'y' to modify this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            fflush(stdin);
            choice = getche();

            // new data is received on approval
            if(choice == 'y' || choice == 'Y')
            {
                system("cls");

                printf("\n\t\t\t\t\t\t\t\t\t    Modify a Record :");
                printf("\n\n\tThis will alter the contents of Books_DB database.\n");
                printf("\n\n\tBook Name : %s\n", input);

                printf("\n\tEnter the Updated Info:\n");

                printf("\n\tSerial No. = ");
                fflush(stdin);
                gets(update[i].serialno);

                printf("\n\tName = ");
                fflush(stdin);
                gets(update[i].name);

                printf("\n\tAuthor = ");
                fflush(stdin);
                gets(update[i].author);

                printf("\n\tISBN = ");
                fflush(stdin);
                gets(update[i].isbn);

                printf("\n\tEdition = ");
                fflush(stdin);
                gets(update[i].edition);

                printf("\n\tReserved ('Yes'/'No') = ");
                fflush(stdin);
                gets(update[i].reserved);
            }
            else
            fwrite(&update[i], sizeof(update[i]), 1, fp);
        }

    fwrite(&update[i], sizeof(update[i]), 1, fp);
    }
    fclose(fp);
    menu();
}
void display_all_books()
{
    system("color 1A");
    system("cls");

    int i = 0,flag=0;


    fp = fopen("Books_DB.txt", "r");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        return;
    }

    printf("\n\t\t\t\t\t\t    Display all Books : \n\n");

    while (1)
    {
        fread(&b, sizeof(b), 1, fp);

        if(feof(fp))
        {
            break;
        }

        /*Displaying records like this is better because in tabular format
        things get jumbled up if the string length is violated*/
        Sleep(30);
        printf("\n\t%c Book#%d : \n", 254, i+1);
        Sleep(30);
        printf("\n\tSerial No. = %s", b.serialno);
        Sleep(30);
        printf("\n\tName       = %s", b.name);
        Sleep(30);
        printf("\n\tAuthor     = %s", b.author);
        Sleep(30);
        printf("\n\tISBN       = %s", b.isbn);
        Sleep(30);
        printf("\n\tEdition    = %s", b.edition);
        Sleep(30);
        printf("\n\tReserved   = %s\n\n", b.reserved);
        Sleep(30);
        flag++;
        i++;
    }
    if(flag==0){
    	printf("\n\t No Record Found \n\n");
    	Sleep(500);
    	menu();
	}

    printf("\t");
    system("pause");
    fclose(fp);
    menu();
}
void issue_a_book(){
    system("color 1A");
    system("cls");

    char input[30], choice;

    int i = 0, size = 0, flag = 0;

    struct book reserve[30];

    printf("\n\t\t\t\t\t\t    Book Issuing Menu :");
    printf("\n\n\tThis will change the 'Reserved' status of the given record\n\tin Book_DB Database.\n\n");

    printf("\n\tName of the Book = ");
    gets(input);

    fp = fopen("Books_DB.txt", "r");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        menu();
    }

    while(1)
    {
        fread(&reserve[i], sizeof(reserve[i]), 1, fp);

        if (feof(fp))
        {
            break;
        }

        /*Reading records and checking whether mentioned
        book is already reserved or not. If already reserved
        then return to main menu after telling the user.*/
        if((strcmp(reserve[i].name, input) == 0))
        {
            if (strcmp(reserve[i].reserved, "Yes") == 0)
            {
                system("cls");

                printf("\n\t\t\t\t\t\t    Book Issuing Menu :");
                printf("\n\n\tThis will change the 'Reserved' status of the given record\n\tin Book_DB Database.\n\n");

                printf("\n\tEnter Book Name : %s", input);

                printf("\n\n\tBook Name '%s' is already reserved.", input);

                printf("\n\n\t");
                system("pause");
                return;
            }
            flag++;
        }

        i++;
        size++;
    }

    if(flag == 0)
    {
        printf("\n\tBook '%s' is not present in Book_DB database.\n\n\t", input);
        system("pause");
        menu();
    }

    fclose(fp);

    fp = fopen("Books_DB.txt", "w");

    if (fp == NULL)
    {
        puts("\nFile inaccessible\n\n");
        system("pause");
        menu();
    }

    for(i = 0; i < size; i++)
    {
        /*On user's approval the record is searched
        and the specified record's reserved status is altered.*/
        if(strcmp(reserve[i].name, input) == 0)
        {
            Sleep(30);
            printf("\n\tSerial No. = %s", reserve[i].serialno);
            Sleep(30);
            printf("\n\tName       = %s", reserve[i].name);
            Sleep(30);
            printf("\n\tAuthor     = %s", reserve[i].author);
            Sleep(30);
            printf("\n\tISBN       = %s", reserve[i].isbn);
            Sleep(30);
            printf("\n\tEdition    = %s", reserve[i].edition);
            Sleep(30);
            printf("\n\tReserved   = %s %c %s\n\n\t", reserve[i].reserved, 175, "Yes");
            Sleep(30);

            printf("\n\tReserve this Book : ");
            printf("\n\n\tPress 'y' to reserve this book.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            choice = getche();

            if(choice == 'y' || choice == 'Y')
            {
                strcpy(reserve[i].reserved, "Yes");

                system("cls");

                printf("\n\t\t\t\t\t\t    Book Issuing Menu :");
                printf("\n\n\t'Reserved' status of the following book has been altered to 'Yes'\n\tin Book_DB Database.\n\n");

                Sleep(30);
                printf("\n\tSerial No. = %s", reserve[i].serialno);
                Sleep(30);
                printf("\n\tName       = %s", reserve[i].name);
                Sleep(30);
                printf("\n\tAuthor     = %s", reserve[i].author);
                Sleep(30);
                printf("\n\tISBN       = %s", reserve[i].isbn);
                Sleep(30);
                printf("\n\tEdition    = %s", reserve[i].edition);
                Sleep(30);
                printf("\n\tReserved   = %s\n\n\t", reserve[i].reserved);
                Sleep(30);

                system("pause");
            }
        }

        fwrite(&reserve[i], sizeof(reserve[i]), 1, fp);
    }

    fclose(fp);
    menu();
}

