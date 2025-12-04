#include <Rte_DataLogger.h>
#include <Sab.h>

void DataLogger_Log()
{
    uint8 value = Rte_IRead_Log_DisplayValue_Value();
    Sab_SubmitInfo("Received data: %d", value);
}