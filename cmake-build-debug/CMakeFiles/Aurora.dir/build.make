# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abcdlsj/github/webserver/Aurora_cp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Aurora.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Aurora.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aurora.dir/flags.make

CMakeFiles/Aurora.dir/src/acceptor.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/acceptor.cc.o: ../src/acceptor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aurora.dir/src/acceptor.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/acceptor.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/acceptor.cc

CMakeFiles/Aurora.dir/src/acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/acceptor.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/acceptor.cc > CMakeFiles/Aurora.dir/src/acceptor.cc.i

CMakeFiles/Aurora.dir/src/acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/acceptor.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/acceptor.cc -o CMakeFiles/Aurora.dir/src/acceptor.cc.s

CMakeFiles/Aurora.dir/src/buffer.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/buffer.cc.o: ../src/buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Aurora.dir/src/buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/buffer.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/buffer.cc

CMakeFiles/Aurora.dir/src/buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/buffer.cc > CMakeFiles/Aurora.dir/src/buffer.cc.i

CMakeFiles/Aurora.dir/src/buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/buffer.cc -o CMakeFiles/Aurora.dir/src/buffer.cc.s

CMakeFiles/Aurora.dir/src/channel.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/channel.cc.o: ../src/channel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Aurora.dir/src/channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/channel.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/channel.cc

CMakeFiles/Aurora.dir/src/channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/channel.cc > CMakeFiles/Aurora.dir/src/channel.cc.i

CMakeFiles/Aurora.dir/src/channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/channel.cc -o CMakeFiles/Aurora.dir/src/channel.cc.s

CMakeFiles/Aurora.dir/src/channel_map.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/channel_map.cc.o: ../src/channel_map.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Aurora.dir/src/channel_map.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/channel_map.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/channel_map.cc

CMakeFiles/Aurora.dir/src/channel_map.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/channel_map.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/channel_map.cc > CMakeFiles/Aurora.dir/src/channel_map.cc.i

CMakeFiles/Aurora.dir/src/channel_map.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/channel_map.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/channel_map.cc -o CMakeFiles/Aurora.dir/src/channel_map.cc.s

CMakeFiles/Aurora.dir/src/event_loop.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/event_loop.cc.o: ../src/event_loop.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Aurora.dir/src/event_loop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/event_loop.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop.cc

CMakeFiles/Aurora.dir/src/event_loop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/event_loop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop.cc > CMakeFiles/Aurora.dir/src/event_loop.cc.i

CMakeFiles/Aurora.dir/src/event_loop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/event_loop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop.cc -o CMakeFiles/Aurora.dir/src/event_loop.cc.s

CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o: ../src/event_loop_thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop_thread.cc

CMakeFiles/Aurora.dir/src/event_loop_thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/event_loop_thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop_thread.cc > CMakeFiles/Aurora.dir/src/event_loop_thread.cc.i

CMakeFiles/Aurora.dir/src/event_loop_thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/event_loop_thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/event_loop_thread.cc -o CMakeFiles/Aurora.dir/src/event_loop_thread.cc.s

CMakeFiles/Aurora.dir/src/http_request.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/http_request.cc.o: ../src/http_request.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Aurora.dir/src/http_request.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/http_request.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/http_request.cc

CMakeFiles/Aurora.dir/src/http_request.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/http_request.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/http_request.cc > CMakeFiles/Aurora.dir/src/http_request.cc.i

CMakeFiles/Aurora.dir/src/http_request.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/http_request.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/http_request.cc -o CMakeFiles/Aurora.dir/src/http_request.cc.s

CMakeFiles/Aurora.dir/src/http_response.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/http_response.cc.o: ../src/http_response.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Aurora.dir/src/http_response.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/http_response.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/http_response.cc

CMakeFiles/Aurora.dir/src/http_response.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/http_response.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/http_response.cc > CMakeFiles/Aurora.dir/src/http_response.cc.i

CMakeFiles/Aurora.dir/src/http_response.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/http_response.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/http_response.cc -o CMakeFiles/Aurora.dir/src/http_response.cc.s

CMakeFiles/Aurora.dir/src/http_server.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/http_server.cc.o: ../src/http_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Aurora.dir/src/http_server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/http_server.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/http_server.cc

CMakeFiles/Aurora.dir/src/http_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/http_server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/http_server.cc > CMakeFiles/Aurora.dir/src/http_server.cc.i

CMakeFiles/Aurora.dir/src/http_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/http_server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/http_server.cc -o CMakeFiles/Aurora.dir/src/http_server.cc.s

CMakeFiles/Aurora.dir/src/log.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/log.cc.o: ../src/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Aurora.dir/src/log.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/log.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/log.cc

CMakeFiles/Aurora.dir/src/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/log.cc > CMakeFiles/Aurora.dir/src/log.cc.i

CMakeFiles/Aurora.dir/src/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/log.cc -o CMakeFiles/Aurora.dir/src/log.cc.s

CMakeFiles/Aurora.dir/src/tcp_server.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/tcp_server.cc.o: ../src/tcp_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Aurora.dir/src/tcp_server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/tcp_server.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_server.cc

CMakeFiles/Aurora.dir/src/tcp_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/tcp_server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_server.cc > CMakeFiles/Aurora.dir/src/tcp_server.cc.i

CMakeFiles/Aurora.dir/src/tcp_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/tcp_server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_server.cc -o CMakeFiles/Aurora.dir/src/tcp_server.cc.s

CMakeFiles/Aurora.dir/src/tcp_connection.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/tcp_connection.cc.o: ../src/tcp_connection.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Aurora.dir/src/tcp_connection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/tcp_connection.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_connection.cc

CMakeFiles/Aurora.dir/src/tcp_connection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/tcp_connection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_connection.cc > CMakeFiles/Aurora.dir/src/tcp_connection.cc.i

CMakeFiles/Aurora.dir/src/tcp_connection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/tcp_connection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_connection.cc -o CMakeFiles/Aurora.dir/src/tcp_connection.cc.s

CMakeFiles/Aurora.dir/src/thread_pool.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/thread_pool.cc.o: ../src/thread_pool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Aurora.dir/src/thread_pool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/thread_pool.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/thread_pool.cc

CMakeFiles/Aurora.dir/src/thread_pool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/thread_pool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/thread_pool.cc > CMakeFiles/Aurora.dir/src/thread_pool.cc.i

CMakeFiles/Aurora.dir/src/thread_pool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/thread_pool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/thread_pool.cc -o CMakeFiles/Aurora.dir/src/thread_pool.cc.s

CMakeFiles/Aurora.dir/src/utils.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/utils.cc.o: ../src/utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Aurora.dir/src/utils.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/utils.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/utils.cc

CMakeFiles/Aurora.dir/src/utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/utils.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/utils.cc > CMakeFiles/Aurora.dir/src/utils.cc.i

CMakeFiles/Aurora.dir/src/utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/utils.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/utils.cc -o CMakeFiles/Aurora.dir/src/utils.cc.s

CMakeFiles/Aurora.dir/src/read.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/read.cc.o: ../src/read.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Aurora.dir/src/read.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/read.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/read.cc

CMakeFiles/Aurora.dir/src/read.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/read.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/read.cc > CMakeFiles/Aurora.dir/src/read.cc.i

CMakeFiles/Aurora.dir/src/read.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/read.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/read.cc -o CMakeFiles/Aurora.dir/src/read.cc.s

CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o: ../src/epolll_dispatcher.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/epolll_dispatcher.cc

CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/epolll_dispatcher.cc > CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.i

CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/epolll_dispatcher.cc -o CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.s

CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o: ../src/poll_dispatcher.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/poll_dispatcher.cc

CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/poll_dispatcher.cc > CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.i

CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/poll_dispatcher.cc -o CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.s

CMakeFiles/Aurora.dir/src/tcp_client.cc.o: CMakeFiles/Aurora.dir/flags.make
CMakeFiles/Aurora.dir/src/tcp_client.cc.o: ../src/tcp_client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Aurora.dir/src/tcp_client.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aurora.dir/src/tcp_client.cc.o -c /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_client.cc

CMakeFiles/Aurora.dir/src/tcp_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aurora.dir/src/tcp_client.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_client.cc > CMakeFiles/Aurora.dir/src/tcp_client.cc.i

CMakeFiles/Aurora.dir/src/tcp_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aurora.dir/src/tcp_client.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abcdlsj/github/webserver/Aurora_cp/src/tcp_client.cc -o CMakeFiles/Aurora.dir/src/tcp_client.cc.s

# Object files for target Aurora
Aurora_OBJECTS = \
"CMakeFiles/Aurora.dir/src/acceptor.cc.o" \
"CMakeFiles/Aurora.dir/src/buffer.cc.o" \
"CMakeFiles/Aurora.dir/src/channel.cc.o" \
"CMakeFiles/Aurora.dir/src/channel_map.cc.o" \
"CMakeFiles/Aurora.dir/src/event_loop.cc.o" \
"CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o" \
"CMakeFiles/Aurora.dir/src/http_request.cc.o" \
"CMakeFiles/Aurora.dir/src/http_response.cc.o" \
"CMakeFiles/Aurora.dir/src/http_server.cc.o" \
"CMakeFiles/Aurora.dir/src/log.cc.o" \
"CMakeFiles/Aurora.dir/src/tcp_server.cc.o" \
"CMakeFiles/Aurora.dir/src/tcp_connection.cc.o" \
"CMakeFiles/Aurora.dir/src/thread_pool.cc.o" \
"CMakeFiles/Aurora.dir/src/utils.cc.o" \
"CMakeFiles/Aurora.dir/src/read.cc.o" \
"CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o" \
"CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o" \
"CMakeFiles/Aurora.dir/src/tcp_client.cc.o"

# External object files for target Aurora
Aurora_EXTERNAL_OBJECTS =

Aurora: CMakeFiles/Aurora.dir/src/acceptor.cc.o
Aurora: CMakeFiles/Aurora.dir/src/buffer.cc.o
Aurora: CMakeFiles/Aurora.dir/src/channel.cc.o
Aurora: CMakeFiles/Aurora.dir/src/channel_map.cc.o
Aurora: CMakeFiles/Aurora.dir/src/event_loop.cc.o
Aurora: CMakeFiles/Aurora.dir/src/event_loop_thread.cc.o
Aurora: CMakeFiles/Aurora.dir/src/http_request.cc.o
Aurora: CMakeFiles/Aurora.dir/src/http_response.cc.o
Aurora: CMakeFiles/Aurora.dir/src/http_server.cc.o
Aurora: CMakeFiles/Aurora.dir/src/log.cc.o
Aurora: CMakeFiles/Aurora.dir/src/tcp_server.cc.o
Aurora: CMakeFiles/Aurora.dir/src/tcp_connection.cc.o
Aurora: CMakeFiles/Aurora.dir/src/thread_pool.cc.o
Aurora: CMakeFiles/Aurora.dir/src/utils.cc.o
Aurora: CMakeFiles/Aurora.dir/src/read.cc.o
Aurora: CMakeFiles/Aurora.dir/src/epolll_dispatcher.cc.o
Aurora: CMakeFiles/Aurora.dir/src/poll_dispatcher.cc.o
Aurora: CMakeFiles/Aurora.dir/src/tcp_client.cc.o
Aurora: CMakeFiles/Aurora.dir/build.make
Aurora: CMakeFiles/Aurora.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable Aurora"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Aurora.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Aurora.dir/build: Aurora

.PHONY : CMakeFiles/Aurora.dir/build

CMakeFiles/Aurora.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Aurora.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Aurora.dir/clean

CMakeFiles/Aurora.dir/depend:
	cd /home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abcdlsj/github/webserver/Aurora_cp /home/abcdlsj/github/webserver/Aurora_cp /home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug /home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug /home/abcdlsj/github/webserver/Aurora_cp/cmake-build-debug/CMakeFiles/Aurora.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Aurora.dir/depend
