#!/usr/bin/env python3

shellcode_length = 0x18F
decoded_shellcode = []

with open('Lab19-02_shellcode.bin','rb') as f:	
	shellcode_raw = f.read()

    #throw away the decoding stub ;)
shellcode_raw = shellcode_raw[0x18:]	
	
for i in range(0,shellcode_length):
	_byte = shellcode_raw[i]
	_byte_decoded = _byte ^ 0xE7
	
	decoded_shellcode.append(_byte_decoded)


with open('Lab19-02_shellcode_decoded.bin','wb') as f:
	f.write( bytes(decoded_shellcode) )
	
	
