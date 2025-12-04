#include <Rte_Counter.h>

uint8 count = 0;

void Counter_GenerateNextNumber()
{
    count++;
    Rte_IWrite_GenerateNextNumber_Number_Value(count);
}