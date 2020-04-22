#!/bin/bash

a=10

echo "Value of a is $a \n"
echo -e "Value of a is $a \n"
echo $"Value of a is $a \n"

echo " \" It is a test \" "
echo \"It is a test \"

name="OK"
echo "$name It is a test"
echo $name It is a test

mouth=8
echo "${mouth}-1-2009"
echo ${mouth}-1-2009

echo -e "OK! \c "
echo "It is a test"

echo '$name \" '

echo `date`
