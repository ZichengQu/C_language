cmake_minimum_required(VERSION 3.0.0)
project(C_language VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(0.setup_env
    setup_env.c
)

add_executable(1.basic
    "C_programming/1. basic.c"
)
add_executable(2.array
    "C_programming/2. array.c"
)
add_executable(3.string
    "C_programming/3. string.c"
)
add_executable(4.malloc
    "C_programming/4. malloc.c"
)

add_executable(5.1-LinkedList
    "C_programming/5. LinkedList/5.1 LinkedList.c"
)
add_executable(5.2-orderList_main
    "C_programming/5. LinkedList/5.2 orderList_main.c"
    "C_programming/5. LinkedList/5.2 orderList.h"
    "C_programming/5. LinkedList/5.2 orderList.c"
)

add_executable(6.input
    "C_programming/6. input.c"
    "C_programming/5. LinkedList/5.2 orderList.h"
    "C_programming/5. LinkedList/5.2 orderList.c"
)
add_executable(7.file
    "C_programming/7. file.c"
)

add_executable(8.1-arrayStack_main
    "C_programming/8. Stack/8.1 arrayStack_main.c"
    "C_programming/8. Stack/8.1 arrayStack.h"
    "C_programming/8. Stack/8.1 arrayStack.c"
)

add_executable(9.1-arrayQueue_main
    "C_programming/9. Queue/9.1 arrayQueue_main.c"
    "C_programming/9. Queue/9.1 arrayQueue.h"
    "C_programming/9. Queue/9.1 arrayQueue.c"
)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


