# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.luhn.Debug:
/Users/viraltaco/code/Exercism/cpp/luhn/build/Debug/luhn:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/luhn/build/Debug/luhn


PostBuild.luhn.Release:
/Users/viraltaco/code/Exercism/cpp/luhn/build/Release/luhn:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/luhn/build/Release/luhn


PostBuild.luhn.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/luhn/build/MinSizeRel/luhn:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/luhn/build/MinSizeRel/luhn


PostBuild.luhn.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/luhn/build/RelWithDebInfo/luhn:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/luhn/build/RelWithDebInfo/luhn




# For each target create a dummy ruleso the target does not have to exist
