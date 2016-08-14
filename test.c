#include <stdio.h>
#include <stdlib.h>
#include "detect.h"

int main(int argc, char *argv[]) {
	const unsigned int uid = 233;
	int i;

	for (i = 1; i < argc; i++) {
		bxcMsgInput(argv[i],uid);
	}

	printf("%f\n",bxcGetTotalWeight(uid));
}
