
#include "Position.h"

void Position::setup()
{
  accel = Adafruit_LSM303_Accel_Unified(30301);
  mag   = Adafruit_LSM303_Mag_Unified(30302);
  bmp   = Adafruit_BMP085_Unified(18001);
  gyro  = Adafruit_L3GD20_Unified(20);
  dof   = Adafruit_10DOF();
  /* Initialise the sensors */
  if(!accel.begin())
    {
      /* There was a problem detecting the ADXL345 ... check your connections */
      SEND(F("Ooops, no LSM303 detected ... Check your wiring!"));
      while(1);
    }
  if(!mag.begin())
    {
      /* There was a problem detecting the LSM303 ... check your connections */
      SEND("Ooops, no LSM303 detected ... Check your wiring!");
      while(1);
    }
  if(!bmp.begin())
    {
      /* There was a problem detecting the BMP085 ... check your connections */
      SEND("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
      while(1);
    }
  if(!gyro.begin())
    {
      /* There was a problem detecting the L3GD20 ... check your connections */
      SEND("Ooops, no L3GD20 detected ... Check your wiring or I2C ADDR!");
      while(1);
    }
}
// Ox, Oy, Oz, Gx, Gy, Gz,tmp,altitude 
void Position::update()
{
  float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;
  SEND(F_IDENTIFIER);
  SEND(SERIAL_OUTPUT_DELIM);
  /* Calculate pitch and roll from the raw accelerometer data */
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
    {
      float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
      /* 'orientation' should have valid .roll and .pitch fields */
      /* Calculate the heading using the magnetometer */
      mag.getEvent(&mag_event);
      dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation);
      SEND(orientation.roll);
      SEND(SERIAL_OUTPUT_DELIM);      
      SEND(-orientation.pitch);      
      SEND(SERIAL_OUTPUT_DELIM);
      SEND(orientation.heading);
      SEND(SERIAL_OUTPUT_DELIM);

      SEND(accel_event.acceleration.x);  
      SEND(SERIAL_OUTPUT_DELIM);
      SEND(accel_event.acceleration.y);

      SEND(SERIAL_OUTPUT_DELIM);

      SEND(-accel_event.acceleration.z);

      SEND(SERIAL_OUTPUT_DELIM);
      SEND(accel_event.acceleration.z);
    }



  /* Calculate the altitude using the barometric pressure sensor */
  bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
    {
      /* Get ambient temperature in C */
      float temperature;
      bmp.getTemperature(&temperature);
      SEND(temperature);
      SEND(SERIAL_OUTPUT_DELIM);
      /* Convert atmospheric pressure, SLP and temp to altitude    */
      SENDLN(bmp.pressureToAltitude(seaLevelPressure,
				  bmp_event.pressure,
				  temperature)); 
    }
  
}
