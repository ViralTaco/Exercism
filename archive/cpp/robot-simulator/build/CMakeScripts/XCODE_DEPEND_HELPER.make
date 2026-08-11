# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.robot-simulator.Debug:
/Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/Debug/robot-simulator:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/Debug/robot-simulator


PostBuild.robot-simulator.Release:
/Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/Release/robot-simulator:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/Release/robot-simulator


PostBuild.robot-simulator.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/MinSizeRel/robot-simulator:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/MinSizeRel/robot-simulator


PostBuild.robot-simulator.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/RelWithDebInfo/robot-simulator:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/robot-simulator/build/RelWithDebInfo/robot-simulator




# For each target create a dummy ruleso the target does not have to exist
