#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int chingon, char* chingonas[]) {
    char beginning[50];
    char end[50];
    
    printf("str:\t%s\n", chingonas[1]);

    memcpy(beginning,chingonas[1], 3);
    memcpy(end, &(chingonas[1][6]),3);
    beginning[3] = '\0';
    end[3] = '\0';

    printf("beginning:\t%s\n", beginning);
    printf("end:\t%s\n", end);

    char ape[3] = {'1','2','\0'};
    printf("strtol%lu\n", strtol(ape,NULL,10));

    
    return 0;
}