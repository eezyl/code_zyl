#!/bin/bash

var="yoyo-"
echo ${var:-"Variable is not set"}
echo "1 - Value of var is ${var}"
var="yoyo="
echo ${var:="Variable is not set"}
echo "2 - Value of var is ${var}"
var="yoyo+"
echo ${var:+"Variable is set"}
echo "3 - Value of var is ${var}"
var="yoyo?"
echo ${var:?"Variable is not set"}
echo "4 - Value of var is ${var}"

unset var
echo ${var:-"Variable is not set"}
echo "5 - Value of var is ${var}"
unset var
echo ${var:="Variable is not set"}
echo "6 - Value of var is ${var}"
unset var
echo ${var:+"Variable is not set"}
echo "7 - Value of var is ${var}"
unset var
echo ${var:?"Variable is not set"}
echo "8 - Value of var is ${var}"









