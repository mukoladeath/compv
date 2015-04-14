/**
*
*  \author     Paul Bovbel <pbovbel@clearpathrobotics.com>
*  \copyright  Copyright (c) 2014-2015, Clearpath Robotics, Inc.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Clearpath Robotics, Inc. nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Please send comments, questions, or patches to code@clearpathrobotics.com
*
*/

#include <ros/ros.h>
#include <ros/console.h>
#include "Hercules.h"

namespace
{
  std::string port_;
}

namespace hercules_wilson
{
  Hercules gHercules;

  void reconnect()
  {
    ROS_INFO_STREAM("Connecting to Hercules on port " << port_ << "...");

    gHercules.reconnect();

    ROS_INFO("Connected");
  }

  void connect(std::string port)
  {
	  port_ = port;
	  if (port_.empty()) {
		  throw std::logic_error("Can't reconnect when port is not configured");
	  }

	  gHercules.connect(port);
  }

  void configureLimits(double max_speed, double max_accel) {
	  gHercules.configureLimits(max_speed, max_accel);
          ROS_DEBUG("configureLimits max_speed=%lf, max_accel=%lf", max_speed, max_accel);
  }

  void controlSpeed(double speed_left, double speed_right, double accel_left, double accel_right){
    ROS_DEBUG("controlSpeed speed_left=%lf, speed_right=%lf", speed_left, speed_right);
    ROS_DEBUG("controlspeed accel_left=%lf, accel_right=%lf", accel_left, accel_right);
	  gHercules.controlSpeed(speed_left, speed_right, accel_left, accel_right);
  }
}
