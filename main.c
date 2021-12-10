#include <string.h>
#include <stdio.h>

/*enum instructions {*/
  /*char '+',*/

/*}*/

void print_tape(unsigned char tape[256])
{
  for (int i = 0; i < 256; i++)
  {
    printf("%i-", tape[i]);
  }
}

int main(void)
{
  unsigned char tape[256] = { 0 };
  
  char *inst = ">>>++++---[>><<++->]";

  int num_of_inst = strlen(inst);

  int tape_ptr = 0;

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
          printf("%i\n", tape[tape_ptr]);
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
          int temp_ptr = 0;

          int temp[256] = { 0 };
          
          char temp_inst[256];

          while(inst[index] != ']') 
          {
            temp_inst[temp_ptr] = inst[index];
            index++;
            temp_ptr++;
          }
          
            for (int i_1 = 0; i_1 < 20; i_1++)
          {
            printf("%c\n", temp_inst[i_1]);
          }

        }
    }
  }

  /*print_tape(tape);*/
}

