# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.all-your-base.Debug:
/Users/viraltaco/code/Exercism/cpp/all-your-base/build/Debug/all-your-base:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/all-your-base/build/Debug/all-your-base


PostBuild.all-your-base.Release:
/Users/viraltaco/code/Exercism/cpp/all-your-base/build/Release/all-your-base:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/all-your-base/build/Release/all-your-base


PostBuild.all-your-base.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/all-your-base/build/MinSizeRel/all-your-base:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/all-your-base/build/MinSizeRel/all-your-base


PostBuild.all-your-base.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/all-your-base/build/RelWithDebInfo/all-your-base:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/all-your-base/build/RelWithDebInfo/all-your-base




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_regex-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
