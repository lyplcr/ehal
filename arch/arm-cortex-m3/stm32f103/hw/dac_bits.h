#ifndef DAC_BITS_H
#define DAC_BITS_H
/********************  Bit definition for DAC_CR register  ********************/
#define  DAC_CR_EN1                          ((uint32_t)0x00000001)        /*!< DAC channel1 enable */
#define  DAC_CR_BOFF1                        ((uint32_t)0x00000002)        /*!< DAC channel1 output buffer disable */
#define  DAC_CR_TEN1                         ((uint32_t)0x00000004)        /*!< DAC channel1 Trigger enable */

#define  DAC_CR_TSEL1                        ((uint32_t)0x00000038)        /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  DAC_CR_TSEL1_0                      ((uint32_t)0x00000008)        /*!< Bit 0 */
#define  DAC_CR_TSEL1_1                      ((uint32_t)0x00000010)        /*!< Bit 1 */
#define  DAC_CR_TSEL1_2                      ((uint32_t)0x00000020)        /*!< Bit 2 */

#define  DAC_CR_WAVE1                        ((uint32_t)0x000000C0)        /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE1_0                      ((uint32_t)0x00000040)        /*!< Bit 0 */
#define  DAC_CR_WAVE1_1                      ((uint32_t)0x00000080)        /*!< Bit 1 */

#define  DAC_CR_MAMP1                        ((uint32_t)0x00000F00)        /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define  DAC_CR_MAMP1_0                      ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  DAC_CR_MAMP1_1                      ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  DAC_CR_MAMP1_2                      ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  DAC_CR_MAMP1_3                      ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  DAC_CR_DMAEN1                       ((uint32_t)0x00001000)        /*!< DAC channel1 DMA enable */
#define  DAC_CR_EN2                          ((uint32_t)0x00010000)        /*!< DAC channel2 enable */
#define  DAC_CR_BOFF2                        ((uint32_t)0x00020000)        /*!< DAC channel2 output buffer disable */
#define  DAC_CR_TEN2                         ((uint32_t)0x00040000)        /*!< DAC channel2 Trigger enable */

#define  DAC_CR_TSEL2                        ((uint32_t)0x00380000)        /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define  DAC_CR_TSEL2_0                      ((uint32_t)0x00080000)        /*!< Bit 0 */
#define  DAC_CR_TSEL2_1                      ((uint32_t)0x00100000)        /*!< Bit 1 */
#define  DAC_CR_TSEL2_2                      ((uint32_t)0x00200000)        /*!< Bit 2 */

#define  DAC_CR_WAVE2                        ((uint32_t)0x00C00000)        /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE2_0                      ((uint32_t)0x00400000)        /*!< Bit 0 */
#define  DAC_CR_WAVE2_1                      ((uint32_t)0x00800000)        /*!< Bit 1 */

#define  DAC_CR_MAMP2                        ((uint32_t)0x0F000000)        /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define  DAC_CR_MAMP2_0                      ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  DAC_CR_MAMP2_1                      ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  DAC_CR_MAMP2_2                      ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  DAC_CR_MAMP2_3                      ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  DAC_CR_DMAEN2                       ((uint32_t)0x10000000)        /*!< DAC channel2 DMA enabled */

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define  DAC_SWTRIGR_SWTRIG1                 ((uint8_t)0x01)               /*!< DAC channel1 software trigger */
#define  DAC_SWTRIGR_SWTRIG2                 ((uint8_t)0x02)               /*!< DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define  DAC_DHR12R1_DACC1DHR                ((uint16_t)0x0FFF)            /*!< DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define  DAC_DHR12L1_DACC1DHR                ((uint16_t)0xFFF0)            /*!< DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define  DAC_DHR8R1_DACC1DHR                 ((uint8_t)0xFF)               /*!< DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define  DAC_DHR12R2_DACC2DHR                ((uint16_t)0x0FFF)            /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define  DAC_DHR12L2_DACC2DHR                ((uint16_t)0xFFF0)            /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define  DAC_DHR8R2_DACC2DHR                 ((uint8_t)0xFF)               /*!< DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define  DAC_DHR12RD_DACC1DHR                ((uint32_t)0x00000FFF)        /*!< DAC channel1 12-bit Right aligned data */
#define  DAC_DHR12RD_DACC2DHR                ((uint32_t)0x0FFF0000)        /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define  DAC_DHR12LD_DACC1DHR                ((uint32_t)0x0000FFF0)        /*!< DAC channel1 12-bit Left aligned data */
#define  DAC_DHR12LD_DACC2DHR                ((uint32_t)0xFFF00000)        /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define  DAC_DHR8RD_DACC1DHR                 ((uint16_t)0x00FF)            /*!< DAC channel1 8-bit Right aligned data */
#define  DAC_DHR8RD_DACC2DHR                 ((uint16_t)0xFF00)            /*!< DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define  DAC_DOR1_DACC1DOR                   ((uint16_t)0x0FFF)            /*!< DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define  DAC_DOR2_DACC2DOR                   ((uint16_t)0x0FFF)            /*!< DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define  DAC_SR_DMAUDR1                      ((uint32_t)0x00002000)        /*!< DAC channel1 DMA underrun flag */
#define  DAC_SR_DMAUDR2                      ((uint32_t)0x20000000)        /*!< DAC channel2 DMA underrun flag */

#endif /* DAC_BITS_H */
