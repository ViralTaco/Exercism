# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.anagram.Debug:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/Debug/anagram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/Debug/anagram


PostBuild.anagram.Release:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/Release/anagram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/Release/anagram


PostBuild.anagram.MinSizeRel:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/MinSizeRel/anagram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/MinSizeRel/anagram


PostBuild.anagram.RelWithDebInfo:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/RelWithDebInfo/anagram:
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/anagram/build/RelWithDebInfo/anagram




# For each target create a dummy ruleso the target does not have to exist
