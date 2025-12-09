#include <Rte_CruiseControl.h>

void CruiseControl_Execute()
{
    float32 car_speed = Rte_IRead_RunnableName_CurrentSpeed_DataElementName();

    if (car_speed < 50)
    {
        // accelerate
        Rte_IWrite_RunnableName_Accelerate_DataElementName(1);
        Rte_IWrite_RunnableName_Brake_DataElementName(0);
    }
    else if (car_speed > 50)
    {
        // brake
        Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
        Rte_IWrite_RunnableName_Brake_DataElementName(1);
    }
    else
    {
        // no auto accelerate or brake
        Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
        Rte_IWrite_RunnableName_Brake_DataElementName(0);
    }
}