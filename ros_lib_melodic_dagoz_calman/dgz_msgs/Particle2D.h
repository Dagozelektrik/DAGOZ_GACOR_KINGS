#ifndef _ROS_dgz_msgs_Particle2D_h
#define _ROS_dgz_msgs_Particle2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Vector2D.h"

namespace dgz_msgs
{

  class Particle2D : public ros::Msg
  {
    public:
      typedef dgz_msgs::Vector2D _pos_type;
      _pos_type pos;
      typedef dgz_msgs::Vector2D _vel_type;
      _vel_type vel;

    Particle2D():
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

    virtual const char * getType() override { return "dgz_msgs/Particle2D"; };
    virtual const char * getMD5() override { return "7676e8ef895f61056ed15bdab6d0319e"; };

  };

}
#endif
