#include <Rte_EmergencyBrake.h>

float32 deceleration_brake = 10.0f;
float32 deceleration_ebrake = 14.0f;
float32 ttc_threshold = 2.0f;

void EmergencyBrake_Apply()
{
    // DistanceLeading
    // CurrentSpeed
    // CC_State

    float32 current_speed_kmh = Rte_IRead_Runnable_Name_CurrentSpeed_DataElementName(); // km per hr
    float32 current_speed_ms = current_speed_kmh * (5.0 / 18.0);                        // meter per second
    float32 d_leading = Rte_IRead_RunnableName_DistanceLeading_DataElementName();
    // boolean is_cc = Rte_IRead_RunnableName_CC_State_DataElementName();

    float32 d_braking = (current_speed_ms * *2) / (2 * deceleration_brake); // distance needed for normal braking
    // float32 d_ebraking = (current_speed_ms * *2) / (2 * deceleration_ebrake); // distance needed for emergency braking

    // check with ttc threshold
    /*
    v_rel = (d_leading_current - d_leading_prev) / dt;
    ttc = d_leading_current / v_rel;
    */

    if (d_braking >= d_leading)
    {
        // if ((d_leading <= current_speed * ttc_threshold) && (d_ebraking < d_leading))
        // {
        Rte_IWrite_RunnableName_EmergencyBrake_DataElementName(1);
        Rte_IWrite_RunnableName_CC_StateNew_DataElementName(0);
        // }
    }
}