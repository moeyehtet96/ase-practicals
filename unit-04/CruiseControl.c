#include <Rte_CruiseControl.h>

void CruiseControl_Control()
{
    float32 car_speed = Rte_IRead_Control_CurrentSpeed_Value();

    boolean is_cc = Rte_IRead_Control_CC_State_Value();
    boolean is_accelerate = Rte_IRead_Control_AcceleratorPedal_Value();
    boolean is_brake = Rte_IRead_Control_BrakePedal_Value();
    float32 target_speed = Rte_IRead_Control_TargetSpeed_Value();

    Rte_IWrite_Control_CC_StateNew_Value(is_cc);

    if(is_cc){

        if(is_accelerate) {
            Rte_IWrite_Control_Accelerate_Value(1);
        }else{
           
        if (car_speed <= target_speed)
        {
            // acceleratec
            Rte_IWrite_Control_Accelerate_Value(1);
            Rte_IWrite_Control_Brake_Value(0);
        }
        else if (car_speed > target_speed)
        {
            // brake
            Rte_IWrite_Control_Accelerate_Value(0);
            Rte_IWrite_Control_Brake_Value(1);
        }
        else
        {
            // no auto accelerate or brake
            Rte_IWrite_Control_Accelerate_Value(0);
            Rte_IWrite_Control_Brake_Value(0);
        }
        }

        if(is_brake){
            Rte_IWrite_Control_CC_StateNew_Value(0);
              Rte_IWrite_Control_Brake_Value(1);
        }
       
    }
    else{
         if (is_accelerate)
        {
            Rte_IWrite_Control_Accelerate_Value(1);
        }else{
            Rte_IWrite_Control_Accelerate_Value(0);
        }

        if (is_brake)
        {
            Rte_IWrite_Control_Brake_Value(1);
        }else{
            Rte_IWrite_Control_Brake_Value(0);
        }
    }

   
}