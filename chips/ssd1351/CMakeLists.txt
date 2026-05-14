# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_SSD1351)
    return()
endif()

zephyr_library_named(alp_chip_ssd1351)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/ssd1351.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
