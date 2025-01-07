# Pico2W-FreeRTOS
Basic setup of FreeRTOS, webserver and Bluetooth

Prerequisites for building in Ubuntu:
sudo apt update
sudo apt install gcc-arm-none-eabi cmake make pkg-config

You should run the following before use of repo:
export PICO_SDK_PATH=$(pwd)/lib/pico-sdk
export FREERTOS_PATH=$(pwd)/lib/FreeRTOS

Steps to build and deploy:
cd $PICO_SDK_PATH/tools/picotool
mkdir build
cd build
cmake ..
make
sudo make install

cd ../../..
mkdir build
cd build
cmake ..
make

cp *.uf2 targetFolder
