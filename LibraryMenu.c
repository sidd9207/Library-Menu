#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdbool.h>

struct book {
	int accessionNumber;
	char bookTitle[50];
	char authorName[50];
	float bookPrice;
};

int main() {
	struct book index[25];
	int counter = 0;

	int breakLoop = 0;

	while (breakLoop < 1) {
		fflush(stdin);
		int input = 0;

		while ((input < 1) || (input > 7)) {
			printf("Enter a number from 1 to 7: ");
			scanf_s("%d", &input);
			fflush(stdin);
		}
		fflush(stdin);

		switch (input) {
			
			// adds a book to index
			case 1:
			{
				bool add = true;
				if (counter >= 25) {
					printf("No more books can be added\n");
					add = false;
				}

				if (add == true) {
					index[counter].accessionNumber = counter;

					printf("Enter Book Title: ");
					scanf_s("%s", &index[counter].bookTitle, 50);
					fflush(stdin);

					printf("Enter Author Name: ");
					scanf_s("%s", &index[counter].authorName, 50);
					fflush(stdin);

					printf("Enter Book Price: ");
					scanf_s("%f", &index[counter].bookPrice);
					fflush(stdin);

					counter++;
				}
				
				break;
			}
			
			//allows user to request information of a book based on accession number
			case 2:
			{
				int request;
				printf("What is the accession number of the book you want information about?: ");
				scanf_s("%d", &request);
				fflush(stdin);

				if (request < counter) {
					printf("Book Title: %s\nAuthor Name: %s\nBook Price: %f\n", index[request].bookTitle, index[request].authorName, index[request].bookPrice);
				}
				else {
					printf("No book found\n");
				}

				break;
			}

			//outputs all novels by a requested author 
			case 3:
			{
				char request[20];
				printf("Enter author you are interested in: ");
				scanf_s("%s", &request, 50);
				fflush(stdin);
				if (counter == 0) {
					printf("There are no books in library\n");
				}
				else {
					printf("Books by the author are: ");
					for (int i = 0; i < counter; i++) {
						int ans = strcmp(index[i].authorName, request);
						if (ans == 0) {
							printf("%s, ", index[i].bookTitle);
						}
					}
					printf("\n");
				}
				break;
			}

			//outputs the title of the book with requested accession number
			case 4:
			{
				int request;
				printf("Enter book number: ");
				scanf_s("%d", &request);
				fflush(stdin);

				if (request >= counter) {
					printf("There is no book with the requested number\n");
				}
				else {
					printf("Book Title: %s\n", index[request].bookTitle);
				}

				break;
			}

			//outputs the number of books in the library
			case 5:
			{
				printf("There are %d books in the library\n", counter);
				break;
			}

			//outputs all books that are stored in the library
			case 6:
			{
				for (int i = 0; i < counter; i++) {
					printf("%s\n", index[i].bookTitle);
				}
				break;
			}

			//allows user to exit the menu and program
			case 7:
			{
				breakLoop = 1;
			}
		}
	}
	return 0;
}