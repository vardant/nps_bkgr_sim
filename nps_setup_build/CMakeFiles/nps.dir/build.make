# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vardan/g4-work/g4.10.01/nps/nps_setup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vardan/g4-work/g4.10.01/nps/nps_setup_build

# Include any dependencies generated for this target.
include CMakeFiles/nps.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nps.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nps.dir/flags.make

CMakeFiles/nps.dir/nps.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/nps.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/nps.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/nps.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/nps.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/nps.cc

CMakeFiles/nps.dir/nps.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/nps.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/nps.cc > CMakeFiles/nps.dir/nps.cc.i

CMakeFiles/nps.dir/nps.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/nps.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/nps.cc -o CMakeFiles/nps.dir/nps.cc.s

CMakeFiles/nps.dir/nps.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/nps.cc.o.requires

CMakeFiles/nps.dir/nps.cc.o.provides: CMakeFiles/nps.dir/nps.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/nps.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/nps.cc.o.provides

CMakeFiles/nps.dir/nps.cc.o.provides.build: CMakeFiles/nps.dir/nps.cc.o

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSSteppingAction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSSteppingAction.cc

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSSteppingAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSSteppingAction.cc > CMakeFiles/nps.dir/src/NPSSteppingAction.cc.i

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSSteppingAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSSteppingAction.cc -o CMakeFiles/nps.dir/src/NPSSteppingAction.cc.s

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.requires

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.provides: CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.provides

CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSDetectorConstruction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSDetectorConstruction.cc

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSDetectorConstruction.cc > CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.i

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSDetectorConstruction.cc -o CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.s

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.requires

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.provides: CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.provides

CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSActionInitialization.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSActionInitialization.cc

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSActionInitialization.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSActionInitialization.cc > CMakeFiles/nps.dir/src/NPSActionInitialization.cc.i

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSActionInitialization.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSActionInitialization.cc -o CMakeFiles/nps.dir/src/NPSActionInitialization.cc.s

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.requires

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.provides: CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.provides

CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackInformation.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackInformation.cc

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSTrackInformation.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackInformation.cc > CMakeFiles/nps.dir/src/NPSTrackInformation.cc.i

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSTrackInformation.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackInformation.cc -o CMakeFiles/nps.dir/src/NPSTrackInformation.cc.s

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.requires

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.provides: CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.provides

CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o

CMakeFiles/nps.dir/src/NPSEventAction.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSEventAction.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSEventAction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSEventAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSEventAction.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSEventAction.cc

CMakeFiles/nps.dir/src/NPSEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSEventAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSEventAction.cc > CMakeFiles/nps.dir/src/NPSEventAction.cc.i

CMakeFiles/nps.dir/src/NPSEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSEventAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSEventAction.cc -o CMakeFiles/nps.dir/src/NPSEventAction.cc.s

CMakeFiles/nps.dir/src/NPSEventAction.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSEventAction.cc.o.requires

CMakeFiles/nps.dir/src/NPSEventAction.cc.o.provides: CMakeFiles/nps.dir/src/NPSEventAction.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSEventAction.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSEventAction.cc.o.provides

CMakeFiles/nps.dir/src/NPSEventAction.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSEventAction.cc.o

CMakeFiles/nps.dir/src/NPSRun.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSRun.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRun.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSRun.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSRun.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRun.cc

CMakeFiles/nps.dir/src/NPSRun.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSRun.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRun.cc > CMakeFiles/nps.dir/src/NPSRun.cc.i

CMakeFiles/nps.dir/src/NPSRun.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSRun.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRun.cc -o CMakeFiles/nps.dir/src/NPSRun.cc.s

CMakeFiles/nps.dir/src/NPSRun.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSRun.cc.o.requires

CMakeFiles/nps.dir/src/NPSRun.cc.o.provides: CMakeFiles/nps.dir/src/NPSRun.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSRun.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSRun.cc.o.provides

CMakeFiles/nps.dir/src/NPSRun.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSRun.cc.o

CMakeFiles/nps.dir/src/SimpleField.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/SimpleField.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/SimpleField.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/SimpleField.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/SimpleField.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/SimpleField.cc

CMakeFiles/nps.dir/src/SimpleField.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/SimpleField.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/SimpleField.cc > CMakeFiles/nps.dir/src/SimpleField.cc.i

CMakeFiles/nps.dir/src/SimpleField.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/SimpleField.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/SimpleField.cc -o CMakeFiles/nps.dir/src/SimpleField.cc.s

CMakeFiles/nps.dir/src/SimpleField.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/SimpleField.cc.o.requires

CMakeFiles/nps.dir/src/SimpleField.cc.o.provides: CMakeFiles/nps.dir/src/SimpleField.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/SimpleField.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/SimpleField.cc.o.provides

CMakeFiles/nps.dir/src/SimpleField.cc.o.provides.build: CMakeFiles/nps.dir/src/SimpleField.cc.o

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerHit.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerHit.cc

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSTrackerHit.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerHit.cc > CMakeFiles/nps.dir/src/NPSTrackerHit.cc.i

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSTrackerHit.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerHit.cc -o CMakeFiles/nps.dir/src/NPSTrackerHit.cc.s

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.requires

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.provides: CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.provides

CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerSD.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerSD.cc

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSTrackerSD.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerSD.cc > CMakeFiles/nps.dir/src/NPSTrackerSD.cc.i

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSTrackerSD.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSTrackerSD.cc -o CMakeFiles/nps.dir/src/NPSTrackerSD.cc.s

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.requires

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.provides: CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.provides

CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o

CMakeFiles/nps.dir/src/NPSRunAction.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSRunAction.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRunAction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSRunAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSRunAction.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRunAction.cc

CMakeFiles/nps.dir/src/NPSRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSRunAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRunAction.cc > CMakeFiles/nps.dir/src/NPSRunAction.cc.i

CMakeFiles/nps.dir/src/NPSRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSRunAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSRunAction.cc -o CMakeFiles/nps.dir/src/NPSRunAction.cc.s

CMakeFiles/nps.dir/src/NPSRunAction.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSRunAction.cc.o.requires

CMakeFiles/nps.dir/src/NPSRunAction.cc.o.provides: CMakeFiles/nps.dir/src/NPSRunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSRunAction.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSRunAction.cc.o.provides

CMakeFiles/nps.dir/src/NPSRunAction.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSRunAction.cc.o

CMakeFiles/nps.dir/src/NPSHistoManager.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSHistoManager.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSHistoManager.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSHistoManager.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSHistoManager.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSHistoManager.cc

CMakeFiles/nps.dir/src/NPSHistoManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSHistoManager.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSHistoManager.cc > CMakeFiles/nps.dir/src/NPSHistoManager.cc.i

CMakeFiles/nps.dir/src/NPSHistoManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSHistoManager.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSHistoManager.cc -o CMakeFiles/nps.dir/src/NPSHistoManager.cc.s

CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.requires

CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.provides: CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.provides

CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSHistoManager.cc.o

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o: CMakeFiles/nps.dir/flags.make
CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o: /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSPrimaryGeneratorAction.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o -c /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSPrimaryGeneratorAction.cc

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSPrimaryGeneratorAction.cc > CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.i

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vardan/g4-work/g4.10.01/nps/nps_setup/src/NPSPrimaryGeneratorAction.cc -o CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.s

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.requires:
.PHONY : CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.requires

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.provides: CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/nps.dir/build.make CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.provides

CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o

# Object files for target nps
nps_OBJECTS = \
"CMakeFiles/nps.dir/nps.cc.o" \
"CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o" \
"CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o" \
"CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o" \
"CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o" \
"CMakeFiles/nps.dir/src/NPSEventAction.cc.o" \
"CMakeFiles/nps.dir/src/NPSRun.cc.o" \
"CMakeFiles/nps.dir/src/SimpleField.cc.o" \
"CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o" \
"CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o" \
"CMakeFiles/nps.dir/src/NPSRunAction.cc.o" \
"CMakeFiles/nps.dir/src/NPSHistoManager.cc.o" \
"CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o"

# External object files for target nps
nps_EXTERNAL_OBJECTS =

nps: CMakeFiles/nps.dir/nps.cc.o
nps: CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o
nps: CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o
nps: CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o
nps: CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o
nps: CMakeFiles/nps.dir/src/NPSEventAction.cc.o
nps: CMakeFiles/nps.dir/src/NPSRun.cc.o
nps: CMakeFiles/nps.dir/src/SimpleField.cc.o
nps: CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o
nps: CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o
nps: CMakeFiles/nps.dir/src/NPSRunAction.cc.o
nps: CMakeFiles/nps.dir/src/NPSHistoManager.cc.o
nps: CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o
nps: CMakeFiles/nps.dir/build.make
nps: /opt/G4/pro/lib64/libG4Tree.so
nps: /opt/G4/pro/lib64/libG4FR.so
nps: /opt/G4/pro/lib64/libG4GMocren.so
nps: /opt/G4/pro/lib64/libG4visHepRep.so
nps: /opt/G4/pro/lib64/libG4RayTracer.so
nps: /opt/G4/pro/lib64/libG4VRML.so
nps: /opt/G4/pro/lib64/libG4OpenGL.so
nps: /opt/G4/pro/lib64/libG4gl2ps.so
nps: /opt/G4/pro/lib64/libG4vis_management.so
nps: /opt/G4/pro/lib64/libG4modeling.so
nps: /opt/G4/pro/lib64/libG4interfaces.so
nps: /opt/G4/pro/lib64/libG4persistency.so
nps: /opt/G4/pro/lib64/libG4analysis.so
nps: /opt/G4/pro/lib64/libG4error_propagation.so
nps: /opt/G4/pro/lib64/libG4readout.so
nps: /opt/G4/pro/lib64/libG4physicslists.so
nps: /opt/G4/pro/lib64/libG4run.so
nps: /opt/G4/pro/lib64/libG4event.so
nps: /opt/G4/pro/lib64/libG4tracking.so
nps: /opt/G4/pro/lib64/libG4parmodels.so
nps: /opt/G4/pro/lib64/libG4processes.so
nps: /opt/G4/pro/lib64/libG4digits_hits.so
nps: /opt/G4/pro/lib64/libG4track.so
nps: /opt/G4/pro/lib64/libG4particles.so
nps: /opt/G4/pro/lib64/libG4geometry.so
nps: /opt/G4/pro/lib64/libG4materials.so
nps: /opt/G4/pro/lib64/libG4graphics_reps.so
nps: /opt/G4/pro/lib64/libG4intercoms.so
nps: /opt/G4/pro/lib64/libG4global.so
nps: /opt/G4/pro/lib64/libG4clhep.so
nps: /opt/G4/pro/lib64/libG4zlib.so
nps: /opt/G4/pro/lib64/libG4geomUSolids.so
nps: /opt/G4/pro/lib64/libG4FR.so
nps: /opt/G4/pro/lib64/libG4vis_management.so
nps: /opt/G4/pro/lib64/libG4modeling.so
nps: /usr/lib64/libXm.so
nps: /usr/lib64/libSM.so
nps: /usr/lib64/libICE.so
nps: /usr/lib64/libX11.so
nps: /usr/lib64/libXext.so
nps: /usr/lib64/libXmu.so
nps: /usr/lib64/libGL.so
nps: /usr/lib64/libxerces-c.so
nps: /opt/G4/pro/lib64/libG4run.so
nps: /opt/G4/pro/lib64/libG4event.so
nps: /opt/G4/pro/lib64/libG4tracking.so
nps: /opt/G4/pro/lib64/libG4processes.so
nps: /opt/G4/pro/lib64/libG4zlib.so
nps: /usr/lib64/libexpat.so
nps: /opt/G4/pro/lib64/libG4digits_hits.so
nps: /opt/G4/pro/lib64/libG4track.so
nps: /opt/G4/pro/lib64/libG4particles.so
nps: /opt/G4/pro/lib64/libG4geometry.so
nps: /opt/G4/pro/lib64/libG4geomUSolids.so
nps: /opt/G4/pro/lib64/libG4materials.so
nps: /opt/G4/pro/lib64/libG4graphics_reps.so
nps: /opt/G4/pro/lib64/libG4intercoms.so
nps: /opt/G4/pro/lib64/libG4global.so
nps: /opt/G4/pro/lib64/libG4clhep.so
nps: CMakeFiles/nps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable nps"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nps.dir/build: nps
.PHONY : CMakeFiles/nps.dir/build

CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/nps.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSSteppingAction.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSDetectorConstruction.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSActionInitialization.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSTrackInformation.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSEventAction.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSRun.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/SimpleField.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSTrackerHit.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSTrackerSD.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSRunAction.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSHistoManager.cc.o.requires
CMakeFiles/nps.dir/requires: CMakeFiles/nps.dir/src/NPSPrimaryGeneratorAction.cc.o.requires
.PHONY : CMakeFiles/nps.dir/requires

CMakeFiles/nps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nps.dir/clean

CMakeFiles/nps.dir/depend:
	cd /home/vardan/g4-work/g4.10.01/nps/nps_setup_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vardan/g4-work/g4.10.01/nps/nps_setup /home/vardan/g4-work/g4.10.01/nps/nps_setup /home/vardan/g4-work/g4.10.01/nps/nps_setup_build /home/vardan/g4-work/g4.10.01/nps/nps_setup_build /home/vardan/g4-work/g4.10.01/nps/nps_setup_build/CMakeFiles/nps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nps.dir/depend

