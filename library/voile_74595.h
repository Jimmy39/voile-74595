#ifndef __VOILE_74595_H__
#define __VOILE_74595_H__

#include "voile_interface_iopin.h"
#include "voile_common.h" 

struct voile_74595_Operate_struct;
typedef const struct voile_74595_Operate_struct voile_const_74595_Operate_t;
struct voile_74595_Get_struct;
typedef const struct voile_74595_Get_struct voile_const_74595_Get_t;


typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // Get value
    voile_const_74595_Get_t *Get;
    
} voile_const_74595_t;

typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // Get value
    voile_const_74595_Get_t *Get;

    // SER pin
    voile_const_ioPin_t *SER;
    
    // SRCLK pin
    voile_const_ioPin_t *SRCLK;
    
    // RCLK pin
    // If SRCLR and RCLK is same pin, 74595 will shift with load, and Operate->Load() will do nothing.
    voile_const_ioPin_t *RCLK;

    // (option) _SRCLR pin
    // If Operate->Reset() is not used, this variable can be initialized to NULL. And Operate->Init() will also init without reset.
    voile_const_ioPin_t *_SRCLR;

    // (option) _OE pin
    // If Operate->Enable() and Operate->Disable() is not used, this variable can be initialized to NULL.
    voile_const_ioPin_t *_OE;
    
    // (option) QH' pin
    // If Operate->ReadQH_() is not used, this variable can be initialized to NULL.
    voile_const_ioPin_t *QH_;

} voile_const_internal_74595_t;

struct voile_74595_Operate_struct{

    /**
     * @brief Init the io for control 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Init(&my74595);
     * @endcode
     * 
     * @details 74595 will be reset (if pin _SRCLR is defined) and disable (if pin _OE is defined).
     * 
    */
    voile_status_t (*Init)(voile_const_74595_t *);

    /**
     * @brief Reset 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Reset(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Reset)(voile_const_74595_t *);

    /**
     * @brief Write bit to 74595 pin, but do not load
     * 
     * @param[in] name  :[voile_const_74595_t *] This 74595 object.
     * @param[in] date  :[bool] The bit to write to 74595.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->ShiftBit(&my74595, 0);
     * @endcode
     * 
    */
    voile_status_t (*ShiftBit)(voile_const_74595_t *, bool);

    /**
     * @brief Write bytes to 74595 registers, but do not load
     * 
     * @param[in] name  :[voile_const_74595_t *] This 74595 object.
     * @param[in] date  :[uint8_t *] The date to write to 74595.
     * @param[in] lenth :[uint8_t]The length of the array.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * uint8_t date[3] = {0x34, 0x8a, 0xd1};
     * my74595.Operate->ShiftBytes(&my74595, &date, 3);
     * @endcode
     * 
    */
    voile_status_t (*ShiftBytes)(voile_const_74595_t *, uint8_t *, uint8_t);

    /**
     * @brief Load date to pin
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Load(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Load)(voile_const_74595_t *);
    
    /**
     * @brief Disable _OE of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Disable(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Disable)(voile_const_74595_t *);
    
    /**
     * @brief Enable _OE of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * my74595.Operate->Enable(&my74595);
     * @endcode
     * 
    */
    voile_status_t (*Enable)(voile_const_74595_t *);
    
    /**
     * @brief Read QH' of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @param[out] HQ_ :[voile_const_74595_t *] The value of pin QH'.
     * @return [voile_status_t] Status defined in common.h.
     * 
     * @par Sample
     * @code {.C}
     * bool value;
     * my74595.Operate->ReadQH_(&my74595, &value);
     * @endcode
     * 
    */
    voile_status_t (*ReadQH_)(voile_const_74595_t *, bool *QH_);

};

struct voile_74595_Get_struct {
    
    /**
     * @brief Read QH' of 74595
     * 
     * @param[in] name :[voile_const_74595_t *] This 74595 object.
     * @return [voile_const_74595_t *] The value of pin QH'.
     * 
     * @par Sample
     * @code {.C}
     * bool in = my74595.Get->ReadQH_(&my74595);
     * @endcode
     * 
     * @note If QH_ is not defined, this function will always return true!!!
     * 
    */
    bool (*ReadQH_)(voile_const_74595_t *);

};

extern voile_const_74595_Operate_t voile_const_74595_Operate;
extern voile_const_74595_Get_t voile_const_74595_Get;

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
    if (this->_SRCLR == NULL) {
        return hardwareUnsupportedError;
    }

    this->_SRCLR->Operate->Write(this->_SRCLR, 0);

    // Do not delete.
    // I don't know why, but my 74HC595 need a rise at RCLK to reset shift resister. 
    voile_74595_Operate_ShiftBit(this, 0);

    this->_SRCLR->Operate->Write(this->_SRCLR, 1);

    return success;
}

static inline voile_status_t voile_74595_Operate_Load(voile_const_internal_74595_t *this) {
    uint8_t delay = 20;
    if (this->SRCLK == this->RCLK){
        return success;
    }
    this->RCLK->Operate->Write(this->RCLK, 0);
    for (; delay > 0; delay--) {
        ;
    }
    return this->RCLK->Operate->Write(this->RCLK, 1);
}

static inline voile_status_t voile_74595_Operate_ReadQH_(voile_const_internal_74595_t *this, bool *value) {
    if (this->QH_ == NULL) {
        return failure;
    }
    return this->QH_->Operate->Read(this->QH_, value);
}

static inline bool voile_74595_Get_ReadQH_(voile_const_internal_74595_t *this) {
    if (this->QH_ == NULL) {
        return 1;
    }
    return this->QH_->Get->Read(this->QH_);
}

#endif // !__VOILE_74595_H__

#ifdef FUNCINIT
#undef FUNCINIT
#endif // FUNCINIT

#define FUNCINIT \
.Operate = &voile_const_74595_Operate, \
.Get = &voile_const_74595_Get
