#include "data_Pile.h"

piledata_t createPileData(char let){
    piledata_t temp;
    temp.value = let;
    return temp;
}

void display_Data(piledata_t datapile){
    printf(datapile.value);
    printf("\n");
}