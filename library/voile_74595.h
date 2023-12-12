#ifndef __VOILE_74595_H__
#define __VOILE_74595_H__

#include "voile_interface_iopin.h"
#include "voile_common.h"

typedef const struct {

    /**
     * @brief Reset 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return voile_status_t defined in common.h
     * 
     * @par Sample
     * @code
     * my74595.Operate->Reset(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Reset)(const void *);

    /**
     * @brief Write date to 74595 pin
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @param[in] date :[uint8_t *] The date to write to 74595. The length of the array needs to be the same as the number of 74595 cascades.
     * 
     * @par Sample
     * @code {.C}
     * uint8_t date[3] = {0x34, 0x8a, 0xd1};
     * my74595.Operate->Write(&my74595, &date);
     * @endcode
     * 
    */
    voile_status_t (*Write)(const void *, uint8_t *);

} voile_const_74595_Operate_t;


typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // The number of 74595 cascades
    uint8_t cascade;
    
} voile_const_74595_t;

typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // The number of 74595 cascades
    uint8_t cascade;

    // _SRCLR pin
    struct voile_ioPin_t *_SRCLR;
    
    // SRCLK pin
    struct voile_ioPin_t *SRCLK;
    
    // SER pin
    struct voile_ioPin_t *SER;
    
    // _RCLK pin
    struct voile_ioPin_t *_RCLK;

} voile_const_internal_74595_t;


#endif // !__VOILE_74595_H__
