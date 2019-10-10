//
// Created by Juuso on 11.2.2019.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include <stdarg.h>


struct date {
    unsigned char day;
    unsigned char month;
    int year;
};


struct book {
    char id[10];
    char *title;
    char *author;
    struct date release_date;
};

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char * p_author, struct date p_release){

    if(strlen(p_id)<=9) {

        strcpy(p_book->id,p_id);
        p_book->title = realloc(p_book->title, sizeof(p_title) + 100);

        strcpy(p_book->title, p_title);

        p_book->author = realloc(p_book->author, sizeof(p_author) + 100);

        strcpy(p_book->author, p_author);

        p_book->release_date=p_release;

        return  1;
    } else{
        return 0;
    }


}
struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book){

    struct book *newbook = realloc(collection,sizeof(struct book)*(size+2));
    newbook[size].title = malloc(strlen(new_book.title) + 100);
    strcpy(newbook[size].title, new_book.title);
    newbook[size].author = malloc(strlen(new_book.author) + 100);
    strcpy(newbook[size].author, new_book.author);
    strcpy(newbook[size].id, new_book.id);
    newbook[size].release_date = new_book.release_date;
    return newbook;

}

void delete_collection(struct book *collection, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        free(collection[i].title);
        free(collection[i].author);
    }
    free(collection);
}

char **init_string_array(void){
    char** taulu=malloc(sizeof(char*)+100000);
    taulu[0]=NULL;
    return taulu;
}
void release_string_array(char **arr){
    int i=0;
    while(arr[i]!=NULL){
        free(arr[i]);
        i++;
    }

    free(arr);


}
char **insert_string(char **arr, const char *str){

    int i=0;
    while(arr[i]!=NULL){
        i++;
    }

    arr[i]=malloc(sizeof(char*)+100);
    strcpy(arr[i], str);
    arr[i+1]=NULL;

    return arr;


}



void sort_string_array(char **arr){
    int i=0;

    while(arr[i]!=NULL){
        int j=1;
        while(arr[i+j]!=NULL){
            if(strcmp(arr[i+j],arr[i])<0){
                char *vali= arr[i];
                arr[i]= arr[i+j];
                arr[i+j]=vali;
            }
            j++;
        }
        i++;
    }
}


void print_string_array(char **arr)
{
    if (!arr)
        return;
    while (*arr) {
        printf("%s  ", *arr);
        arr++;
    }
    printf("\n");
}

int myprint(const char *str, ...){

    int howMany=0;

    char * pch;
    pch=strchr(str,'&');
    while (pch!=NULL)
    {
        howMany++;

        pch=strchr(pch+1,'&');
    }


    va_list args;
    int j=0;

    va_start(args, str);
    for (int i = 0; i < howMany; i++) {
        while(str[j]!='&'){
            printf("%c",str[j]);
            j++;
        }

        printf("%d", va_arg(args, int));
        j++;
    }
    va_end(args);
    return howMany;


}



int main(void)
{
    char **string_array = init_string_array();

    string_array = insert_string(string_array, "oNe");
    string_array = insert_string(string_array, "TWO");
    string_array = insert_string(string_array, "three");
    string_array = insert_string(string_array, "Four");

    print_string_array(string_array);

    //make_lower(string_array);
    sort_string_array(string_array);

    print_string_array(string_array);
    release_string_array(string_array);

    return EXIT_SUCCESS;
}
