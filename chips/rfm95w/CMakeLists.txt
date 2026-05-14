# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_RFM95W)
    return()
endif()

zephyr_library_named(alp_chip_rfm95w)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/rfm95w.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
