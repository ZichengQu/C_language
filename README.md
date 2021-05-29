# Data Structure &amp;&amp; Algorithm (C语言描述)</br>
1. **basic**
2. **array**
3. **string**
4. **malloc**
5. **LinkedList**</br>
   5.1 **LinkedList**</br>
   5.2 **orderList**</br>
6. **input**
7. **file**
8. **Stack**</br>
   8.1 **Stack implementation via array**</br>
   8.2 **Stack implementation via list**</br>
9. **Queue**</br>
   9.1 **Queue implementation via array**</br>
   9.2 **Queue implementation via list**</br>
10. **Tree**</br>
11. **Graph**</br>
   11.1 **Graph main**</br>
   11.2 **Graph implementation via array**</br>
   11.3 **Graph implementation via matrix**</br>
   11.4 **Graph implementation via list**</br>
   11.5 **DFS code && BFS pseudocode**</br>
</br>
# 工具 && 环境
1. **使用环境及软件**</br>
   [Windows 10 (x64 systems: Version 1903 or higher, with Build 18362 or higher)](https://www.microsoft.com/en-hk/software-download/windows10)</br>
   [WSL2 (English Version)](https://docs.microsoft.com/en-us/windows/wsl/install-win10) or [WSL2 (中文简体)](https://docs.microsoft.com/zh-cn/windows/wsl/install-win10)</br>
[Ubuntu 20.04](https://docs.microsoft.com/zh-cn/windows/wsl/install-win10#step-6---install-your-linux-distribution-of-choice)</br>
[Visual Studio Code (VSCode)](https://code.visualstudio.com/)</br>
1. **使用的VSCode插件 (在VSCode->Extensions进行install)**</br>
[Remote-WSL](https://code.visualstudio.com/docs/remote/wsl)</br>
[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)</br>
[CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)</br>

3. **安装C环境**
   ```
   sudo apt update
   ```
   ```
   sudo apt-get install cmake gcc clang gdb build-essential
   ```
4. **配置Debug环境**</br>
   4.1 配置方案 (1)</br>
   ```
   .vscode/c_cpp_properties.json
   ```
   ```
   .vscode/tasks.json
   ```
   ```
   .vscode/launch.json
   ```
   4.2 配置方案 (2)</br>
   若想使用``CMake``，则需 ``Ctrl + Shift + P`` 搜索``cmake -> quick start -> execute``，在生成的``CMakeLists.txt``中配置``add_executable``; 并在``.vscode``中添加``setting.json``, 在其中添加 ``cmake.debugConfig`` 进行传``argv``等参数.