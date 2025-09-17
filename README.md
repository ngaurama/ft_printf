# ft_printf

A reimplementation of the standard C `printf` function, written from scratch as part of the **42 Common Core** curriculum.  
The project reproduces the behavior of `printf`, handling formatting, flags, and conversions with a custom-built library.

---

## Features

Supported conversions:
- `%c` : Print a single character.
- `%s` : Print a string (C convention, null-terminated).
- `%p` : Print a pointer in hexadecimal format.
- `%d` : Print a signed decimal (base 10).
- `%i` : Print an integer (base 10).
- `%u` : Print an unsigned decimal (base 10).
- `%x` : Print a hexadecimal (base 16, lowercase).
- `%X` : Print a hexadecimal (base 16, uppercase).
- `%%` : Print a literal percent sign.

Supported flags (Bonus):
- Field width, precision (`.`), left align (`-`), zero padding (`0`)
- `#` (alternate form), `+` (force sign), and space flag.

---

## Project Structure

```
├── libft/ # Dependency (libft project)
├── ft_printf.c # Core implementation
├── ft_printf_*.c # Conversion-specific handlers
├── helpers.c / utils.c # Utilities
├── Makefile
└── README.md
```

---

## Installation

### Clone and build
```bash
git clone https://github.com/ngaurama/ft_printf.git
cd ft_printf
make
```
This will generate the static library:

libftprintf.a

Install globally (optional)

You can install libftprintf.a system-wide so it can be linked in any project:
```bash
curl -fsSL https://raw.githubusercontent.com/ngaurama/ft_printf/install.sh | bash
```
(See Installer Script for details)

▶ Usage

Link the library when compiling your C programs:
```
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello %s! Hex: %#x\n", "World", 255);
    return (0);
}
```

Compile with:
```
gcc main.c -L. -lftprintf -o your_program
```
Or, if installed globally:
```
gcc main.c -lftprintf -o your_program
```
---

### Learning Outcomes

Through this project, I gained experience with:
+ Variadic functions (<stdarg.h>).
+ String formatting and parsing.
+ Implementing number conversion algorithms (decimal, hex, unsigned).
+ Designing modular C code with a custom build system.
+ Extending a library with flags and format handling.
---
## Author
+ Nitai Gauramani
  - 42 Paris – Common Core project <br>

![Nitai's GitHub stats](https://github-readme-stats.vercel.app/api?username=ngaurama&show_icons=true&theme=transparent)
