#!/bin/bash
Hello () {
    echo "Url is http://google.com"
}

Hello

funWithReturn() {
    echo "The function is to get the sum of two numbers.."
    echo -n "Input first number: "
    read aNum
    echo -n "Input another number: "
    read anotherNum
    echo "The two numbers are $aNum and $anotherNum !"
    return `(expr $aNum + $anotherNum)`
}
funWithReturn
ret=$?
echo "The sum of two numbers is $ret !"

number_one() {
    echo "Hello"
    number_two
}

number_two() {
    echo " World"
}

number_one

unset  funWithReturn
funWithReturn
