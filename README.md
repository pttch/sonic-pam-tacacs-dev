## Introduction
sonic-pam-tacacs-dev is a c project to develop pam_tacacs

## OS limit
please run on ubuntu 18.04 or higher, this develop environment need g++7

## download code & initial submodule
    git clone https://github.com/chaoskao/sonic-pam-tacacs-dev.git  
    cd sonic-pam-tacacs-dev  
    git submodule init  
    git submodule update  

## setup environment
    sudo apt-get install -y autoconf libtool cmake make psmisc build-essential  

## download required library
    # for client
    sudo apt-get install -y libpam0g-dev libssl-dev libgtest-dev  

    sudo cmake /usr/src/googletest && sudo make && sudo make install  

    # for server
    sudo apt-get install -y flex bison libwrap0-dev

## HOWTO
    cd sonic-pam-tacacs-dev  
    ./build.sh  
    mkdir build 
    cd build  
    cmake ../ -DSERVER_BIN_PATH=`pwd`/../server/sbin/ -DSERVER_PORT=4900  
    make
