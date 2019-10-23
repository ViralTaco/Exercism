# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.crypto-square.Debug:
/Users/viraltaco/code/Exercism/cpp/crypto-square/build/Debug/crypto-square:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/crypto-square/build/Debug/crypto-square


PostBuild.crypto-square.Release:
/Users/viraltaco/code/Exercism/cpp/crypto-square/build/Release/crypto-square:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/crypto-square/build/Release/crypto-square


PostBuild.crypto-square.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/crypto-square/build/MinSizeRel/crypto-square:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/crypto-square/build/MinSizeRel/crypto-square


PostBuild.crypto-square.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/crypto-square/build/RelWithDebInfo/crypto-square:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/crypto-square/build/RelWithDebInfo/crypto-square




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_regex-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
