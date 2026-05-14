# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_DS18B20)
    return()
endif()

zephyr_library_named(alp_chip_ds18b20)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/ds18b20.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
