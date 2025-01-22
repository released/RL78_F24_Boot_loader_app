
# input file
.\DefaultBuild\flash5000_3FFFF.hex -Intel

# just keep code area for CRC calculation
# reserve field , from xxxx , to xxxx
# target size : 0x40000 , 0x40000 - 0x5000 for boot loader code size
-crop 0x5000 0x3FFFC

# fill code area with 0xFF
# fill 0xFF into the field , from xxxx , to xxxx				
#-fill 0xFF 0x5000 0x3FFFC					

# select checksum algorithm
-crc32-l-e 0x3FFFC		

# keep the CRC itself
-crop 0x3FFFC 0x40000

# output hex display											
-Output 
- 
-HEX_Dump

# input file
#.\DefaultBuild\flash5000_3FFFF.hex -Intel		

# just keep code area for CRC calculation
#-crop 0x5000 0x3FFFC	

# fill code area with 0xFF	
#-fill 0xFF 0x5000 0x3FFFC

# produce the output file
#-Output
#.\DefaultBuild\flash5000_3FFFF.hex -Intel



