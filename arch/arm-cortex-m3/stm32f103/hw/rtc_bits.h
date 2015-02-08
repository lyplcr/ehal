/******************************************************************************/
/*                                                                            */
/*                             Real-Time Clock                                */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for RTC_CRH register  ********************/
#define  RTC_CRH_SECIE                       ((uint8_t)0x01)               /*!< Second Interrupt Enable */
#define  RTC_CRH_ALRIE                       ((uint8_t)0x02)               /*!< Alarm Interrupt Enable */
#define  RTC_CRH_OWIE                        ((uint8_t)0x04)               /*!< OverfloW Interrupt Enable */

/*******************  Bit definition for RTC_CRL register  ********************/
#define  RTC_CRL_SECF                        ((uint8_t)0x01)               /*!< Second Flag */
#define  RTC_CRL_ALRF                        ((uint8_t)0x02)               /*!< Alarm Flag */
#define  RTC_CRL_OWF                         ((uint8_t)0x04)               /*!< OverfloW Flag */
#define  RTC_CRL_RSF                         ((uint8_t)0x08)               /*!< Registers Synchronized Flag */
#define  RTC_CRL_CNF                         ((uint8_t)0x10)               /*!< Configuration Flag */
#define  RTC_CRL_RTOFF                       ((uint8_t)0x20)               /*!< RTC operation OFF */

/*******************  Bit definition for RTC_PRLH register  *******************/
#define  RTC_PRLH_PRL                        ((uint16_t)0x000F)            /*!< RTC Prescaler Reload Value High */

/*******************  Bit definition for RTC_PRLL register  *******************/
#define  RTC_PRLL_PRL                        ((uint16_t)0xFFFF)            /*!< RTC Prescaler Reload Value Low */

/*******************  Bit definition for RTC_DIVH register  *******************/
#define  RTC_DIVH_RTC_DIV                    ((uint16_t)0x000F)            /*!< RTC Clock Divider High */

/*******************  Bit definition for RTC_DIVL register  *******************/
#define  RTC_DIVL_RTC_DIV                    ((uint16_t)0xFFFF)            /*!< RTC Clock Divider Low */

/*******************  Bit definition for RTC_CNTH register  *******************/
#define  RTC_CNTH_RTC_CNT                    ((uint16_t)0xFFFF)            /*!< RTC Counter High */

/*******************  Bit definition for RTC_CNTL register  *******************/
#define  RTC_CNTL_RTC_CNT                    ((uint16_t)0xFFFF)            /*!< RTC Counter Low */

/*******************  Bit definition for RTC_ALRH register  *******************/
#define  RTC_ALRH_RTC_ALR                    ((uint16_t)0xFFFF)            /*!< RTC Alarm High */

/*******************  Bit definition for RTC_ALRL register  *******************/
#define  RTC_ALRL_RTC_ALR                    ((uint16_t)0xFFFF)            /*!< RTC Alarm Low */


