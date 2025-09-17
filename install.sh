#!/bin/bash

set -e

GREEN="\033[1;32m"
YELLOW="\033[1;33m"
CYAN="\033[1;36m"
RESET="\033[0m"

PREFIX="$HOME/.ft_printf"
ZSHRC="$HOME/.zshrc"
BASHRC="$HOME/.bashrc"
PROFILE_FILE=""

echo -e "${YELLOW}Building ft_printf...${RESET}"
make

echo -e "${YELLOW}Installing ft_printf to $PREFIX...${RESET}"
mkdir -p "$PREFIX/libft"
cp libftprintf.a "$PREFIX/"
cp ft_printf.h "$PREFIX/"
cp ft_printf.h "$PREFIX/"
cp libft/libft.h "$PREFIX/libft/"


make fclean

update_profile() {
    PROFILE_FILE=$1
    grep -qxF "export C_INCLUDE_PATH=$PREFIX" "$PROFILE_FILE" || echo "export C_INCLUDE_PATH=$PREFIX" >> "$PROFILE_FILE"
    grep -qxF "export LIBRARY_PATH=$PREFIX" "$PROFILE_FILE" || echo "export LIBRARY_PATH=$PREFIX" >> "$PROFILE_FILE"
}

if [ -f "$ZSHRC" ]; then
    PROFILE_FILE="$ZSHRC"
    update_profile "$ZSHRC"
elif [ -f "$BASHRC" ]; then
    PROFILE_FILE="$BASHRC"
    update_profile "$BASHRC"
else
    echo -e "${YELLOW}No .zshrc or .bashrc found. Please add the following lines manually:${RESET}"
fi


if [ -n "$PROFILE_FILE" ]; then
    PROFILE_NAME=$(basename "$PROFILE_FILE")
    echo -e "${YELLOW}The following lines were added to your shell profile (${PROFILE_NAME}):${RESET}"
    echo ""
    echo -e "    ${CYAN}export C_INCLUDE_PATH=$PREFIX${RESET}"
    echo -e "    ${CYAN}export LIBRARY_PATH=$PREFIX${RESET}"
    echo ""
    echo -e "${YELLOW}To apply changes immediately, run:${RESET} ${GREEN}source ~/$PROFILE_NAME${RESET}"
else
    echo -e "    ${CYAN}export C_INCLUDE_PATH=$PREFIX${RESET}"
    echo -e "    ${CYAN}export LIBRARY_PATH=$PREFIX${RESET}"
fi
