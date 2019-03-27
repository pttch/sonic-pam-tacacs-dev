## Introduction
sonic-pam-tacacs-dev is a c project to develop pam_tacacs

## download code & initial submodule
    git clone https://github.com/chaoskao/sonic-pam-tacacs-dev.git  
    cd sonic-pam-tacacs-dev  
    git submodule init  
    git submodule update  

## setup environment
    sudo apt-get install -y autoconf libtool cmake 

## download required library
    # for client
    sudo apt-get install -y libpam0g-dev libssl-dev libgtest-dev

    cd /usr/src/gtest
    sudo cmake .  
    sudo make  
    sudo cp *.a /usr/lib/

    cd /usr/src/gmock
    sudo cmake .  
    sudo make  
    sudo cp *.a /usr/lib/

    # for server
    sudo apt-get install -y flex bison libwrap0-dev

## HOWTO
    cd sonic-pam-tacacs-dev  
    ./build.sh  
    mkdir build 
    cd build  
    cmake ../ -DSERVER_BIN_PATH=`pwd`/../server/sbin/ -DSERVER_PORT=4900
