#include <Rte_CruiseControl.h>

void CruiseControl_Execute()
{
    float32 car_speed = Rte_IRead_RunnableName_CurrentSpeed_DataElementName();

    boolean is_cc = Rte_IRead_RunnableName_CC_State_DataElementName();

    Rte_IWrite_RunnableName_CC_StateNew_DataElementName(is_cc);

    if (is_cc)
    {
        // from sub task 1
        if (car_speed < 50)
        {
            Rte_IWrite_RunnableName_Accelerate_DataElementName(1);
            Rte_IWrite_RunnableName_Brake_DataElementName(0);
        }
        else if (car_speed > 50)
        {
            Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
            Rte_IWrite_RunnableName_Brake_DataElementName(1);
        }
        else
        {
            Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
            Rte_IWrite_RunnableName_Brake_DataElementName(0);
        }
    }
    else
    {
        Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
        Rte_IWrite_RunnableName_Brake_DataElementName(0);
    }
}