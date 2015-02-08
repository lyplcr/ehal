#ifndef PWR_BITS_H
#define PWR_BITS_H
/********************  Bit definition for PWR_CR register  ********************/
#define  PWR_CR_LPDS                         ((uint16_t)0x0001)     /*!< Low-Power Deepsleep */
#define  PWR_CR_PDDS                         ((uint16_t)0x0002)     /*!< Power Down Deepsleep */
#define  PWR_CR_CWUF                         ((uint16_t)0x0004)     /*!< Clear Wakeup Flag */
#define  PWR_CR_CSBF                         ((uint16_t)0x0008)     /*!< Clear Standby Flag */
#define  PWR_CR_PVDE                         ((uint16_t)0x0010)     /*!< Power Voltage Detector Enable */

#define  PWR_CR_PLS                          ((uint16_t)0x00E0)     /*!< PLS[2:0] bits (PVD Level Selection) */
#define  PWR_CR_PLS_0                        ((uint16_t)0x0020)     /*!< Bit 0 */
#define  PWR_CR_PLS_1                        ((uint16_t)0x0040)     /*!< Bit 1 */
#define  PWR_CR_PLS_2                        ((uint16_t)0x0080)     /*!< Bit 2 */

/*!< PVD level configuration */
#define  PWR_CR_PLS_2V2                      ((uint16_t)0x0000)     /*!< PVD level 2.2V */
#define  PWR_CR_PLS_2V3                      ((uint16_t)0x0020)     /*!< PVD level 2.3V */
#define  PWR_CR_PLS_2V4                      ((uint16_t)0x0040)     /*!< PVD level 2.4V */
#define  PWR_CR_PLS_2V5                      ((uint16_t)0x0060)     /*!< PVD level 2.5V */
#define  PWR_CR_PLS_2V6                      ((uint16_t)0x0080)     /*!< PVD level 2.6V */
#define  PWR_CR_PLS_2V7                      ((uint16_t)0x00A0)     /*!< PVD level 2.7V */
#define  PWR_CR_PLS_2V8                      ((uint16_t)0x00C0)     /*!< PVD level 2.8V */
#define  PWR_CR_PLS_2V9                      ((uint16_t)0x00E0)     /*!< PVD level 2.9V */

#define  PWR_CR_DBP                          ((uint16_t)0x0100)     /*!< Disable Backup Domain write protection */


/*******************  Bit definition for PWR_CSR register  ********************/
#define  PWR_CSR_WUF                         ((uint16_t)0x0001)     /*!< Wakeup Flag */
#define  PWR_CSR_SBF                         ((uint16_t)0x0002)     /*!< Standby Flag */
#define  PWR_CSR_PVDO                        ((uint16_t)0x0004)     /*!< PVD Output */
#define  PWR_CSR_EWUP                        ((uint16_t)0x0100)     /*!< Enable WKUP pin */

#endif /* PWR_BITS_H */
