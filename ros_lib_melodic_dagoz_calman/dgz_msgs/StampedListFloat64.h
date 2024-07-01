#ifndef _ROS_dgz_msgs_StampedListFloat64_h
#define _ROS_dgz_msgs_StampedListFloat64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/ListFloat64.h"

namespace dgz_msgs
{

  class StampedListFloat64 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::ListFloat64 _data_type;
      _data_type data;

    StampedListFloat64():
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

    virtual const char * getType() override { return "dgz_msgs/StampedListFloat64"; };
    virtual const char * getMD5() override { return "4c082b7820de5e2776a5f02ae355e774"; };

  };

}
#endif
