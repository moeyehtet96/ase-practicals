#include <Rte_TargetSpeedControl.h>

float32 target_speed = 10;
const float32 MAX_SPEED = 130;

void TargetSpeedControl_SetSpeed(){
        uint8 btn_state = Rte_IRead_SetSpeed_ButtonState_Value();

        switch (btn_state)
        {
        case 1:
           if (target_speed < MAX_SPEED)
            {
                target_speed += 5;
            }
            break;
         case 2:
            if (target_speed > 10)
            {
                target_speed -= 5;
            }
            break;
        default:
            break;
        }

        Rte_IWrite_SetSpeed_TargetSpeed_Value(target_speed);
}