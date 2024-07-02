#ifndef _ROS_dgz_msgs_StampedTwist2D_h
#define _ROS_dgz_msgs_StampedTwist2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/Twist2D.h"

namespace dgz_msgs
{

  class StampedTwist2D : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::Twist2D _data_type;
      _data_type data;

    StampedTwist2D():
      header(),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/StampedTwist2D"; };
    virtual const char * getMD5() override { return "dae35b0cd098ec3b23750fa7d1c20cb6"; };

  };

}
#endif
