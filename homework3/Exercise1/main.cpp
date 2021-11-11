#include "list.h"
#include <iostream>

int main(){
    int test[7][7] = {};
    for(int i = 0; i < 7; i++)
        test[i][i] = i+1;

    List testList{7, 7, (int*)test};
    
    testList.printList();

    return 0;
}
