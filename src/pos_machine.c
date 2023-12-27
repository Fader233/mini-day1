#include "pos_machine.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128

typedef struct MarketItem_ {
    char barCode[100];
    char name[100];
    float price;
} MarketItem;

typedef struct AllMarketItems_ {
    int length;
    MarketItem data[100];
} AllMarketItems;


AllMarketItems *loadAllMarketItems()
{
    static AllMarketItems allMarketItems = {
        5,
        {
            {"ITEM000001", "cocacola", 3.00},
            {"ITEM000002", "badminton", 1.00},
            {"ITEM000003", "banana 0.5kg", 2.50},
            {"ITEM000004", "sprite", 3.50},
            {"ITEM000005", "apple", 4.50},
        }};

    return &allMarketItems;
}

void UpdateReceipt(Receipt *result, char item[100], AllMarketItems *allMarketItems) 
{   
    ReceiptItems *receipt = &result->receiptItems;
    float num = 1;
    if (item[10] == '-') {
        num = item[11] - '0';
    }
    item[10] = '\0';
    bool check = true;
    int i = 0;
    for (i = 0; i < allMarketItems->length; ++i) {
        if (strcmp(item, allMarketItems->data[i].barCode) == 0) {
            break;
        }
    }
    MarketItem itemData = allMarketItems->data[i];
    for (i = 0; i < receipt->length; i++) {
        if (strcmp(itemData.name,receipt->data[i].name) == 0) {
            check = false;
            receipt->data[i].count += num;
            receipt->data[i].subTotal = (float)(receipt->data[i].count) * (receipt->data[i].price);
            break;
        }
    }

    if (check){
        strcpy(receipt->data[receipt->length].name, itemData.name);
        receipt->data[receipt->length].price = itemData.price;
        receipt->data[receipt->length].count = (float)num;
        receipt->data[receipt->length].subTotal = (float)num * itemData.price;
        receipt->length += 1;
    }
    
    return;
}

void PrintSystem(Receipt *result){
    printf("*******your receipt*******\n");
        for (int i = 0; i < result->receiptItems.length; i++){
            printf("name: %s",result->receiptItems.data[i].name);
            printf(" price: %0.2f",result->receiptItems.data[i].price);
            printf(" subtotal: %0.2f\n",(float)result->receiptItems.data[i].subTotal);
        }
}

unsigned int BuildReceipt(ItemsInputInCart *inputItems, Receipt *result)
{   
    result->summary.total = 0;
    result->receiptItems.length = 0;
    AllMarketItems *allItems = loadAllMarketItems();
    for (int i = 0; i < inputItems->length; i++) {
        UpdateReceipt(result, inputItems->data[i].content, allItems);
    }
    for (int i = 0; i < result->receiptItems.length; i++){
        result->summary.total += (float)result->receiptItems.data[i].subTotal;
    }
    PrintSystem(result);
    return 0;
}