#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


struct tcpHeader {
    unsigned short src_port;
    unsigned short dest_port;
    unsigned int seq_number;
    unsigned int acknowledgment;
    unsigned int offset;  // in bytes
    char ns;
    char cwr;
    char ece;
    char urg;
    char ack;
    char psh;
    char rst;
    char syn;
    char fin;
    unsigned int window;
    unsigned int checksum;
    unsigned int urg_ptr;
};


int getSourcePort(const unsigned char *tcp_hdr){

    unsigned char a = tcp_hdr[0];
    unsigned char b = tcp_hdr[1];
    uint16_t i = ((uint16_t) a)<<8;
    i += (uint16_t) b;

    return i;


}

int getDestinationPort(const unsigned char *tcp_hdr){

    unsigned char a = tcp_hdr[2];
    unsigned char b = tcp_hdr[3];
    uint16_t i = ((uint16_t) a)<<8;
    i += (uint16_t) b;

    return i;

}
int getAckFlag(const unsigned char *tcp_hdr){
    unsigned char tavu = tcp_hdr[13];
    unsigned char verrokki=0x80;

    verrokki=verrokki>>3;

    if(tavu&verrokki){
        return 1;
    } else{
        return 0;
    }

}

int getDataOffset(const unsigned char *tcp_hdr){
    int tavu = tcp_hdr[12];

    tavu=tavu>>4;

    return  tavu;
}


void setSourcePort(unsigned char *tcp_hdr, int port){
    int a=port>>8;
    unsigned char b=a;
    unsigned char c=port;
    tcp_hdr[0]=b;

    tcp_hdr[1]=c;



}
void setDestinationPort(unsigned char *tcp_hdr, int port){
    int a=port>>8;
    unsigned char b=a;
    unsigned char c=port;
    tcp_hdr[2]=b;

    tcp_hdr[3]=c;
}
void setAckFlag(unsigned char *tcp_hdr, int flag){

    unsigned  char verrokki=0x80>>3;

    unsigned  char a=tcp_hdr[13];

    if(flag==0){


        tcp_hdr[13]=a^verrokki;

    }else{
        tcp_hdr[13]=a|verrokki;
    }
}
void setDataOffset(unsigned char *tcp_hdr, int offset){
    unsigned char a=tcp_hdr[12];
    a=a<<4;a=a>>4;
    unsigned char b=(offset<<4);
    tcp_hdr[12]=b|a;
}
