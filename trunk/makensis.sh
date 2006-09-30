#!/bin/bash

# Dom's custom script to generate the correct output for the NSIS 
# installer script

# NEAR:      Section "Game Files" SEC01

if [ "$#" != 1 ]; then
	echo "ERROR: Expected a path to distributable dir (e.g. dist/win32/ninjas-engine-xyz/)"
	exit -1;
fi

DIST_DIR=$1

installerfile_part1=installer_part1.txt
installerfile_part2=installer_part2.txt
installerfile_part3=installer_part3.txt
tmpfile=tmpfile

msg1="; ---------- GENERATED BY makensis.sh, DO NOT EDIT -------------"
msg2="; ---------- DONE GENERATED -------------"

echo $msg1 > $installerfile_part1
echo $msg1 > $installerfile_part2
echo $msg1 > $installerfile_part3

find "$DIST_DIR" -type d -printf "%P\n" | grep -v '\.svn' | while read -r dir; do
	
	echo '	SetOutPath "$INSTDIR\'$dir'"' >> $installerfile_part1

	if [ "$dir" != "" ]; then
		echo '	RMDir "$INSTDIR\'$dir'"' >> $installerfile_part2
	fi

	find "$DIST_DIR/$dir" -maxdepth 1 -not \( -type d -o -name .svn  \) -printf "%f\n" | while read -r file; do
		
		echo '	File "'"$DIST_DIR$dir/$file"'"' >> $installerfile_part1

		echo '	Delete "$INSTDIR\'"$dir/$file"'"' >> $installerfile_part3

	done

done 
		
echo '	RMDir "$INSTDIR\"' >> $installerfile_part2

echo $msg2 >> $installerfile_part1
echo $msg2 >> $installerfile_part2
echo $msg2 >> $installerfile_part3

cat $installerfile_part1 | sed 's+/+\\+g' | sed 's+\\\\+\\+g' > $tmpfile
mv -f $tmpfile $installerfile_part1

cat $installerfile_part2 | sed 's+/+\\+g' | sed 's+\\\\+\\+g' > $tmpfile
mv -f $tmpfile $installerfile_part2

cat $installerfile_part3 | sed 's+/+\\+g' | sed 's+\\\\+\\+g' > $tmpfile
mv -f $tmpfile $installerfile_part3 
