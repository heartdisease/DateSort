#!/bin/bash
make clean
qmake -project
mv DateSort.pro DateSort.pro~
cat DateSort.pro~ output.txt > DateSort.pro
rm DateSort.pro~
qmake
