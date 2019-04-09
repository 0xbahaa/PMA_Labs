#include <idc.idc>

/*
  This script registers a hotkey (shift + ~ ) to NOP the byte at current position in IDA,
	and mark it as code too,
    to make cleaning anti-disassembly stuff easier.
	P.S. (turn off autoAnalysis in IDA for a better result)

  By: @0xbahaa
  Inspired by "Practical Malware Analysis" book and labs.
*/

static _Nop_the_byte() {
    //get cursor position
  auto ea= ScreenEA();
  
  // replace byte at current position with NOP
  patch_byte(ea, "0x90");
  MakeCode(ea);
  Message("Patched byte at %x\n", ea);
  
    // advance the cursor by one
  Jump(ea+1);
}

  // registerin the Hotkey in the main func
static main() {
  //AddHotkey("~", "_Nop_the_byte");
  add_idc_hotkey("~", "_Nop_the_byte");	// Shift + Tilde (~)
  Message("Hotkey registered!!\n");
}