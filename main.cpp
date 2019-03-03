//main.cpp Charlotte Pieters
// Compile using g++ -std=c++11 main.cpp -o i2c
#include <iostream>
#include "./eeprom/eeprom.h"
using namespace std;


int main(void) {
	//declareren van variabelen
	EEPROM e(0xA0>>1); //7-bit slave address
	char adr[2] = {0x00,0x00};
    char testid[16] = "aaaa567HDP9g2dM"; //0x41, 0xE2, 0xC3,0x04,0x01, 0x12, 0x53,0x04,0x01, 0x02, 0x03,0x04,0x01, 0x02, 0x03,'a'
    char buffer[18] = {};
    for(int i = 0; i<18; i++){
        if(i<2){
            buffer[i] = adr[i];
        }
        else{
            buffer[i] = testid[i-2];
        }
    }
	char result[18] = {};
	e.write_id(buffer);
	e.get_id(result);
	cout<< result<< endl;
	e.finish();

	
}