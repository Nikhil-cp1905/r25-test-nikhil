#include <stdint.h>
#include "parsing.h"  
#include <math.h>

int interpolation(uint16_t sbus_channel) {
    const int SBUS_MIN = 0;
    const int SBUS_MAX = 2407;
    const int PWM_MIN = 1;
    const int PWM_MAX = 127;

    // Linear interpolation formula to convert SBUS to PWM
    int pwm_value = round(PWM_MIN + (sbus_channel - SBUS_MIN) * 
                (PWM_MAX - PWM_MIN) / (2047 - SBUS_MIN));

    return pwm_value;
}

uint16_t *parse_buffer(uint8_t buff[]) {
    static uint16_t channels[16]; // Array to hold extracted channel values
    uint16_t bitmask = 0x07FF;    // Mask to extract 11-bit values

    // Extracting each 11-bit channel value from the SBUS data buffer
    channels[0]  = (buff[1] | (buff[2] << 8)) & bitmask;
    channels[1]  = ((buff[2] >> 3) | (buff[3] << 5)) & bitmask;
    channels[2]  = ((buff[3] >> 6) | (buff[4] << 2) | 
                    (buff[5] << 10)) & bitmask;
    channels[3]  = ((buff[5] >> 1) | (buff[6] << 7)) & bitmask;
    channels[4]  = ((buff[6] >> 4) | (buff[7] << 4)) & bitmask;
    channels[5]  = ((buff[7] >> 7) | (buff[8] << 1) | 
                    (buff[9] << 9)) & bitmask;
    channels[6]  = ((buff[9] >> 2) | (buff[10] << 6)) & bitmask;
    channels[7]  = ((buff[10] >> 5) | (buff[11] << 3)) & bitmask;
    channels[8]  = (buff[12] | (buff[13] << 8)) & bitmask;
    channels[9]  = ((buff[13] >> 3) | (buff[14] << 5)) & bitmask;
    channels[10] = ((buff[14] >> 6) | (buff[15] << 2) | 
                    (buff[16] << 10)) & bitmask;
    channels[11] = ((buff[16] >> 1) | (buff[17] << 7)) & bitmask;
    channels[12] = ((buff[17] >> 4) | (buff[18] << 4)) & bitmask;
    channels[13] = ((buff[18] >> 7) | (buff[19] << 1) | 
                    (buff[20] << 9)) & bitmask;
    channels[14] = ((buff[20] >> 2) | (buff[21] << 6)) & bitmask;
    channels[15] = ((buff[21] >> 5) | (buff[22] << 3)) & bitmask;

    return channels;
}

