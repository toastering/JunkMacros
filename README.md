# Description
Compile-time generated junk code.\
Uses __asm keyword to generate asm fuckery to generate specific junk code.
# Library Capabilities
Prevention of static byte/signature scanning.\
Slight confusion and obfuscation.\
File size pumping.\
etc
# Macro Usage
All macros are to be called with 1 argument with the amount of the same junk opcodes to be repeated, null or 0 will make it random.

NOP_JUNK - Generates opcode 90(nop) which is an instruction that gets ignored, but still practical for avoiding static byte scanning because it uses 1 byte, does not effect ida pseudocode.

MOV_JUNK - Generates assembly to push and move a random number into the stack x amount of times, causes interesting and funny ida pseudocode results.

WIND_JUNK - Internally calls random hardcoded selected windows functions.

NULLSUB_JUNK - Generates assembly that calls a nullsub function x amount of times, an empty void function, if used right after MOV_JUNK will confuse ida pseudocode really hard.

IF_JUNK - Generates assembly that is equivalent to a C if statement, if used right after MOV_JUNK will confuse ida pseudocode even harder than NULLSUB_JUNK.

JMP_JUNK - Generates assembly that jumps between generated nodes, does not effect ida pseudocode.
