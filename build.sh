#!/bin/bash

echo -n "[*] Building scrypt-lite... "
mkdir -p bin
g++ src/*.cpp -o bin/scrypt-lite
echo "Done"
