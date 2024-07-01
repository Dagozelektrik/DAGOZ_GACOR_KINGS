#ifndef _ROS_SERVICE_ExecuteKick_h
#define _ROS_SERVICE_ExecuteKick_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dgz_msgs
{

static const char EXECUTEKICK[] = "dgz_msgs/ExecuteKick";

  class ExecuteKickRequest : public ros::Msg
  {
    public:
      typedef double _target_distance_type;
      _target_distance_type target_distance;
      typedef bool _is_shoot_type;
      _is_shoot_type is_shoot;

    ExecuteKickRequest():
      target_distance(0),
      is_shoot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_target_distance;
      u_target_distance.real = this->target_distance;
      *(outbuffer + offset + 0) = (u_target_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_target_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_target_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_target_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_target_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->target_distance);
      union {
        bool real;
        uint8_t base;
      } u_is_shoot;
      u_is_shoot.real = this->is_shoot;
      *(outbuffer + offset + 0) = (u_is_shoot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_shoot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_target_distance;
      u_target_distance.base = 0;
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_target_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->target_distance = u_target_distance.real;
      offset += sizeof(this->target_distance);
      union {
        bool real;
        uint8_t base;
      } u_is_shoot;
      u_is_shoot.base = 0;
      u_is_shoot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_shoot = u_is_shoot.real;
      offset += sizeof(this->is_shoot);
     return offset;
    }

    virtual const char * getType() override { return EXECUTEKICK; };
    virtual const char * getMD5() override { return "3f2b854381e6d9997e6567a43c9b6498"; };

  };

  class ExecuteKickResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    ExecuteKickResponse():
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

    virtual const char * getType() override { return EXECUTEKICK; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class ExecuteKick {
    public:
    typedef ExecuteKickRequest Request;
    typedef ExecuteKickResponse Response;
  };

}
#endif
