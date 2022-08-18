#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

void SUB(long h1, long m1, long h2, long m2, long* dest) {
    if(m1-m2<0) {
        dest[1] = m1 + 60 - m2;
        dest[0] = h1-h2-1;
    }else {
        dest[1] = m1 - m2;
        dest[0] = h1-h2;
    }
}

void ADD(long h1, long m1, long h2, long m2, long* dest) {
    if(m1+m2>59) {
        dest[1] = m1 + m2 - 60;
        dest[0] = h1 + h2 + 1;
    }else {
        dest[1] = m1 + m2;
        dest[0] = h1 + h2;
    }
}

int main(int chingon, char* chingonas[]) {
    if(chingon != 4){
        printf("Error.\n");
        return 0;
    }
    if(strtol(chingonas[1],NULL,10) >= strtol(chingonas[2],NULL,10) || strtol(chingonas[2],NULL,10) >= strtol(chingonas[3],NULL,10)) {
        printf("Error.\n");
        return 0;
    }

    long hour[3];
    long min[3];

    for(int i=1; i<chingon; i+=1) {
        char temphour[3]; char tempmin[3];
        int ind = strlen(chingonas[i])-2;
        
        memcpy(temphour, chingonas[i], ind);
        memcpy(tempmin, &(chingonas[i][ind]), 2);

        temphour[ind] = '\0';
        tempmin[2] = '\0';
        
        hour[i-1] = strtol(temphour,NULL,10);
        min[i-1] = strtol(tempmin,NULL,10);
    }

    long before[2];
    long after[2];
    long out[2];
    // out = 8 + in + lunch_in - lunch_out
    // in       lunch_out           lunch_in

    // before = lunch_out - in
    SUB(hour[1],min[1],hour[0],min[0],before);
    // after = 8 - before
    SUB(8,0,before[0],before[1],after);
    // out = lunch_in + after
    ADD(hour[2],min[2],after[0],after[1],out);

    if(out[1] < 10) {
        printf("Clock out at %ld:0%ld\n",out[0],out[1]);
    } else {
        printf("Clock out at %ld:%ld\n",out[0],out[1]);
    }
    /*for(int i=1; i<chingon; i+=1) {
        printf("str: %s\tstrlen: %lu\n", chingonas[i], strlen(chingonas[i]));
    }*/

    return 0;
}