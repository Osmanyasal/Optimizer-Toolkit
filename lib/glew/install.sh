#!/bin/bash

CGLEW="Custom GLEW"

if [ $# -gt 0 ]; then
    if [ "$1" = "--help" ]; then
        echo "$0 [clean]"
        exit 0
    fi
    if [ "$1" = "clean" ]; then
        echo "${CGLEW} executing make clean"
        make clean 
        exit 0
    else
        echo "Unknown parameter: $1"
        exit 1
    fi
fi

# Function to install packages on Debian/Ubuntu/Mint
install_debian_packages() {
    sudo apt-get install -y build-essential libxmu-dev libxi-dev libgl-dev
}

# Function to install packages on RedHat/CentOS/Fedora
install_redhat_packages() {
    sudo yum install -y libXmu-devel libXi-devel libGL-devel
}

# Function to install packages on FreeBSD
install_freebsd_packages() {
    sudo pkg install -y xorg lang/gcc git cmake gmake bash python3 perl5
}


# Detect the operating system
os_type=$(uname)
echo "${CGLEW} detected os type : $os_type"

# Detect the operating system
if [ ${os_type} == "Linux" ]; then
    
    # Check if Debian/Ubuntu/Mint
    if [ -f /etc/debian_version ]; then
        echo "${CGLEW}: debian"
        install_debian_packages
    # Check if RedHat/CentOS/Fedora
    elif [ -f /etc/redhat-release ]; then
        echo "${CGLEW}: redhat"
        install_redhat_packages
    else
        echo "Unsupported Linux distribution."
        exit 1
    fi
elif [ ${os_type} == "FreeBSD" ]; then
    echo "${CGLEW}: FreeBSD"
    install_freebsd_packages
else
    echo "Unsupported operating system: ${os_type}"
    exit 1
fi

cd ./auto; make
echo "${CGLEW} auto/make executed"
cd ..

make
echo "${CGLEW} make executed"

sudo make install
echo "${CGLEW} make install executed"

#make clean