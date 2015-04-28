#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

MPU6050 mpu_head;
MPU6050 mpu_body;

//#define OUTPUT_READABLE_QUATERNION
#define OUTPUT_READABLE_EULER
#define OUTPUT_READABLE_YAWPITCHROLL
#define OUTPUT_READABLE_REALACCEL
#define OUTPUT_READABLE_WORLDACCEL
//#define OUTPUT_TEAPOT

// MPU control/status vars
bool dmpHeadReady = false;  // set true if DMP init was successful
bool dmpBodyReady = false;  // set true if DMP init was successful

// orientation/motion vars
/*
Quaternion dmpQuat;         // [w, x, y, z]         quaternion container
VectorInt16 dmpAccel;       // [x, y, z]            accel sensor measurements
VectorInt16 dmpAccelReal;   // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 dmpAccelWorld;  // [x, y, z]            world-frame accel sensor measurements
VectorFloat dmpGravity;     // [x, y, z]            gravity vector
float dmpEuler[3];          // [psi, theta, phi]    Euler angle container
float dmpYawPitchRoll[3];   // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
*/

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================
void setup() {
    //mpu_head.setDebug(true);
    dmpHeadReady = mpu_head.dmpStartDevice(0x68, 0, 0, 0);
    
    //mpu_body.setDebug(true);
    dmpBodyReady = mpu_body.dmpStartDevice(0x69, 0, 0, 0);
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================
void loop() {
    if(mpu_head.dmpGetData())
    {
        //dmpQuat = mpu_head.getDmpQuaternion();
        printf("quat %7.2f %7.2f %7.2f %7.2f    ", dmpQuat.w,dmpQuat.x,dmpQuat.y,dmpQuat.z);
        
        //dmpAccel = mpu_head.getDmpAccel();
        printf("areal %6d %6d %6d    ", dmpAccel.x, dmpAccel.y, dmpAccel.z);
        
        //dmpAccelReal = mpu_head.getDmpAccelReal();
        printf("areal %6d %6d %6d    ", dmpAccelReal.x, dmpAccelReal.y, dmpAccelReal.z);
        
        //dmpAccelWorld = mpu_head.getDmpAccelWorld();
        printf("aworld %6d %6d %6d    ", dmpAccelWorld.x, dmpAccelWorld.y, dmpAccelWorld.z);
        
        //dmpGravity = mpu_head.getDmpGravity();
        printf("areal %7.2f %7.2f %7.2f    ", dmpGravity.x, dmpGravity.y, dmpGravity.z);
        
        //dmpEuler = mpu_head.getDmpEuler();
        printf("euler %7.2f %7.2f %7.2f    ", dmpEuler[0], dmpEuler[1], dmpEuler[2]);
        
        //dmpYawPitchRoll = mpu_head.getDmpYawPitchRoll();
        printf("ypr  %7.2f %7.2f %7.2f    ", dmpYawPitchRoll[0], dmpYawPitchRoll[1], dmpYawPitchRoll[2]);
    }
    
    if(mpu_body.dmpGetData())
    {
        //dmpQuat = mpu_body.getDmpQuaternion();
        printf("quat %7.2f %7.2f %7.2f %7.2f    ", dmpQuat.w,dmpQuat.x,dmpQuat.y,dmpQuat.z);
        
        //dmpAccel = mpu_body.getDmpAccel();
        printf("areal %6d %6d %6d    ", dmpAccel.x, dmpAccel.y, dmpAccel.z);
        
        //dmpAccelReal = mpu_body.getDmpAccelReal();
        printf("areal %6d %6d %6d    ", dmpAccelReal.x, dmpAccelReal.y, dmpAccelReal.z);
        
        //dmpAccelWorld = mpu_body.getDmpAccelWorld();
        printf("aworld %6d %6d %6d    ", dmpAccelWorld.x, dmpAccelWorld.y, dmpAccelWorld.z);
        
        //dmpGravity = mpu_body.getDmpGravity();
        printf("areal %7.2f %7.2f %7.2f    ", dmpGravity.x, dmpGravity.y, dmpGravity.z);
        
        //dmpEuler = mpu_body.getDmpEuler();
        printf("euler %7.2f %7.2f %7.2f    ", dmpEuler[0], dmpEuler[1], dmpEuler[2]);
        
        //dmpYawPitchRoll = mpu_body.getDmpYawPitchRoll();
        printf("ypr  %7.2f %7.2f %7.2f    ", dmpYawPitchRoll[0], dmpYawPitchRoll[1], dmpYawPitchRoll[2]); 
    }
}

int main() {
    setup();
    usleep(100000);
    
    for (;;)
        loop();
    
    return 0;
}

