#!/usr/bin/env bash

if [ "$#" == 0 ]
then
    echo "Realizando make em todas as pastas..."
    echo
    make clean
    make all
    echo
    echo "Todas as pastas foram compiladas!"
    echo "Execute 'sudo make qemu' dentro da pasta que deseja rodar"
    exit
fi

if [ $@ == 1 ]
then
    cd tasks\ 1
fi
if [ $@ == 2 ]
then
    cd tasks\ 2
fi
if [ $@ == 3 ]
then
    cd tasks\ 3
fi
if [ $@ == 4 ]
then
    cd tasks\ 4
fi

make clean
make all
sudo make qemu
cd -