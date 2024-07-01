#ifndef _ROS_dgz_msgs_StampedAngle_h
#define _ROS_dgz_msgs_StampedAngle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dgz_msgs/Angle.h"

namespace dgz_msgs
{

  class StampedAngle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef dgz_msgs::Angle _data_type;
      _data_type data;

    StampedAngle():
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

    virtual const char * getType() override { return "dgz_msgs/StampedAngle"; };
    virtual const char * getMD5() override { return "d73fc4d1044e5cec4418669deb95899b"; };

  };

}
#endif
