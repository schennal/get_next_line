Get_next_line

Get_next_line is a project that implements a function to read a line from a file descriptor, developed as part of the 42Cursus curriculum. This project enhances your understanding of file handling and dynamic memory management in C.

Features

- Line Reading: Reads a single line from a file or standard input.
- Dynamic Memory: Utilizes dynamic memory allocation to handle varying line lengths.
- Multiple File Descriptors: Supports reading from multiple file descriptors simultaneously.

Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
make
```

Usage

Include the header file and use the `get_next_line` function in your program:

```c
#include "get_next_line.h"

int main() {
    char *line;
    int fd = open("file.txt", O_RDONLY);

    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
