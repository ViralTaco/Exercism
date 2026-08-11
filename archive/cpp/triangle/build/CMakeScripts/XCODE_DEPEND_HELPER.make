# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.triangle.Debug:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/Debug/triangle:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/Debug/triangle


PostBuild.triangle.Release:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/Release/triangle:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/Release/triangle


PostBuild.triangle.MinSizeRel:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/MinSizeRel/triangle:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/MinSizeRel/triangle


PostBuild.triangle.RelWithDebInfo:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/RelWithDebInfo/triangle:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/triangle/build/RelWithDebInfo/triangle




# For each target create a dummy ruleso the target does not have to exist
