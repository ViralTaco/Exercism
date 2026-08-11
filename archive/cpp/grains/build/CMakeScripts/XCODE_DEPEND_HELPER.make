# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.grains.Debug:
/Users/viraltaco/code/Exercism/cpp/grains/build/Debug/grains:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/grains/build/Debug/grains


PostBuild.grains.Release:
/Users/viraltaco/code/Exercism/cpp/grains/build/Release/grains:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/grains/build/Release/grains


PostBuild.grains.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/grains/build/MinSizeRel/grains:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/grains/build/MinSizeRel/grains


PostBuild.grains.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/grains/build/RelWithDebInfo/grains:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/grains/build/RelWithDebInfo/grains




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_regex-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
