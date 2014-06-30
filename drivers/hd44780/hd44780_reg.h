// RS=0
// RW=0 (Write)
/* -------------------------------------------------------------------------- */
#define CMD_CLEAR        0x01
#define CMD_HOME         0x02

#define CMD_MODE_M       0x04
#define CMD_MODE_INC_DEC 0x02 // Increment/Decrement.
#define CMD_MODE_SHIFT   0x01 // Acompanies display shift.

#define CMD_CTL_M        0x08
#define CMD_CTL_DISPLAY  0x04
#define CMD_CTL_CURSOR   0x02
#define CMD_CTL_BLINK    0x01

#define CMD_SHIFT_M      0x10
#define CMD_SHIFT_SHIFT  0x08
#define CMD_SHIFT_RIGHT  0x04

#define CMD_FN_M         0x20
#define CMD_FN_8PINS     0x10
#define CMD_FN_4PINS     0x00
#define CMD_FN_2LINES    0x08
#define CMD_FN_1LINES    0x00
#define CMD_FN_FONT      0x04

#define CMD_CGR_ADDR_M   0x7f
#define CMD_DDR_ADDR_M   0xff

// RS=0
// RW=1 (Read)
/* -------------------------------------------------------------------------- */
#define CMD_FLAGS        0xff
#define CMD_FLAGS_BUSY   0x80

/* ========================================================================== */
// RS=1
// RW=0
/* -------------------------------------------------------------------------- */
// WRITE DATA

// RS=1
// RW=1
/* -------------------------------------------------------------------------- */
// READ DATA
