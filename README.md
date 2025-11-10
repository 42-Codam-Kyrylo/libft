# 🧩 libft

**libft** is a custom implementation of the standard C library —  
the very first foundational project at **Codam / 42 Network**.  
The goal is to rebuild essential libc functions from scratch  
and gain a deep understanding of C memory management, pointers, and data manipulation.

---

## 🗂️ Project Structure

```
libft/
├── Makefile            # Builds the static library (libft.a)
├── libft.h             # Header file with all function declarations
├── ft_*.c              # 43 source files (implementation of functions)
├── build/              # Object files directory
└── tests/              # Criterion unit tests for selected functions
    ├── Makefile
    └── *.test.c
```

---

## ⚙️ Usage

### 🧱 Build the library
```bash
make
```
This will compile all mandatory functions and create `libft.a`.

### 🎁 Build with bonus functions
```bash
make bonus
```
This will compile bonus functions (linked list operations) and add them to `libft.a`.

### 🧹 Clean up object files
```bash
make clean
```

### 🧽 Clean everything (including the library)
```bash
make fclean
```

### 🔁 Rebuild
```bash
make re
```

---

## 🧪 Unit Tests

The `/tests` directory contains **Criterion**-based unit tests for several functions.

### Prerequisites
- **Linux:** Install Criterion to `~/criterion-2.4.3-linux-x86_64/`
- **macOS:** Install via Homebrew: `brew install criterion`

### Run all tests:
```bash
cd tests
make test
```

### Run tests with verbose output:
```bash
make show
```

### Run specific test file:
```bash
make test FILE=ft_split.test.c
```

### List all available tests:
```bash
make test-list
```

> Tests automatically compile libft with bonus functions included.

---

## 📚 Implemented Functions

| Category | Examples |
|-----------|-----------|
| **Libc Reimplementations** | `memset`, `bzero`, `memcpy`, `strlen`, `strchr`, `strncmp`, `atoi` |
| **Additional Utilities** | `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa`, `ft_strmapi` |
| **Linked List Functions** | `ft_lstnew`, `ft_lstadd_back`, `ft_lstclear`, `ft_lstmap` |

> The project adheres to **C99** standards and must compile cleanly with  
> `-Wall -Wextra -Werror` flags.

---

## 🔧 Tech Stack

- **Language:** C (ISO C99)  
- **Tools:** Makefile, Criterion, Clang  
- **Environment:** Linux / macOS  

---

## 🧠 About

This project is part of the **Codam (42 Network)** curriculum.  
It serves as a base library for all future 42 projects  
(`get_next_line`, `ft_printf`, and beyond).

---

### 🪄 Author

👤 **Kyrylo**  
[GitHub](https://github.com/42-Codam-Kyrylo) · [LinkedIn](https://www.linkedin.com/link)
