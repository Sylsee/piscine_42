#!/bin/sh

number=$(jot -r 1  0 1000000000)
./rush-02 $number
say -v Fiona $number
