#ifndef _ROS_dgz_msgs_StampedListVector2D_h
#define _ROS_dgz_msgs_StampedListVector2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/ListVector2D.h"

namespace dgz_msgs
{

  class StampedListVector2D : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::ListVector2D _data_type;
      _data_type data;

    StampedListVector2D():
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

    virtual const char * getType() override { return "dgz_msgs/StampedListVector2D"; };
    virtual const char * getMD5() override { return "344c95c7acc4b267ffbeb664ffd56343"; };

  };

}
#endif
