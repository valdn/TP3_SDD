#ifndef data_pile_h
#define DATA_PILE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct piledata {
    char value;
} piledata_t;

piledata_t createPileData(char let);
void display_Data(piledata_t temp);

#endif
