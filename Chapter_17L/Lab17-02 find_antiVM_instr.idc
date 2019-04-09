#include <idc.idc>

/*
    This script colors the antiVM instructions in IDA.
	-- Just fill-in the start_addr and end_addr of the range you want to scan
	
	By: @0xbahaa
    Inspired from the idaPython script in "Practical Malware Analysis" book.
	
	to-do:
		- add an array of addresses where antiVM instructions were found, and print them after scanning
*/


static main() {
    
    auto start_addr = 0x10001000;
    auto end_addr = 0x10015400;
    auto current_addr = start_addr;
	auto _count = 0;
	
    while (current_addr < end_addr){
        // find the mnemonic at this address
        auto _mnemonic = print_insn_mnem(current_addr);
        // color this line if the mnemonic is one of the antiVM ones
    if ( (_mnemonic == "sidt") | 
		(_mnemonic == "sgdt") | 
		(_mnemonic == "sldt") | 
		(_mnemonic == "smsw") | 
		(_mnemonic == "str") | 
		(_mnemonic == "in") | 
		(_mnemonic == "cpuid")
	){
            //set_color(address, 1/2/3, RGB_#_code)
        set_color(current_addr, 1, 0xff0);
		_count = _count + 1;
    }
    
		//increment the current address
    current_addr++;
    }
    
	Message("\n~> Found %d antiVM instruction(s)\n", _count);
}