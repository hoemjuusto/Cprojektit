#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*double vectorlength(double x, double y, double z) {
    return sqrt(pow(x,2.0)+pow(y,2.0)+pow(z,2.0));
}
void simple_multiply(){
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);

    int tulo= a*b;

    printf("%d * %d = %d\n", a, b, tulo);
}






void simple_math() {
    /*float a;
    scanf("%f", &a);

    char v;
    scanf("%c", &v);

    float b;
    scanf("%f", &b);*/

    /*float a=0;
    char v=0;
    float b=0;

    scanf("%f %c %f", &a, &v, &b);

    switch (v) {
        case '+':  // ASCII '1' on sama kuin kokonaisluku 49


            printf("%.1f\n", a + b);
            break;

        case '-':


            printf("%.1f\n", a - b);
            break;

        case '/':


            printf("%.1f\n", a / b);
            break;


        case '*':


            printf("%.1f\n", a * b);
            break;

        default:
            printf("ERR\n");
            break;

    }
}





void draw_triangle(unsigned int size){


    int a=1;
    while (a < size+1){
        int i=0;
        while(i < size-a){
            printf(".");
            i++;
        }
        while(i < size){
            printf("#");
            i++;
        }
        printf("\n");
        a++;
    }

}

void ascii_chart(char min, char max){
    int a;
    a = min;
    int c;
    c = a-1;
    int b;
    b = max;

    while(a<=b){

        if((a-c)%4==0&&a!=c) {
            printf("%3d ", a);
            if (a < 16) {
                printf("0x0%x ", a);
            } else {
                printf("0x%x ", a);
            }
            if (isprint(a) == 0) {
                printf("?\n");
            } else {
                printf("%c\n", a);
            }
        } else{
            printf("%3d ", a);
            if (a < 16) {
                printf("0x0%x ", a);
            } else {
                printf("0x%x ", a);
            }
            if (isprint(a) == 0) {
                printf("?\t");
            } else {
                printf("%c\t", a);
            }
        }
        a++;

    }

}

#include <stdio.h>

int array_sum(int *array, int count)
{
    int i;
    int sum;
    sum=0;
    for(i=0; i<count; i++){
        sum+=array[i];
    }
    return sum;
}

int array_reader(int *vals, int n)
{
    int i;
    i=0;
    int j;
    while(i<n){

        int ret;

        int sij;

        ret=scanf("%d", &sij);

        j=i;

        if(!ret) {
            i=n;

        } else{
            vals[i]=sij;
        }
        i++;
    }
    return j;

}

unsigned int arraylen(const char *array)
{
    int i;
    i=0;
    while(array[i]!=0){
        i+=1;
    }
    return i;
}

void countchars(const char *array, unsigned int *counts)
{
    int i;
    for(i=0;i<arraylen(array);i++){
        int a=array[i];
        counts[a]+=1;
    }
}

void sort(int *start, int size)
{
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            if(start[j]>start[i]){
                int vali= start[i];
                start[i]= start[j];
                start[j]=vali;
            }
        }
    }
}


int count_isalpha(const char *str){

    int sum;
    sum=0;
    while (*str != '\0') {  // Repeat until we are at the end of the string
        if (isalpha(*str)) {  // is it a space?
            sum+=1;  // replace it with a period
        }
        str++;  // move pointer to the next character
    }
    return sum;
}

int num_substr(const char *str, const char *sub){
    int sum;
    sum=0;
    while(strstr(str, sub)!=NULL){

        sum+=1;
        char *p;
        p=strstr(str, sub);
        str=p;
        str+=strlen(sub);
    }
    return sum;


}

char *my_toupper(char *dest, const char *src){

    char *p;
    p=dest;

    int a;
    a=0;

    while (a==0) {  // Repeat until we are at the end of the string

        if(*src == '\0'){
            *dest = '\0';
            a=1;
        }else if (*src == '?') {  // is it a space?
            *dest = '!';  // replace it with a period
        }else if (*src == '.') {  // is it a space?
            *dest = '!';
            dest++;
            *dest = '!';
            dest++;
            *dest = '!';// replace it with a period
        } else{
            *dest=toupper(*src);
        }
        src++;
        dest++;// move pointer to the next character
    }



    return p;
}



void qstr_print(const char *s){

    while(*s!='?'){
        printf("%c",*s);
        s++;
    }

}

unsigned int qstr_length(const char *s) {

    unsigned int sum;
    sum = 0;
    while (*s != '?') {  // Repeat until we are at the end of the string
        sum++;
        s++;
    }

    return sum;

}

int qstr_cat(char *dst, char *src){

    int sum;
    sum=0;
    while(*dst!='?'){
        dst++;
        sum++;
    }
    while(*src!='?'){
        *dst=*src;
        dst++;
        src++;
        sum++;
    }

    *dst='?';

    return sum;





}

const char *qstr_strstr(const char *str1, const char *str2){

    while (*str1!='?')
    {
        const char *Begin;
        Begin = str1;
        const char *pattern;
        pattern = str2;
        int errorFound=0;


        while (*str1!='?' && *pattern!='?')
        {
            if(*str1 != *pattern){
                errorFound++;
            }
            str1++;
            pattern++;
        }

        if (errorFound==0)
            return Begin;

        str1 = Begin + 1;
    }
    return NULL;



}

int *create_dyn_array(unsigned int n){

    int *str= malloc(sizeof(int)*n);
    int *origdest;
    origdest = str;

    int i=0;

    while(i<n){
        scanf("%d",str);
        str++;
        i++;
    }

    return origdest;
}

int *add_dyn_array(int *arr, unsigned int num, int newval){


    int *str;
    str = realloc(arr, sizeof(int) * (num + 1) + 1);



    str[num]=newval;

    return str;



}

int *join_arrays(unsigned int lkm1, int *eka, unsigned int lkm2, int *toka, unsigned int lkm3, int *kolmas){

    int *origdest;


    int *str=malloc(sizeof(int)*(lkm1+lkm2+lkm3));
    origdest=str;
    for(int i=0;i<lkm1;i++){
        *str++=*eka++;

    }


    for(int i=0;i<lkm2;i++){
        *str++=*toka++;

    }
    for(int j=0;j<lkm3;j++){
        *str++=*kolmas++;

    }
    return origdest;

}*/

/*char *delete_comments(char *input){

    char *str=malloc(strlen(input)*4);
    char *origdest;
    origdest=str;
    int i=0;

    while(*input&&(i<strlen(input)-1)){
        if(input[i]=='/'&&input[i+1]=='*'){
            while(!(input[i]=='*'&&input[i+1]=='/')){
                i++;
                input++;
            }
            i+=2;
            input+=2;
        } else if(input[i]=='/'&&input[i+1]=='/'){
            while(!(input[i]=='\n')){
                i++;
                input++;
            }
            i++;
            input++;
        } else{
            *str++=*input++;
            i++;
        }

    }

    free(input);
    return origdest;


}
*/

char *delete_comments(char *input) {
    size_t size = strlen(input);
    char *clean = malloc(size + 100);
    int multiline = 0;
    int cleanindex = 0;
    int singleline = 0;
    for (int i = 0; i < size; i++) {
        if ((input[i] == '/') && (input[i + 1] == '*')) {
            multiline = 1;
        }
        else if ((input[i] == '*') && (input[i + 1] == '/')&&(multiline==1)) {
            multiline = 0;
            i += 1;
        }
        else if ((input[i] == '/') && (input[i + 1] == '/')) {
            singleline = 1;
        }
        else if ((input[i] == '\n')&&(singleline==1)) {
            singleline = 0;
        }
        else if ((multiline == 0)&&(singleline==0)) {
            clean[cleanindex] = input[i];
            cleanindex += 1;
        }
    }
    clean[cleanindex] = 0;
    free(input);
    return clean;

}


char *read_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;

    char *buf = NULL;
    unsigned int count = 0;
    const unsigned int ReadBlock = 100;
    unsigned int n;
    do {
        buf = realloc(buf, count + ReadBlock + 1);
        n = fread(buf + count, 1, ReadBlock, f);
        count += n;
    } while (n == ReadBlock);

    buf[count] = 0;

    fclose(f);
    return buf;
}










