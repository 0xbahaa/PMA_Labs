#import <idc.idc>
static main(){

        // our address range
    auto start_addr = 0x407030;
	auto shellcode_length = 0x1A7;
    auto end_addr = start_addr + shellcode_length;

        // current position
    auto current_addr = start_addr;
    auto flag = 0;    // for debugging

        // some other variables we'll use
    auto _byte = 0x00;

        // ###################################################
    Message("\nShellcode starts here:\n========================\n");

    while (current_addr < end_addr){

            // grab the byte at the cursor's address
        _byte = byte(current_addr);
		    // print it out (without trailing newline)
        Message("%02x",_byte);
		    // then advance the cursor
		current_addr = current_addr + 1;
    }
        // ###################################################
    Message("\nShellcode ends here ^ \n========================\n");


}


