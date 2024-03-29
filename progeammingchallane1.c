#include<iostream>
#include <cstdint>

#define MAX_PACKET_DATA_LENGTH (50)
using namespace std;

typedef struct data_packet_t {
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;                               // CRC (Cyclic Redundancy Check)
} data_packet_t;

bool isPacketCorrupted(const data_packet_t& packet) {
    // Calculate CRC for the packet data
    uint16_t calculated_crc = 0;
    for (int i = 0; i < packet.data_length; i++) {
        calculated_crc += packet.data[i];
    }

    // Compare calculated CRC with the packet's CRC field
    return calculated_crc != packet.crc;
}

int main() {
    // Example usage
    data_packet_t packet;
    packet.id = 1;
    packet.data_length = 10;
    for (int i = 0; i < packet.data_length; i++) {
        packet.data[i] = i + 1;
    }
    packet.crc = 55;

    if (isPacketCorrupted(packet)) {
        // Packet is corrupted
        cout<<"Packet is corrupted"<<endl;
    } else {
        // Packet is not corrupted
        cout<<"Packet is not corrupted"<<endl;
    }

    return 0;
}
