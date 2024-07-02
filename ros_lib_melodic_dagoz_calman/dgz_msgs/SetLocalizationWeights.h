#ifndef _ROS_SERVICE_SetLocalizationWeights_h
#define _ROS_SERVICE_SetLocalizationWeights_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dgz_msgs
{

static const char SETLOCALIZATIONWEIGHTS[] = "dgz_msgs/SetLocalizationWeights";

  class SetLocalizationWeightsRequest : public ros::Msg
  {
    public:
      typedef double _amcl_weight_pos_type;
      _amcl_weight_pos_type amcl_weight_pos;
      typedef double _ext_odom_weight_pos_type;
      _ext_odom_weight_pos_type ext_odom_weight_pos;
      typedef double _amcl_weight_ort_type;
      _amcl_weight_ort_type amcl_weight_ort;
      typedef double _ext_odom_weight_ort_type;
      _ext_odom_weight_ort_type ext_odom_weight_ort;
      typedef double _int_odom_weight_ort_type;
      _int_odom_weight_ort_type int_odom_weight_ort;

    SetLocalizationWeightsRequest():
      amcl_weight_pos(0),
      ext_odom_weight_pos(0),
      amcl_weight_ort(0),
      ext_odom_weight_ort(0),
      int_odom_weight_ort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_amcl_weight_pos;
      u_amcl_weight_pos.real = this->amcl_weight_pos;
      *(outbuffer + offset + 0) = (u_amcl_weight_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amcl_weight_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amcl_weight_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amcl_weight_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_amcl_weight_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_amcl_weight_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_amcl_weight_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_amcl_weight_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->amcl_weight_pos);
      union {
        double real;
        uint64_t base;
      } u_ext_odom_weight_pos;
      u_ext_odom_weight_pos.real = this->ext_odom_weight_pos;
      *(outbuffer + offset + 0) = (u_ext_odom_weight_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ext_odom_weight_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ext_odom_weight_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ext_odom_weight_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ext_odom_weight_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ext_odom_weight_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ext_odom_weight_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ext_odom_weight_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ext_odom_weight_pos);
      union {
        double real;
        uint64_t base;
      } u_amcl_weight_ort;
      u_amcl_weight_ort.real = this->amcl_weight_ort;
      *(outbuffer + offset + 0) = (u_amcl_weight_ort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amcl_weight_ort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amcl_weight_ort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amcl_weight_ort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_amcl_weight_ort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_amcl_weight_ort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_amcl_weight_ort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_amcl_weight_ort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->amcl_weight_ort);
      union {
        double real;
        uint64_t base;
      } u_ext_odom_weight_ort;
      u_ext_odom_weight_ort.real = this->ext_odom_weight_ort;
      *(outbuffer + offset + 0) = (u_ext_odom_weight_ort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ext_odom_weight_ort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ext_odom_weight_ort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ext_odom_weight_ort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ext_odom_weight_ort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ext_odom_weight_ort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ext_odom_weight_ort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ext_odom_weight_ort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ext_odom_weight_ort);
      union {
        double real;
        uint64_t base;
      } u_int_odom_weight_ort;
      u_int_odom_weight_ort.real = this->int_odom_weight_ort;
      *(outbuffer + offset + 0) = (u_int_odom_weight_ort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int_odom_weight_ort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int_odom_weight_ort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int_odom_weight_ort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_int_odom_weight_ort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_int_odom_weight_ort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_int_odom_weight_ort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_int_odom_weight_ort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->int_odom_weight_ort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_amcl_weight_pos;
      u_amcl_weight_pos.base = 0;
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_amcl_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->amcl_weight_pos = u_amcl_weight_pos.real;
      offset += sizeof(this->amcl_weight_pos);
      union {
        double real;
        uint64_t base;
      } u_ext_odom_weight_pos;
      u_ext_odom_weight_pos.base = 0;
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ext_odom_weight_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ext_odom_weight_pos = u_ext_odom_weight_pos.real;
      offset += sizeof(this->ext_odom_weight_pos);
      union {
        double real;
        uint64_t base;
      } u_amcl_weight_ort;
      u_amcl_weight_ort.base = 0;
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_amcl_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->amcl_weight_ort = u_amcl_weight_ort.real;
      offset += sizeof(this->amcl_weight_ort);
      union {
        double real;
        uint64_t base;
      } u_ext_odom_weight_ort;
      u_ext_odom_weight_ort.base = 0;
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ext_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ext_odom_weight_ort = u_ext_odom_weight_ort.real;
      offset += sizeof(this->ext_odom_weight_ort);
      union {
        double real;
        uint64_t base;
      } u_int_odom_weight_ort;
      u_int_odom_weight_ort.base = 0;
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_int_odom_weight_ort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->int_odom_weight_ort = u_int_odom_weight_ort.real;
      offset += sizeof(this->int_odom_weight_ort);
     return offset;
    }

    virtual const char * getType() override { return SETLOCALIZATIONWEIGHTS; };
    virtual const char * getMD5() override { return "8339de1d1ab592ace1b0066ec172d389"; };

  };

  class SetLocalizationWeightsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetLocalizationWeightsResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return SETLOCALIZATIONWEIGHTS; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetLocalizationWeights {
    public:
    typedef SetLocalizationWeightsRequest Request;
    typedef SetLocalizationWeightsResponse Response;
  };

}
#endif
