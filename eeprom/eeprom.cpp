 #include "eeprom.h"

 using namespace std;
EEPROM::EEPROM(const int SLAVE_ADDRESS){
    //verbinding maken via i2C
    if ((i2cfile = open(DEVICE.c_str(), O_RDWR)) < 0) {
        cout << "Could not open bus" << endl;
        exit(1);
    }
    cout << "Successfully opened the i2c bus" << endl;

    if (ioctl(i2cfile, I2C_SLAVE, SLAVE_ADDRESS) < 0) {
        cout << "Failed to acquire bus access and/or talk to slave." << endl;
        exit(1);
    }
    cout << "Ready to communicate with slave device" << endl;
}

void EEPROM::get_id(char * id){
    char buffer[2] = {0x00,0x00};
    write(i2cfile, buffer, 2);
    sleep(2);
    read(i2cfile, id, 16);
}
void EEPROM::write_id(char buf[18]){
    //inlezen buffer 1
    write(i2cfile, buf, 18);
    sleep(2);
}
void EEPROM::finish(){
    close(i2cfile);
}
