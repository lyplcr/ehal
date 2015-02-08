#ifndef CEC_BITS_H
#define CEC_BITS_H
/********************  Bit definition for CEC_CFGR register  ******************/
#define  CEC_CFGR_PE              ((uint16_t)0x0001)     /*!<  Peripheral Enable */
#define  CEC_CFGR_IE              ((uint16_t)0x0002)     /*!<  Interrupt Enable */
#define  CEC_CFGR_BTEM            ((uint16_t)0x0004)     /*!<  Bit Timing Error Mode */
#define  CEC_CFGR_BPEM            ((uint16_t)0x0008)     /*!<  Bit Period Error Mode */

/********************  Bit definition for CEC_OAR register  ******************/
#define  CEC_OAR_OA               ((uint16_t)0x000F)     /*!<  OA[3:0]: Own Address */
#define  CEC_OAR_OA_0             ((uint16_t)0x0001)     /*!<  Bit 0 */
#define  CEC_OAR_OA_1             ((uint16_t)0x0002)     /*!<  Bit 1 */
#define  CEC_OAR_OA_2             ((uint16_t)0x0004)     /*!<  Bit 2 */
#define  CEC_OAR_OA_3             ((uint16_t)0x0008)     /*!<  Bit 3 */

/********************  Bit definition for CEC_PRES register  ******************/
#define  CEC_PRES_PRES            ((uint16_t)0x3FFF)   /*!<  Prescaler Counter Value */

/********************  Bit definition for CEC_ESR register  ******************/
#define  CEC_ESR_BTE              ((uint16_t)0x0001)     /*!<  Bit Timing Error */
#define  CEC_ESR_BPE              ((uint16_t)0x0002)     /*!<  Bit Period Error */
#define  CEC_ESR_RBTFE            ((uint16_t)0x0004)     /*!<  Rx Block Transfer Finished Error */
#define  CEC_ESR_SBE              ((uint16_t)0x0008)     /*!<  Start Bit Error */
#define  CEC_ESR_ACKE             ((uint16_t)0x0010)     /*!<  Block Acknowledge Error */
#define  CEC_ESR_LINE             ((uint16_t)0x0020)     /*!<  Line Error */
#define  CEC_ESR_TBTFE            ((uint16_t)0x0040)     /*!<  Tx Block Transfer Finished Error */

/********************  Bit definition for CEC_CSR register  ******************/
#define  CEC_CSR_TSOM             ((uint16_t)0x0001)     /*!<  Tx Start Of Message */
#define  CEC_CSR_TEOM             ((uint16_t)0x0002)     /*!<  Tx End Of Message */
#define  CEC_CSR_TERR             ((uint16_t)0x0004)     /*!<  Tx Error */
#define  CEC_CSR_TBTRF            ((uint16_t)0x0008)     /*!<  Tx Byte Transfer Request or Block Transfer Finished */
#define  CEC_CSR_RSOM             ((uint16_t)0x0010)     /*!<  Rx Start Of Message */
#define  CEC_CSR_REOM             ((uint16_t)0x0020)     /*!<  Rx End Of Message */
#define  CEC_CSR_RERR             ((uint16_t)0x0040)     /*!<  Rx Error */
#define  CEC_CSR_RBTF             ((uint16_t)0x0080)     /*!<  Rx Block Transfer Finished */

/********************  Bit definition for CEC_TXD register  ******************/
#define  CEC_TXD_TXD              ((uint16_t)0x00FF)     /*!<  Tx Data register */

/********************  Bit definition for CEC_RXD register  ******************/
#define  CEC_RXD_RXD              ((uint16_t)0x00FF)     /*!<  Rx Data register */

#endif /* CEC_BITS_H */
