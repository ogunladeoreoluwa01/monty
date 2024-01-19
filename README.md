Certainly! Here's a revamped version of the README for the Monty 0.98 interpreter:

---

# Monty 0.98 Interpreter

Monty 0.98 is a scripting language with a unique stack and specific instructions to manipulate it. This project aims to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Monty byte code files have the `.m` extension. While most industries follow this standard, it's not mandatory as per the language specification. Each line contains only one instruction, and there can be any number of spaces before or after the opcode and its argument.

## The Monty Program

### Usage

```bash
monty file
```

- `file`: Path to the file containing Monty byte code.

### Error Handling

If the user doesn't provide any file or more than one argument, the program displays:

```bash
USAGE: monty file
```

If the program can't open the file, it shows:

```bash
Error: Can't open file <file>
```

If the file contains an invalid instruction, it displays:

```bash
L<line_number>: unknown instruction <opcode>
```

- `<line_number>`: The line number where the instruction appears (starting from 1).

### Execution

The Monty program runs bytecodes line by line and stops if:

- It successfully executes every line of the file.
- It encounters an error in the file.
- An error occurs during execution.

If the program can't allocate more memory, it prints:

```bash
Error: malloc failed
```

### Note

- Use `malloc` and `free`; other functions from `man malloc` (e.g., `realloc`, `calloc`) are not allowed.

---

This revamped README provides clear sections for usage, error handling, and execution, making it easier for users and contributors to understand and use the Monty 0.98 interpreter.
