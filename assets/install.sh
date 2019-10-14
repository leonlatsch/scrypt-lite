#!/bin/bash

#   MIT License
#
#   Copyright (c) 2019 Leon Latsch

if [ $EUID -ne 0 ]; then
    echo "[!] Root needed"
    exit
fi

echo -n "[*] Installing scrypt-lite... "
mv scrypt-lite scrypt
chmod +x scrypt
mv scrypt /usr/bin/
rm install.sh
echo "Done"
echo "[*] Try it by typing 'scrypt' in your terminal"
