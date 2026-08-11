# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.collatz-conjecture.Debug:
/Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/Debug/collatz-conjecture:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/Debug/collatz-conjecture


PostBuild.collatz-conjecture.Release:
/Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/Release/collatz-conjecture:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/Release/collatz-conjecture


PostBuild.collatz-conjecture.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/MinSizeRel/collatz-conjecture:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/MinSizeRel/collatz-conjecture


PostBuild.collatz-conjecture.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/RelWithDebInfo/collatz-conjecture:
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/collatz-conjecture/build/RelWithDebInfo/collatz-conjecture




# For each target create a dummy ruleso the target does not have to exist
