#!/bin/bash

strace -ttt -v -o straceOp.txt -e trace=%file gcc hello.c
python3 straceProc.py straceOp.txt
echo Done.
