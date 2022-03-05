# Embed resources into binary with XXD and CMake

Embed resources into binary with XXD and CMake in a cross-platform way (Linux, Windows and Mac support).

XXD converts the data file into a C array, which is slow to compile for large files, due to the way how compiler represents the array internally. In order to embed large files, please use [res_embed](https://github.com/dmikushin/res_embed.git) instead.

## Example

1. Add this xxd project to your CMake project as a submodule:

```
cd some/path
git submodule add https://github.com/dmikushin/xxd.git
```

2. Integrate xxd project into your `CMakeLists.txt`:

```cmake 
add_subdirectory(some/path/xxd)
```

3. Embed the following example resource file into an executable using `xxd_embed` macro:

```
$ cat resource 
Hello, world!
```

```cmake
set(SRCS "example.cpp")
xxd_embed("resource", ${CMAKE_CURRENT_SOURCE_DIR}/resource SRCS)

add_executable(example ${SRCS})
target_link_libraries(example xxd::xxd)
```

4. Use the embedded resource in your program:

```c++
#include "xxd.h"

#include <cstdio>

int main(int argc, char* argv[])
{
	printf("%s", xxd::get("resource"));
	return 0;
}
```

## Credits

This code uses the original public domain `xxd` utility, which is

(c) 1990-1998 by Juergen Weigert

