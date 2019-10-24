# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.pascals-triangle.Debug:
/Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/Debug/pascals-triangle:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/Debug/pascals-triangle


PostBuild.pascals-triangle.Release:
/Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/Release/pascals-triangle:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/Release/pascals-triangle


PostBuild.pascals-triangle.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/MinSizeRel/pascals-triangle:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/MinSizeRel/pascals-triangle


PostBuild.pascals-triangle.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/RelWithDebInfo/pascals-triangle:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/pascals-triangle/build/RelWithDebInfo/pascals-triangle




# For each target create a dummy ruleso the target does not have to exist
