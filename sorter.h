#ifndef SORTER_H_INCLUDED
#define SORTER_H_INCLUDED

typedef struct node {


    char** category;

    struct node* next;

}node;

char** parseCSV(char* line);

void addNode(char** splitString);

int getSearchIndex(char* argv[], char** cat_name);

void csvOutput(node* root);

char* trim(char* s);

#endif // SORTER_H_INCLUDED
