# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.prime-factors.Debug:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/Debug/prime-factors:\
	/usr/local/lib/libboost_unit_test_framework.a\
	/usr/local/lib/libboost_date_time.a\
	/usr/local/lib/libboost_regex.a
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/Debug/prime-factors


PostBuild.prime-factors.Release:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/Release/prime-factors:\
	/usr/local/lib/libboost_unit_test_framework.a\
	/usr/local/lib/libboost_date_time.a\
	/usr/local/lib/libboost_regex.a
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/Release/prime-factors


PostBuild.prime-factors.MinSizeRel:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/MinSizeRel/prime-factors:\
	/usr/local/lib/libboost_unit_test_framework.a\
	/usr/local/lib/libboost_date_time.a\
	/usr/local/lib/libboost_regex.a
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/MinSizeRel/prime-factors


PostBuild.prime-factors.RelWithDebInfo:
/Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/RelWithDebInfo/prime-factors:\
	/usr/local/lib/libboost_unit_test_framework.a\
	/usr/local/lib/libboost_date_time.a\
	/usr/local/lib/libboost_regex.a
	/bin/rm -f /Users/viraltaco/Desktop/projects/code/Exercism/cpp/prime-factors/build/RelWithDebInfo/prime-factors




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time.a:
/usr/local/lib/libboost_regex.a:
/usr/local/lib/libboost_unit_test_framework.a:
