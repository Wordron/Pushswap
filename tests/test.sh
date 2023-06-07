#!/bin/bash

clear

echo -e "\033[92mTest '5 4 7 5 7' :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "sa ra ra sa ra ra ra"
echo -e "\033[31mGot :\033[00m"
./push_swap 5 4 7 5 7
echo
echo -e "\033[92mTest '5 4 1 5 7' :\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e ""
echo -e "\033[31mGot :\033[00m"
./push_swap 5 4 1 5 7