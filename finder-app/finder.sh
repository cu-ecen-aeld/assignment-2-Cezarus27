#!/bin/bash

FILES_DIR=$1
SEARCH_STR=$2

if [[ -z $FILES_DIR || -z $SEARCH_STR ]]
then
    echo "FILES_DIR or SEARCH_STR is empty"
    echo $FILES_DIR $SEARCH_STR
    exit 1
fi

if [ ! -d $FILES_DIR ]
then
    echo "FILES_DIR is not a directory"
    exit 1
fi

directoryCounts=$(find $FILES_DIR -type f | wc -l)
matchStrCounts=$(grep -r "${SEARCH_STR}" $FILES_DIR | wc -l)
echo "The number of files are ${directoryCounts} and the number of matching lines are ${matchStrCounts}"
