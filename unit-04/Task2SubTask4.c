#include <Rte_TargetSpeedControl.h>

float32 target_speed = 10;
const MAX_SPEED = 130;

void TargetSpeedControl_SetTargetSpeed()
{
    uint8 btn_state = Rte_IRead_RunnableName_ButtonState_DataElementName();

    // if (btn_state == 1)
    // {
    //     if (target_speed < MAX_SPEED)
    //     {
    //         target_speed += 5;
    //     }
    // }
    // else if (btn_state == 2)
    // {
    //     if (target_speed > 10)
    //     {
    //         target_speed -= 5;
    //     }
    // }

    switch (btn_state):
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

    Rte_IWrite_RunnableName_TargetSpeed_DataElementName(target_speed);
}