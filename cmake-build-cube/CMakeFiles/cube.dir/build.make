# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hportife/hportife/cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hportife/hportife/cube/cmake-build-cube

# Include any dependencies generated for this target.
include CMakeFiles/cube.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/cube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cube.dir/flags.make

CMakeFiles/cube.dir/main.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cube.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/main.c.o -c /Users/hportife/hportife/cube/main.c

CMakeFiles/cube.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/main.c > CMakeFiles/cube.dir/main.c.i

CMakeFiles/cube.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/main.c -o CMakeFiles/cube.dir/main.c.s

CMakeFiles/cube.dir/duarrlen.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/duarrlen.c.o: ../duarrlen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cube.dir/duarrlen.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/duarrlen.c.o -c /Users/hportife/hportife/cube/duarrlen.c

CMakeFiles/cube.dir/duarrlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/duarrlen.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/duarrlen.c > CMakeFiles/cube.dir/duarrlen.c.i

CMakeFiles/cube.dir/duarrlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/duarrlen.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/duarrlen.c -o CMakeFiles/cube.dir/duarrlen.c.s

CMakeFiles/cube.dir/error_call.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/error_call.c.o: ../error_call.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cube.dir/error_call.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/error_call.c.o -c /Users/hportife/hportife/cube/error_call.c

CMakeFiles/cube.dir/error_call.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/error_call.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/error_call.c > CMakeFiles/cube.dir/error_call.c.i

CMakeFiles/cube.dir/error_call.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/error_call.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/error_call.c -o CMakeFiles/cube.dir/error_call.c.s

CMakeFiles/cube.dir/nohawesym.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/nohawesym.c.o: ../nohawesym.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cube.dir/nohawesym.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/nohawesym.c.o -c /Users/hportife/hportife/cube/nohawesym.c

CMakeFiles/cube.dir/nohawesym.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/nohawesym.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/nohawesym.c > CMakeFiles/cube.dir/nohawesym.c.i

CMakeFiles/cube.dir/nohawesym.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/nohawesym.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/nohawesym.c -o CMakeFiles/cube.dir/nohawesym.c.s

CMakeFiles/cube.dir/noonsym.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/noonsym.c.o: ../noonsym.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cube.dir/noonsym.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/noonsym.c.o -c /Users/hportife/hportife/cube/noonsym.c

CMakeFiles/cube.dir/noonsym.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/noonsym.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/noonsym.c > CMakeFiles/cube.dir/noonsym.c.i

CMakeFiles/cube.dir/noonsym.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/noonsym.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/noonsym.c -o CMakeFiles/cube.dir/noonsym.c.s

CMakeFiles/cube.dir/onsymofstr.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/onsymofstr.c.o: ../onsymofstr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cube.dir/onsymofstr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/onsymofstr.c.o -c /Users/hportife/hportife/cube/onsymofstr.c

CMakeFiles/cube.dir/onsymofstr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/onsymofstr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/onsymofstr.c > CMakeFiles/cube.dir/onsymofstr.c.i

CMakeFiles/cube.dir/onsymofstr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/onsymofstr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/onsymofstr.c -o CMakeFiles/cube.dir/onsymofstr.c.s

CMakeFiles/cube.dir/serv_fncs_I.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/serv_fncs_I.c.o: ../serv_fncs_I.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cube.dir/serv_fncs_I.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/serv_fncs_I.c.o -c /Users/hportife/hportife/cube/serv_fncs_I.c

CMakeFiles/cube.dir/serv_fncs_I.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/serv_fncs_I.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/serv_fncs_I.c > CMakeFiles/cube.dir/serv_fncs_I.c.i

CMakeFiles/cube.dir/serv_fncs_I.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/serv_fncs_I.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/serv_fncs_I.c -o CMakeFiles/cube.dir/serv_fncs_I.c.s

CMakeFiles/cube.dir/sne_noonsym.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/sne_noonsym.c.o: ../sne_noonsym.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cube.dir/sne_noonsym.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/sne_noonsym.c.o -c /Users/hportife/hportife/cube/sne_noonsym.c

CMakeFiles/cube.dir/sne_noonsym.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/sne_noonsym.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/sne_noonsym.c > CMakeFiles/cube.dir/sne_noonsym.c.i

CMakeFiles/cube.dir/sne_noonsym.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/sne_noonsym.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/sne_noonsym.c -o CMakeFiles/cube.dir/sne_noonsym.c.s

CMakeFiles/cube.dir/str_no_have_syms.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/str_no_have_syms.c.o: ../str_no_have_syms.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/cube.dir/str_no_have_syms.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/str_no_have_syms.c.o -c /Users/hportife/hportife/cube/str_no_have_syms.c

CMakeFiles/cube.dir/str_no_have_syms.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/str_no_have_syms.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/str_no_have_syms.c > CMakeFiles/cube.dir/str_no_have_syms.c.i

CMakeFiles/cube.dir/str_no_have_syms.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/str_no_have_syms.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/str_no_have_syms.c -o CMakeFiles/cube.dir/str_no_have_syms.c.s

CMakeFiles/cube.dir/valid_fncs.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/valid_fncs.c.o: ../valid_fncs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/cube.dir/valid_fncs.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/valid_fncs.c.o -c /Users/hportife/hportife/cube/valid_fncs.c

CMakeFiles/cube.dir/valid_fncs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/valid_fncs.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/valid_fncs.c > CMakeFiles/cube.dir/valid_fncs.c.i

CMakeFiles/cube.dir/valid_fncs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/valid_fncs.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/valid_fncs.c -o CMakeFiles/cube.dir/valid_fncs.c.s

CMakeFiles/cube.dir/getsympos.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/getsympos.c.o: ../getsympos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/cube.dir/getsympos.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/getsympos.c.o -c /Users/hportife/hportife/cube/getsympos.c

CMakeFiles/cube.dir/getsympos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/getsympos.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/getsympos.c > CMakeFiles/cube.dir/getsympos.c.i

CMakeFiles/cube.dir/getsympos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/getsympos.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/getsympos.c -o CMakeFiles/cube.dir/getsympos.c.s

CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o: ../libft_fncs/ft_strnstr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_strnstr.c

CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_strnstr.c > CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.i

CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_strnstr.c -o CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.s

CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o: ../libft_fncs/ft_isalnum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_isalnum.c

CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_isalnum.c > CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.i

CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_isalnum.c -o CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.s

CMakeFiles/cube.dir/get_next_line/get_next_line.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/get_next_line/get_next_line.c.o: ../get_next_line/get_next_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/cube.dir/get_next_line/get_next_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/get_next_line/get_next_line.c.o -c /Users/hportife/hportife/cube/get_next_line/get_next_line.c

CMakeFiles/cube.dir/get_next_line/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/get_next_line/get_next_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/get_next_line/get_next_line.c > CMakeFiles/cube.dir/get_next_line/get_next_line.c.i

CMakeFiles/cube.dir/get_next_line/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/get_next_line/get_next_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/get_next_line/get_next_line.c -o CMakeFiles/cube.dir/get_next_line/get_next_line.c.s

CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o: ../get_next_line/get_next_line_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o -c /Users/hportife/hportife/cube/get_next_line/get_next_line_utils.c

CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/get_next_line/get_next_line_utils.c > CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.i

CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/get_next_line/get_next_line_utils.c -o CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.s

CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o: ../libft_fncs/ft_isalpha.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_isalpha.c

CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_isalpha.c > CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.i

CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_isalpha.c -o CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.s

CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o: ../libft_fncs/ft_substr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_substr.c

CMakeFiles/cube.dir/libft_fncs/ft_substr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_substr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_substr.c > CMakeFiles/cube.dir/libft_fncs/ft_substr.c.i

CMakeFiles/cube.dir/libft_fncs/ft_substr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_substr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_substr.c -o CMakeFiles/cube.dir/libft_fncs/ft_substr.c.s

CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o: ../libft_fncs/ft_atoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_atoi.c

CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_atoi.c > CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.i

CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_atoi.c -o CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.s

CMakeFiles/cube.dir/stradd.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/stradd.c.o: ../stradd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/cube.dir/stradd.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/stradd.c.o -c /Users/hportife/hportife/cube/stradd.c

CMakeFiles/cube.dir/stradd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/stradd.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/stradd.c > CMakeFiles/cube.dir/stradd.c.i

CMakeFiles/cube.dir/stradd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/stradd.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/stradd.c -o CMakeFiles/cube.dir/stradd.c.s

CMakeFiles/cube.dir/duarrfree.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/duarrfree.c.o: ../duarrfree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/cube.dir/duarrfree.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/duarrfree.c.o -c /Users/hportife/hportife/cube/duarrfree.c

CMakeFiles/cube.dir/duarrfree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/duarrfree.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/duarrfree.c > CMakeFiles/cube.dir/duarrfree.c.i

CMakeFiles/cube.dir/duarrfree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/duarrfree.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/duarrfree.c -o CMakeFiles/cube.dir/duarrfree.c.s

CMakeFiles/cube.dir/fstsym.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/fstsym.c.o: ../fstsym.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/cube.dir/fstsym.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/fstsym.c.o -c /Users/hportife/hportife/cube/fstsym.c

CMakeFiles/cube.dir/fstsym.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/fstsym.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/fstsym.c > CMakeFiles/cube.dir/fstsym.c.i

CMakeFiles/cube.dir/fstsym.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/fstsym.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/fstsym.c -o CMakeFiles/cube.dir/fstsym.c.s

CMakeFiles/cube.dir/duarrcalloc.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/duarrcalloc.c.o: ../duarrcalloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/cube.dir/duarrcalloc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/duarrcalloc.c.o -c /Users/hportife/hportife/cube/duarrcalloc.c

CMakeFiles/cube.dir/duarrcalloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/duarrcalloc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/duarrcalloc.c > CMakeFiles/cube.dir/duarrcalloc.c.i

CMakeFiles/cube.dir/duarrcalloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/duarrcalloc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/duarrcalloc.c -o CMakeFiles/cube.dir/duarrcalloc.c.s

CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o: ../libft_fncs/ft_memset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building C object CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o -c /Users/hportife/hportife/cube/libft_fncs/ft_memset.c

CMakeFiles/cube.dir/libft_fncs/ft_memset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/libft_fncs/ft_memset.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hportife/hportife/cube/libft_fncs/ft_memset.c > CMakeFiles/cube.dir/libft_fncs/ft_memset.c.i

CMakeFiles/cube.dir/libft_fncs/ft_memset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/libft_fncs/ft_memset.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hportife/hportife/cube/libft_fncs/ft_memset.c -o CMakeFiles/cube.dir/libft_fncs/ft_memset.c.s

# Object files for target cube
cube_OBJECTS = \
"CMakeFiles/cube.dir/main.c.o" \
"CMakeFiles/cube.dir/duarrlen.c.o" \
"CMakeFiles/cube.dir/error_call.c.o" \
"CMakeFiles/cube.dir/nohawesym.c.o" \
"CMakeFiles/cube.dir/noonsym.c.o" \
"CMakeFiles/cube.dir/onsymofstr.c.o" \
"CMakeFiles/cube.dir/serv_fncs_I.c.o" \
"CMakeFiles/cube.dir/sne_noonsym.c.o" \
"CMakeFiles/cube.dir/str_no_have_syms.c.o" \
"CMakeFiles/cube.dir/valid_fncs.c.o" \
"CMakeFiles/cube.dir/getsympos.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o" \
"CMakeFiles/cube.dir/get_next_line/get_next_line.c.o" \
"CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o" \
"CMakeFiles/cube.dir/stradd.c.o" \
"CMakeFiles/cube.dir/duarrfree.c.o" \
"CMakeFiles/cube.dir/fstsym.c.o" \
"CMakeFiles/cube.dir/duarrcalloc.c.o" \
"CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o"

# External object files for target cube
cube_EXTERNAL_OBJECTS =

cube: CMakeFiles/cube.dir/main.c.o
cube: CMakeFiles/cube.dir/duarrlen.c.o
cube: CMakeFiles/cube.dir/error_call.c.o
cube: CMakeFiles/cube.dir/nohawesym.c.o
cube: CMakeFiles/cube.dir/noonsym.c.o
cube: CMakeFiles/cube.dir/onsymofstr.c.o
cube: CMakeFiles/cube.dir/serv_fncs_I.c.o
cube: CMakeFiles/cube.dir/sne_noonsym.c.o
cube: CMakeFiles/cube.dir/str_no_have_syms.c.o
cube: CMakeFiles/cube.dir/valid_fncs.c.o
cube: CMakeFiles/cube.dir/getsympos.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_strnstr.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_isalnum.c.o
cube: CMakeFiles/cube.dir/get_next_line/get_next_line.c.o
cube: CMakeFiles/cube.dir/get_next_line/get_next_line_utils.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_isalpha.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_substr.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_atoi.c.o
cube: CMakeFiles/cube.dir/stradd.c.o
cube: CMakeFiles/cube.dir/duarrfree.c.o
cube: CMakeFiles/cube.dir/fstsym.c.o
cube: CMakeFiles/cube.dir/duarrcalloc.c.o
cube: CMakeFiles/cube.dir/libft_fncs/ft_memset.c.o
cube: CMakeFiles/cube.dir/build.make
cube: CMakeFiles/cube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking C executable cube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cube.dir/build: cube
.PHONY : CMakeFiles/cube.dir/build

CMakeFiles/cube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cube.dir/clean

CMakeFiles/cube.dir/depend:
	cd /Users/hportife/hportife/cube/cmake-build-cube && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hportife/hportife/cube /Users/hportife/hportife/cube /Users/hportife/hportife/cube/cmake-build-cube /Users/hportife/hportife/cube/cmake-build-cube /Users/hportife/hportife/cube/cmake-build-cube/CMakeFiles/cube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cube.dir/depend

