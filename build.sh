#!/bin/bash

echo -n "[*] Building scrypt-lite... "
mkdir -p bin
g++ src/*.cpp src/lib/aes256/*.cpp -o bin/scrypt-lite
echo "Done"
