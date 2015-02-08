#ifndef FSMC_BITS_H
#define FSMC_BITS_H
/******************  Bit definition for FSMC_BCR1 register  *******************/
#define  FSMC_BCR1_MBKEN                     ((uint32_t)0x00000001)        /*!< Memory bank enable bit */
#define  FSMC_BCR1_MUXEN                     ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable bit */

#define  FSMC_BCR1_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] bits (Memory type) */
#define  FSMC_BCR1_MTYP_0                    ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  FSMC_BCR1_MTYP_1                    ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  FSMC_BCR1_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] bits (Memory data bus width) */
#define  FSMC_BCR1_MWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BCR1_MWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_BCR1_FACCEN                    ((uint32_t)0x00000040)        /*!< Flash access enable */
#define  FSMC_BCR1_BURSTEN                   ((uint32_t)0x00000100)        /*!< Burst enable bit */
#define  FSMC_BCR1_WAITPOL                   ((uint32_t)0x00000200)        /*!< Wait signal polarity bit */
#define  FSMC_BCR1_WRAPMOD                   ((uint32_t)0x00000400)        /*!< Wrapped burst mode support */
#define  FSMC_BCR1_WAITCFG                   ((uint32_t)0x00000800)        /*!< Wait timing configuration */
#define  FSMC_BCR1_WREN                      ((uint32_t)0x00001000)        /*!< Write enable bit */
#define  FSMC_BCR1_WAITEN                    ((uint32_t)0x00002000)        /*!< Wait enable bit */
#define  FSMC_BCR1_EXTMOD                    ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  FSMC_BCR1_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< Asynchronous wait */
#define  FSMC_BCR1_CBURSTRW                  ((uint32_t)0x00080000)        /*!< Write burst enable */

/******************  Bit definition for FSMC_BCR2 register  *******************/
#define  FSMC_BCR2_MBKEN                     ((uint32_t)0x00000001)        /*!< Memory bank enable bit */
#define  FSMC_BCR2_MUXEN                     ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable bit */

#define  FSMC_BCR2_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] bits (Memory type) */
#define  FSMC_BCR2_MTYP_0                    ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  FSMC_BCR2_MTYP_1                    ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  FSMC_BCR2_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] bits (Memory data bus width) */
#define  FSMC_BCR2_MWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BCR2_MWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_BCR2_FACCEN                    ((uint32_t)0x00000040)        /*!< Flash access enable */
#define  FSMC_BCR2_BURSTEN                   ((uint32_t)0x00000100)        /*!< Burst enable bit */
#define  FSMC_BCR2_WAITPOL                   ((uint32_t)0x00000200)        /*!< Wait signal polarity bit */
#define  FSMC_BCR2_WRAPMOD                   ((uint32_t)0x00000400)        /*!< Wrapped burst mode support */
#define  FSMC_BCR2_WAITCFG                   ((uint32_t)0x00000800)        /*!< Wait timing configuration */
#define  FSMC_BCR2_WREN                      ((uint32_t)0x00001000)        /*!< Write enable bit */
#define  FSMC_BCR2_WAITEN                    ((uint32_t)0x00002000)        /*!< Wait enable bit */
#define  FSMC_BCR2_EXTMOD                    ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  FSMC_BCR2_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< Asynchronous wait */
#define  FSMC_BCR2_CBURSTRW                  ((uint32_t)0x00080000)        /*!< Write burst enable */

/******************  Bit definition for FSMC_BCR3 register  *******************/
#define  FSMC_BCR3_MBKEN                     ((uint32_t)0x00000001)        /*!< Memory bank enable bit */
#define  FSMC_BCR3_MUXEN                     ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable bit */

#define  FSMC_BCR3_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] bits (Memory type) */
#define  FSMC_BCR3_MTYP_0                    ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  FSMC_BCR3_MTYP_1                    ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  FSMC_BCR3_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] bits (Memory data bus width) */
#define  FSMC_BCR3_MWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BCR3_MWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_BCR3_FACCEN                    ((uint32_t)0x00000040)        /*!< Flash access enable */
#define  FSMC_BCR3_BURSTEN                   ((uint32_t)0x00000100)        /*!< Burst enable bit */
#define  FSMC_BCR3_WAITPOL                   ((uint32_t)0x00000200)        /*!< Wait signal polarity bit. */
#define  FSMC_BCR3_WRAPMOD                   ((uint32_t)0x00000400)        /*!< Wrapped burst mode support */
#define  FSMC_BCR3_WAITCFG                   ((uint32_t)0x00000800)        /*!< Wait timing configuration */
#define  FSMC_BCR3_WREN                      ((uint32_t)0x00001000)        /*!< Write enable bit */
#define  FSMC_BCR3_WAITEN                    ((uint32_t)0x00002000)        /*!< Wait enable bit */
#define  FSMC_BCR3_EXTMOD                    ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  FSMC_BCR3_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< Asynchronous wait */
#define  FSMC_BCR3_CBURSTRW                  ((uint32_t)0x00080000)        /*!< Write burst enable */

/******************  Bit definition for FSMC_BCR4 register  *******************/
#define  FSMC_BCR4_MBKEN                     ((uint32_t)0x00000001)        /*!< Memory bank enable bit */
#define  FSMC_BCR4_MUXEN                     ((uint32_t)0x00000002)        /*!< Address/data multiplexing enable bit */

#define  FSMC_BCR4_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] bits (Memory type) */
#define  FSMC_BCR4_MTYP_0                    ((uint32_t)0x00000004)        /*!< Bit 0 */
#define  FSMC_BCR4_MTYP_1                    ((uint32_t)0x00000008)        /*!< Bit 1 */

#define  FSMC_BCR4_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] bits (Memory data bus width) */
#define  FSMC_BCR4_MWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BCR4_MWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_BCR4_FACCEN                    ((uint32_t)0x00000040)        /*!< Flash access enable */
#define  FSMC_BCR4_BURSTEN                   ((uint32_t)0x00000100)        /*!< Burst enable bit */
#define  FSMC_BCR4_WAITPOL                   ((uint32_t)0x00000200)        /*!< Wait signal polarity bit */
#define  FSMC_BCR4_WRAPMOD                   ((uint32_t)0x00000400)        /*!< Wrapped burst mode support */
#define  FSMC_BCR4_WAITCFG                   ((uint32_t)0x00000800)        /*!< Wait timing configuration */
#define  FSMC_BCR4_WREN                      ((uint32_t)0x00001000)        /*!< Write enable bit */
#define  FSMC_BCR4_WAITEN                    ((uint32_t)0x00002000)        /*!< Wait enable bit */
#define  FSMC_BCR4_EXTMOD                    ((uint32_t)0x00004000)        /*!< Extended mode enable */
#define  FSMC_BCR4_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< Asynchronous wait */
#define  FSMC_BCR4_CBURSTRW                  ((uint32_t)0x00080000)        /*!< Write burst enable */

/******************  Bit definition for FSMC_BTR1 register  ******************/
#define  FSMC_BTR1_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BTR1_ADDSET_0                  ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BTR1_ADDSET_1                  ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BTR1_ADDSET_2                  ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BTR1_ADDSET_3                  ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BTR1_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BTR1_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BTR1_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BTR1_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BTR1_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BTR1_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BTR1_DATAST_0                  ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BTR1_DATAST_1                  ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BTR1_DATAST_2                  ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BTR1_DATAST_3                  ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BTR1_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FSMC_BTR1_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_BTR1_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_BTR1_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_BTR1_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  FSMC_BTR1_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BTR1_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BTR1_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BTR1_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BTR1_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BTR1_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BTR1_DATLAT_0                  ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BTR1_DATLAT_1                  ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BTR1_DATLAT_2                  ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BTR1_DATLAT_3                  ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BTR1_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BTR1_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BTR1_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BTR2 register  *******************/
#define  FSMC_BTR2_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BTR2_ADDSET_0                  ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BTR2_ADDSET_1                  ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BTR2_ADDSET_2                  ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BTR2_ADDSET_3                  ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BTR2_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BTR2_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BTR2_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BTR2_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BTR2_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BTR2_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BTR2_DATAST_0                  ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BTR2_DATAST_1                  ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BTR2_DATAST_2                  ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BTR2_DATAST_3                  ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BTR2_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FSMC_BTR2_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_BTR2_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_BTR2_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_BTR2_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  FSMC_BTR2_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BTR2_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BTR2_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BTR2_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BTR2_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BTR2_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BTR2_DATLAT_0                  ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BTR2_DATLAT_1                  ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BTR2_DATLAT_2                  ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BTR2_DATLAT_3                  ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BTR2_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BTR2_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BTR2_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< Bit 1 */

/*******************  Bit definition for FSMC_BTR3 register  *******************/
#define  FSMC_BTR3_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BTR3_ADDSET_0                  ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BTR3_ADDSET_1                  ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BTR3_ADDSET_2                  ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BTR3_ADDSET_3                  ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BTR3_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BTR3_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BTR3_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BTR3_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BTR3_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BTR3_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BTR3_DATAST_0                  ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BTR3_DATAST_1                  ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BTR3_DATAST_2                  ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BTR3_DATAST_3                  ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BTR3_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FSMC_BTR3_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_BTR3_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_BTR3_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_BTR3_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  FSMC_BTR3_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BTR3_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BTR3_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BTR3_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BTR3_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BTR3_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BTR3_DATLAT_0                  ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BTR3_DATLAT_1                  ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BTR3_DATLAT_2                  ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BTR3_DATLAT_3                  ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BTR3_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BTR3_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BTR3_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BTR4 register  *******************/
#define  FSMC_BTR4_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BTR4_ADDSET_0                  ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BTR4_ADDSET_1                  ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BTR4_ADDSET_2                  ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BTR4_ADDSET_3                  ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BTR4_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BTR4_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BTR4_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BTR4_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BTR4_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BTR4_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BTR4_DATAST_0                  ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BTR4_DATAST_1                  ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BTR4_DATAST_2                  ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BTR4_DATAST_3                  ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BTR4_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FSMC_BTR4_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_BTR4_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_BTR4_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_BTR4_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< Bit 3 */

#define  FSMC_BTR4_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BTR4_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BTR4_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BTR4_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BTR4_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BTR4_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BTR4_DATLAT_0                  ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BTR4_DATLAT_1                  ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BTR4_DATLAT_2                  ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BTR4_DATLAT_3                  ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BTR4_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BTR4_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BTR4_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BWTR1 register  ******************/
#define  FSMC_BWTR1_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BWTR1_ADDSET_0                 ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BWTR1_ADDSET_1                 ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BWTR1_ADDSET_2                 ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BWTR1_ADDSET_3                 ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BWTR1_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BWTR1_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BWTR1_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BWTR1_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BWTR1_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BWTR1_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BWTR1_DATAST_0                 ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BWTR1_DATAST_1                 ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BWTR1_DATAST_2                 ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BWTR1_DATAST_3                 ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BWTR1_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BWTR1_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BWTR1_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BWTR1_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BWTR1_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BWTR1_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BWTR1_DATLAT_0                 ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BWTR1_DATLAT_1                 ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BWTR1_DATLAT_2                 ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BWTR1_DATLAT_3                 ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BWTR1_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BWTR1_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BWTR1_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BWTR2 register  ******************/
#define  FSMC_BWTR2_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BWTR2_ADDSET_0                 ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BWTR2_ADDSET_1                 ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BWTR2_ADDSET_2                 ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BWTR2_ADDSET_3                 ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BWTR2_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BWTR2_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BWTR2_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BWTR2_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BWTR2_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BWTR2_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BWTR2_DATAST_0                 ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BWTR2_DATAST_1                 ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BWTR2_DATAST_2                 ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BWTR2_DATAST_3                 ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BWTR2_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BWTR2_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BWTR2_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< Bit 1*/
#define  FSMC_BWTR2_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BWTR2_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BWTR2_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BWTR2_DATLAT_0                 ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BWTR2_DATLAT_1                 ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BWTR2_DATLAT_2                 ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BWTR2_DATLAT_3                 ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BWTR2_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BWTR2_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BWTR2_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BWTR3 register  ******************/
#define  FSMC_BWTR3_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BWTR3_ADDSET_0                 ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BWTR3_ADDSET_1                 ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BWTR3_ADDSET_2                 ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BWTR3_ADDSET_3                 ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BWTR3_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BWTR3_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BWTR3_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BWTR3_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BWTR3_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BWTR3_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BWTR3_DATAST_0                 ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BWTR3_DATAST_1                 ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BWTR3_DATAST_2                 ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BWTR3_DATAST_3                 ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BWTR3_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BWTR3_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BWTR3_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BWTR3_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BWTR3_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BWTR3_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BWTR3_DATLAT_0                 ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BWTR3_DATLAT_1                 ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BWTR3_DATLAT_2                 ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BWTR3_DATLAT_3                 ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BWTR3_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BWTR3_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BWTR3_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_BWTR4 register  ******************/
#define  FSMC_BWTR4_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] bits (Address setup phase duration) */
#define  FSMC_BWTR4_ADDSET_0                 ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_BWTR4_ADDSET_1                 ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_BWTR4_ADDSET_2                 ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_BWTR4_ADDSET_3                 ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  FSMC_BWTR4_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FSMC_BWTR4_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_BWTR4_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  FSMC_BWTR4_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  FSMC_BWTR4_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< Bit 3 */

#define  FSMC_BWTR4_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST [3:0] bits (Data-phase duration) */
#define  FSMC_BWTR4_DATAST_0                 ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_BWTR4_DATAST_1                 ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_BWTR4_DATAST_2                 ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_BWTR4_DATAST_3                 ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  FSMC_BWTR4_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] bits (Clock divide ratio) */
#define  FSMC_BWTR4_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< Bit 0 */
#define  FSMC_BWTR4_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< Bit 1 */
#define  FSMC_BWTR4_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< Bit 2 */
#define  FSMC_BWTR4_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< Bit 3 */

#define  FSMC_BWTR4_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] bits (Data latency) */
#define  FSMC_BWTR4_DATLAT_0                 ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_BWTR4_DATLAT_1                 ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_BWTR4_DATLAT_2                 ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_BWTR4_DATLAT_3                 ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  FSMC_BWTR4_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] bits (Access mode) */
#define  FSMC_BWTR4_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< Bit 0 */
#define  FSMC_BWTR4_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< Bit 1 */

/******************  Bit definition for FSMC_PCR2 register  *******************/
#define  FSMC_PCR2_PWAITEN                   ((uint32_t)0x00000002)        /*!< Wait feature enable bit */
#define  FSMC_PCR2_PBKEN                     ((uint32_t)0x00000004)        /*!< PC Card/NAND Flash memory bank enable bit */
#define  FSMC_PCR2_PTYP                      ((uint32_t)0x00000008)        /*!< Memory type */

#define  FSMC_PCR2_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] bits (NAND Flash databus width) */
#define  FSMC_PCR2_PWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_PCR2_PWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_PCR2_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC computation logic enable bit */

#define  FSMC_PCR2_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] bits (CLE to RE delay) */
#define  FSMC_PCR2_TCLR_0                    ((uint32_t)0x00000200)        /*!< Bit 0 */
#define  FSMC_PCR2_TCLR_1                    ((uint32_t)0x00000400)        /*!< Bit 1 */
#define  FSMC_PCR2_TCLR_2                    ((uint32_t)0x00000800)        /*!< Bit 2 */
#define  FSMC_PCR2_TCLR_3                    ((uint32_t)0x00001000)        /*!< Bit 3 */

#define  FSMC_PCR2_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] bits (ALE to RE delay) */
#define  FSMC_PCR2_TAR_0                     ((uint32_t)0x00002000)        /*!< Bit 0 */
#define  FSMC_PCR2_TAR_1                     ((uint32_t)0x00004000)        /*!< Bit 1 */
#define  FSMC_PCR2_TAR_2                     ((uint32_t)0x00008000)        /*!< Bit 2 */
#define  FSMC_PCR2_TAR_3                     ((uint32_t)0x00010000)        /*!< Bit 3 */

#define  FSMC_PCR2_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[1:0] bits (ECC page size) */
#define  FSMC_PCR2_ECCPS_0                   ((uint32_t)0x00020000)        /*!< Bit 0 */
#define  FSMC_PCR2_ECCPS_1                   ((uint32_t)0x00040000)        /*!< Bit 1 */
#define  FSMC_PCR2_ECCPS_2                   ((uint32_t)0x00080000)        /*!< Bit 2 */

/******************  Bit definition for FSMC_PCR3 register  *******************/
#define  FSMC_PCR3_PWAITEN                   ((uint32_t)0x00000002)        /*!< Wait feature enable bit */
#define  FSMC_PCR3_PBKEN                     ((uint32_t)0x00000004)        /*!< PC Card/NAND Flash memory bank enable bit */
#define  FSMC_PCR3_PTYP                      ((uint32_t)0x00000008)        /*!< Memory type */

#define  FSMC_PCR3_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] bits (NAND Flash databus width) */
#define  FSMC_PCR3_PWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_PCR3_PWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_PCR3_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC computation logic enable bit */

#define  FSMC_PCR3_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] bits (CLE to RE delay) */
#define  FSMC_PCR3_TCLR_0                    ((uint32_t)0x00000200)        /*!< Bit 0 */
#define  FSMC_PCR3_TCLR_1                    ((uint32_t)0x00000400)        /*!< Bit 1 */
#define  FSMC_PCR3_TCLR_2                    ((uint32_t)0x00000800)        /*!< Bit 2 */
#define  FSMC_PCR3_TCLR_3                    ((uint32_t)0x00001000)        /*!< Bit 3 */

#define  FSMC_PCR3_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] bits (ALE to RE delay) */
#define  FSMC_PCR3_TAR_0                     ((uint32_t)0x00002000)        /*!< Bit 0 */
#define  FSMC_PCR3_TAR_1                     ((uint32_t)0x00004000)        /*!< Bit 1 */
#define  FSMC_PCR3_TAR_2                     ((uint32_t)0x00008000)        /*!< Bit 2 */
#define  FSMC_PCR3_TAR_3                     ((uint32_t)0x00010000)        /*!< Bit 3 */

#define  FSMC_PCR3_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[2:0] bits (ECC page size) */
#define  FSMC_PCR3_ECCPS_0                   ((uint32_t)0x00020000)        /*!< Bit 0 */
#define  FSMC_PCR3_ECCPS_1                   ((uint32_t)0x00040000)        /*!< Bit 1 */
#define  FSMC_PCR3_ECCPS_2                   ((uint32_t)0x00080000)        /*!< Bit 2 */

/******************  Bit definition for FSMC_PCR4 register  *******************/
#define  FSMC_PCR4_PWAITEN                   ((uint32_t)0x00000002)        /*!< Wait feature enable bit */
#define  FSMC_PCR4_PBKEN                     ((uint32_t)0x00000004)        /*!< PC Card/NAND Flash memory bank enable bit */
#define  FSMC_PCR4_PTYP                      ((uint32_t)0x00000008)        /*!< Memory type */

#define  FSMC_PCR4_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] bits (NAND Flash databus width) */
#define  FSMC_PCR4_PWID_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  FSMC_PCR4_PWID_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */

#define  FSMC_PCR4_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC computation logic enable bit */

#define  FSMC_PCR4_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] bits (CLE to RE delay) */
#define  FSMC_PCR4_TCLR_0                    ((uint32_t)0x00000200)        /*!< Bit 0 */
#define  FSMC_PCR4_TCLR_1                    ((uint32_t)0x00000400)        /*!< Bit 1 */
#define  FSMC_PCR4_TCLR_2                    ((uint32_t)0x00000800)        /*!< Bit 2 */
#define  FSMC_PCR4_TCLR_3                    ((uint32_t)0x00001000)        /*!< Bit 3 */

#define  FSMC_PCR4_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] bits (ALE to RE delay) */
#define  FSMC_PCR4_TAR_0                     ((uint32_t)0x00002000)        /*!< Bit 0 */
#define  FSMC_PCR4_TAR_1                     ((uint32_t)0x00004000)        /*!< Bit 1 */
#define  FSMC_PCR4_TAR_2                     ((uint32_t)0x00008000)        /*!< Bit 2 */
#define  FSMC_PCR4_TAR_3                     ((uint32_t)0x00010000)        /*!< Bit 3 */

#define  FSMC_PCR4_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[2:0] bits (ECC page size) */
#define  FSMC_PCR4_ECCPS_0                   ((uint32_t)0x00020000)        /*!< Bit 0 */
#define  FSMC_PCR4_ECCPS_1                   ((uint32_t)0x00040000)        /*!< Bit 1 */
#define  FSMC_PCR4_ECCPS_2                   ((uint32_t)0x00080000)        /*!< Bit 2 */

/*******************  Bit definition for FSMC_SR2 register  *******************/
#define  FSMC_SR2_IRS                        ((uint8_t)0x01)               /*!< Interrupt Rising Edge status */
#define  FSMC_SR2_ILS                        ((uint8_t)0x02)               /*!< Interrupt Level status */
#define  FSMC_SR2_IFS                        ((uint8_t)0x04)               /*!< Interrupt Falling Edge status */
#define  FSMC_SR2_IREN                       ((uint8_t)0x08)               /*!< Interrupt Rising Edge detection Enable bit */
#define  FSMC_SR2_ILEN                       ((uint8_t)0x10)               /*!< Interrupt Level detection Enable bit */
#define  FSMC_SR2_IFEN                       ((uint8_t)0x20)               /*!< Interrupt Falling Edge detection Enable bit */
#define  FSMC_SR2_FEMPT                      ((uint8_t)0x40)               /*!< FIFO empty */

/*******************  Bit definition for FSMC_SR3 register  *******************/
#define  FSMC_SR3_IRS                        ((uint8_t)0x01)               /*!< Interrupt Rising Edge status */
#define  FSMC_SR3_ILS                        ((uint8_t)0x02)               /*!< Interrupt Level status */
#define  FSMC_SR3_IFS                        ((uint8_t)0x04)               /*!< Interrupt Falling Edge status */
#define  FSMC_SR3_IREN                       ((uint8_t)0x08)               /*!< Interrupt Rising Edge detection Enable bit */
#define  FSMC_SR3_ILEN                       ((uint8_t)0x10)               /*!< Interrupt Level detection Enable bit */
#define  FSMC_SR3_IFEN                       ((uint8_t)0x20)               /*!< Interrupt Falling Edge detection Enable bit */
#define  FSMC_SR3_FEMPT                      ((uint8_t)0x40)               /*!< FIFO empty */

/*******************  Bit definition for FSMC_SR4 register  *******************/
#define  FSMC_SR4_IRS                        ((uint8_t)0x01)               /*!< Interrupt Rising Edge status */
#define  FSMC_SR4_ILS                        ((uint8_t)0x02)               /*!< Interrupt Level status */
#define  FSMC_SR4_IFS                        ((uint8_t)0x04)               /*!< Interrupt Falling Edge status */
#define  FSMC_SR4_IREN                       ((uint8_t)0x08)               /*!< Interrupt Rising Edge detection Enable bit */
#define  FSMC_SR4_ILEN                       ((uint8_t)0x10)               /*!< Interrupt Level detection Enable bit */
#define  FSMC_SR4_IFEN                       ((uint8_t)0x20)               /*!< Interrupt Falling Edge detection Enable bit */
#define  FSMC_SR4_FEMPT                      ((uint8_t)0x40)               /*!< FIFO empty */

/******************  Bit definition for FSMC_PMEM2 register  ******************/
#define  FSMC_PMEM2_MEMSET2                  ((uint32_t)0x000000FF)        /*!< MEMSET2[7:0] bits (Common memory 2 setup time) */
#define  FSMC_PMEM2_MEMSET2_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PMEM2_MEMSET2_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PMEM2_MEMSET2_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PMEM2_MEMSET2_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PMEM2_MEMSET2_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PMEM2_MEMSET2_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PMEM2_MEMSET2_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PMEM2_MEMSET2_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PMEM2_MEMWAIT2                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT2[7:0] bits (Common memory 2 wait time) */
#define  FSMC_PMEM2_MEMWAIT2_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PMEM2_MEMWAIT2_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PMEM2_MEMWAIT2_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PMEM2_MEMWAIT2_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PMEM2_MEMWAIT2_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PMEM2_MEMWAIT2_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PMEM2_MEMWAIT2_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PMEM2_MEMWAIT2_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PMEM2_MEMHOLD2                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD2[7:0] bits (Common memory 2 hold time) */
#define  FSMC_PMEM2_MEMHOLD2_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PMEM2_MEMHOLD2_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PMEM2_MEMHOLD2_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PMEM2_MEMHOLD2_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PMEM2_MEMHOLD2_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PMEM2_MEMHOLD2_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PMEM2_MEMHOLD2_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PMEM2_MEMHOLD2_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PMEM2_MEMHIZ2                  ((uint32_t)0xFF000000)        /*!< MEMHIZ2[7:0] bits (Common memory 2 databus HiZ time) */
#define  FSMC_PMEM2_MEMHIZ2_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PMEM2_MEMHIZ2_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PMEM2_MEMHIZ2_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PMEM2_MEMHIZ2_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PMEM2_MEMHIZ2_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PMEM2_MEMHIZ2_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PMEM2_MEMHIZ2_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PMEM2_MEMHIZ2_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PMEM3 register  ******************/
#define  FSMC_PMEM3_MEMSET3                  ((uint32_t)0x000000FF)        /*!< MEMSET3[7:0] bits (Common memory 3 setup time) */
#define  FSMC_PMEM3_MEMSET3_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PMEM3_MEMSET3_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PMEM3_MEMSET3_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PMEM3_MEMSET3_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PMEM3_MEMSET3_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PMEM3_MEMSET3_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PMEM3_MEMSET3_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PMEM3_MEMSET3_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PMEM3_MEMWAIT3                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT3[7:0] bits (Common memory 3 wait time) */
#define  FSMC_PMEM3_MEMWAIT3_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PMEM3_MEMWAIT3_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PMEM3_MEMWAIT3_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PMEM3_MEMWAIT3_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PMEM3_MEMWAIT3_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PMEM3_MEMWAIT3_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PMEM3_MEMWAIT3_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PMEM3_MEMWAIT3_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PMEM3_MEMHOLD3                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD3[7:0] bits (Common memory 3 hold time) */
#define  FSMC_PMEM3_MEMHOLD3_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PMEM3_MEMHOLD3_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PMEM3_MEMHOLD3_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PMEM3_MEMHOLD3_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PMEM3_MEMHOLD3_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PMEM3_MEMHOLD3_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PMEM3_MEMHOLD3_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PMEM3_MEMHOLD3_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PMEM3_MEMHIZ3                  ((uint32_t)0xFF000000)        /*!< MEMHIZ3[7:0] bits (Common memory 3 databus HiZ time) */
#define  FSMC_PMEM3_MEMHIZ3_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PMEM3_MEMHIZ3_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PMEM3_MEMHIZ3_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PMEM3_MEMHIZ3_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PMEM3_MEMHIZ3_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PMEM3_MEMHIZ3_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PMEM3_MEMHIZ3_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PMEM3_MEMHIZ3_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PMEM4 register  ******************/
#define  FSMC_PMEM4_MEMSET4                  ((uint32_t)0x000000FF)        /*!< MEMSET4[7:0] bits (Common memory 4 setup time) */
#define  FSMC_PMEM4_MEMSET4_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PMEM4_MEMSET4_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PMEM4_MEMSET4_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PMEM4_MEMSET4_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PMEM4_MEMSET4_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PMEM4_MEMSET4_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PMEM4_MEMSET4_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PMEM4_MEMSET4_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PMEM4_MEMWAIT4                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT4[7:0] bits (Common memory 4 wait time) */
#define  FSMC_PMEM4_MEMWAIT4_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PMEM4_MEMWAIT4_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PMEM4_MEMWAIT4_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PMEM4_MEMWAIT4_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PMEM4_MEMWAIT4_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PMEM4_MEMWAIT4_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PMEM4_MEMWAIT4_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PMEM4_MEMWAIT4_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PMEM4_MEMHOLD4                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD4[7:0] bits (Common memory 4 hold time) */
#define  FSMC_PMEM4_MEMHOLD4_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PMEM4_MEMHOLD4_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PMEM4_MEMHOLD4_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PMEM4_MEMHOLD4_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PMEM4_MEMHOLD4_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PMEM4_MEMHOLD4_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PMEM4_MEMHOLD4_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PMEM4_MEMHOLD4_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PMEM4_MEMHIZ4                  ((uint32_t)0xFF000000)        /*!< MEMHIZ4[7:0] bits (Common memory 4 databus HiZ time) */
#define  FSMC_PMEM4_MEMHIZ4_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PMEM4_MEMHIZ4_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PMEM4_MEMHIZ4_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PMEM4_MEMHIZ4_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PMEM4_MEMHIZ4_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PMEM4_MEMHIZ4_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PMEM4_MEMHIZ4_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PMEM4_MEMHIZ4_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PATT2 register  ******************/
#define  FSMC_PATT2_ATTSET2                  ((uint32_t)0x000000FF)        /*!< ATTSET2[7:0] bits (Attribute memory 2 setup time) */
#define  FSMC_PATT2_ATTSET2_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PATT2_ATTSET2_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PATT2_ATTSET2_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PATT2_ATTSET2_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PATT2_ATTSET2_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PATT2_ATTSET2_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PATT2_ATTSET2_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PATT2_ATTSET2_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PATT2_ATTWAIT2                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT2[7:0] bits (Attribute memory 2 wait time) */
#define  FSMC_PATT2_ATTWAIT2_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PATT2_ATTWAIT2_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PATT2_ATTWAIT2_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PATT2_ATTWAIT2_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PATT2_ATTWAIT2_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PATT2_ATTWAIT2_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PATT2_ATTWAIT2_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PATT2_ATTWAIT2_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PATT2_ATTHOLD2                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD2[7:0] bits (Attribute memory 2 hold time) */
#define  FSMC_PATT2_ATTHOLD2_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PATT2_ATTHOLD2_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PATT2_ATTHOLD2_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PATT2_ATTHOLD2_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PATT2_ATTHOLD2_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PATT2_ATTHOLD2_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PATT2_ATTHOLD2_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PATT2_ATTHOLD2_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PATT2_ATTHIZ2                  ((uint32_t)0xFF000000)        /*!< ATTHIZ2[7:0] bits (Attribute memory 2 databus HiZ time) */
#define  FSMC_PATT2_ATTHIZ2_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PATT2_ATTHIZ2_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PATT2_ATTHIZ2_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PATT2_ATTHIZ2_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PATT2_ATTHIZ2_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PATT2_ATTHIZ2_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PATT2_ATTHIZ2_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PATT2_ATTHIZ2_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PATT3 register  ******************/
#define  FSMC_PATT3_ATTSET3                  ((uint32_t)0x000000FF)        /*!< ATTSET3[7:0] bits (Attribute memory 3 setup time) */
#define  FSMC_PATT3_ATTSET3_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PATT3_ATTSET3_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PATT3_ATTSET3_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PATT3_ATTSET3_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PATT3_ATTSET3_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PATT3_ATTSET3_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PATT3_ATTSET3_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PATT3_ATTSET3_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PATT3_ATTWAIT3                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT3[7:0] bits (Attribute memory 3 wait time) */
#define  FSMC_PATT3_ATTWAIT3_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PATT3_ATTWAIT3_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PATT3_ATTWAIT3_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PATT3_ATTWAIT3_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PATT3_ATTWAIT3_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PATT3_ATTWAIT3_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PATT3_ATTWAIT3_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PATT3_ATTWAIT3_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PATT3_ATTHOLD3                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD3[7:0] bits (Attribute memory 3 hold time) */
#define  FSMC_PATT3_ATTHOLD3_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PATT3_ATTHOLD3_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PATT3_ATTHOLD3_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PATT3_ATTHOLD3_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PATT3_ATTHOLD3_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PATT3_ATTHOLD3_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PATT3_ATTHOLD3_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PATT3_ATTHOLD3_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PATT3_ATTHIZ3                  ((uint32_t)0xFF000000)        /*!< ATTHIZ3[7:0] bits (Attribute memory 3 databus HiZ time) */
#define  FSMC_PATT3_ATTHIZ3_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PATT3_ATTHIZ3_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PATT3_ATTHIZ3_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PATT3_ATTHIZ3_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PATT3_ATTHIZ3_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PATT3_ATTHIZ3_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PATT3_ATTHIZ3_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PATT3_ATTHIZ3_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PATT4 register  ******************/
#define  FSMC_PATT4_ATTSET4                  ((uint32_t)0x000000FF)        /*!< ATTSET4[7:0] bits (Attribute memory 4 setup time) */
#define  FSMC_PATT4_ATTSET4_0                ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PATT4_ATTSET4_1                ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PATT4_ATTSET4_2                ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PATT4_ATTSET4_3                ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PATT4_ATTSET4_4                ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PATT4_ATTSET4_5                ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PATT4_ATTSET4_6                ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PATT4_ATTSET4_7                ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PATT4_ATTWAIT4                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT4[7:0] bits (Attribute memory 4 wait time) */
#define  FSMC_PATT4_ATTWAIT4_0               ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PATT4_ATTWAIT4_1               ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PATT4_ATTWAIT4_2               ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PATT4_ATTWAIT4_3               ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PATT4_ATTWAIT4_4               ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PATT4_ATTWAIT4_5               ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PATT4_ATTWAIT4_6               ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PATT4_ATTWAIT4_7               ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PATT4_ATTHOLD4                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD4[7:0] bits (Attribute memory 4 hold time) */
#define  FSMC_PATT4_ATTHOLD4_0               ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PATT4_ATTHOLD4_1               ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PATT4_ATTHOLD4_2               ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PATT4_ATTHOLD4_3               ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PATT4_ATTHOLD4_4               ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PATT4_ATTHOLD4_5               ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PATT4_ATTHOLD4_6               ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PATT4_ATTHOLD4_7               ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PATT4_ATTHIZ4                  ((uint32_t)0xFF000000)        /*!< ATTHIZ4[7:0] bits (Attribute memory 4 databus HiZ time) */
#define  FSMC_PATT4_ATTHIZ4_0                ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PATT4_ATTHIZ4_1                ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PATT4_ATTHIZ4_2                ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PATT4_ATTHIZ4_3                ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PATT4_ATTHIZ4_4                ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PATT4_ATTHIZ4_5                ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PATT4_ATTHIZ4_6                ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PATT4_ATTHIZ4_7                ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_PIO4 register  *******************/
#define  FSMC_PIO4_IOSET4                    ((uint32_t)0x000000FF)        /*!< IOSET4[7:0] bits (I/O 4 setup time) */
#define  FSMC_PIO4_IOSET4_0                  ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  FSMC_PIO4_IOSET4_1                  ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  FSMC_PIO4_IOSET4_2                  ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  FSMC_PIO4_IOSET4_3                  ((uint32_t)0x00000008)        /*!< Bit 3 */
#define  FSMC_PIO4_IOSET4_4                  ((uint32_t)0x00000010)        /*!< Bit 4 */
#define  FSMC_PIO4_IOSET4_5                  ((uint32_t)0x00000020)        /*!< Bit 5 */
#define  FSMC_PIO4_IOSET4_6                  ((uint32_t)0x00000040)        /*!< Bit 6 */
#define  FSMC_PIO4_IOSET4_7                  ((uint32_t)0x00000080)        /*!< Bit 7 */

#define  FSMC_PIO4_IOWAIT4                   ((uint32_t)0x0000FF00)        /*!< IOWAIT4[7:0] bits (I/O 4 wait time) */
#define  FSMC_PIO4_IOWAIT4_0                 ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  FSMC_PIO4_IOWAIT4_1                 ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  FSMC_PIO4_IOWAIT4_2                 ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  FSMC_PIO4_IOWAIT4_3                 ((uint32_t)0x00000800)        /*!< Bit 3 */
#define  FSMC_PIO4_IOWAIT4_4                 ((uint32_t)0x00001000)        /*!< Bit 4 */
#define  FSMC_PIO4_IOWAIT4_5                 ((uint32_t)0x00002000)        /*!< Bit 5 */
#define  FSMC_PIO4_IOWAIT4_6                 ((uint32_t)0x00004000)        /*!< Bit 6 */
#define  FSMC_PIO4_IOWAIT4_7                 ((uint32_t)0x00008000)        /*!< Bit 7 */

#define  FSMC_PIO4_IOHOLD4                   ((uint32_t)0x00FF0000)        /*!< IOHOLD4[7:0] bits (I/O 4 hold time) */
#define  FSMC_PIO4_IOHOLD4_0                 ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  FSMC_PIO4_IOHOLD4_1                 ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  FSMC_PIO4_IOHOLD4_2                 ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  FSMC_PIO4_IOHOLD4_3                 ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  FSMC_PIO4_IOHOLD4_4                 ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  FSMC_PIO4_IOHOLD4_5                 ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  FSMC_PIO4_IOHOLD4_6                 ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  FSMC_PIO4_IOHOLD4_7                 ((uint32_t)0x00800000)        /*!< Bit 7 */

#define  FSMC_PIO4_IOHIZ4                    ((uint32_t)0xFF000000)        /*!< IOHIZ4[7:0] bits (I/O 4 databus HiZ time) */
#define  FSMC_PIO4_IOHIZ4_0                  ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  FSMC_PIO4_IOHIZ4_1                  ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  FSMC_PIO4_IOHIZ4_2                  ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  FSMC_PIO4_IOHIZ4_3                  ((uint32_t)0x08000000)        /*!< Bit 3 */
#define  FSMC_PIO4_IOHIZ4_4                  ((uint32_t)0x10000000)        /*!< Bit 4 */
#define  FSMC_PIO4_IOHIZ4_5                  ((uint32_t)0x20000000)        /*!< Bit 5 */
#define  FSMC_PIO4_IOHIZ4_6                  ((uint32_t)0x40000000)        /*!< Bit 6 */
#define  FSMC_PIO4_IOHIZ4_7                  ((uint32_t)0x80000000)        /*!< Bit 7 */

/******************  Bit definition for FSMC_ECCR2 register  ******************/
#define  FSMC_ECCR2_ECC2                     ((uint32_t)0xFFFFFFFF)        /*!< ECC result */

/******************  Bit definition for FSMC_ECCR3 register  ******************/
#define  FSMC_ECCR3_ECC3                     ((uint32_t)0xFFFFFFFF)        /*!< ECC result */

#endif /* FSMC_BITS_H */
