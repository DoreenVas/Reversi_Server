cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Server.cpp Server.h CommandsManager.cpp CommandsManager.h Command.h StartCommand.cpp StartCommand.h List_GamesCommand.cpp List_GamesCommand.h JoinCommand.cpp JoinCommand.h Game.cpp Game.h GamesManager.cpp GamesManager.h Close_ServerCommand.cpp Close_ServerCommand.h)
add_executable(server ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS -pthread)