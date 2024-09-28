#include <stdio.h>
#include "SequentialAccess.h"

#pragma warning(disable: 4996)

int main()
{
    const char* filename = "SequencialAccess.dat";

    remove(filename);

    Data data1 = { 1, "Smartphone", "Electronics", 50, 699.99 };
    Data data2 = { 2, "Laptop", "Electronics", 30, 999.99 };
    Data data3 = { 3, "Tablet", "Electronics", 20, 299.99 };

    SequentialAddData(filename, data1);
    SequentialAddData(filename, data2);
    SequentialAddData(filename, data3);
    
    printf("Before delete:\n");
    SequentialReadData(filename);

    SequentialDeleteData(filename, 1);

    printf("After delete:\n");
    SequentialReadData(filename);
   
    printf("Updating item with ID 3...\n");
    Data updatedData3 = { 3, "Updated Tablet", "Electronics", 25, 349.99 };
    SequentialUpdateData(filename, updatedData3, 3);

  
    printf("After update:\n");
    SequentialReadData(filename);

    return 0;
}
