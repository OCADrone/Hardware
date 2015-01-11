
#include "Forces.h"

// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================



void Forces::setup()
{
  int errcode;
  

  Wire.begin();
  imu = RTIMU::createIMU(&settings);                        // create the imu object
  
  Serial.print("ArduinoIMU starting using device "); Serial.println(imu->IMUName());
  if ((errcode = imu->IMUInit()) < 0) {
    Serial.print("Failed to init IMU: "); Serial.println(errcode);
  }
  
  if (imu->getCalibrationValid())
    Serial.println("Using compass calibration");
  else
    Serial.println("No valid compass calibration data");

  lastDisplay = lastRate = millis();
  sampleCount = 0;

}

void Forces::update()
{

  unsigned long now = millis();
  unsigned long delta;
  
  if (imu->IMURead()) {                                // get the latest data if ready yet
    fusion.newIMUData(imu->getGyro(), imu->getAccel(), imu->getCompass(), imu->getTimestamp());
    sampleCount++;
    if ((delta = now - lastRate) >= 1000) {
      //Serial.print("Sample rate: "); Serial.print(sampleCount);
      if (imu->IMUGyroBiasValid())
	{
	  //Serial.println(", gyro bias valid");
	}
      else
	{
	  //Serial.println(", calculating gyro bias - don't move IMU!!");
        }
      sampleCount = 0;
      lastRate = now;
    }
    if (1 || (now - lastDisplay) >= DISPLAY_INTERVAL) {
      lastDisplay = now;
      //            RTMath::display("Gyro:", (RTVector3&)imu->getGyro());                // gyro data
      //      RTMath::display("Accel:", (RTVector3&)imu->getAccel());              // accel data
      //      RTMath::display("Mag:", (RTVector3&)imu->getCompass());              // compass data
      //      RTMath::displayDegrees("Pose:", (RTVector3&)fusion.getFusionPose()); // fused output
      SEND(F_IDENTIFIER);
      SEND(SERIAL_OUTPUT_DELIM);
      SEND(((RTVector3&)fusion.getFusionPose()).x());
      SEND(SERIAL_OUTPUT_DELIM);
      SEND(((RTVector3&)fusion.getFusionPose()).y());
      SEND(SERIAL_OUTPUT_DELIM);
      SEND(((RTVector3&)fusion.getFusionPose()).z());
      Serial.println();
    }
  }

  /*
  SEND(F_IDENTIFIER);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(ax);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(ay);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(az);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(gx);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(gy);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(gz);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(mx);
  SEND(SERIAL_OUTPUT_DELIM);
  SEND(my);
  SEND(SERIAL_OUTPUT_DELIM);
  SENDLN(mz);
  */
}
