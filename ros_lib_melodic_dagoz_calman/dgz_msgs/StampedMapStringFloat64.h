#ifndef _ROS_dgz_msgs_StampedMapStringFloat64_h
#define _ROS_dgz_msgs_StampedMapStringFloat64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/MapStringFloat64.h"

namespace dgz_msgs
{

  class StampedMapStringFloat64 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::MapStringFloat64 _data_type;
      _data_type data;

    StampedMapStringFloat64():
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

    virtual const char * getType() override { return "dgz_msgs/StampedMapStringFloat64"; };
    virtual const char * getMD5() override { return "02729da4dc71022a2c4a322d8473599a"; };

  };

}
#endif
