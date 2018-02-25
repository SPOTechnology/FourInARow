#include "globals.h"

int compareN(const void * a, const void *b) {
	if ((((Moves*) b)->val > ((Moves*) a)->val)) {
		return (1);
	}
	if ((((Moves*) b)->val < ((Moves*) a)->val)) {
		return (-1);
	}
	if ((((Moves*) b)->prior > ((Moves*) a)->prior)) {
		return (1);
	}
	if ((((Moves*) b)->prior < ((Moves*) a)->prior)) {
		return (-1);
	}
	return (0);
}

int compareM(const void * a, const void *b) {
	if ((((Moves*) b)->move < ((Moves*) a)->move)) {
		return (1);
	}
	if ((((Moves*) b)->move > ((Moves*) a)->move)) {
		return (-1);
	}
	return (0);
}
