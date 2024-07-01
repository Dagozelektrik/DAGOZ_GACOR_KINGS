#ifndef _ROS_dgz_msgs_LocalWorldState_h
#define _ROS_dgz_msgs_LocalWorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Body2D.h"
#include "dgz_msgs/Particle2D.h"
#include "dgz_msgs/Particle3D.h"
#include "dgz_msgs/ListVector2D.h"
#include "dgz_msgs/Vector2D.h"

namespace dgz_msgs
{

  class LocalWorldState : public ros::Msg
  {
    public:
      typedef bool _ball_in_possession_type;
      _ball_in_possession_type ball_in_possession;
      typedef bool _ball_in_sight_type;
      _ball_in_sight_type ball_in_sight;
      typedef dgz_msgs::Body2D _my_kinematics_type;
      _my_kinematics_type my_kinematics;
      typedef dgz_msgs::Particle2D _ball_kinematics_type;
      _ball_kinematics_type ball_kinematics;
      typedef dgz_msgs::Particle3D _ball_3d_kinematics_type;
      _ball_3d_kinematics_type ball_3d_kinematics;
      typedef dgz_msgs::ListVector2D _obstacle_positions_type;
      _obstacle_positions_type obstacle_positions;
      typedef dgz_msgs::Vector2D _obstacle_with_ball_position_type;
      _obstacle_with_ball_position_type obstacle_with_ball_position;
      typedef dgz_msgs::Particle2D _friend_kinematics_type;
      _friend_kinematics_type friend_kinematics;

    LocalWorldState():
      ball_in_possession(0),
      ball_in_sight(0),
      my_kinematics(),
      ball_kinematics(),
      ball_3d_kinematics(),
      obstacle_positions(),
      obstacle_with_ball_position(),
      friend_kinematics()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ball_in_possession;
      u_ball_in_possession.real = this->ball_in_possession;
      *(outbuffer + offset + 0) = (u_ball_in_possession.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_in_possession);
      union {
        bool real;
        uint8_t base;
      } u_ball_in_sight;
      u_ball_in_sight.real = this->ball_in_sight;
      *(outbuffer + offset + 0) = (u_ball_in_sight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ball_in_sight);
      offset += this->my_kinematics.serialize(outbuffer + offset);
      offset += this->ball_kinematics.serialize(outbuffer + offset);
      offset += this->ball_3d_kinematics.serialize(outbuffer + offset);
      offset += this->obstacle_positions.serialize(outbuffer + offset);
      offset += this->obstacle_with_ball_position.serialize(outbuffer + offset);
      offset += this->friend_kinematics.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ball_in_possession;
      u_ball_in_possession.base = 0;
      u_ball_in_possession.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_in_possession = u_ball_in_possession.real;
      offset += sizeof(this->ball_in_possession);
      union {
        bool real;
        uint8_t base;
      } u_ball_in_sight;
      u_ball_in_sight.base = 0;
      u_ball_in_sight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ball_in_sight = u_ball_in_sight.real;
      offset += sizeof(this->ball_in_sight);
      offset += this->my_kinematics.deserialize(inbuffer + offset);
      offset += this->ball_kinematics.deserialize(inbuffer + offset);
      offset += this->ball_3d_kinematics.deserialize(inbuffer + offset);
      offset += this->obstacle_positions.deserialize(inbuffer + offset);
      offset += this->obstacle_with_ball_position.deserialize(inbuffer + offset);
      offset += this->friend_kinematics.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/LocalWorldState"; };
    virtual const char * getMD5() override { return "f2be1c82801855453059eac722525ae2"; };

  };

}
#endif
