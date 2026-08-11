# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.circular-buffer.Debug:
/Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/Debug/circular-buffer:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/Debug/circular-buffer


PostBuild.circular-buffer.Release:
/Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/Release/circular-buffer:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/Release/circular-buffer


PostBuild.circular-buffer.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/MinSizeRel/circular-buffer:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/MinSizeRel/circular-buffer


PostBuild.circular-buffer.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/RelWithDebInfo/circular-buffer:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/circular-buffer/build/RelWithDebInfo/circular-buffer




# For each target create a dummy ruleso the target does not have to exist
