#include <stdlib.h>
#include <string.h>

#include "badWords.h"

struct node {
	unsigned int id;
	float totalWeight;
	struct node *next;
};

static struct node *listStart = NULL;

static int getCount (const char *str, const char *p) {
	int c = 0;
	int len = strlen(p);
	while( (str = strstr(str,p)) != NULL ) {
		str += len;
		c++;
	}
	return c;
}

static inline void initNode (struct node *n, unsigned int id) {
	n -> id = id;
	n -> totalWeight = 0.0;
	n -> next = NULL;
}

static struct node *findUserById (unsigned int id) {
	struct node *current = listStart;

	for(;; current = current -> next) {
		if(current -> id == id) return current;
		if(current -> next == NULL) break;
	}

	current = (current -> next = malloc(sizeof(struct node)));
	initNode(current, id);

	return current;
}

static void __attribute__((constructor)) bxcInit (void) {
	listStart = malloc(sizeof(struct node));
	initNode(listStart, 0xffffffff);
}

void bxcMsgInput (const char *msg, unsigned int id) {
	int i;

	struct node *user=NULL;

	user = findUserById(id);

	for(i = 0; i < badWordSize; i++) user -> totalWeight += (wordWeights[i] * getCount(msg, badWords[i]));
}

float bxcGetTotalWeight (unsigned int id) {
	return findUserById(id) -> totalWeight;
}

