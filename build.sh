#/bin/bash

home="$( pwd )"
echo $home

#build client
cd pam_tacplus
./auto.sh
./configure --prefix=${home}/client
make
make install

#build server
cd ../tac_plus/tacacs-F4.0.4.28
./configure --prefix=${home}/server
make
make install

#copy config file
cp ${home}/tac_plus.conf ${home}/server/sbin/
