#!/bin/bash

num1=$1
num2=$2

if test $[ num1 ] -eq $[ num2 ]
then
    echo "The two numbers are equal"
else
    echo "The two numbers are not equal"
fi

if test num1 = num2
then
    echo "The two strings are equal"
else
    echo "The two strings are not equal"
fi

cd /bin
if test -e ./bash
then 
    echo "The file already exists!"
else
    echo "The file does not exist!"
fi

if test -e ./notFile -o ./bash
then
    echo "At least one file exists!"
else
    echo "Both do not exist!"
fi
