# minishell
The goal of this 42 school project is to recreate a small part of the **bash** shell. This project helps us develop our knowledge of process, file descriptor, how shells work and helps us to developp the way we parse input. This is the first 42 school project that we get to do with a partner, due to this, it also helps us get to know how we work in team and what could do to be better. I mainly worked on the parsing and builtins part of the project.
## Mandatory
The mandatory requirement for this project are as followed:
  - Display a prompt while waiting for a command
  - Working command history
  - Launch executable
  - Handling of single and double quotes as they would in ##bash##
  - Implementation of redirections ('>', '<', '>>', '<<')
  - Implementation of pipes ('|')
  - Handling of environment variables ('$' followed by a string of character)
  - Handling of $? which expand to the exit status of the last command
  - Handling of "**ctrl-C**", "**ctrl-D**" and "**ctrl-\**". They should behave like in **bash**
  - Impement the following **builtins**:
    1. **echo** with the flag -n
