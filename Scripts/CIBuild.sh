#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

# Download WE-Core
WECORE_HOME="$(cd $SCRIPT_DIR/.. > /dev/null 2>&1 && pwd)"
WECORE_SRC="$WECORE_HOME/WECore"
git checkout https://github.com/jd-13/WE-Core ../WECore

# Generate the makefile
$JUCE_PATH/Projucer --resave $SCRIPT_DIR/../Carve.jucer

# Update the include paths
sed -i 's#-I$(HOME)/WEA/WECore/WECore#-I../../WECore/WECore#g' $SCRIPT_DIR/../Builds/LinuxMakefile/Makefile

# Run the build
cd $SCRIPT_DIR/../Builds/LinuxMakefile
make
