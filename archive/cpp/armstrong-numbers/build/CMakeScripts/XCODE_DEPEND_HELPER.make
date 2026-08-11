# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.armstrong-numbers.Debug:
/Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/Debug/armstrong-numbers:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/Debug/armstrong-numbers


PostBuild.armstrong-numbers.Release:
/Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/Release/armstrong-numbers:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/Release/armstrong-numbers


PostBuild.armstrong-numbers.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/MinSizeRel/armstrong-numbers:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/MinSizeRel/armstrong-numbers


PostBuild.armstrong-numbers.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/RelWithDebInfo/armstrong-numbers:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/armstrong-numbers/build/RelWithDebInfo/armstrong-numbers




# For each target create a dummy ruleso the target does not have to exist
