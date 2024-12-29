#!/bin/sh

while true; do
    sensors | grep "Package id 0:" | tr -d '+' | awk '{print $4}'
    sleep 2
done
