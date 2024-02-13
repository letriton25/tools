#! /bin/bash

#########
# CONST #
#########

regex_textfile='^.+:.*text.*$'

#############
# FUNCTIONS #
#############

file_count ()
{
    local count=0
    # check if the file has a textual format
    if file $1 | grep -E $regex_textfile >/dev/null; then
        count=$(wc -l < $1)
    fi
    echo $count
    exit 0
}

dir_count ()
{
    local count=0
    for path in $1/*; do
        # check if $path is a regular file and no a symbolic link to a file
        if [ ! -h $path ] && [ -f $path ]; then
            local filecount=$(file_count $path)
            count=$(( $count + $filecount ))
        fi
    done
    echo $count
    exit 0
}

recursive_count ()
{
    local count=0
    for path in $1/*; do
        # check if $path is a regular file and no a symbolic link to a file
        if [ ! -h $path ] && [ -f $path ]; then
            local filecount=$(file_count $path)
            count=$(( $count + $filecount ))
        fi
        # recursily call this function if $path is a directory not pointed by a symbolic link
        if [ ! -h $path ] && [ -d $path ]; then
            local dircount=$(recursive_count $path)
            count=$(( $count + $dircount ))
        fi
    done
    echo $count
    exit 0
}

####################
# ARGS PROCCESSING #
####################

