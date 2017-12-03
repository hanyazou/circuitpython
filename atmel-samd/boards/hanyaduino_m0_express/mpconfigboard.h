// LEDs
//#define MICROPY_HW_LED_MSC              PIN_PA17 // red
// #define UART_REPL
#define USB_REPL

#define MICROPY_HW_BOARD_NAME "Hanyaduino M0 Express"
#define MICROPY_HW_MCU_NAME "samd21g18"

#define MICROPY_PORT_A (PORT_PA18 | PORT_PA19 | PORT_PA22 \
			| PORT_PA28 | PORT_PA23 \
			| PORT_PA24 | PORT_PA25)
#define MICROPY_PORT_B        (0)

// Salae reads 12mhz which is the limit even though we set it to the safer 8mhz.
#define SPI_FLASH_BAUDRATE  (8000000)

// hanyaduino settings
#define SPI_FLASH_MUX_SETTING SPI_SIGNAL_MUX_SETTING_E
#define SPI_FLASH_PAD0_PINMUX PINMUX_PA22C_SERCOM3_PAD0 // MISO
#define SPI_FLASH_PAD1_PINMUX PINMUX_UNUSED             // we manage chip select ourselves
#define SPI_FLASH_PAD2_PINMUX PINMUX_PA18D_SERCOM3_PAD2 // MOSI
#define SPI_FLASH_PAD3_PINMUX PINMUX_PA19D_SERCOM3_PAD3 // SCK
#define SPI_FLASH_SERCOM SERCOM3
//#define SPI_FLASH_CS PIN_PA28
#define SPI_FLASH_CS PIN_PA23  // D10

#include "spi_flash.h"

// If you change this, then make sure to update the linker scripts as well to
// make sure you don't overwrite code.
#define CIRCUITPY_INTERNAL_NVM_SIZE 256

#define BOARD_FLASH_SIZE (0x00040000 - 0x2000 - CIRCUITPY_INTERNAL_NVM_SIZE)

//#include "flash_S25FL127S.h"
#include "flash_W25Q32BV.h"
