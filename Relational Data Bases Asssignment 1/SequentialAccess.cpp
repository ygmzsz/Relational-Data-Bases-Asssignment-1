#include <stdio.h>
#include <stdlib.h>
#include "SequentialAccess.h"

#pragma warning(disable: 4996)


void SequentialReadData(const char* filename)
{
    FILE* file = fopen(filename, "rb"); 
    if (file == NULL)
    {
        printf("ERROR: Something went wrong while opening the file\n");
        return;
    }
    Data temp;
    while (fread(&temp, sizeof(Data), 1, file))
    {
        printf("\n--------------------\n");
        printf("ID: %d\n", temp.id);
        printf("Price: %.2f\n", temp.price);
        printf("Name: %s\n", temp.name);
        printf("Category: %s\n", temp.category);
        printf("Quantity: %d\n", temp.quantity);
        printf("\n---------------------\n");
    }
    fclose(file);
}


void SequentialAddData(const char* filename, Data data) {
    FILE* file = fopen(filename, "ab");  
    if (file == NULL)
    {
        printf("ERROR: Something went wrong while opening the file\n");
        return;
    }
    fwrite(&data, sizeof(Data), 1, file);
    fclose(file);
}


void SequentialUpdateData(const char* filename, Data data, int itemId)
{
    FILE* file = fopen(filename, "r+b");  
    if (file == NULL)
    {
        printf("ERROR: Something went wrong while opening the file\n");
        return;
    }

    Data temp;
    while (fread(&temp, sizeof(Data), 1, file))
    {
        if (temp.id == itemId)
        {
            fseek(file, -(long)sizeof(Data), SEEK_CUR); 
            fwrite(&data, sizeof(Data), 1, file);       
            break;
        }
    }
    fclose(file);
}
void SequentialDeleteData(const char* filename, int itemId)
{
    FILE* file = fopen(filename, "rb");  
    if (file == NULL)
    {
        printf("ERROR: Something went wrong while opening the file\n");
        return;
    }

    FILE* tempFile = fopen("temp.bin", "wb");  
    if (tempFile == NULL)
    {
        printf("ERROR: Something went wrong while creating the temp file\n");
        fclose(file);
        return;
    }

    Data temp;
    int found = 0;

    
    while (fread(&temp, sizeof(Data), 1, file))
    {
        if (temp.id != itemId)
        {
            fwrite(&temp, sizeof(Data), 1, tempFile);
        }
        else
        {
            found = 1;  
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove(filename);  
        rename("temp.bin", filename);  
        printf("Item with ID %d deleted successfully.\n", itemId);
    }
    else
    {
        printf("Item with ID %d not found.\n");
        remove("temp.bin"); 
    }
}
