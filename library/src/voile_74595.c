#include "voile_74595.h"

voile_const_74595_Operate_t voile_const_74595_Operate = {
    .Init = (voile_status_t (*)(voile_const_74595_t *))voile_74595_Operate_Init,
    .Reset = (voile_status_t (*)(voile_const_74595_t *))voile_74595_Operate_Reset,
    .ShiftBit = (voile_status_t (*)(voile_const_74595_t *, bool))voile_74595_Operate_ShiftBit,
    .ShiftBytes = (voile_status_t (*)(voile_const_74595_t *, uint8_t *, uint8_t))voile_74595_Operate_ShiftBytes,
    .Load = (voile_status_t (*)(voile_const_74595_t *))voile_74595_Operate_Load,
    .Disable = (voile_status_t (*)(voile_const_74595_t *))voile_74595_Operate_Disable,
    .Enable = (voile_status_t (*)(voile_const_74595_t *))voile_74595_Operate_Enable,
    .ReadQH_ = (voile_status_t (*)(voile_const_74595_t *, bool *))voile_74595_Operate_ReadQH_
};

voile_const_74595_Get_t voile_const_74595_Get = {
    .ReadQH_ = (bool (*)(voile_const_74595_t *))voile_74595_Get_ReadQH_
};

voile_status_t voile_74595_Operate_Init(voile_const_internal_74595_t* this) {

    // Defination cheak
    if ((this->SER == NULL)||(this->SRCLK == NULL)||(this->RCLK == NULL)) {
        return failure;
    }

    this->SER->Operate->SetMode(this->SER, IOmodePushPull);
    this->SER->Operate->Write(this->SER, 0);
    this->SRCLK->Operate->SetMode(this->SRCLK, IOmodePushPull);
    this->SRCLK->Operate->Write(this->SRCLK, 1);
    if (this->RCLK != this->SRCLK) {
        this->RCLK->Operate->SetMode(this->RCLK, IOmodePushPull);
        this->RCLK->Operate->Write(this->RCLK, 0);
    }
    if (this->_OE != NULL) {
        this->_OE->Operate->SetMode(this->_OE, IOmodePushPull);
        this->_OE->Operate->Write(this->_OE, 1);
    }
    if (this->_SRCLR != NULL) {
        this->_SRCLR->Operate->SetMode(this->_SRCLR, IOmodePushPull);
        this->_SRCLR->Operate->Write(this->_SRCLR, 0);
    }
    if (this->QH_ != NULL) {
        this->QH_->Operate->SetMode(this->QH_, IOmodeInput);
    }
    this->RCLK->Operate->Init(this->RCLK);
    this->SER->Operate->Init(this->SER);
    if (this->RCLK != this->SRCLK) {
        this->SRCLK->Operate->Init(this->SRCLK);
    }
    if (this->_OE != NULL) {
        this->_OE->Operate->Init(this->_OE);
    }
    if (this->_SRCLR != NULL) {
        this->_SRCLR->Operate->Init(this->_SRCLR);
    }
    if (this->QH_ != NULL) {
        this->QH_->Operate->Init(this->QH_);
    }
    voile_74595_Operate_Reset(this);
    return success;
} 

voile_status_t voile_74595_Operate_ShiftBytes(voile_const_internal_74595_t* this, uint8_t *date, uint8_t lenth) {
    uint8_t delay = 20;
    uint8_t byte;
    for(; lenth > 0; lenth--) {
        byte = date[lenth-1];
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));
        byte <<= 1;
        for (delay = 20; delay > 0; delay--) {
            ;
        }
        voile_74595_Operate_ShiftBit(this, !!(byte & 0x80));       
    }
    return success;
}
