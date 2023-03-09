## How to run .asm file

Make sure NASM is installed on your system

Go to your folder and open terminal

Execute the below commands

```sh
nasm -f elf64 yourFileName.asm
ld -o yourFileName yourFileName.o
./yourFileName
```
