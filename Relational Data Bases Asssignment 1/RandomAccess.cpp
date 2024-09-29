#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RandomAccess.h"

#pragma warning(disable: 4996)

void initProductManager(ProductManager* pm, const char* filename)
{
    pm->filename = filename;
}

int positionHash(int productId)
{
    return (productId - 1) * sizeof(DataR);
}

void printData(const DataR* data)
{
    printf("Data: ID=%d, Name=%s, Category=%s, Quantity=%d, Price=%.2lf, IsDeleted=%s\n",
        data->id, data->name, data->category, data->quantity, data->price, data->isDeleted ? "true" : "false");
}

void addDataRandom(ProductManager* pm, int productId, DataR data)
{
    FILE* file = fopen(pm->filename, "rb+");
    if (!file) file = fopen(pm->filename, "wb+");

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    int position = positionHash(productId);
    fseek(file, position, SEEK_SET);
    fwrite(&data, sizeof(DataR), 1, file);
    fflush(file);
    fclose(file);
}

void searchByPositionRandom(ProductManager* pm, int productId)
{
    FILE* file = fopen(pm->filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    int position = positionHash(productId);
    fseek(file, position, SEEK_SET);

    DataR data;
    size_t bytesRead = fread(&data, sizeof(DataR), 1, file);
    if (bytesRead != 1)
    {
        printf("Error reading from file or record not found\n");
        fclose(file);
        return;
    }

    printData(&data);
    fclose(file);
}

void updateDataRandom(ProductManager* pm, int productId, DataR data)
{
    FILE* file = fopen(pm->filename, "rb+");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    int position = positionHash(productId);
    fseek(file, position, SEEK_SET);
    fwrite(&data, sizeof(DataR), 1, file);
    fflush(file);
    fclose(file);
}

void deleteProductRandom(ProductManager* pm, int productId)
{
    FILE* file = fopen(pm->filename, "rb+");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    int position = positionHash(productId);
    fseek(file, position, SEEK_SET);

    DataR data;
    size_t bytesRead = fread(&data, sizeof(DataR), 1, file);
    if (bytesRead != 1)
    {
        printf("Error reading from file or record not found\n");
        fclose(file);
        return;
    }

    data.isDeleted = true;
    fseek(file, position, SEEK_SET);
    fwrite(&data, sizeof(DataR), 1, file);
    fflush(file);
    fclose(file);
}
