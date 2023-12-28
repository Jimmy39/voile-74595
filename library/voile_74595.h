#ifndef __VOILE_74595_H__
#define __VOILE_74595_H__

#include "voile_interface_iopin.h"
#include "voile_common.h"

typedef const struct {

    /**
     * @brief Init the io for control 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return voile_status_t defined in common.h
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Init(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Init)(const void *);

    /**
     * @brief Reset 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return voile_status_t defined in common.h
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Reset(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Reset)(const void *);

    /**
     * @brief Write bit to 74595 pin, but do not load
     * 
     * @param[in] name  :[voile_const_74595_t *] This 74595 object.
     * @param[in] date  :[bool] The bit to write to 74595.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->ShiftBit(&my74595, 0);
     * @endcode
     * 
    */
    voile_status_t (*ShiftBit)(const void *, bool);

    /**
     * @brief Write bytes to 74595 registers, but do not load
     * 
     * @param[in] name  :[voile_const_74595_t *] This 74595 object.
     * @param[in] date  :[uint8_t *] The date to write to 74595.
     * @param[in] lenth :[uint8_t]The length of the array.
     * 
     * @par Sample
     * @code {.C}
     * uint8_t date[3] = {0x34, 0x8a, 0xd1};
     * my74595.Operate->ShiftBytes(&my74595, &date, 3);
     * @endcode
     * 
    */
    voile_status_t (*ShiftBytes)(const void *, uint8_t *, uint8_t);

    /**
     * @brief Load date to pin
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Load(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Load)(const void *);
    
    /**
     * @brief Disable _OE of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Disable(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Disable)(const void *);
    
    /**
     * @brief Enable _OE of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Enable(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Enable)(const void *);

} voile_const_74595_Operate_t;


typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;
    
} voile_const_74595_t;

typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // (option) _SRCLR pin
    voile_const_ioPin_t *_SRCLR;

    // (option) _OE pin
    voile_const_ioPin_t *_OE;
    
    // SRCLK pin
    voile_const_ioPin_t *SRCLK;
    
    // SER pin
    voile_const_ioPin_t *SER;
    
    // _RCLK pin
    voile_const_ioPin_t *RCLK;

    // (reserved) QH' pin
    voile_const_ioPin_t *QH_;

    // (reserved) variable for save state
    uint8_t *state;

} voile_const_internal_74595_t;


extern voile_const_74595_Operate_t voile_const_74595_Operate;

extern voile_status_t voile_74595_Operate_Init(voile_const_internal_74595_t*);

static inline voile_status_t voile_74595_Operate_Disable(voile_const_internal_74595_t* this) {
    if (this->_OE != NULL) {
        this->_OE->Operate->Write(this->_OE, 1);
        return success;
    }
    else {
        return hardwareUnsupportedError;
    }
}

static inline voile_status_t voile_74595_Operate_Enable(voile_const_internal_74595_t* this) {
    if (this->_OE != NULL) {
        this->_OE->Operate->Write(this->_OE, 0);
        return success;
    }
    else {
        return hardwareUnsupportedError;
    }
}

static inline voile_status_t voile_74595_Operate_ShiftBit(voile_const_internal_74595_t* this, bool bit) {
    uint8_t delay = 20;
    this->SER->Operate->Write(this->SER, bit);
    this->SRCLK->Operate->Write(this->SRCLK, 0);
    for (; delay > 0; delay--) {
        ;
    }
    this->SRCLK->Operate->Write(this->SRCLK, 1);
    return success;
}


extern voile_status_t voile_74595_Operate_ShiftBytes(voile_const_internal_74595_t *, uint8_t *, uint8_t);


static inline voile_status_t voile_74595_Operate_Reset(voile_const_internal_74595_t *this) {
    if (this->_SRCLR != NULL) {

        this->_SRCLR->Operate->Write(this->_SRCLR, 0);

        // Do not delete.
        // I don't know why, but my 74HC595 need a rise at RCLK to reset shift resister. 
        voile_74595_Operate_ShiftBit(this, 0);

        this->_SRCLR->Operate->Write(this->_SRCLR, 1);

        return success;
    }
    else {
        return hardwareUnsupportedError;
    }
}
static inline voile_status_t voile_74595_Operate_Load(voile_const_internal_74595_t *this) {
    uint8_t delay = 20;
    this->RCLK->Operate->Write(this->RCLK, 0);
    for (; delay > 0; delay--) {
        ;
    }
    this->RCLK->Operate->Write(this->RCLK, 1);
    return success;
}

#endif // !__VOILE_74595_H__

#ifdef FUNCINIT
#undef FUNCINIT
#endif // FUNCINIT

#define FUNCINIT \
.Operate = &voile_const_74595_Operate
