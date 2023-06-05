cmake_minimum_required(VERSION 3.2)


project(Games_in_C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra -Werror -D_GNU_SOURCE")


add_executable(ping_pong
    ping_pong/main.c
)

# add_executable(game_life
#     GameOfLife/game_of_life.c
# )

add_executable(mandelbrot
    Mandelbrot/mandelbrot.c
)

add_executable(donut
    Donut/main.c
)

# add_executable(polish_notation
#     PolishNotation/det.c
#     PolishNotation/invert.c
# )

# target_link_libraries(game_life m)
target_link_libraries(mandelbrot m)
target_link_libraries(donut m)
# target_link_libraries(polish_notation m)
# target_link_libraries(${PROJECT_NAME} PRIVATE m)
