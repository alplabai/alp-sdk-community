# SPDX-License-Identifier: Apache-2.0
if(NOT DEFINED CONFIG_ALP_SDK_CHIP_NRF24L01)
    return()
endif()

zephyr_library_named(alp_chip_nrf24l01)

zephyr_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/src/nrf24l01.c)

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
