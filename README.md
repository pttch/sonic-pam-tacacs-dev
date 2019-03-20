## Introduction
sonic-pam-tacacs-dev is a c project to develop pam_tacacs

# TACACS+ client
## download code & initial submodule
    git clone https://github.com/chaoskao/sonic-pam-tacacs-dev.git  
    cd sonic-pam-tacacs-dev  
    git submodule init  
    git submodule update  

## setup environment
    sudo apt-get install autoconf  
    sudo apt-get install libtools

## download required library
    sudo apt-get install libpam0g-dev  
    sudo apt-get install libssl-dev

## HOWTO    
    cd sonic-pam-tacacs-dev/pam_tacplus  
    ./auto.sh  
    ./configure  
    make

# TACACS+ server for testing

## download code & initial submodule
    git clone https://github.com/facebook/tac_plus.git

## download required library
    sudo apt-get install flex  
	sudo apt-get install bison  
	sudo apt-get install libwrap0-dev
	
## HOWTO
    cd tac_plus/tacacs-F4.0.4.28
	./configure prefix=<local_dir>/build
    make
    make install


=========================================  
need to check how to link
## checkout openssl
wget https://www.openssl.org/source/old/1.1.0/openssl-1.1.0i.tar.gz  
tar zxvf openssl-1.1.0i.tar.gz  
cd openssl-1.1.0i  
CROSS_COMPILE= perl Configure --prefix=/home/nms/code/sonic_tacacs/ssl linux-x86_64  
make

## checkout libpam
git clone https://github.com/linux-pam/linux-pam.git  
cd linux-pam  
./autogen.sh  
./configure  

==========================================
