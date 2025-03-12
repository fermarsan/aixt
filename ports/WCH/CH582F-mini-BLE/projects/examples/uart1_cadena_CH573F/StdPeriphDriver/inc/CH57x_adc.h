/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_adc.h
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef __CH57x_ADC_H__
#define __CH57x_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define ROM_CFG_TMP_25C    0x7F014

/**
 * @brief  adc single channel define
 */
typedef enum
{
    CH_EXTIN_0 = 0,   // ADC �ⲿģ��ͨ�� 0
    CH_EXTIN_1,       // ADC �ⲿģ��ͨ�� 1
    CH_EXTIN_2,       // ADC �ⲿģ��ͨ�� 2
    CH_EXTIN_3,       // ADC �ⲿģ��ͨ�� 3
    CH_EXTIN_4,       // ADC �ⲿģ��ͨ�� 4
    CH_EXTIN_5,       // ADC �ⲿģ��ͨ�� 5
    CH_EXTIN_8 = 8,   // ADC �ⲿģ��ͨ�� 8
    CH_EXTIN_9,       // ADC �ⲿģ��ͨ�� 9
    CH_EXTIN_12 = 12, // ADC �ⲿģ��ͨ�� 12
    CH_EXTIN_13,      // ADC �ⲿģ��ͨ�� 13

    CH_INTE_VBAT = 14,  // ADC �ڲ���ؼ��ͨ��
    CH_INTE_VTEMP = 15, // ADC �ڲ��¶ȴ��������ͨ��

} ADC_SingleChannelTypeDef;

/**
 * @brief  adc differential channel define
 */
typedef enum
{
    CH_DIFF_0_2 = 0, // ADC ���ͨ�� #0-#2
    CH_DIFF_1_3,     // ADC ���ͨ�� #1-#3

} ADC_DiffChannelTypeDef;

/**
 * @brief  adc sampling clock
 */
typedef enum
{
    SampleFreq_3_2 = 0, // 3.2M ����Ƶ��
    SampleFreq_8,       // 8M ����Ƶ��
    SampleFreq_5_33,    // 5.33M ����Ƶ��
    SampleFreq_4,       // 4M ����Ƶ��
} ADC_SampClkTypeDef;

/**
 * @brief  adc signal PGA
 */
typedef enum
{
    ADC_PGA_1_4 = 0, // -12dB, 1/4��
    ADC_PGA_1_2,     // -6dB, 1/2��
    ADC_PGA_0,       // 0dB, 1����������
    ADC_PGA_2,       // 6dB, 2��
} ADC_SignalPGATypeDef;

/**
 * @brief  Configuration DMA mode
 */
typedef enum
{
    ADC_Mode_Single = 0, // ����ģʽ
    ADC_Mode_LOOP,       // ѭ��ģʽ
} ADC_DMAModeTypeDef;


/**
 * @brief   ���� ADC ����ͨ��
 *
 * @param   d   - refer to ADC_SingleChannelTypeDef
 */
#define ADC_ChannelCfg(d)      (R8_ADC_CHANNEL = d)

/**
 * @brief   ���� ADC ����ʱ��
 *
 * @param   d   - refer to ADC_SampClkTypeDef
 */
#define ADC_SampClkCfg(d)      (R8_ADC_CFG = R8_ADC_CFG & (~RB_ADC_CLK_DIV) | (d << 6))

/**
 * @brief   ���� ADC �ź�����
 *
 * @param   d   - refer to ADC_SignalPGATypeDef
 */
#define ADC_PGACfg(d)          (R8_ADC_CFG = R8_ADC_CFG & (~RB_ADC_PGA_GAIN) | (d << 4))

/**
 * @brief   �����ڲ��¶ȴ�����У׼ֵ
 *
 * @param   d   - У׼ֵ
 */
#define ADC_TempCalibCfg(d)    (R8_TEM_SENSOR = R8_TEM_SENSOR & (~RB_TEM_SEN_CALIB) | d)

/**
 * @brief   �ⲿ�źŵ�ͨ��������ʼ��
 *
 * @param   sp  - refer to ADC_SampClkTypeDef
 * @param   ga  - refer to ADC_SignalPGATypeDef
 */
void ADC_ExtSingleChSampInit(ADC_SampClkTypeDef sp, ADC_SignalPGATypeDef ga);

/**
 * @brief   �ⲿ�źŲ��ͨ��������ʼ��
 *
 * @param   sp  - refer to ADC_SampClkTypeDef
 * @param   ga  - refer to ADC_SignalPGATypeDef
 */
void ADC_ExtDiffChSampInit(ADC_SampClkTypeDef sp, ADC_SignalPGATypeDef ga);

/**
 * @brief   ��������ͨ��������ʼ��
 */
void TouchKey_ChSampInit(void);

/**
 * @brief   �ر�TouchKey��Դ
 */
#define TouchKey_DisableTSPower()    (R8_TKEY_CFG &= ~RB_TKEY_PWR_ON)

/**
 * @brief   �����¶ȴ�����������ʼ��
 */
void ADC_InterTSSampInit(void);

/**
 * @brief   �ر��¶ȴ�������Դ
 */
#define ADC_DisableTSPower()    (R8_TEM_SENSOR = 0)

/**
 * @brief   ���õ�ص�ѹ������ʼ��
 */
void ADC_InterBATSampInit(void);

/**
 * @brief   ADCִ�е���ת��
 *
 * @return  ADCת���������
 */
uint16_t ADC_ExcutSingleConver(void);

/**
 * @brief   �������ݴֵ�,��ȡƫ��ֵ,����������ADC����ô˺�����ȡУ׼ֵ
 *
 * @return  ƫ��
 */
signed short ADC_DataCalib_Rough(void);

/**
 * @brief   TouchKeyת��������
 *
 * @param   charg   - Touchkey���ʱ��,5bits��Ч, t=charg*Tadc
 * @param   disch   - Touchkey�ŵ�ʱ��,3bits��Ч, t=disch*Tadc
 *
 * @return  ��ǰTouchKey��Ч����
 */
uint16_t TouchKey_ExcutSingleConver(uint8_t charg, uint8_t disch);

/**
 * @brief   �������� ADC������
 *
 * @param   cycle   - ��λΪ 16��ϵͳʱ��
 */
void ADC_AutoConverCycle(uint8_t cycle);

/**
 * @brief   ����DMA����
 *
 * @param   s           - �Ƿ��DMA����
 * @param   startAddr   - DMA ��ʼ��ַ
 * @param   endAddr     - DMA ������ַ
 * @param   m           - ����DMAģʽ
 */
void ADC_DMACfg(uint8_t s, uint16_t startAddr, uint16_t endAddr, ADC_DMAModeTypeDef m);

/**
 * @brief   Convert ADC value to temperature(Celsius)
 *
 * @param   adc_val - adc value
 *
 * @return  temperature (Celsius)
 */
int adc_to_temperature_celsius(uint16_t adc_val);

/**
 * @brief   ��ȡADCת��ֵ
 *
 * @return  ADCת��ֵ
 */
@[inline]
pub fn readConverValue() {
	C.(R16_ADC_DATA)
}

/**
 * @brief   ADCִ�е���ת��
 */
#define ADC_StartUp()             (R8_ADC_CONVERT = RB_ADC_START)

/**
 * @brief   ��ȡADC�ж�״̬
 */
#define ADC_GetITStatus()         (R8_ADC_INT_FLAG & RB_ADC_IF_EOC)

/**
 * @brief   ���ADC�жϱ�־
 */
#define ADC_ClearITFlag()         (R8_ADC_CONVERT = 0)

/**
 * @brief   ��ȡADC DMA���״̬
 */
#define ADC_GetDMAStatus()        (R8_ADC_DMA_IF & RB_ADC_IF_DMA_END)

/**
 * @brief   ���ADC DMA��ɱ�־
 */
#define ADC_ClearDMAFlag()        (R8_ADC_DMA_IF |= RB_ADC_IF_DMA_END)

/**
 * @brief   �����Զ����� ADC
 */
#define ADC_StartDMA()            (R8_ADC_CTRL_DMA |= RB_ADC_AUTO_EN)

/**
 * @brief   ֹͣ�Զ����� ADC
 */
#define ADC_StopDMA()            (R8_ADC_CTRL_DMA &= ~RB_ADC_AUTO_EN)

/**
 * @brief   ��ȡTouchKey�ж�״̬
 */
#define TouchKey_GetITStatus()    (R8_ADC_INT_FLAG & RB_ADC_IF_EOC)

/**
 * @brief   ���TouchKey�жϱ�־
 */
#define TouchKey_ClearITFlag()    (R8_TKEY_CTRL |= RB_TKEY_PWR_ON)


#ifdef __cplusplus
}
#endif

#endif  // __CH57x_ADC_H__	

