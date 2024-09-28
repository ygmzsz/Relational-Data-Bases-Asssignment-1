#pragma once
#define DELIMITER ","
#define MAXPRODUCTDATACHAR 50
#define MAXCHARCOUNT 1000

struct productData
{
	int id;
	char name[MAXPRODUCTDATACHAR];
	char category[MAXPRODUCTDATACHAR];
	int quantity;
	double price;
};

void readFile(const char* fileName);
void appendFile(struct productData* content, const char* fileName);
void updateFileById(struct productData* content, const char* fileName, int id);
void deleteFileContentsById(const char* fileName, int id);
void deleteFile(const char* fileName);
void findLineById(const char* fileName);

