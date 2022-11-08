#include <stdio.h>
#include <inttypes.h>

#define LIMIT 1000000


int numofprimefacts[LIMIT];

/* Erato-like sieve*/
void init() {
	int i, j;

	for (i = 2; i < LIMIT; i++) {
		if (numofprimefacts[i] == 0) { //Prime
			for (j = i; j < LIMIT; j += i) {
				numofprimefacts[j]++; //Every mult: factors+1
			}
		}
	}

}

int main()
{
    int target = 4; //target = 3 to try the statement example

    init();

    int found = 0;
    int j;
    for(int i = target + 1; !found && i < LIMIT; i++){
        found = 1;
        for(j = i - target+1; found && j<=i; j++){
            found = (numofprimefacts[j]==target);
        }
    }

    if(found){
        for(int k = j - target;  k < j; k++){
            printf("%d ", k);
        }
        printf("\n");
    }else{
        printf("NOT FOUND\n");
    }

}

