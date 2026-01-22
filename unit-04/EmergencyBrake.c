#include <Rte_EmergencyBrake.h>


const float32 DECELERATION_BRAKE = 10.0f;
const float32 DECELERATION_EBRAKE = 14.0f;
// const float32 deceleration_ebrake = 14.0f;
// const float32 ttc_threshold = 2.0f;

void EmergencyBrake_Apply(){
    float32 current_speed_kmh = Rte_IRead_Apply_CurrentSpeed_Value(); // km per hr
    float32 current_speed_ms = current_speed_kmh * (5.0 / 18.0);     
    
    float32 d_leading = Rte_IRead_Apply_DistanceLeading_Value();
    float32 d_braking = (current_speed_ms * current_speed_ms ) / (2 * DECELERATION_BRAKE);
    float32 d_ebraking = (current_speed_ms * current_speed_ms ) / (2 * DECELERATION_EBRAKE);

    // if (d_braking >= d_leading)
    // {
    //     Rte_IWrite_Apply_EmergencyBrake_Value(1);
    //     Rte_IWrite_Apply_CC_StateNew_Value(0);
       
    // }

    if (d_braking >= d_leading)
    {
        if (d_ebraking >= d_leading - 5){
            Rte_IWrite_Apply_EmergencyBrake_Value(1);
            Rte_IWrite_Apply_CC_StateNew_Value(0);
        }
    }
    
    if(current_speed_kmh == 0.0 ){
        Rte_IWrite_Apply_EmergencyBrake_Value(0);
    }
    
}