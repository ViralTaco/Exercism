# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.phone-number.Debug:
/Users/viraltaco/code/Exercism/cpp/phone-number/build/Debug/phone-number:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/phone-number/build/Debug/phone-number


PostBuild.phone-number.Release:
/Users/viraltaco/code/Exercism/cpp/phone-number/build/Release/phone-number:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/phone-number/build/Release/phone-number


PostBuild.phone-number.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/phone-number/build/MinSizeRel/phone-number:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/phone-number/build/MinSizeRel/phone-number


PostBuild.phone-number.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/phone-number/build/RelWithDebInfo/phone-number:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/phone-number/build/RelWithDebInfo/phone-number




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
