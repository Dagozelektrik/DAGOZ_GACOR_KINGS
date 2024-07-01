#ifndef _ROS_dgz_msgs_Angle_h
#define _ROS_dgz_msgs_Angle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dgz_msgs
{

  class Angle : public ros::Msg
  {
    public:
      typedef double _val_type;
      _val_type val;

    Angle():
      val(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_val;
      u_val.real = this->val;
      *(outbuffer + offset + 0) = (u_val.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_val.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_val.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_val.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_val.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_val.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_val.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_val.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->val);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_val;
      u_val.base = 0;
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_val.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->val = u_val.real;
      offset += sizeof(this->val);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/Angle"; };
    virtual const char * getMD5() override { return "122db3e2ea0d4d63e59164b6bc31deaf"; };

  };

}
#endif
