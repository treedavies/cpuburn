#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * cpuburn
 * Author: Tree Davies <tdavies@darkphysics.net>
 * Burn CPU cycles to test for thermal event
 * */

void burn(){
	long double nums[10000];
	srand(time(NULL));

	int i;
	for(i = 0; i<10000; i++) {
		nums[i] = rand();
	}

	while(1){
		for(i = 0; i<9998; i++) {
			nums[i] = sqrt(nums[i]) / 2.7125 * sqrt(nums[i+1]) / 3.141596254 ;
		}
	}
}

int main(int argc, char* argv[]) {
	int proc_nr;
	if (argc < 2)
		proc_nr = 1;
	else {
		proc_nr = atoi(argv[1]);
		if (proc_nr<1)
			proc_nr = 1;
	}

	int y;
	for( y = 0; y < proc_nr; y++){
		pid_t child = fork();

		if(child == 0) {
			burn();
		}
		else {
			printf("\n Parent...\n");        
		}
	}
}


