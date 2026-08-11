# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.reverse-string.Debug:
/Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/Debug/reverse-string:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/Debug/reverse-string


PostBuild.reverse-string.Release:
/Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/Release/reverse-string:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/Release/reverse-string


PostBuild.reverse-string.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/MinSizeRel/reverse-string:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/MinSizeRel/reverse-string


PostBuild.reverse-string.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/RelWithDebInfo/reverse-string:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/reverse-string/build/RelWithDebInfo/reverse-string




# For each target create a dummy ruleso the target does not have to exist
