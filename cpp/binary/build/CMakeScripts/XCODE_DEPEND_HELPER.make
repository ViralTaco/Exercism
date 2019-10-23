# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.binary.Debug:
/Users/viraltaco/code/code/Exercism/cpp/binary/build/Debug/binary:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary/build/Debug/binary


PostBuild.binary.Release:
/Users/viraltaco/code/code/Exercism/cpp/binary/build/Release/binary:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary/build/Release/binary


PostBuild.binary.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/binary/build/MinSizeRel/binary:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary/build/MinSizeRel/binary


PostBuild.binary.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/binary/build/RelWithDebInfo/binary:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary/build/RelWithDebInfo/binary




# For each target create a dummy ruleso the target does not have to exist
