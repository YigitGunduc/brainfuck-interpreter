/*
brainfuck interpreter
Copyright © 2021 Yigit Gunduc

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <string.h>

#define TAPE_LEN 30000

int tape_ptr = 0;
unsigned char tape[TAPE_LEN] = { 0 };

void print_tape(unsigned char tape[TAPE_LEN])
{
  for (int i = 0; i < TAPE_LEN; i++)
  {
    printf(" %i -", tape[i]);
    if ((i + 1) % 16 == 0)
    {
      puts("");
    }
  }
  puts("");
}

void eval(char inst[256], int num_of_inst)
{
  for (int i = 0; i < num_of_inst; i++)
  {

    switch (inst[i]) {

      case '+': 
        {
          tape[tape_ptr]++;
          break;
        }

      case '-': 
        {
          tape[tape_ptr]--;
          break;
        }

      case '>': 
        {
          tape_ptr++;
          break;
        }

      case '<': 
        {
          tape_ptr--;
          break;
        }

      case '.':
        {
          printf("%i", tape[tape_ptr]);
          break;
        }

      case ',':
        {
          int input;
          scanf("%i", &input);
          tape[tape_ptr] = input;
          break;
        }

      case '[':
        {
          int index = i + 1;
          char temp_inst[256];
          int temp_inst_ptr = 0;
          int temp_tape_ptr = tape_ptr;

          while(inst[index] != ']') 
          {
            temp_inst[temp_inst_ptr] = inst[index];
            index++;
            temp_inst_ptr++;
          }

          while(tape[temp_tape_ptr] != 0)
          {
            eval(temp_inst, temp_inst_ptr);
          }

          break;
        }
    }
  }
}

int main(void)
{
  char instructions[256] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-].";
  
  eval(instructions, strlen(instructions));

  print_tape(tape);
}
