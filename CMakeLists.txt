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

add_executable(8.stack_main
    "C_programming/8. Stack/8.0 stack_main.c"
    "C_programming/8. Stack/8.1 arrayStack.h"
    "C_programming/8. Stack/8.1 arrayStack.c"
    "C_programming/8. Stack/8.2 listStack.h"
    "C_programming/8. Stack/8.2 listStack.c"
)

add_executable(9.queue_main
    "C_programming/9. Queue/9.0 queue_main.c"
    "C_programming/9. Queue/9.1 arrayQueue.h"
    "C_programming/9. Queue/9.1 arrayQueue.c"
    "C_programming/9. Queue/9.2 listQueue.h"
    "C_programming/9. Queue/9.2 listQueue.c"
)

add_executable(10.tree_main
    "C_programming/10. Tree/10.1 tree_main.c"
    "C_programming/10. Tree/10.1 tree.h"
    "C_programming/10. Tree/10.1 tree.c"
)

add_executable(11.2-array_graph
    "C_programming/11. Graph/11.1 graph_main.c"
    "C_programming/11. Graph/11.1 graph.h"
    "C_programming/11. Graph/11.2 array_edge_graph.c"
)
add_executable(11.3-matrix_graph
    "C_programming/11. Graph/11.1 graph_main.c"
    "C_programming/11. Graph/11.1 graph.h"
    "C_programming/11. Graph/11.3 matrix_graph.c"
)
add_executable(11.4-adjacency_list_graph
    "C_programming/11. Graph/11.1 graph_main.c"
    "C_programming/11. Graph/11.1 graph.h"
    "C_programming/11. Graph/11.4 list_graph.c"
    "C_programming/11. Graph/utils/list.h"
    "C_programming/11. Graph/utils/list.c"
)
add_executable(11.5-dfs
    "C_programming/11. Graph/11.5 dfs_main.c"
    "C_programming/11. Graph/11.1 graph.h"
    "C_programming/11. Graph/11.3 matrix_graph.c"
    "C_programming/11. Graph/11.5 dfs.h"
    "C_programming/11. Graph/11.5 dfs.c"
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


