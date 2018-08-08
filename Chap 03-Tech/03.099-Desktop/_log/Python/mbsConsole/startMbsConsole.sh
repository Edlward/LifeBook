
export MBS_SDK_ROOT=`dirname "$(readlink -f "$0")"`/../../..


# Add python paths
export PYTHONPATH=$PYTHONPATH:$MBS_SDK_ROOT/tools/python/mbsConsole


$MBS_SDK_ROOT/tools/python/mbsConsole/mbsConsole.py $1
