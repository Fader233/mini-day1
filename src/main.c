#include <stdio.h>
#include "pos_machine.h"

int main()
{
    ItemsInputInCart inputItems = {
        4,
        {
            {"ITEM000001"},
            {"ITEM000001-2"},
            {"ITEM000002-2"},
            {"ITEM000003"},
        }};
    Receipt receipt;
    BuildReceipt(&inputItems, &receipt);
    
    return 0;
}
