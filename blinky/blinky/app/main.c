#include "bsp.h"
#include "stm32f1xx_hal.h"

int main(void) {
    BSP_init();
    while (1) {
        BSP_ledRedOn();
        HAL_Delay(500U);
        BSP_ledRedOff();
        HAL_Delay(500U);
    }
}
