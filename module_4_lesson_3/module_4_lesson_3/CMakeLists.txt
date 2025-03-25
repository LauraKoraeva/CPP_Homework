cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    src/main.cpp
    src/Board.cpp
    src/Game.cpp
    src/Player.cpp
    src/HumanPlayer.cpp
    src/ComputerPlayer.cpp
)

include_directories(include)

add_executable(TicTacToe ${SOURCE_FILES})