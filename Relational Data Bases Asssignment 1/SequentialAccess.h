#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

typedef struct
{
    int id;
    char name[50];
    char category[50];
    int quantity;
    double price;
} Data;


void SequentialReadData(const char* filename);
void SequentialAddData(const char* filename, Data data);
void SequentialUpdateData(const char* filename, Data data, int itemId);
void SequentialDeleteData(const char* filename, int itemId);

#endif