#!/bin/bash

echo -n "[*] Building scrypt-lite... "
mkdir -p bin
g++ src/main.cpp -o bin/scrypt-lite
echo "Done"
