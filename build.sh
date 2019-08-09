#!/bin/bash

echo "[*] Building scrypt-lite..."
mkdir build
g++ main.cpp -o build/scrypt-lite
