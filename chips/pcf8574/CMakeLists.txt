# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_PCF8574)
    return()
endif()

zephyr_library_named(alp_chip_pcf8574)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/pcf8574.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
