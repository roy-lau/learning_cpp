#!/bin/bash
rm -rf out && mkdir out
for f in *.c; 
do 
  # build
  gcc $f -o "./out/"`basename $f .c`
  echo "oldFile $f build to  --->  ./out/"`basename $f .c`
  # run
  # "./out/"`basename $f .c`
done