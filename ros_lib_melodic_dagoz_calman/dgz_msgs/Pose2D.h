#ifndef _ROS_dgz_msgs_Pose2D_h
#define _ROS_dgz_msgs_Pose2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Vector2D.h"
#include "dgz_msgs/Angle.h"

namespace dgz_msgs
{

  class Pose2D : public ros::Msg
  {
    public:
      typedef dgz_msgs::Vector2D _pos_type;
      _pos_type pos;
      typedef dgz_msgs::Angle _ort_type;
      _ort_type ort;

    Pose2D():
      pos(),
      ort()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->ort.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->ort.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/Pose2D"; };
    virtual const char * getMD5() override { return "bc0ad900609948c5eeeb84bf0ee55a26"; };

  };

}
#endif
