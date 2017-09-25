#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {

    char* color; /// boolean????
    char* director_name;
    int num_critic_for_reviews;
    int duration;
    int director_fb_likes;
    int actor_3_likes;
    char* actor_2_name;
    int actor_1_fb_likes;
    int gross;  /// double?????
    char* genres; /// array that holds multiple genre strings
    char* actor_1_name;
    char* movie_title;
    int num_voted_users;
    int cast_total_fb_likes;
    char* actor_3_name;
    int facenumber_in_poster;
    char* plot_keywords; /// array that holds multiple plot keyword strings
    char* movie_imdb_link;
    int num_user_for_reviews;
    char* language;
    char* country; ///?????
    char* content_rating;
    int budget; /// double???
    int title_year;
    int actor_2_fb_likes;
    double imdb_score;
    double aspect_ratio;
    int movie_fb_likes;

    struct node* next;

}node;


/// ***It works on most input but it can not find commas at the end of a line ***
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

    splitString[i] = malloc(sizeof(char) * 400);  /// allocates space for data in array index

    memcpy(splitString[i], start, end - start);  /// copies data to appropriate index
                                                     /// end - start subtracts the memory addresses to find out
                                                     /// how many bytes data is

    splitString[i][end - start] = '\0';   /// Place NULL char at end of string


    printf("The winner is %s \n", splitString[i]);


    return splitString;
}

node* root;  /// the head of linked list
node* lastNode;  /// the last node in the linked list

/// DONT FORGET TO FREE NODES WHEN FINISHED!!!!!!

void addNode(char** splitString) {

    node *newNode =  malloc(sizeof(node));  /// creates new newNode to be inserted

    /// place data in node
    /// ***Trim all the spaces in Strings***
    newNode->color = splitString[0];
    newNode->director_name = splitString[1];
    newNode->num_critic_for_reviews = atoi(splitString[2]);
    newNode->duration = atoi(splitString[3]);
    newNode->director_fb_likes = atoi(splitString[4]);
    newNode->actor_3_likes = atoi(splitString[5]);
    newNode->actor_2_name = splitString[6];
    newNode->actor_1_fb_likes = atoi(splitString[7]);
    newNode->gross = atoi(splitString[8]);
    newNode->genres = splitString[9];       /// Put all the genres in array
    newNode->actor_1_name = splitString[10]; /// Do this for all categories with many entries
    newNode->movie_title = splitString[11];  /// Get rid of weird character at the end of movie_title; maybe trim will fix
    newNode->num_voted_users = atoi(splitString[12]);
    newNode->cast_total_fb_likes = atoi(splitString[13]);
    newNode->actor_3_name = splitString[14];
    newNode->facenumber_in_poster = atoi(splitString[15]);
    newNode->plot_keywords = splitString[16];
    newNode->movie_imdb_link = splitString[17];
    newNode->num_user_for_reviews = atoi(splitString[18]);
    newNode->language = splitString[19];
    newNode->country = splitString[20];
    newNode->content_rating = splitString[21];
    newNode->budget = atoi(splitString[22]);
    newNode->title_year = atoi(splitString[23]);
    newNode->actor_2_fb_likes = atoi(splitString[24]);
    newNode->imdb_score = atof(splitString[25]);   /// Edit the double for precision EX. 7.10000000
    newNode->aspect_ratio = atof(splitString[26]);  /// Do this for all double values
    newNode->movie_fb_likes = atoi(splitString[27]);

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



int main(int argc, char *argv[]) {









    /// Code to test the linked list
    /*
    char* s = ",Doug Walker,,,131,,Rob Walker,131,,Documentary,Doug Walker,Star Wars: Episode VII - The Force Awakens             ,8,143,,0,,http://www.imdb.com/title/tt5289954/?ref_=fn_tt_tt_1,,,,,,,12,7.1,,0";

    char* k = "Color,James Cameron,723,178,0,855,Joel David Moore,1000,760505847,Action|Adventure|Fantasy|Sci-Fi,CCH Pounder,Avatar ,886204,4834,Wes Studi,0,avatar|future|marine|native|paraplegic,http://www.imdb.com/title/tt0499549/?ref_=fn_tt_tt_1,3054,English,USA,PG-13,237000000,2009,936,7.9,1.78,33000";

    char **n = parseCSV(k);

    addNode(n);

    n = parseCSV(s);

    addNode(n);


    node* p = root;

    printf("\n");
    printf("\n");

    int i;
    for(i = 0; i < 2; i++) {

        printf("Color is %s\n",p->color);
        printf("Director is %s\n",p->director_name);
        printf("Gross is %d\n",p->gross);
        printf("Genres is %s\n",p->genres);
        printf("Movie title %s\n",p->movie_title);
        printf("Plot Keywords is %s\n",p->plot_keywords);
        printf("Imdb Score %lf", p->imdb_score);

        p = p->next;


        printf("\n");
        printf("\n");
    }

*/


    return 0;

}
