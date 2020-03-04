#!/bin/bash

strace -ttt -v -o straceOp.txt -e trace=%file gcc sampleProg.c
python3 straceProc.py straceOp.txt
echo Done.
