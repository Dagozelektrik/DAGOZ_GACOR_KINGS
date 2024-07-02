#ifndef _ROS_dgz_msgs_Twist2D_h
#define _ROS_dgz_msgs_Twist2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Vector2D.h"

namespace dgz_msgs
{

  class Twist2D : public ros::Msg
  {
    public:
      typedef dgz_msgs::Vector2D _vel_type;
      _vel_type vel;
      typedef double _rot_type;
      _rot_type rot;

    Twist2D():
      vel(),
      rot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->vel.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.real = this->rot;
      *(outbuffer + offset + 0) = (u_rot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->vel.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.base = 0;
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot = u_rot.real;
      offset += sizeof(this->rot);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/Twist2D"; };
    virtual const char * getMD5() override { return "27d83a6a6c236aeb473f11c6cee23a52"; };

  };

}
#endif
