# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.secret-handshake.Debug:
/Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/Debug/secret-handshake:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/Debug/secret-handshake


PostBuild.secret-handshake.Release:
/Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/Release/secret-handshake:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/Release/secret-handshake


PostBuild.secret-handshake.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/MinSizeRel/secret-handshake:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/MinSizeRel/secret-handshake


PostBuild.secret-handshake.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/RelWithDebInfo/secret-handshake:
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/secret-handshake/build/RelWithDebInfo/secret-handshake




# For each target create a dummy ruleso the target does not have to exist
