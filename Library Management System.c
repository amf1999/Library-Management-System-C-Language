#include <stdio.h>
#include <string.h>

struct library
{
	int accessionNum;
	char title[50];
	char author[30];
	int price;
	int flag;   
	
}   obj[50] = { 1, "OOP", "Paul", 358, 1,
	2, "Data Structures And Algorithms", "Mark Allen", 400, 1,
	3, "Harry Potter : The Philosopher's Stone", "J. K. Rowling", 550, 0,
	4, "Effective Java", "Joshua Bloch", 425, 1,
	5, "Data Communications", "Paul", 258, 0};

int main()
{

    int choice = 1, accessionNum;
	char auth[30];
	while (choice != 6)
	{
		
		printf("\n\t\t--------LIBRARY MANAGEMENT SYSTEM--------\n\n");
		printf("\n1. Add Book Information");
		printf("\n2. Display Book Information");
		printf("\n3. List all books of given author");
		printf("\n4. List the title of specified book");
		printf("\n5. List the counts of the books in library");
		printf("\n6. Exit");
		printf("\n\tEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				addBook();
				break;
				
			case 2:
				printf("\nEnter the accession number of the book : ");
				scanf("%d", &accessionNum);
				displayBookInfo(accessionNum);
				break;
				
			case 3:
				while (getchar() != '\n');
				getBookByAuthor();
				break;
				
			case 4:
				printf("\nEnter the accession number of book : ");
				scanf("%d", &accessionNum);
				getBookByTitle(accessionNum);
				break;
				
			case 5:
				printf("\nTotal Number of books : %d", countBooks());
				break;
				
			case 6:
			   choice = 6;
				break;
		
			default:
				printf("\nWrong choice!!");
				break;

		}
	}
	return 0;
}


void addBook()
{
	int next = countBooks();
	obj[next].accessionNum = next + 1; //start after last record

	while (getchar() != '\n');
	
		printf("\nEnter the title of the book : ");
		gets(obj[next].title);
		printf("\nEnter the author name of the book : ");
		gets(obj[next].author);
		printf("\nEnter the price of the book : ");
		scanf("%d", &obj[next].price);
		obj[next].flag = 1;	

}

void displayBookInfo(int i)
{
	i--;  //as index starts with 0
	printf("\n\n\n");
	printf("\nAccession Number : %d", obj[i].accessionNum);
	printf("\nTitle : %s", obj[i].title);
	printf("\nAuthor : %s", obj[i].author);
	printf("\nPrice : %d", obj[i].price);
	
	if (obj[i].flag ==0) 
	{
		printf("\nStatus : Book Issued");
	}
	else
	{
		printf("\nStatus : Book Available");
	}
}


void getBookByTitle(int accessionNum)
{
	
	int i = 0;
	while (obj[i].accessionNum)
	{
		if (obj[i].accessionNum == accessionNum)
		{
			printf("\n\nTitle of the book : %s\n", obj[i].title);
			return;
		}
		i++;
	}
	
	printf("No book found\n");

	 
}

int countBooks()
{
	int count = 0;
	while (obj[count].accessionNum)
	{
		count++;
	}
	
	return count;
}


void getBookByAuthor()
{
	 int i,count=0;
	 char name[20];
	 
	 printf("\nEnter name of author (case sensitive): ");
	 gets(name);
	 
	 for(i=0;i<countBooks();i++)
	 {
		  if(strcmp (name , obj[i].author)==0)
		  {
		   count++;
		   printf("\n %s \n",obj[i].title);
		  }
	 }
	 
	 if(count==0)
	 {	 
	    printf("\n There is no such book! \n");
	 }
}

