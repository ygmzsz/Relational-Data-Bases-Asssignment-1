#pragma once
#include <stdbool.h>

typedef struct
{
    int id;
    char name[50];
    char category[50];
    int quantity;
    double price;
    bool isDeleted;
} DataR;

typedef struct
{
    const char* filename;
} ProductManager;

// Function Prototypes
void initProductManager(ProductManager* pm, const char* filename);
int positionHash(int productId);
void addDataRandom(ProductManager* pm, int productId, DataR data);
void searchByPositionRandom(ProductManager* pm, int productId);
void updateDataRandom(ProductManager* pm, int productId, DataR data);
void deleteProductRandom(ProductManager* pm, int productId);
void printData(const DataR* data);
