# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.bob.Debug:
/Users/viraltaco/code/Exercism/cpp/bob/build/Debug/bob:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/bob/build/Debug/bob


PostBuild.bob.Release:
/Users/viraltaco/code/Exercism/cpp/bob/build/Release/bob:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/bob/build/Release/bob


PostBuild.bob.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/bob/build/MinSizeRel/bob:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/bob/build/MinSizeRel/bob


PostBuild.bob.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/bob/build/RelWithDebInfo/bob:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/bob/build/RelWithDebInfo/bob




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
