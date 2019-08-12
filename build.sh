#!/bin/bash

echo "[*] Building scrypt-lite..."
mkdir -p build
g++ main.cpp -o build/scrypt-lite
