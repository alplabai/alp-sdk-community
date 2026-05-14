# SPDX-License-Identifier: Apache-2.0
# alp-sdk-community chip-skeleton CMake fragment.
#
# Sourced by the alp-sdk Zephyr build when this chip is enabled via
# the consumer's west.yml or board.yaml.

if(NOT DEFINED CONFIG_ALP_SDK_CHIP_CHIP_TEMPLATE)
    return()
endif()

zephyr_library_named(alp_chip_chip_template)

zephyr_library_sources(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chip_template.c
)

zephyr_include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
