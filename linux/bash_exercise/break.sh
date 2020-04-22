#!/bin/bash

while :
do
    echo -n "Input a number between 1 to 5: "
    read aNum
    case $aNum in
        1 | 2 | 3 | 4 | 5 ) echo "Your number is $aNum"
            ;;
        *) echo "You do not select a number between 1 to 5, game over!"
            break
            ;;
    esac
done

for var1 in 1 2 3
do 
    for var2 in 0 5
    do
        if [ $var1 -eq 2 -a $var2 -eq 0 ]
        then
            break 2
        else
            echo "$var1 $var2"
        fi
    done
done
