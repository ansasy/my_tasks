
#include <Wire.h>

#define IMU_ADD 0X68
#define Gyro_XOUT_H 0x43
#define MPU6050_GYRO_CONFIG_VALUE 0x08
#define MPU6050_REG_GYRO_CONFIG 0x1B

int16_t gyro_X=0;
int16_t gyro_Y=0;
int16_t gyro_Z=0;
double yaw =0.0;

void setup() {
Wire.begin();
  Serial.begin(9600);
  MPU_Init();
  
}

void loop() {
MPU_readGyro(); 
//the delta here shows the interval i want to read the data in which here is 50ms
double deltaT=0.05;
//using integration which is summation of the changes in velocity
yaw +=(gyro_Z*deltaT);
 Serial.print("Yaw Angle: ");
    Serial.println(yaw);

    delay(50); 
}

void MPU_readGyro(){
Wire.beginTransmission(IMU_ADD);
Wire.write(Gyro_XOUT_H);
Wire.endTransmission();
Wire.requestFrom(IMU_ADD, 6);
while(Wire.available()<6);
gyro_X= Wire.read()<<8 | Wire.read();
gyro_Y= Wire.read()<<8 | Wire.read();
gyro_Z = Wire.read() << 8 | Wire.read();

}



void MPU_Init() {
  // Wake up the MPU6050 and configure gyro sensitivity
  Wire.beginTransmission(IMU_ADD);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // Clear sleep mode bit (activate device)
  Wire.endTransmission();

  Wire.beginTransmission(IMU_ADD);
  Wire.write(MPU6050_REG_GYRO_CONFIG);
  Wire.write(MPU6050_GYRO_CONFIG_VALUE);
  Wire.endTransmission();
}
