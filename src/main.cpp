#include <Arduino.h>
#include <SmartLeds.h>
#include <iostream>
#include <vector>

const int LED_COUNT = 256*2;
const int DATA_PIN = 21;
const int CHANNEL = 0;
SmartLed leds(LED_WS2812, LED_COUNT, DATA_PIN, CHANNEL, DoubleBuffer);

struct Rgbtype{
    unsigned int r;
    unsigned int g;
    unsigned int b;
};
// sokolska
std::vector<std::vector<Rgbtype>> grid = {{{0,0,0},{0,0,0},{0,5,5},{0,5,5},{0,5,5},{0,0,0},{0,5,5},{0,0,0},{0,0,0},{5,0,0},{5,0,0},{5,0,0},{0,0,0},{0,0,0},{5,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,0,0},{0,0,0},{5,0,0},{0,0,0},{5,0,0},{0,0,0},{0,0,0},{5,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,5,5},{0,5,5},{0,0,0},{0,0,0},{5,0,0},{0,0,0},{5,0,0},{5,0,0},{5,0,0},{5,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{5,2,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,5},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,5},{0,0,0},{0,0,5},{0,0,5},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{5,2,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,4,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,2},{0,0,0},{0,0,2},{0,0,2},{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,4,0},{0,0,0},{5,4,0},{5,4,0},{0,0,0}},{{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{1,5,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0}},{{0,0,0},{5,0,0},{5,0,0},{5,0,0},{0,0,0},{0,0,0},{5,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0}},{{0,0,0},{5,0,0},{0,0,0},{5,0,0},{0,0,0},{0,0,0},{5,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{1,5,0},{0,0,0},{0,0,0}},{{0,0,0},{5,0,0},{0,0,0},{5,0,0},{5,0,0},{5,0,0},{5,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,5,0},{0,5,0},{0,5,0},{0,5,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{5,2,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,5,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{5,2,0},{0,0,0},{0,0,0},{0,0,0},{0,5,5},{0,5,5},{0,5,5},{0,0,0},{0,5,5},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,2,0},{5,2,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,5,5},{0,0,0},{0,5,5},{0,5,5},{0,5,5},{0,0,0}},{{0,0,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{5,4,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{5,4,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,5},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{5,4,0},{0,0,0},{5,4,0},{5,4,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,5},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,5},{0,0,0},{0,0,5},{0,0,5},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{1,5,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,2},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{1,5,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,2},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,5,0},{1,5,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,2},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,2},{0,0,2},{0,0,2},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,5,0},{0,5,0},{0,5,0},{0,5,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,2},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,5,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}};




void showCulomn(int x,const std::vector<Rgbtype>& culomn){
    if(x%2==0){
        for(std::size_t i = 0; i < culomn.size(); i++){
            leds[i+16*x] = Rgb{culomn[15-i].r, culomn[15-i].g, culomn[15-i].b};
        }
    } else {
        for(std::size_t i = 0; i < culomn.size(); i++){
            leds[i+16*x] = Rgb{culomn[i].r, culomn[i].g, culomn[i].b};
        }
    }
}

void setup(){
    Serial.begin(115200);
    
}



int current = 0;

void loop(){   
    for(std::size_t i = 0; i < 32; i++){
        showCulomn(i,grid[(i+current)%grid.size()]);
    }
    leds.wait();
    leds.show();
    delay(200);
    current+=1;
}

