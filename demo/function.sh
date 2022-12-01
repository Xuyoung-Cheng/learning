#! /bin/bash

function print()
{
	echo 'hello world'
}

print

echo ' exercise1-16 '

function add()
{
	return `expr $1 + $2`
}

add 10 20
echo $?

function output_string()
{
	echo "hello world"
}


RET=`output_string`
echo $RET


