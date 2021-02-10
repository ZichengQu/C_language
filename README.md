# C_language
C language and Data Structure &amp;&amp; Algorithm
使用环境为WSL2, Ubuntu20.04(瑞哥推荐16 or 18), VSCode.
使用的VSCode插件为Remote-WSL、C/C++、 CMake Tools、Prettier(Code Formatter).
可通过Remote-SSH连接远程服务器进行操作, ssh user@host.
User: zID
Host: cse.unsw.edu.au == login.cse.unsw.edu.au
UNSW机房的C版本是C11，会使用dcc代替gcc，dcc会检测是否内存泄漏。

0. 安装C环境: sudo apt-get install cmake gcc clang gdb build-essential
1. 配置Debug环境: "build.c", ".vscode/c_cpp_properties.json", "vscode/tasks.json", ".vscode/launch.json"
2. C basic: C_programming/basic.c
3. 