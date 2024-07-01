#ifndef _ROS_dgz_msgs_StampedListInt32_h
#define _ROS_dgz_msgs_StampedListInt32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/ListInt32.h"

namespace dgz_msgs
{

  class StampedListInt32 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::ListInt32 _data_type;
      _data_type data;

    StampedListInt32():
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

    virtual const char * getType() override { return "dgz_msgs/StampedListInt32"; };
    virtual const char * getMD5() override { return "6274cee38a55b34c55e3a6686bb2d030"; };

  };

}
#endif
