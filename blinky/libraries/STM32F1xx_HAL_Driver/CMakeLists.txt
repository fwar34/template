set(LIB_NAME "stm32f10x_hal")

file(GLOB stm32f10x_hal_srcs CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/STM32F1xx_HAL_Driver/Src/*.c")

add_library(${LIB_NAME} STATIC "")

target_sources(${LIB_NAME} PRIVATE "${stm32f10x_hal_srcs}")

target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMSIS/Include")
target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32F1xx/Include")
target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/STM32F1xx_HAL_Driver/Inc")
target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/STM32F1xx_HAL_Driver/Inc/Legacy")


target_sources(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/system_stm32f1xx.c")
target_sources(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/${__TOOLCHAIN__}/startup_stm32f103xb.s")
# target_sources(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/${__TOOLCHAIN__}/startup_stm32f103xe.s")

target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/include")

# if(__CHIP_TYPE__ STREQUAL "STM32F103ZE")
if(__CHIP_TYPE__ STREQUAL "STM32F103C8")
    target_compile_definitions(${LIB_NAME}
    PUBLIC
        USE_HAL_DRIVER
        STM32F103xB
        # STM32F103xE
    )

    target_link_options(${LIB_NAME}
    PUBLIC
        -T "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/${__TOOLCHAIN__}/STM32F103XX_FLASH.ld"
        # -T "${CMAKE_CURRENT_LIST_DIR}/../../${__PROJ_NAME__}/chip/${__CHIP_TYPE__}/${__TOOLCHAIN__}/STM32F103ZETx_FLASH.ld"
    )
endif()
