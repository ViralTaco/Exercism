# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.binary-search.Debug:
/Users/viraltaco/code/code/Exercism/cpp/binary-search/build/Debug/binary-search:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary-search/build/Debug/binary-search


PostBuild.binary-search.Release:
/Users/viraltaco/code/code/Exercism/cpp/binary-search/build/Release/binary-search:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary-search/build/Release/binary-search


PostBuild.binary-search.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/binary-search/build/MinSizeRel/binary-search:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary-search/build/MinSizeRel/binary-search


PostBuild.binary-search.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/binary-search/build/RelWithDebInfo/binary-search:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/binary-search/build/RelWithDebInfo/binary-search




# For each target create a dummy ruleso the target does not have to exist
