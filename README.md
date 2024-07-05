# Dynamic Windows API Resolver
A simple single-include utility that makes runtime winapi resolving a breeze.
Using `LoadLibraryA` and `GetProcAddress` manually each time you want to use an api can be cumbersome and error-prone,
especially with the need to repeatedly cast function pointers to the correct types.
This project aims to take away that complexity.


### Usage
```c++
#include <iostream>
#include "resolver.hpp"

int main(int argc, char* argv[]) 
{
    auto pMessageBoxA = WinApi("user32.dll", MessageBoxA);
    if (!pMessageBoxA) {
        std::cerr << "Failed to resolve api" << std::endl;
        return -1;
    }

    pMessageBoxA(NULL, "hello world", "hello world", MB_OK);
}
```
The following image shows the import directory of the output executable in CFF Explorer 🌶
![alt text](assets\image.png)
As you can see - `user32.dll` is not found under the `Module Name` column.

### Disclaimer
This repository is for research and educational purposes only, use of this code is your responsibility.  
I take no responsibility and/or liability for how you choose to use the code available here.  
By using, copying, or distributing any part of this repository, you understand and agree to use it at your own risk and you hold full responsibility for your actions.  
This repository does not promote any hacking-related activity.