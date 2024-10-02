#include <stdint.h>
#include <stdio.h>
#include "serial.h"
#include "parsing.h"

void receive_sbuspackets(uint8_t* sbus_packet) {

}

int main(int argc, char** argv) {
    char *port_name_1 = argv[1]; 
    char *port_name_2 = argv[2];  

    FILE *sbus; 
    FILE *sabertooth;
    uint8_t sbus_packet[25]; 
    uint16_t *channel;
    int pwm;
    sbus = open_file(port_name_1, "rb");
    sabertooth = open_file(port_name_2, "w+");
    read_SBUS(sbus_packet,sizeof(uint8_t), 25, sbus);
    channel = parse_buffer(sbus_packet);
        pwm = interpolation(channel[0]);
        write_to_SB(sabertooth, "%d\n", pwm);
    close_file(sbus);
    close_file(sabertooth);
    return 0;
}
