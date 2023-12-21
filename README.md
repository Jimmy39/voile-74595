# voile-74595
Operate 74595 in voile library.Suppot basic operation include shift, load and reset etc.

For more informations about voile library, see [voile-library](https://github.com/Jimmy39/voile-library).

## Dependence
This library use with:

**[voile-interface-iopin](https://github.com/Jimmy39/voile-interface-iopin)** : Use io to control 74595.

**[voile-library](https://github.com/Jimmy39/voile-library)** : Some common defination.

## Class voile_const_internal_74595_t and voile_const_74595_t
This library defines struct ```voile_const_internal_74595_t``` for chip 74595:

```C
typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;

    // _SRCLR pin
    voile_const_ioPin_t *_SRCLR;

    // _OE pin
    voile_const_ioPin_t *_OE;
    
    // SRCLK pin
    voile_const_ioPin_t *SRCLK;
    
    // SER pin
    voile_const_ioPin_t *SER;
    
    // _RCLK pin
    voile_const_ioPin_t *RCLK;

    // QH' pin
    voile_const_ioPin_t *QH_;

} voile_const_internal_74595_t;
```

And the struct ```voile_const_74595_t``` is interface:

```C
typedef const struct {

    // Operate the 74595
    voile_const_74595_Operate_t *Operate;
    
} voile_const_74595_t;
```

### Define
You should define and init struct at *devicelist.c*

```C
// Define the io you use to control 74595
#include "voile_iopin_xxx.h"

voile_const_internal_ioPin_xxx_t my595_QH = {
    // ...
    // It depends
};

// ...
// And other pin
#include "voile_iopin_xxx_end.h"

// Define 74595
#include "voile_74595.h"

voile_const_internal_74595_t my595 = {
    // A micro to init all const function pointer srtuct
    FUNCINIT,

    // The pin you use to control 74595
    .RCLK = (const voile_const_ioPin_t *)&my595_RCLK,
    .SER = (const voile_const_ioPin_t *)&my595_SER,
    .SRCLK = (const voile_const_ioPin_t *)&my595_SRCLK,
    ._OE = (const voile_const_ioPin_t *)&my595__OE,
    ._SRCLR = (const voile_const_ioPin_t *)&my595__SRCLR,
    .QH_ = (const voile_const_ioPin_t *)&my595_QH
};


// some else voile_const_internal_ioPin_rp2040_t structs defination

#include "voile_74595_end.h"
```

### Declare
And declare at *devicelist.h* as struct ```voile_const_74595_t```

```C
#include "voile_74595.h"

extern voile_const_74595_t my595;
```

### Usage
There is a docs created by doxygen.

[https://jimmy39.github.io/voile-74595/index.html](https://jimmy39.github.io/voile-74595/index.html)
