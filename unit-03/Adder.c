#include <Rte_Adder.h>

void Adder_Compute()
{
    uint8 input_a = Rte_IRead_Compute_InputA_Value();
    uint8 input_b = Rte_IRead_Compute_InputB_Value();

    uint8 sum = input_a + input_b;

    Rte_IWrite_Compute_Sum_Value(count);
}