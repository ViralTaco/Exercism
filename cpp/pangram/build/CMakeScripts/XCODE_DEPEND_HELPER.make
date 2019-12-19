# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.pangram.Debug:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/Debug/pangram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/Debug/pangram


PostBuild.pangram.Release:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/Release/pangram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/Release/pangram


PostBuild.pangram.MinSizeRel:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/MinSizeRel/pangram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/MinSizeRel/pangram


PostBuild.pangram.RelWithDebInfo:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/RelWithDebInfo/pangram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/pangram/build/RelWithDebInfo/pangram




# For each target create a dummy ruleso the target does not have to exist
