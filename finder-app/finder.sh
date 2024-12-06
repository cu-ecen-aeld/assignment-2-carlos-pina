#!/bin/sh

if [ -n "$1" ] && [ -n "$2" ]
then
  filesdir=$1
  searchstr=$2
else
  echo "Two parameters are mandatory!"
  exit 1
fi

if ! [ -d "$filesdir" ]
then
  echo "$filesdir is not a directory!"
  exit 1
fi

files_number=$(find $filesdir -type f | wc -l)

matching_lines=$(grep -ro $searchstr $filesdir | wc -l)

echo "The number of files are $files_number and the number of matching lines are $matching_lines"
