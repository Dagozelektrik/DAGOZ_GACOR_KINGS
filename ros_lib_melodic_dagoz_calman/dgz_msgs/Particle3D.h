#ifndef _ROS_dgz_msgs_Particle3D_h
#define _ROS_dgz_msgs_Particle3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Vector3D.h"

namespace dgz_msgs
{

  class Particle3D : public ros::Msg
  {
    public:
      typedef dgz_msgs::Vector3D _pos_type;
      _pos_type pos;
      typedef dgz_msgs::Vector3D _vel_type;
      _vel_type vel;

    Particle3D():
      pos(),
      vel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->vel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->vel.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/Particle3D"; };
    virtual const char * getMD5() override { return "1cc513376d60835070501e5505f0defe"; };

  };

}
#endif
