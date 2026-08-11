# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.protein-translation.Debug:
/Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/Debug/protein-translation:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/Debug/protein-translation


PostBuild.protein-translation.Release:
/Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/Release/protein-translation:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/Release/protein-translation


PostBuild.protein-translation.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/MinSizeRel/protein-translation:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/MinSizeRel/protein-translation


PostBuild.protein-translation.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/RelWithDebInfo/protein-translation:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/protein-translation/build/RelWithDebInfo/protein-translation




# For each target create a dummy ruleso the target does not have to exist
