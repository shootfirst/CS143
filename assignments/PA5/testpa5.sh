#!/bin/bash

perl pa5-grading.pl

python change.py

cd grading

./143publicgrading PA5

cd ..

make clean


