#!/bin/bash

echo -n "[*] Building scrypt-lite... "
mkdir -p build
g++ main.cpp -o build/scrypt-lite
echo "Done"
