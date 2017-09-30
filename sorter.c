#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sorter.h"
#include "mergesort.c"


char* trim(char* s) {


    char* news = malloc(sizeof(char) * 400);

    int i;
    for(i = 0; isspace(s[i]) != 0; i++);

    printf("start is %d\n",i);

    int j;
    for(j = i; s[j] != '\0';j++);

    j--; /// So it does not count null char

    for(; isspace(s[j]) != 0; j--);

    printf("end is %d\n",j);


    int count = 0;
    for(count = 0; i <= j; i++) {

       news[count] = s[i];
       count++;
    }

    news[count] = '\0';

    return news;


}



/// ***It works on most input but it can not find commas at the end of a line ***
/// ***Trim all the whitespace
/// RATING: B- Needs more testing
char** parseCSV(char* line) {

    /// There are 28 items per movie
    char** splitString = malloc(sizeof(char*) * 29);  /// Array of strings that contain csv data
                                                      /// Missing data is denoted by "-1"
    splitString[29] = '\0';  /// NUll character to signify end of string array



    printf("strlen is %d\n", strlen(line));


    char* start = line;  /// Pointer to first index of csv line
    char* end = strchr(start, ',');  /// Pointer to first comma of csv line

    printf("new start is %c \n", *(start));
    printf("new end is %c \n", *(end));


    /// Parses string to get each value within csv line and places it in each index of splitString
    int i;
    for(i = 0; end != NULL; i++) {  /// Continues until last comma is reached

        if(*start == ',') {  /// If there is no data in category; stops looping when data is found

            while(*start == ',') {  /// Loops until it finds next set of data
                                    /// Places a -1 if data category is empty

                splitString[i] = "-1\0";
                i++;  /// increments to next open spot in array
                start++;  /// increments to next char in string
            }
            i--;  /// Decrements i by 1; Without this it will create an empty space in array
                     /// due to the loop incrementing i at the end of iteration

            end = strchr(start, ',');  /// Gets the next comma at the end of data

        } else {  /// If there is data in category

            splitString[i] = malloc(sizeof(char) * 400);  /// allocates space for data in array index

            memcpy(splitString[i], start, end - start);  /// copies data to appropriate index
                                                         /// end - start subtracts the memory addresses to find out
                                                         /// how many bytes data is

            splitString[i][end - start] = '\0';  /// Place NULL char at end of string

            printf("split s is %s \n", splitString[i]);


            start = end + 1;  /// Places start at the beginning of next string

            printf("new start is %c \n", *(start));


            end = strchr(start, ',');   /// Places end at the end of next string

        }

    }

     /// Since the loop checks for commas after data to check if there is another string
    /// This must get last string in csv line


    end = strchr(start, '\0');  ///  Sets end to the last char in string


    printf("FFFstart is %c\n",*(end-1));
    if(*(end-1) == ',') {
        printf("hello");
        splitString[i] = "-1\0";
    } else {



        splitString[i] = malloc(sizeof(char) * 400);  /// allocates space for data in array index

        memcpy(splitString[i], start, end - start);  /// copies data to appropriate index
                                                     /// end - start subtracts the memory addresses to find out
                                                     /// how many bytes data is

        splitString[i][end - start] = '\0';   /// Place NULL char at end of string


        printf("The winner is %s \n", splitString[i]);
    }

    return splitString;
}

node* root;  /// the head of linked list
node* lastNode;  /// the last node in the linked list

/// DONT FORGET TO FREE NODES WHEN FINISHED!!!!!!

void addNode(char** splitString) {

    node *newNode =  malloc(sizeof(node));  /// creates new newNode to be inserted

    newNode->category = malloc(sizeof(char*) * 28);
    newNode->category[28] = '\0';

    int i;
    for(i = 0; i < 28; i++) {

        newNode->category[i] = malloc(sizeof(char) * 400);
        newNode->category[i] = trim(splitString[i]);

    }

    /// place data in node
    /// ***Trim all the spaces in Strings***

     if (root == NULL) {  /// if there are no nodes in linked list

        root = newNode;  /// set the root to first node
        newNode->next = NULL;  /// sets the next to null
        lastNode = newNode;  /// sets the last node pointer in linked list to the new node

    } else {  /// if it is not the first node in linked list

        lastNode->next = newNode;  /// last node pointer is set to new node
        newNode->next = NULL;  /// sets new node to null since it is last in list
        lastNode = newNode;  /// last node pointer is set to the new node at the end
    }

}

int getSearchIndex(char* argv[], char** cat_name) {

    if(strcmp(argv[1],"-c") != 0) {

        printf("Input Error\nProgram Terminated\n");
        exit(0);
    }

    int i;
    for(i = 0; i < 28; i++){
            printf("i is %d\n",i);

        if(strcmp(cat_name[i], argv[2]) == 0) {

            return i;
        }
    }

    if(strcmp("movie_facebook_likes",argv[2]) == 0) {

        return 27;
    }


    printf("Input Error\nProgram Terminated\n");
    exit(0);
}


void csvOutput(node* root) {

    node* n = root;

    while(n != NULL) {

       int i;
       for(i = 0; i < 27; i++) {

            if(strcmp(n->category[i],"-1") != 0) {

                printf("%s,",n->category[i]);


            } else {

                 printf(",");
            }

       }

       printf("%s",n->category[27]);  /// Prints last category without a comma


        n = n->next;

        printf("\n\n\n");

    }
}

void freeNodes() {

    node* front = root->next;

    while(root != NULL) {

        free(root->category);

        free(root);

        root = front;

        if(front != NULL) {

            front = front->next;
        }

    }
}




int main(int argc, char *argv[]) {

    char line[1024];  /// Buffer to put read in lines

    fgets(line, 1024, stdin);  /// Reads in line with the category names

    char** cat_name = parseCSV(line);  /// Puts category names in array

    int n = getSearchIndex(argv,cat_name);  /// Checks for errors in command line; returns index number to be searched on


    while(fgets(line, 1024, stdin) != NULL) {  /// Goes through each line in CSV file

        char** k = parseCSV(line);  /// Parses the line; puts data into array

        addNode(k);  /// add the data to a node

    }


    /// PUT YOUR MERGE SORT HERE!!!!!!!!

    //mergesort(root,n);

    csvOutput(root); /// Outputs data into CSV format to STDOUT

    freeNodes();


    return 0;
}
