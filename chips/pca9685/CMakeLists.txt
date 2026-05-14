# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_PCA9685)
    return()
endif()

zephyr_library_named(alp_chip_pca9685)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/pca9685.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
