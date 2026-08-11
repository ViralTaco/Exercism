# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.isogram.Debug:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/Debug/isogram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/Debug/isogram


PostBuild.isogram.Release:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/Release/isogram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/Release/isogram


PostBuild.isogram.MinSizeRel:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/MinSizeRel/isogram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/MinSizeRel/isogram


PostBuild.isogram.RelWithDebInfo:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/RelWithDebInfo/isogram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/isogram/build/RelWithDebInfo/isogram




# For each target create a dummy ruleso the target does not have to exist
