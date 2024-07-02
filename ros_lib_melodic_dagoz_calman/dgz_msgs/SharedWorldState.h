#ifndef _ROS_dgz_msgs_SharedWorldState_h
#define _ROS_dgz_msgs_SharedWorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Body2D.h"
#include "dgz_msgs/Particle2D.h"

namespace dgz_msgs
{

  class SharedWorldState : public ros::Msg
  {
    public:
      typedef const char* _robot_id_type;
      _robot_id_type robot_id;
      typedef bool _ball_in_possession_type;
      _ball_in_possession_type ball_in_possession;
      typedef bool _ball_in_sight_type;
      _ball_in_sight_type ball_in_sight;
      typedef dgz_msgs::Body2D _my_kinematics_type;
      _my_kinematics_type my_kinematics;
      typedef dgz_msgs::Particle2D _ball_kinematics_type;
      _ball_kinematics_type ball_kinematics;
      typedef const char* _current_task_type;
      _current_task_type current_task;

    SharedWorldState():
      robot_id(""),
      ball_in_possession(0),
      ball_in_sight(0),
      my_kinematics(),
      ball_kinematics(),
      current_task("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_robot_id = strlen(this->robot_id);
      varToArr(outbuffer + offset, length_robot_id);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_id, length_robot_id);
      offset += length_robot_id;
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
      uint32_t length_current_task = strlen(this->current_task);
      varToArr(outbuffer + offset, length_current_task);
      offset += 4;
      memcpy(outbuffer + offset, this->current_task, length_current_task);
      offset += length_current_task;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_robot_id;
      arrToVar(length_robot_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_id-1]=0;
      this->robot_id = (char *)(inbuffer + offset-1);
      offset += length_robot_id;
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
      uint32_t length_current_task;
      arrToVar(length_current_task, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_task; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_task-1]=0;
      this->current_task = (char *)(inbuffer + offset-1);
      offset += length_current_task;
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/SharedWorldState"; };
    virtual const char * getMD5() override { return "0a9a85b4777c1d1503116615f4c83084"; };

  };

}
#endif
