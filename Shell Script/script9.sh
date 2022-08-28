#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Usage: ./script9 options"
	exit 0
fi

for item in $*
do
	str=$item" "$str
done

echo $str
