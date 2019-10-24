# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.beer-song.Debug:
/Users/viraltaco/code/code/Exercism/cpp/beer-song/build/Debug/beer-song:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/beer-song/build/Debug/beer-song


PostBuild.beer-song.Release:
/Users/viraltaco/code/code/Exercism/cpp/beer-song/build/Release/beer-song:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/beer-song/build/Release/beer-song


PostBuild.beer-song.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/beer-song/build/MinSizeRel/beer-song:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/beer-song/build/MinSizeRel/beer-song


PostBuild.beer-song.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/beer-song/build/RelWithDebInfo/beer-song:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/beer-song/build/RelWithDebInfo/beer-song




# For each target create a dummy ruleso the target does not have to exist
