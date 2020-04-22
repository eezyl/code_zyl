#!/bin/bash

str='this is a string'
echo $str

your_name='qinjx'
str="Hello, I know you are \"$your_name\"!\n"
echo -e $str

greeting1="hello, "$your_name" !"
greeting2="hello, ${your_name} !"
echo $greeting1
echo $greeting2

string=$1
echo ${#string}

string="alibaba is a great company"
echo ${string:1:4}

echo `expr index "$string" is`
