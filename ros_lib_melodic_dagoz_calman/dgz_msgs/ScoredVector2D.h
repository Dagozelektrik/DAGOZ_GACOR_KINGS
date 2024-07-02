#ifndef _ROS_dgz_msgs_ScoredVector2D_h
#define _ROS_dgz_msgs_ScoredVector2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dgz_msgs/Vector2D.h"

namespace dgz_msgs
{

  class ScoredVector2D : public ros::Msg
  {
    public:
      typedef double _score_type;
      _score_type score;
      typedef dgz_msgs::Vector2D _data_type;
      _data_type data;

    ScoredVector2D():
      score(0),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_score;
      u_score.real = this->score;
      *(outbuffer + offset + 0) = (u_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_score.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_score.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_score.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_score.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->score);
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_score;
      u_score.base = 0;
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->score = u_score.real;
      offset += sizeof(this->score);
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/ScoredVector2D"; };
    virtual const char * getMD5() override { return "998a4e2d3a7ad423df05531f2afc3cb9"; };

  };

}
#endif
