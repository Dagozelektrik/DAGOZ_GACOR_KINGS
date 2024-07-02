#ifndef _ROS_dgz_msgs_Body2D_h
#define _ROS_dgz_msgs_Body2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Pose2D.h"
#include "dgz_msgs/Twist2D.h"

namespace dgz_msgs
{

  class Body2D : public ros::Msg
  {
    public:
      typedef dgz_msgs::Pose2D _pose_type;
      _pose_type pose;
      typedef dgz_msgs::Twist2D _twist_type;
      _twist_type twist;

    Body2D():
      pose(),
      twist()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/Body2D"; };
    virtual const char * getMD5() override { return "34c3d6344d54138f443d3c7d80a026af"; };

  };

}
#endif
