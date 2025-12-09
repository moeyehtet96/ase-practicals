#include <Rte_CruiseControl.h>

void CruiseControl_Execute()
{
    float32 car_speed = Rte_IRead_RunnableName_CurrentSpeed_DataElementName();
    float32 target_speed = Rte_IRead_RunnableName_TargetSpeed_DataElementName();

    boolean is_cc = Rte_IRead_RunnableName_CC_State_DataElementName();

    boolean is_accelerate = Rte_IRead_RunnableName_AcceleratorPedal_DataElementName();
    boolean is_brake = Rte_IRead_RunnableName_BrakePedal_DataElementName();

    Rte_IWrite_RunnableName_CC_StateNew_DataElementName(is_cc);

    if (is_cc)
    {
        if (is_accelerate)
        {
            Rte_IWrite_RunnableName_Accelerate_DataElementName(1);
        }
        else
        {
            // from sub task 1
            // change to target speed in SubTask4
            if (car_speed < 50)
            {
                Rte_IWrite_RunnableName_Accelerate_DataElementName(1);
                Rte_IWrite_RunnableName_Brake_DataElementName(0);
            }
            else if (car_speed > 50)
            {
                // change to target spped in SubTask4
                Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
                Rte_IWrite_RunnableName_Brake_DataElementName(1);
            }
            else
            {
                // add == 50 if doesn't work
                Rte_IWrite_RunnableName_Accelerate_DataElementName(0);
                Rte_IWrite_RunnableName_Brake_DataElementName(0);
            }
        }

        if (is_brake)
        {
            Rte_IWrite_RunnableName_CC_StateNew_DataElementName(0);
            Rte_IWrite_RunnableName_Brake_DataElementName(1);
        }
    }
    else
    {
        if (is_accelerate)
        {
            Rte_IWrite_RunnableName_Accelerate_DataElementName(1);
        }

        if (is_brake)
        {
            Rte_IWrite_RunnableName_Brake_DataElementName(1);
        }
    }
}