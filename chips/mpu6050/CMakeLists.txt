# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_MPU6050)
    return()
endif()

zephyr_library_named(alp_chip_mpu6050)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/mpu6050.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
