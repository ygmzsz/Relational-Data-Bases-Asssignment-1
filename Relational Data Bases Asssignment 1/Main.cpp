#include <stdio.h>
#include "SequentialAccess.h"
#include "Delimited.h"
#include "RandomAccess.h"

int main()
{
    // Delimited file operations
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

    
    const char* seqFilename = "SequentialAccess.dat";
    remove(seqFilename);

    Data data1 = { 1, "Smartphone", "Electronics", 50, 699.99 };
    Data data2 = { 2, "Laptop", "Electronics", 30, 999.99 };
    Data data3 = { 3, "Tablet", "Electronics", 20, 299.99 };

    SequentialAddData(seqFilename, data1);
    SequentialAddData(seqFilename, data2);
    SequentialAddData(seqFilename, data3);

    printf("Before Sequential delete:\n");
    SequentialReadData(seqFilename);

    SequentialDeleteData(seqFilename, 1);
    printf("After Sequential delete:\n");
    SequentialReadData(seqFilename);

    printf("Sequentially Updating item with ID 3\n");
    Data updatedData3 = { 3, "Ipad", "Electronics", 25, 349.99 };
    SequentialUpdateData(seqFilename, updatedData3, 3);
    printf("After sequential update:\n");
    SequentialReadData(seqFilename);

    // Random access file operations
    ProductManager pm;
    const char* randFilename = "randomAccess.data";
    initProductManager(&pm, randFilename);

    DataR dataR1 = { 1, "Smartphone", "Electronics", 50, 699.99, false };
    DataR dataR2 = { 2, "Laptop", "Electronics", 30, 999.99, false };
    DataR dataR3 = { 3, "Tablet", "Electronics", 20, 299.99, false };

    
    printf("Adding data:\n");
    addDataRandom(&pm, dataR1.id, dataR1);
    addDataRandom(&pm, dataR2.id, dataR2);
    addDataRandom(&pm, dataR3.id, dataR3);

    
    printf("\nSearching for ID 2:\n");
    searchByPositionRandom(&pm, 2);

    
    printf("\nUpdating ID 2 with new values:\n");
    DataR updatedRandomData = { 2, "Gaming Laptop", "Electronics", 25, 1299.99, false };
    updateDataRandom(&pm, updatedRandomData.id, updatedRandomData);
    searchByPositionRandom(&pm, 2);

   
    printf("\nDeleting product with ID 1:\n");
    deleteProductRandom(&pm, 1);
    searchByPositionRandom(&pm, 1);

    return 0;
}
