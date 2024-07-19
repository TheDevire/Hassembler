# Hassembler 
---
Hssembler is an assembler mentioned in nand2tetris course which translates 16-bit Hack assembly code to machine code.

## Description
Hassembler takes .asm file through command line translate it to machine code and write output to .hack file.

The source code is divided into three modules, as follows:
1.**Parser**: The main function of the parser is to break each assembly command into its underlying components (fields and symbols).
2.**Code**:Translates Hack assembly language mnemonics into binary codes
3.**SymbolTable**: Keeps a correspondence between symbolic labels and numeric
addresses.

---
## Compile & Run
#### Compile
```
git clone https://github.com/TheDevire/Hassembler.git
cd Hassembler
make assembler
```
#### Run 
```
./assembler <.asm file>
```
Store the output file in current directory 

