#**********************************************************************************
#**********************************************************************************
#**********************************************************************************
#Delete Partition Script will delete the partition created in the OS with help of**
#Gdisk Tool.                                                                     **
#Please Make sure gdisk is installed in your Server.                             **
###Option to be Provide deleting Partition.                                      **
###GPT fdisk (gdisk) version 1.0.3                                               **
###Partition table scan:                                                         **
### MBR: not present                                                             **
###  BSD: not present                                                            **
###  APM: not present                                                            **
###  GPT: not present                                                            **
#                                                                                **
### Creating new GPT entries.                                                    **
### Command (? for help): x                                                      **
### Expert command (? for help): z                                               **
### About to wipe out GPT on /dev/sdaw. Proceed? (Y/N): Y                        **
### GPT data structures destroyed! You may now partition the disk using fdisk or **
### other utilities.                                                             **
###Blank out MBR? (Y/N): Y                                                       **
#**********************************************************************************
#**********************************************************************************
#**********************************************************************************
#!/bin/bash
ls -lrt /dev/sd* > /tmp/device.txt
sed -i 's/b.*\//\/dev\//' /tmp/device.txt
for F in $(cat /tmp/device.txt) ; do
  echo $F
  if [ -e "$F" ]; then
     sg_inq $F | grep "Product revision level" | grep "1.00"
     res=$?
     #echo $res
     if [ $res -eq 1 ];
     then
         echo $F
         count="$(ls -lrt $F* | wc -l)"
         min=1
         echo 'count' $count
         echo 'MIN:' $min
         if [ $count != $min ];then
            echo '-------------------------------------------------------------------------------'
            echo 'deleteing partition from below file' $F '--------------with count--' $count '--'
            echo '-------------------------------------------------------------------------------'
            sg_inq $F
            #Need To provide above mention options
            gdisk $F
         fi
     fi
  fi
done
