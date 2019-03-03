#pragma once
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>   // close
#include <fcntl.h>    // O_RDWR
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>  // I2C_SLAVE
#include <time.h> //sleep

class EEPROM{
     
    public: 
        EEPROM(const int SLAVE_ADDRESS);
        void write_id(char buf[16]);
        void finish();
        void get_id(char * id);

    private:
        char buffer[16] = {};
        const std::string DEVICE = "/dev/i2c-1";
        const unsigned int BUFFER_SIZE = 16;
        int i2cfile;
};