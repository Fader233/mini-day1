#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ItemInput_ {
    char content[100];
} ItemInput;

typedef struct ItemsInputInCart_ {
    int length;
    ItemInput data[100];
} ItemsInputInCart;

typedef struct ReceiptItem_ {
    char name[100];
    int count;
    float price;
    float subTotal;
} ReceiptItem;

typedef struct ReceiptItems_ {
    int length;
    ReceiptItem data[100];
} ReceiptItems;

typedef struct Summary_ {
    float total;
} Summary;

typedef struct Receipt_ {
    Summary summary;
    ReceiptItems receiptItems;
} Receipt;

unsigned int BuildReceipt(ItemsInputInCart *inputItems, Receipt *result);

#ifdef __cplusplus
}
#endif
