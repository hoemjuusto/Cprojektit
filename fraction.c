#include <stdlib.h>
#include "fraction.h"

/* Algorithm for determining greatest common divisor, needed in (d) */
/* The function returns gcd between the two parameters, u and v */
/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

Fraction* setFraction(unsigned int numerator, unsigned int denominator){
    Fraction *f=malloc(sizeof(struct fraction_st));
    f->numerator=numerator;
    f->denominator=denominator;
    return f;
}

void freeFraction(Fraction* f){
    free(f);
}
unsigned int getNum(const Fraction *f){
    return f->numerator;
}
unsigned int getDenom(const Fraction *f){
    return f->denominator;
}
int compFraction(const Fraction *a, const Fraction *b){
    double ao=(double)a->numerator;
    double an=(double)a->denominator;
    double bo=(double)b->numerator;
    double bn=(double)b->denominator;

    if((ao/an)<(bo/bn)){
        return -1;
    } else if((ao/an)==(bo/bn)){
        return 0;
    } else{
        return 1;


    }


}

Fraction *addFraction(const Fraction *a, const Fraction *b){
    unsigned int ao=a->numerator;
    unsigned int an=a->denominator;
    unsigned int bo=b->numerator;
    unsigned int bn=b->denominator;

    ao=ao*bn;
    bo=bo*an;
    an=an*bn;
    bn=bn*an;

    return setFraction(ao+bo,an);



}

void reduceFraction(Fraction *val){
    unsigned  int a=val->numerator;
    unsigned  int b=val->denominator;
    val->denominator=val->denominator/gcd(a,b);
    val->numerator=val->numerator/gcd(a,b);
}
