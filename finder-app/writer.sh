#!/bin/bash

WRITE_FILE=$1
WRITE_STR=$2

if [[ -z $WRITE_FILE || -z $WRITE_STR ]]
then
    echo "WRITE_FILE or WRITE_STR is empty"
    echo $WRITE_FILE $WRITE_STR
    exit 1
fi

if [ ! -w $WRITE_FILE ]
then
    dirname=$(dirname $WRITE_FILE)
    mkdir -p $dirname
    touch $WRITE_FILE
fi

echo $WRITE_STR >> $WRITE_FILE
