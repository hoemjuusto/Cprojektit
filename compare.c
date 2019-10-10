#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include <stdarg.h>



typedef struct {
    char name[31];
    float price;
    int in_stock;
} Product;


/* Compare two strings lexically (ASCII value-wise, same as strcmp())
 * The string "duck" is before "rabbit" in this order but
 *  "Rabbit" is before "duck" (see an ASCII chart)
 * Returns: 0 if the two strings are equal
 * Hint: strcmp
 */
int compareAlpha(const void* a, const void* b){
    const Product *name_a = a;
    const Product *name_b = b;

    // first compare the last names
    int res;
    res = strcmp(name_a->name, name_b->name);

    return res;
}

/* Same as compareAlpha but compares the product *in_stock* numerically.
 * The product with higher *in_stock* -value should be first in the array.
 * If there are two or more products with same *in_stock* -value, they are compared lexically.
 */
int compareNum(const void* a, const void* b){
    const Product *product_a = a;
    const Product *product_b = b;

    if(product_a->in_stock<product_b->in_stock){
        return 1;
    } else if(product_a->in_stock>product_b->in_stock){
        return -1;
    } else{
        return compareAlpha(product_a,product_b);
    }


}

/* Finds a product from a sorted array of products
 * Returns: Whatever bsearch returned.
 * IMPORTANT: Remember that bsearch takes a pointer to a type as first parameter, and 
 * pointer to an array with same type elements as in first parameter.
 */
Product* findProduct(Product* p_array, const char* searchkey, int (*cmp)(const void*, const void*)){
    Product *a=malloc(sizeof(Product));
    char nimi[100];
    strcpy(nimi,searchkey);
    strcpy(a->name,nimi);
    int i=0;
    while(p_array[i].name[0]!=0){
        i++;
    }
    Product *ret=bsearch(a,p_array,i, sizeof(Product),cmp);

    free(a);
    return ret;


}