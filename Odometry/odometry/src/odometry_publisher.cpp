//This code has lots of errors.

#include <iostream>
#include <stdio.h>
#include <odometry/odometry.h>

using namespace std;

odometry_space::OdometryFactory *odometry_factory;

/* This method cannot return void, it must return a msg or similar. Fix countless of such errors first. */
void encoderCallback(const geometry_msgs::Point& msg) {

    ROS_INFO("Encoder data received...");

    odometry_factory->updateOdometryData(msg);
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "odometry");

    odometry_factory = new odometry_space::OdometryFactory();

    ros::NodeHandle n;
    ros::Publisher odometry_publisher = n.advertise<nav_msgs::Odometry > ("odometry", 30, true);
    ros::Subscriber encoder_subscriber = n.subscribe("encoderData", 1, encoderCallback);

    nav_msgs::Odometry odometry_message;

    ros::Rate publisher_rate(10);

    printf("Odometry node initialized...\n");

    while (ros::ok()) {

        ros::spinOnce();

        odometry_publisher.publish(odometry_message);

        publisher_rate.sleep();

    }

    return 0;
}


//I think this code is not properly written as the according to code it should take the encoder data and publish the converted Odometry message. But in reality It will print some garbage values and in the callback function the Odometry data will be updated but it will not be converted into **Odometry message. And the printed <odometry_message> is not used anywhere to store the if so called converted odometry message. 
