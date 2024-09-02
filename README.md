# Minihell

Welcome to **Minihell**, a simplified version of the Bash shell, written in C. This project is developed as part of the curriculum at [42 School](https://www.42.fr/), aiming to recreate basic functionalities of a Unix shell, similar to Bash. The name "Minihell" is a playful take on "Minishell," indicating the challenges and learning experiences faced while implementing this project.

## Features

Minihell implements several key features of a shell environment, including:

- Command parsing and execution.
- Signal handling (e.g., `Ctrl+C`, `Ctrl+Z`).
- Tokenization of input for command and argument separation.
- Error handling and output.
  
### Building the Project

The project includes a `Makefile` to simplify the build process. Use the following commands to build, clean, or rebuild the project.

To compile the project, simply run:

```bash
make
```
After building the project, you can run the minishell executable with:

```bash
./minishell
```
