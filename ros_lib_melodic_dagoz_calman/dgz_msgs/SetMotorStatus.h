#ifndef _ROS_SERVICE_SetMotorStatus_h
#define _ROS_SERVICE_SetMotorStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dgz_msgs
{

static const char SETMOTORSTATUS[] = "dgz_msgs/SetMotorStatus";

  class SetMotorStatusRequest : public ros::Msg
  {
    public:
      typedef bool _motor1FL_type;
      _motor1FL_type motor1FL;
      typedef bool _motor2FR_type;
      _motor2FR_type motor2FR;
      typedef bool _motor3BL_type;
      _motor3BL_type motor3BL;
      typedef bool _motor4BR_type;
      _motor4BR_type motor4BR;

    SetMotorStatusRequest():
      motor1FL(0),
      motor2FR(0),
      motor3BL(0),
      motor4BR(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_motor1FL;
      u_motor1FL.real = this->motor1FL;
      *(outbuffer + offset + 0) = (u_motor1FL.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor1FL);
      union {
        bool real;
        uint8_t base;
      } u_motor2FR;
      u_motor2FR.real = this->motor2FR;
      *(outbuffer + offset + 0) = (u_motor2FR.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor2FR);
      union {
        bool real;
        uint8_t base;
      } u_motor3BL;
      u_motor3BL.real = this->motor3BL;
      *(outbuffer + offset + 0) = (u_motor3BL.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor3BL);
      union {
        bool real;
        uint8_t base;
      } u_motor4BR;
      u_motor4BR.real = this->motor4BR;
      *(outbuffer + offset + 0) = (u_motor4BR.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor4BR);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_motor1FL;
      u_motor1FL.base = 0;
      u_motor1FL.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor1FL = u_motor1FL.real;
      offset += sizeof(this->motor1FL);
      union {
        bool real;
        uint8_t base;
      } u_motor2FR;
      u_motor2FR.base = 0;
      u_motor2FR.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor2FR = u_motor2FR.real;
      offset += sizeof(this->motor2FR);
      union {
        bool real;
        uint8_t base;
      } u_motor3BL;
      u_motor3BL.base = 0;
      u_motor3BL.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor3BL = u_motor3BL.real;
      offset += sizeof(this->motor3BL);
      union {
        bool real;
        uint8_t base;
      } u_motor4BR;
      u_motor4BR.base = 0;
      u_motor4BR.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor4BR = u_motor4BR.real;
      offset += sizeof(this->motor4BR);
     return offset;
    }

    virtual const char * getType() override { return SETMOTORSTATUS; };
    virtual const char * getMD5() override { return "0c8d958f5a3dd80698c74cbe666a175c"; };

  };

  class SetMotorStatusResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetMotorStatusResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return SETMOTORSTATUS; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetMotorStatus {
    public:
    typedef SetMotorStatusRequest Request;
    typedef SetMotorStatusResponse Response;
  };

}
#endif
