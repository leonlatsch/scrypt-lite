#!/bin/bash

#   MIT License
#
#   Copyright (c) 2019 Leon Latsch

function dev-build() {
    DEBUG=$1
    echo -n "[*] Building scrypt-lite... "
    mkdir -p bin
    g++ $DEBUG src/*.cpp src/lib/AES/*.cpp -o bin/scrypt-lite
    echo "Done"
}

function release-build() {
    RELEASE=$1
    echo "[*] Building $RELEASE"
    dev-build # Build binary

    echo -n '[*] Building package... '
    rm -rf $RELEASE
    mkdir $RELEASE
    cp assets/install.sh $RELEASE
    cp bin/scrypt-lite $RELEASE
    cd $RELEASE

    RAW=$(lscpu | grep Arch) # Get system Architecture
    PARTS=$(echo $RAW | tr "" "\n")
    for i in $PARTS; do
        if [ ${i} != *"Arch"* ]; then
            ARCH=$i
        fi
    done
    
    PACKAGE=scrypt-lite-$RELEASE-$ARCH
    mkdir $PACKAGE
    mv scrypt-lite $PACKAGE
    mv install.sh $PACKAGE
    zip -rq $PACKAGE.zip $PACKAGE 
    rm -rf $PACKAGE

    echo "Done"
}

if [ "$#" -gt "0" ]; then
    release-build $1
else
    dev-build -g
fi
