# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.hexadecimal.Debug:
/Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/Debug/hexadecimal:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/Debug/hexadecimal


PostBuild.hexadecimal.Release:
/Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/Release/hexadecimal:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/Release/hexadecimal


PostBuild.hexadecimal.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/MinSizeRel/hexadecimal:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/MinSizeRel/hexadecimal


PostBuild.hexadecimal.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/RelWithDebInfo/hexadecimal:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/hexadecimal/build/RelWithDebInfo/hexadecimal




# For each target create a dummy ruleso the target does not have to exist
