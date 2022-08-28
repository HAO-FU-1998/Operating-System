#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Usage: ./script10 options"
	exit 0
fi

until [ $# -eq 0 ]
do
	str=$1" "$str
	shift
done

echo $str
