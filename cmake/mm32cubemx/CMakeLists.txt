cmake_minimum_required(VERSION 3.22)

project(mm32cubemx)
add_library(mm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(mm32cubemx INTERFACE 
#	USE_HAL_DRIVER 
#	STM32F103x6 
#	STM32_THREAD_SAFE_STRATEGY=2
    $<$<CONFIG:Debug>:DEBUG>
    USE_STDPERIPH_DRIVER
)

target_include_directories(mm32cubemx INTERFACE
    ../../Core/Inc
    ../../Drivers/CMSIS/Core
    ../../Drivers/HAL_Lib/Inc
    ../../Drivers/CMSIS/Core/Inc
)

target_sources(mm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/mm32g0001_it.c
    ../../Core/Src/gpio_led_toggle.c
    ../../Core/Src/platform.c
    
    ../../Drivers/HAL_Lib/Src/hal_adc.c
    ../../Drivers/HAL_Lib/Src/hal_crc.c
    ../../Drivers/HAL_Lib/Src/hal_dbg.c
    ../../Drivers/HAL_Lib/Src/hal_exti.c
    ../../Drivers/HAL_Lib/Src/hal_flash.c
    ../../Drivers/HAL_Lib/Src/hal_gpio.c
    ../../Drivers/HAL_Lib/Src/hal_i2c.c
    ../../Drivers/HAL_Lib/Src/hal_iwdg.c
    ../../Drivers/HAL_Lib/Src/hal_misc.c
    ../../Drivers/HAL_Lib/Src/hal_pwr.c
    ../../Drivers/HAL_Lib/Src/hal_rcc.c
    ../../Drivers/HAL_Lib/Src/hal_spi.c
    ../../Drivers/HAL_Lib/Src/hal_syscfg.c
    ../../Drivers/HAL_Lib/Src/hal_tim.c
    ../../Drivers/HAL_Lib/Src/hal_uid.c
    ../../Drivers/HAL_Lib/Src/hal_usart.c  
    
    ../../Drivers/startup/system_mm32g0001.c
    ../../Drivers/startup/startup_mm32g0001_keil.S
)

target_link_directories(mm32cubemx INTERFACE
)

target_link_libraries(mm32cubemx INTERFACE
)

# Validate that mm32cubemx code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


