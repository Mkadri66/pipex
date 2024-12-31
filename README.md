# Pipex

![42](https://img.shields.io/badge/42-School-blue)
![C](https://img.shields.io/badge/Language-C-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

**Pipex** is a 42 School project that aims to recreate the behavior of shell pipes (`|`). This project helps to deeply understand the concepts of process management, file handling, and pipes in C.

---

## 📋 Table of Contents

1. [Introduction](#-introduction)
2. [Features](#-features)
3. [How to Use](#-how-to-use)
4. [Compilation](#-compilation)
5. [Author](#-author)
6. [License](#-license)

---

## 🌟 Introduction

The **Pipex** project involves creating a C program that replicates the behavior of shell pipes. For example, the following shell command:

```bash
$> file1 cmd1 | cmd2 > file2
```
---

## 📜 Features

Pipe management : Creates a pipe to transfer the output of one command to the input of another.

File redirection : Redirects standard input and output to files.

Error handling : Handles errors robustly (non-existent files, invalid commands, etc.).

Support for absolute and relative paths : Executes commands using absolute or relative paths.

---

## 🛠 How to Use

1. Clone this repository:
 ```bash
 git clone https://github.com/Mkadri66/pipex
```

2. Go to repository:
```bash
cd pipex
```


## 🔧 Compilation 

To compile the library, use the provided Makefile:
  ```bash
  make
  ```
    
This generates a pipex.a file (static library).

You can execute the code with this command : 
  ```bash
  ./pipex <infile> <cmd1> <cmd2> <outfile>
  ```

To clean up object files:
   ```bash
   make clean
   ```

To clean up object files and the library:
   ```bash
   make fclean
   ```
    
To recompile everything:
   ```bash
   make re
   ```

## 👤 Author
 [Mkadri66](https://github.com/Mkadri66)

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
     
