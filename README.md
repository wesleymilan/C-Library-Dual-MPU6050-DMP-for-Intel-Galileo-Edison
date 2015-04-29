# C-Library-MPU6050-DMP-for-Intel-Galileo-Edson
This is a C++ library for Dual MPU6050 using DMP for Intel Galileo and Intel Edison for IoT

This is a extended version of Jeff Rowberg library for MPU6050.

I'm using I2Cdev library from http://www.i2cdevlib.com/.

This library was tested with Galileo Gen 1 where interruption detection just works in EDGE_BOTH mode, so I'm not using interrupt detection to improve performance of I2C network.

The repository have 3 executables:
- demo_raw: Print the pure RAW data from Gyro to help you find the offset number from each axe
- demo_dmp: The original example that execute each step for connection, accessing and catching data from gyro
- demo_optimized: Optimized version using abstracted functions to simplify main code and reduce the I2C requests

The original version made one request for each cycle of your application, increasing the CPU utilization and the I2C traffic.
An empty request just for check if FIFO Buffer is done to load expends between 2ms and 6ms, and a load request uses between 6ms and 12ms of your cycle time, but the average time between each effective data load is 30ms, so, you can use this time to do a lot of things in your application including process data and capture information from other sensors. The getIntDataReadyStatus() supposed to get information from the interrupt port, but it makes a request through I2C taking the same 2~6ms to get the answer, so it is not good enough for me.

The optimized version does not use interrupt yet, so if you want to help, please be my guest to implement and send me a pull request.

A time average function monitor the interval between each request and make your application avoid empty requests releasing your CPU during 8 to 24 cycles.  You can test it's efficiency using Debug mode.

I need your help to improve this library:

TODO list:
- Reorganize the functions and remove function code from header files
- Turn the captured data and timing data private inside each class instead share with all instances
- Implement interruption detection even using time functions to accurate the performance and avoid data loss
- Make it compatible with other boards like RaspBerryPI, Edison, PCDuino, etc

PLEASE FORK, improve and send a pull request to help us

Enjoy
