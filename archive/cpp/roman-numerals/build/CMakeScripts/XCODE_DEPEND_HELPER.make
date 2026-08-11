# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.roman-numerals.Debug:
/Users/viraltaco/code/Exercism/cpp/roman-numerals/build/Debug/roman-numerals:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/roman-numerals/build/Debug/roman-numerals


PostBuild.roman-numerals.Release:
/Users/viraltaco/code/Exercism/cpp/roman-numerals/build/Release/roman-numerals:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/roman-numerals/build/Release/roman-numerals


PostBuild.roman-numerals.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/roman-numerals/build/MinSizeRel/roman-numerals:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/roman-numerals/build/MinSizeRel/roman-numerals


PostBuild.roman-numerals.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/roman-numerals/build/RelWithDebInfo/roman-numerals:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/roman-numerals/build/RelWithDebInfo/roman-numerals




# For each target create a dummy ruleso the target does not have to exist
