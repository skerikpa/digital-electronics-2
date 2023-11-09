   | **Instruction** | **Operation** | **Description** | **Cycles** |
   | :-- | :-: | :-- | :-: |
   | `add Rd, Rr` | Rd = Rd + Rr | Adds two registers without the C flag and places the result in the destination register Rd | 1 |
   | `andi Rd, K` | Rd = Rd and K | Logical AND between register Rd and 8-bit constant K | 1 |
   | `bld Rd, b` | Rd(b) = T | Copies the T bit in the SREG (Status Register) to bit b in register Rd | 1 |
   | `bst Rd, b` | T = Rd(b) | Stores bit b from Rd to the T bit in SREG (Status Register) | 1 |
   | `com Rd` | Rd = 0xFF - Rd | This instruction performs a One’s Complement of register Rd | 1 |
   | `eor Rd, Rr` | Rd = Rd ⊕ Rr | Performs the logical EOR between the contents of register Rd and register Rr and places the result in the destination register Rd | 1 |
   | `mul Rd, Rr` | R1:R0 = Rd × Rr (unsigned = unsigned × unsigned) | The multiplicand Rd and the multiplier Rr are two registers containing unsigned numbers. The 16-bit unsigned product is placed in R1 (high byte) and R0 (low byte). Note that if the multiplicand or the multiplier is selected from R0 or R1, the result will overwrite those after multiplication. | 1 |
   | `pop Rd` | Rd = STACK | This instruction loads register Rd with a byte from the STACK. The Stack Pointer is pre-incremented by 1 before the POP. | 1 |
   | `push Rr` | STACK = Rr | This instruction stores the contents of register Rr on the STACK. The Stack Pointer is post-decremented by 1 after the PUSH. | 1 |
   | `ret` | PC(15:0) ← STACK | Returns from the subroutine. The return address is loaded from the STACK | 16 |
   | `rol Rd` | Rd << 1 | Shifts all bits in Rd one place to the left. The C flag is shifted into bit 0 of Rd | 1 |
   | `ror Rd` | Rd >> 1 | Shifts all bits in Rd one place to the right. The C flag is shifted into bit 7 of Rd. Bit 0 is shifted into the C flag | 1 |

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-- | :-: |
   | `add r24, r0` | `0000 1101 1000 0000` | `0D 80` |  |
   | `mul r22, r20` | `1001 1111 0110 0100` | `9F 64` |  |
   | `ret` | `1001_0101_0000_1000` | `95 08` |  |

C:\Users\240982\.platformio\packages\toolchain-atmelavr\bin\avr-objdump -S -d -m avr .pio/build/uno/firmware.elf > firmware.lst

0, 1, 3, 7, 14, 13, 11, 6, 12, 9, 2, 5, 10, 4, 8, 
 Number of values: 15

0, 1, 3, 6, 12, 8, 
 Number of values: 6

0, 1, 2, 5, 10, 4, 9, 3, 6, 13, 11, 7, 14, 12, 8, 
 Number of values: 15

5bit tap: 5,3 
0, 1, 3, 7, 14, 28, 25, 18, 4, 8, 17, 2, 5, 10, 21, 11, 23, 15, 30, 29, 27, 22, 13, 26, 20, 9, 19, 6, 12, 24, 16, 
 Number of values: 31

7bit tap: 7,6
0, 1, 3, 7, 15, 31, 63, 126, 125, 123, 119, 111, 95, 62, 124, 121, 115, 103, 79, 30, 61, 122, 117, 107, 87, 46, 92, 56, 112, 97, 67, 6, 13, 27, 55, 110, 93, 58, 116, 
105, 83, 38, 76, 24, 49, 98, 69, 10, 21, 43, 86, 44, 88, 48, 96, 65, 2, 5, 11, 23, 
47, 94, 60, 120, 113, 99, 71, 14, 29, 59, 118, 109, 91, 54, 108, 89, 50, 100, 73, 18, 37, 74, 20, 41, 82, 36, 72, 16, 33, 66, 4, 9, 19, 39, 78, 28, 57, 114, 101, 75, 
22, 45, 90, 52, 104, 81, 34, 68, 8, 17, 35, 70, 12, 25, 51, 102, 77, 26, 53, 106, 85, 42, 84, 40, 80, 32, 64, 
 Number of values: 127
