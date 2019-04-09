#!/usr/bin/env python3
import re

bytes_from_olly = "978B8B8FC5D0D0888888D18F8D9E9C8B969C9E93929E93889E8D9A9E919E93868C968CD19C9092D08B8BD1978B9293FF008C8F9090938C8D89D19A879AFF"
bytes_list = re.findall("..",bytes_from_olly)

decoded_strings = ""

for each_byte in bytes_list:
	_decoded_byte = chr( int(each_byte,16) ^ 0xff )
	decoded_strings += _decoded_byte
	
print(decoded_strings)