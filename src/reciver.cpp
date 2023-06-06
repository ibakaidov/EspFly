#include <Arduino.h>
#include <cstddef>
#include <IBusBM.h>

IBusBM IBus;    // IBus object

void initReciver(){
      IBus.begin(Serial2,1);    // iBUS object connected to serial2 RX2 pin and use timer 1
}

int* readChannels(){
    int* channels = new int[6];
    for (size_t i = 0; i < 6; i++)
    {
        channels[i] = IBus.readChannel(i);
    }
    
    return channels;
}