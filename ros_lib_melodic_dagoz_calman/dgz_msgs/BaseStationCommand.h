#ifndef _ROS_dgz_msgs_BaseStationCommand_h
#define _ROS_dgz_msgs_BaseStationCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Pose2D.h"

namespace dgz_msgs
{

  class BaseStationCommand : public ros::Msg
  {
    public:
      typedef uint16_t _state_type;
      _state_type state;
      typedef uint8_t _modifier_type;
      _modifier_type modifier;
      typedef dgz_msgs::Pose2D _pose_type;
      _pose_type pose;

    BaseStationCommand():
      state(0),
      modifier(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state >> (8 * 1)) & 0xFF;
      offset += sizeof(this->state);
      *(outbuffer + offset + 0) = (this->modifier >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modifier);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->state =  ((uint16_t) (*(inbuffer + offset)));
      this->state |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->state);
      this->modifier =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->modifier);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/BaseStationCommand"; };
    virtual const char * getMD5() override { return "3d8d6af90f87d0301eb2508c04699a3f"; };

  };

}
#endif
