#!/bin/bash

array_name=(
value0
value1
value2
value3
)
echo ${array_name[1]}

NAME[0]="Zara"
NAME[1]="Qadir"
NAME[2]="Mahnaz"
NAME[3]="Ayan"
NAME[4]="Daisy"
echo "First Index: ${NAME[0]}"
echo "Second Index: ${NAME[1]}"
echo "First Method: ${NAME[*]}"
echo "Second Method: ${NAME[@]}"

length=${#array_name[@]}
echo "$length"
length=${#array_name[*]}
echo "$length"
lengthn=${#array_name[3]}
echo "$lengthn"
