#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

void SUB(long* one, long* two, long* dest);
void ADD(long* one, long* two, long* dest);

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
        memcpy(tempmin, &(chingonas[i][ind]), 2)

        temphour[ind] = '\0';
        tempmin[2] = '\0';
        
        hour[i-1] = strtol(temphour,NULL,10);
        min[i-1] = strtol(tempmin,NULL,10);
    }

    // before = lunch_out - in
    // after = 8 - before
    // out = lunch_in + after


    // out = 8 + in + lunch_in - lunch_out

    for(int i=1; i<chingon; i+=1) {
        printf("str: %s\tstrlen: %lu\n", chingonas[i], strlen(chingonas[i]));
    }

    return 0;
}