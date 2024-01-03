#include <SimpleFOC.h>

// MagneticSensorSPI(MagneticSensorSPIConfig_s config, int cs)
//  config  - SPI config
//  cs      - SPI chip select pin 
// magnetic sensor instance - SPI
MagneticSensorSPI sensor1 = MagneticSensorSPI(AS5048_SPI, A0);
MagneticSensorSPI sensor2 = MagneticSensorSPI(AS5048_SPI, A1);
// alternative constructor (chipselsect, bit_resolution, angle_read_register, )
// MagneticSensorSPI sensor = MagneticSensorSPI(10, 14, 0x3FFF);

void setup() {
  // monitoring port
  Serial.begin(9600);

  // initialise magnetic sensor hardware
  sensor1.init();
  sensor2.init();
  
  Serial.println("Sensors ready");
  _delay(1000);
}

void loop() {
  // iterative function updating the sensor internal variables
  // it is usually called in motor.loopFOC()
  // this function reads the sensor hardware and 
  // has to be called before getAngle nad getVelocity
  sensor1.update();
  sensor2.update();
  // display the angle and the angular velocity to the terminal
  Serial.print(sensor1.getAngle());
  Serial.print("\t");
  Serial.println(sensor2.getAngle());
}
