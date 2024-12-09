# SPDX-License-Identifier: CC0-1.0
#
# SPDX-FileContributor: Antonio Niño Díaz, 2023

BLOCKSDS	?= /opt/blocksds/core

# User config

NAME		:= libadx-nds
GAME_TITLE	:= libadx-nds test
NITROFSDIR	:= nitro

include $(BLOCKSDS)/sys/default_makefiles/rom_arm9arm7/Makefile
