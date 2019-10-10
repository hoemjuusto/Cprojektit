//
// Created by Juuso on 13.3.2019.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#include "bits.h"


void op_bit_set(unsigned char* data, int i){
    int dataindeksi=i/8;
    int indeksi=i%8;

    unsigned char tavu=data[dataindeksi];

    unsigned char verrokki=0x80;

    verrokki=verrokki>>indeksi;

    data[dataindeksi]=tavu|verrokki;


}

void op_bit_unset(unsigned char* data, int i){
    int dataindeksi=i/8;
    int indeksi=i%8;

    unsigned char tavu=data[dataindeksi];

    unsigned char verrokki=0x80;

    verrokki=verrokki>>indeksi;

    data[dataindeksi]=tavu^verrokki;
}

int op_bit_get(const unsigned char* data, int i){

    int dataindeksi=i/8;
    int indeksi=i%8;

    unsigned char tavu=data[dataindeksi];

    unsigned char verrokki=0x80;

    verrokki=verrokki>>indeksi;

    if(tavu&verrokki){
        return 1;
    } else{
        return 0;
    }

}



void op_print_byte(unsigned char b){
    for (int i = 7; i >= 0; i--) {
        // (1 << i) generates value where only i'th bit is set
        // value & (1 << i)) is non-zero only if i'th bit is set in value
        if (b & (1 << i))
            printf("1");
        else
            printf("0");
    }
}

unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many){
    int amountofzeros=8-how_many;
    int j=0;
    int a;
    unsigned char tavu=0xff; //1000 0000 0100 0000 = 0000 0000
    unsigned char verrokki;
    while(j<how_many){
        a=op_bit_get(data,i+j);
        if(a==0){
            verrokki=0x80;

            verrokki=verrokki>>j;

            tavu=tavu^verrokki;
        }else{
            verrokki=0x80;

            verrokki=verrokki>>j;

            tavu=tavu|verrokki;


        }
        j++;


    }
    tavu=tavu>>amountofzeros;
    return tavu;


}
