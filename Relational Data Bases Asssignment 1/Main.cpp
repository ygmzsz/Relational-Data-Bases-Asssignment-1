#include <stdio.h>
#include "SequentialAccess.h"
#include "Delimited.h"

int main()
{
    const char delimitedFile[] = "file.csv";

    struct productData smartPhone = { 1, "Smartphone", "Electronics", 50, 699.99 };
    struct productData laptop = { 2, "Laptop", "Electronics", 30, 999.99 };
    struct productData tablet = { 3, "Tablet", "Electronics", 20, 299.99 };

    appendFile(&smartPhone, delimitedFile);

    appendFile(&laptop, delimitedFile);

    readFile(delimitedFile);

    deleteFileContentsById(delimitedFile, '2');

    readFile(delimitedFile);

    appendFile(&laptop, delimitedFile);

    readFile(delimitedFile);

    updateFileById(&tablet, delimitedFile, '2');

    readFile(delimitedFile);

    deleteFile(delimitedFile);

    const char* filename = "SequencialAccess.dat";

    remove(filename);

    Data data1 = { 1, "Smartphone", "Electronics", 50, 699.99 };
    Data data2 = { 2, "Laptop", "Electronics", 30, 999.99 };
    Data data3 = { 3, "Tablet", "Electronics", 20, 299.99 };


    SequentialAddData(filename, data1);
    SequentialAddData(filename, data2);
    SequentialAddData(filename, data3);

    
    printf("Before Sequential delete:\n");
    SequentialReadData(filename);

   
    SequentialDeleteData(filename, 1);

   
    printf("After Sequential delete:\n");
    SequentialReadData(filename);

    
    printf("Sequentially Updating item with ID 3\n");
    Data updatedData3 = { 3, "Ipad", "Electronics", 25, 349.99 };
    SequentialUpdateData(filename, updatedData3, 3);

    
    printf("After sequential update:\n");
    SequentialReadData(filename);

    return 0;
}
