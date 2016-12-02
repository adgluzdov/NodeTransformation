#include "add.h"
#include <stdio.h>


void transform(CNode* HEAD){
	if(HEAD == NULL)
		throw 1;
	CNode* VANGA = HEAD;
	CNode* CHANGER = HEAD;
	int first, second;
	while(VANGA->next){
		first = VANGA->data;
		VANGA = VANGA->next;
		second = VANGA->data;

		CHANGER->data = second;
		CHANGER = CHANGER->next;
		CHANGER->data = first;

		if(VANGA->next){
			VANGA = VANGA->next;
			CHANGER = CHANGER->next;
		}
	}
}
