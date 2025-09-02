// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: ADC functions (WCH-CH582F)

module adc

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: ADC functions (WCH-CH582F)


fn C.read(valor u8) 

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: ADC functions (WCH-CH582F)


@[inline]
pub fn setup(channel) {
C.ADC_ChannelCfg(channel)
}
